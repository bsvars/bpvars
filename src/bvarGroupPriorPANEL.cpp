#include <RcppArmadillo.h>
#include "progress.hpp"
#include "bsvars.h"

#include "sample_mniw.h"
#include "utils.h"
#include "missing.h"

using namespace Rcpp;
using namespace arma;


// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
Rcpp::List bvarGroupPriorPANEL(
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,          // a C-list of (T_c + p)xN elements
    const Rcpp::List&             missing,    // a C-list of T_cxN elements - 1 for missing
    const Rcpp::List&             exogenous,  // a C-list of (T_c + p)x(d+1) - with intercept
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const int                     thin,                 // introduce thinning
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups,      // whether to estimate group-specific parameters
    const int                     p           // autoregressive lag order
) {
  
  // Progress bar setup
  vec prog_rep_points = arma::round(arma::linspace(0, S, 50));
  
  std::string oo      = "";
  if ( thin != 1 ) {
    oo                = bsvars::ordinal(thin) + " ";
  }
  
  if (show_progress) {
    Rcout << "**************************************************|" << endl;
    Rcout << " bpvars: Forecasting with Bayesian Panel VARs     |" << endl;
    Rcout << "**************************************************|" << endl;
    Rcout << " Progress of the MCMC simulation for " << S << " draws" << endl;
    Rcout << "    Every " << oo << "draw is saved via MCMC thinning" << endl;
    Rcout << " Press Esc to interrupt the computations" << endl;
    Rcout << "**************************************************|" << endl;
  }
  Progress p_bvarPANEL(50, show_progress);
  
  cube    aux_A_c     = as<cube>(starting_values["A_c"]);
  cube    aux_Sigma_c = as<cube>(starting_values["Sigma_c"]);
  cube    aux_A_g     = as<cube>(starting_values["A_g"]);
  cube    aux_Sigma_g = as<cube>(starting_values["Sigma_g"]);
  mat     aux_V       = as<mat>(starting_values["V"]);
  mat     aux_V_inv   = inv_sympd( aux_V );
  double  aux_nu      = as<double>(starting_values["nu"]);
  double  aux_m       = as<double>(starting_values["m"]);
  double  aux_w       = as<double>(starting_values["w"]);
  double  aux_s       = as<double>(starting_values["s"]);
  vec     aux_ga      = as<vec>(starting_values["group_allocation"]) - 1;
  
  const int G         = aux_A_g.n_slices;
  const int C         = aux_A_c.n_slices;
  const int N         = aux_A_c.n_cols;
  const int K         = aux_A_c.n_rows;
  const int SS        = floor(S / thin);
  
  field<mat> aux_Y(C);
  field<mat> y(C);
  field<mat> x(C);
  for (int c=0; c<C; c++) {
    aux_Y(c)          = as<mat>(Y[c]);
  }
  
  field<mat>  postY(C, SS);
  field<cube> posterior_Y(C);
  field<cube> posterior_A_c_cpp(SS);
  field<cube> posterior_Sigma_c_cpp(SS);
  field<cube> posterior_A_g_cpp(SS);
  field<cube> posterior_Sigma_g_cpp(SS);
  cube        posterior_V(K, K, SS);
  mat         posterior_ga(C, SS);
  vec         posterior_nu(SS);
  vec         posterior_nu_S(S);
  vec         posterior_m(SS);
  vec         posterior_w(SS);
  vec         posterior_s(SS);
  
  cube    aux_Sigma_c_inv(N, N, C);
  for (int c=0; c<C; c++) {
    aux_Sigma_c_inv.slice(c) = inv_sympd( aux_Sigma_c.slice(c) );
  } // END c loop
  vec   scale(S);
  int   ss = 0;
  
  // the initial value for the adaptive_scale is set to the negative inverse of 
  // Hessian for the posterior log_kenel for nu
  double adaptive_scale = cov_nu(aux_nu, C, N);
  vec aux_nu_tmp(2);
  
  for (int s=0; s<S; s++) {
    // Rcout << "Iteration: " << s << endl;
    
    // Increment progress bar
    if (any(prog_rep_points == s)) p_bvarPANEL.increment();
    // Check for user interrupts
    if (s % 200 == 0) checkUserInterrupt();
    
    // sample aux_Y
    // Rcout << " sample aux_Y" << endl;
    for (int c=0; c<C; c++) {
      mat miss    = as<mat>(missing[c]);
      mat exo     = as<mat>(exogenous[c]);
      int gac     = aux_ga(c);
      
      try {
        aux_Y(c)    = sample_missing( aux_Y(c), miss, exo, aux_A_c.slice(c), aux_Sigma_c.slice(c), aux_A_g.slice(gac), aux_Sigma_g.slice(gac) );
      } catch (std::runtime_error &e) {
        // Rcout << "   s: " << s <<" c: "<<c << endl;
      }
      
      field<mat> YXtmp = Y_c_and_X_c( aux_Y(c), exo, p );
      y(c)        = YXtmp(0);
      x(c)        = YXtmp(1);
    } // END c loop
    
    
    // sample aux_m, aux_w, aux_s
    // Rcout << "  sample aux_m, aux_w, aux_s" << endl;
    aux_m       = sample_m_gg( aux_A_g, aux_V_inv, aux_s, prior );
    aux_w       = sample_w( aux_V, prior );
    aux_s       = sample_s_gg( aux_A_g, aux_Sigma_g, aux_V_inv, aux_m, prior );
    
    // sample aux_nu
    // Rcout << "  sample aux_nu" << endl;
    aux_nu_tmp  = sample_nu_gg ( aux_nu, adaptive_scale, aux_Sigma_c, aux_Sigma_c_inv, aux_Sigma_g, aux_ga, prior, s, adptive_alpha_gamma );
    aux_nu      = aux_nu_tmp(0);
    scale(s)    = aux_nu_tmp(1);
    
    // sample aux_V
    // Rcout << "  sample aux_V" << endl;
    try {
      aux_V       = sample_V_gg( aux_A_c, aux_Sigma_c_inv, aux_A_g, aux_ga, aux_s, aux_m, aux_w, prior ); 
      aux_V_inv   = inv_sympd( aux_V );
    } catch (std::runtime_error &e) {
      // Rcout << "   s: " << s <<" c: "<<c << endl;
    }
    
    // sample aux_Sigma_g
    // Rcout << "  sample aux_Sigma_g" << endl;
    try {
      aux_Sigma_g = sample_Sigma_g( aux_Sigma_c_inv, aux_ga, aux_s, aux_nu, prior, G );
    } catch (std::runtime_error &e) {
      // Rcout << "   s: " << s <<" c: "<<c << endl;
    }
    
    // sample aux_A_g
    // Rcout << "  sample aux_A" << endl;
    try {
      aux_A_g   = sample_A_g( aux_A_c, aux_Sigma_c_inv, aux_V, aux_ga, aux_s, aux_m, prior, G );
    } catch (std::runtime_error &e) {
      // Rcout << "   s: " << s <<" c: "<<c << endl;
    }
    
    // sample aux_ga
    if ( estimate_groups ) {
      aux_ga    = sample_group_allocation_gg( aux_ga, aux_A_g, aux_Sigma_g, aux_A_c, aux_Sigma_c_inv, aux_V_inv, aux_nu, aux_m, aux_s, prior );
    }
    
    // sample aux_A_c, aux_Sigma_c
    // Rcout << "  sample aux_A_c, aux_Sigma_c" << endl;
    for (int c=0; c<C; c++) {
      int gac                     = aux_ga(c);
      field<mat> tmp_A_c_Sigma_c  = sample_A_c_Sigma_c( y(c), x(c), aux_A_g.slice(gac), aux_V, aux_Sigma_g.slice(gac), aux_nu );
      aux_A_c.slice(c)            = tmp_A_c_Sigma_c(0);
      aux_Sigma_c.slice(c)        = tmp_A_c_Sigma_c(1);
      aux_Sigma_c_inv.slice(c)    = inv_sympd( aux_Sigma_c.slice(c) );
    } // END c loop
    
    if (s % thin == 0) {
      posterior_A_c_cpp(ss)     = aux_A_c;
      posterior_Sigma_c_cpp(ss) = aux_Sigma_c;
      posterior_A_g_cpp(ss)     = aux_A_g;
      posterior_Sigma_g_cpp(ss) = aux_Sigma_g;
      posterior_V.slice(ss)     = aux_V;
      posterior_ga.col(ss)      = aux_ga;
      posterior_nu(ss)          = aux_nu;
      posterior_m(ss)           = aux_m;
      posterior_w(ss)           = aux_w;
      posterior_s(ss)           = aux_s;
      for (int c=0; c<C; c++) {
        postY(c, ss)            = aux_Y(c);
      } // END c loop
      
      ss++;
    }
  } // END s loop
  
  List aux_y_out(C);
  for (int c=0; c<C; c++) {
    cube posty            = zeros<cube>(aux_Y(c).n_rows, aux_Y(c).n_cols, SS);
    for (int ss=0; ss<SS; ss++) {
      posty.slice(ss)      = postY(c, ss);
    }
    posterior_Y(c)        = posty;
    aux_y_out(c)          = aux_Y(c);
  }
  
  return List::create(
    _["last_draw"]  = List::create(
      _["A_c"]      = aux_A_c,
      _["Sigma_c"]  = aux_Sigma_c,
      _["A_g"]      = aux_A_g,
      _["Sigma_g"]  = aux_Sigma_g,
      _["V"]        = aux_V,
      _["nu"]       = aux_nu,
      _["m"]        = aux_m,
      _["w"]        = aux_w,
      _["s"]        = aux_s,
      _["group_allocation"] = aux_ga + 1,
      _["Y"]        = aux_y_out
    ),
    _["posterior"]  = List::create(
      _["A_c_cpp"]  = posterior_A_c_cpp,
      _["Sigma_c_cpp"]  = posterior_Sigma_c_cpp,
      _["A_g_cpp"]  = posterior_A_g_cpp,
      _["Sigma_g_cpp"]  = posterior_Sigma_g_cpp,
      _["V"]        = posterior_V,
      _["nu"]       = posterior_nu,
      _["m"]        = posterior_m,
      _["w"]        = posterior_w,
      _["s"]        = posterior_s,
      _["scale"]    = scale,
      _["group_allocation"] = posterior_ga + 1,
      _["Y"]        = posterior_Y
    )
  );
} // END bvarGroupPriorPANEL
