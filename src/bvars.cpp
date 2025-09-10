#include <RcppArmadillo.h>
#include "progress.hpp"
#include "bsvars.h"

#include "sample_mniw.h"

using namespace Rcpp;
using namespace arma;


// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
Rcpp::List bvars_cpp(
    const int&                    S,          // No. of posterior draws
    const Rcpp::List&             Y,          // a C-list of T_cxN elements
    const Rcpp::List&             X,          // a C-list of T_cxK elements
    const Rcpp::List&             prior,      // a list of priors
    const Rcpp::List&             starting_values,
    const int                     thin, // introduce thinning
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
) {

  // Progress bar setup
  vec prog_rep_points = arma::round(arma::linspace(0, S, 50));

  std::string oo      = "";
  if ( thin != 1 ) {
    oo                = bsvars::ordinal(thin) + " ";
  }

  if (show_progress) {
    Rcout << "**************************************************|" << endl;
    Rcout << "bpvars: Forecasting with Bayesian Panel VARs      |" << endl;
    Rcout << "**************************************************|" << endl;
    Rcout << " Progress of the MCMC simulation for " << S << " draws" << endl;
    Rcout << "    Every " << oo << "draw is saved via MCMC thinning" << endl;
    Rcout << " Press Esc to interrupt the computations" << endl;
    Rcout << "**************************************************|" << endl;
  }
  Progress p_bvarPANEL(50, show_progress);

  cube    aux_A_c     = as<cube>(starting_values["A_c"]);
  cube    aux_Sigma_c = as<cube>(starting_values["Sigma_c"]);
  vec     aux_nu      = as<vec>(starting_values["nu"]);
  vec     aux_m       = as<vec>(starting_values["m"]);
  vec     aux_w       = as<vec>(starting_values["w"]);
  vec     aux_s       = as<vec>(starting_values["s"]);

  mat     prior_M     = as<mat>(prior["M"]);
  mat     prior_W     = as<mat>(prior["W"]);
  mat     prior_S_inv = as<mat>(prior["S_inv"]);
  mat     prior_S     = inv_sympd(prior_S_inv);
  
  const int C         = aux_A_c.n_slices;
  const int N         = aux_A_c.n_cols;
  
  const int   SS    = floor(S / thin);

  field<cube> posterior_A_c_cpp(SS);
  field<cube> posterior_Sigma_c_cpp(SS);
  mat         posterior_nu(C, SS);
  mat         posterior_m(C, SS);
  mat         posterior_w(C, SS);
  mat         posterior_s(C, SS);

  field<mat> y(C);
  field<mat> x(C);
  cube  aux_Sigma_c_inv(N, N, C);
  vec   adaptive_scale(C);
  for (int c=0; c<C; c++) {
    y(c)                  = as<mat>(Y[c]);
    x(c)                  = as<mat>(X[c]);
    aux_Sigma_c_inv.slice(c) = inv_sympd( aux_Sigma_c.slice(c) );
    
    // the initial value for the adaptive_scale is set to the negative inverse of
    // Hessian for the posterior log_kenel for nu
    adaptive_scale(c)     = cov_nu_bvars(aux_nu(c), N);
  } // END c loop

  vec   scale(S);
  int   ss = 0;
  List  aux_nu_tmp;

  for (int s=0; s<S; s++) {
    // Rcout << "Iteration: " << s << endl;

    // Increment progress bar
    if (any(prog_rep_points == s)) p_bvarPANEL.increment();
    // Check for user interrupts
    if (s % 200 == 0) checkUserInterrupt();

    // sample aux_m, aux_w, aux_s
    aux_m       = sample_m_bvars(aux_A_c, aux_Sigma_c_inv, aux_w, prior);
    aux_w       = sample_w_bvars(aux_A_c, aux_Sigma_c_inv, aux_m, prior);
    aux_s       = sample_s_bvars(aux_Sigma_c_inv, aux_nu, prior);

    // sample aux_nu
    aux_nu_tmp  = sample_nu_bvars ( aux_nu, adaptive_scale, aux_s, aux_Sigma_c, aux_Sigma_c_inv, prior, s, adptive_alpha_gamma );
    aux_nu          = as<vec>(aux_nu_tmp["aux_nu"]);
    adaptive_scale  = as<vec>(aux_nu_tmp["adaptive_scale"]);

    // sample aux_A_c, aux_Sigma_c
    for (int c=0; c<C; c++) {
      field<mat> tmp_A_c_Sigma_c  = sample_A_c_Sigma_c_bvars( y(c), x(c), aux_m(c) * prior_M, aux_w(c) * prior_W, aux_s(c) * prior_S, aux_nu(c) );
      aux_A_c.slice(c)            = tmp_A_c_Sigma_c(0);
      aux_Sigma_c.slice(c)        = tmp_A_c_Sigma_c(1);
      aux_Sigma_c_inv.slice(c)    = inv_sympd( aux_Sigma_c.slice(c) );
    } // END c loop

    
    if (s % thin == 0) {
      posterior_A_c_cpp(ss)     = aux_A_c;
      posterior_Sigma_c_cpp(ss) = aux_Sigma_c;
      posterior_nu.col(ss)      = aux_nu;
      posterior_m.col(ss)       = aux_m;
      posterior_w.col(ss)       = aux_w;
      posterior_s.col(ss)       = aux_s;

      ss++;
    }
  } // END s loop

  return List::create(
    _["last_draw"]  = List::create(
      _["A_c"]      = aux_A_c,
      _["Sigma_c"]  = aux_Sigma_c,
      _["nu"]       = aux_nu,
      _["m"]        = aux_m,
      _["w"]        = aux_w,
      _["s"]        = aux_s
    ),
    _["posterior"]  = List::create(
      _["A_c_cpp"]  = posterior_A_c_cpp,
      _["Sigma_c_cpp"]  = posterior_Sigma_c_cpp,
      _["nu"]       = posterior_nu,
      _["m"]        = posterior_m,
      _["w"]        = posterior_w,
      _["s"]        = posterior_s,
      _["scale"]    = scale
    )
  );
} // END bvars_cpp
