#include <RcppArmadillo.h>
#include "progress.hpp"

#include "bsvars.h"
#include "forecast_panel.h"
#include "sample_mniw.h"
#include "rtmvtnorm.h"
#include "utils.h"

using namespace Rcpp;
using namespace arma;

// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List bvarPANEL_noprog(
      const int&                    S,          // No. of posterior draws
      const Rcpp::List&             Y,          // a C-list of T_cxN elements
      const Rcpp::List&             X,          // a C-list of T_cxK elements
      const Rcpp::List&             prior,      // a list of priors
      const Rcpp::List&             starting_values, 
      const arma::vec&              adptive_alpha_gamma, // 2x1 vector with target acceptance rate and step size
      const bool                    type_wozniak = true
) {
    
    const int thin      = 1;
    
    cube    aux_A_c     = as<cube>(starting_values["A_c"]);
    cube    aux_Sigma_c = as<cube>(starting_values["Sigma_c"]);
    mat     aux_A       = as<mat>(starting_values["A"]);
    mat     aux_V       = as<mat>(starting_values["V"]);
    mat     aux_Sigma   = as<mat>(starting_values["Sigma"]);
    double  aux_nu      = as<double>(starting_values["nu"]);
    double  aux_m       = as<double>(starting_values["m"]);
    double  aux_w       = as<double>(starting_values["w"]);
    double  aux_s       = as<double>(starting_values["s"]);
    
    const int C         = aux_A_c.n_slices;
    const int N         = aux_A.n_cols;
    const int K         = aux_A.n_rows;
    
    const int   SS    = floor(S / thin);
    
    field<cube> posterior_A_c_cpp(SS);
    field<cube> posterior_Sigma_c_cpp(SS);
    cube        posterior_A(K, N, SS);
    cube        posterior_V(K, K, SS);
    cube        posterior_Sigma(N, N, SS);
    vec         posterior_nu(SS);
    vec         posterior_nu_S(S);
    vec         posterior_m(SS);
    vec         posterior_w(SS);
    vec         posterior_s(SS);
    
    field<mat> y(C);
    field<mat> x(C);
    cube aux_Sigma_c_inv(N, N, C);
    for (int c=0; c<C; c++) {
      y(c)                  = as<mat>(Y[c]);
      x(c)                  = as<mat>(X[c]);
      aux_Sigma_c_inv.slice(c) = inv_sympd( aux_Sigma_c.slice(c) );
    } // END c loop
    
    vec   scale(S);
    int   ss = 0;
    
    // the initial value for the adaptive_scale is set to the negative inverse of 
    // Hessian for the posterior log_kenel for nu
    double adaptive_scale = cov_nu(aux_nu, C, N);
    vec aux_nu_tmp(2);
    
    for (int s=0; s<S; s++) {
      
      // sample aux_m, aux_w, aux_s
      // Rcout << "  sample m" << endl;
      if ( type_wozniak ) {
        aux_m       = sample_m( aux_A, aux_V, aux_s, aux_w, prior );
      }
      
      // Rcout << "  sample w" << endl;
      if ( type_wozniak ) {
        aux_w       = sample_w( aux_V, prior );
      }
      
      // Rcout << "  sample s" << endl;
      if ( type_wozniak ) {
        aux_s       = sample_s( aux_A, aux_V, aux_Sigma, aux_m, prior );
      }
      
      // sample aux_nu
      if ( type_wozniak ) {
        aux_nu_tmp  = sample_nu ( aux_nu, adaptive_scale, aux_Sigma_c, aux_Sigma_c_inv, aux_Sigma, prior, s, adptive_alpha_gamma );
        aux_nu      = aux_nu_tmp(0);
        scale(s)    = aux_nu_tmp(1);
      }
      
      // sample aux_Sigma
      // Rcout << "  sample Sigma" << endl;
      if ( type_wozniak ) {
        aux_Sigma   = sample_Sigma( aux_Sigma_c_inv, aux_s, aux_nu, prior );
      }
      
      // sample aux_A, aux_V
      // Rcout << "  sample AV" << endl;
      if ( type_wozniak ) {
        field<mat> tmp_AV     = sample_AV( aux_A_c, aux_Sigma_c_inv, aux_s, aux_m, aux_w, prior );
        aux_A       = tmp_AV(0);  
        aux_V       = tmp_AV(1);
      } else {
        field<mat> tmp_AV     = sample_AV_jaro( aux_A_c, aux_Sigma_c, aux_A, aux_s, prior );
        aux_A       = tmp_AV(0);  
        aux_V       = tmp_AV(1);
        mat aux_s_tmp = tmp_AV(2);
        aux_s       = aux_s_tmp(0, 0);
      }
      // sample aux_A_c, aux_Sigma_c
      // Rcout << "  sample A_c Sigma_c" << endl;
      // Rcout << "  aux_nu: " << aux_nu << endl;
      for (int c=0; c<C; c++) {
        field<mat> tmp_A_c_Sigma_c  = sample_A_c_Sigma_c( y(c), x(c), aux_A, aux_V, aux_Sigma, aux_nu );
        aux_A_c.slice(c)            = tmp_A_c_Sigma_c(0);
        aux_Sigma_c.slice(c)        = tmp_A_c_Sigma_c(1);
        aux_Sigma_c_inv.slice(c)    = inv_sympd( aux_Sigma_c.slice(c) );
      } // END c loop
      
      posterior_nu_S(s) = aux_nu;
      
      if (s % thin == 0) {
        posterior_A_c_cpp(ss)     = aux_A_c;
        posterior_Sigma_c_cpp(ss) = aux_Sigma_c;
        posterior_A.slice(ss)     = aux_A;
        posterior_V.slice(ss)     = aux_V;
        posterior_Sigma.slice(ss) = aux_Sigma;
        posterior_nu(ss)          = aux_nu;
        posterior_m(ss)           = aux_m;
        posterior_w(ss)           = aux_w;
        posterior_s(ss)           = aux_s;
        
        ss++;
      }
    } // END s loop
    
    return List::create(
      _["last_draw"]  = List::create(
        _["A_c"]      = aux_A_c,
        _["Sigma_c"]  = aux_Sigma_c,
        _["A"]        = aux_A,
        _["V"]        = aux_V,
        _["Sigma"]    = aux_Sigma,
        _["nu"]       = aux_nu,
        _["m"]        = aux_m,
        _["w"]        = aux_w,
        _["s"]        = aux_s
      ),
      _["posterior"]  = List::create(
        _["A_c_cpp"]  = posterior_A_c_cpp,
        _["Sigma_c_cpp"]  = posterior_Sigma_c_cpp,
        _["A"]        = posterior_A,
        _["V"]        = posterior_V,
        _["Sigma"]    = posterior_Sigma,
        _["nu"]       = posterior_nu,
        _["m"]        = posterior_m,
        _["w"]        = posterior_w,
        _["s"]        = posterior_s,
        _["scale"]    = scale
      )
    );
  } // END bvarPANEL

  
  
  
  


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List bvarPANEL_just_sv_out (
    const int&                    S,          // No. of posterior draws
    const Rcpp::List              Y,          // a C-list of T_cxN elements
    const Rcpp::List              X,          // a C-list of T_cxK elements
    const Rcpp::List&             prior,      // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma, // 2x1 vector with target acceptance rate and step size
    const bool                    type_wozniak = true
) {
  
  // this function is just created for memory management, when just 
  // starting_values are needed from the estimation
  List post   = bvarPANEL_noprog( S, Y, X, prior, starting_values, adptive_alpha_gamma, type_wozniak );
  
  List sv_out = post["last_draw"];
  return sv_out;
} // END bvarPANEL_just_sv_out



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List bvarGroupPANEL_noprog(
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,                    // a C-list of T_cxN elements
    const Rcpp::List&             X,                    // a C-list of T_cxK elements
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false // whether to estimate group-specific parameters
) {
  
  const int thin      = 1;
  
  cube    aux_A_c     = as<cube>(starting_values["A_c"]);
  cube    aux_Sigma_c = as<cube>(starting_values["Sigma_c"]);
  cube    aux_A_g     = as<cube>(starting_values["A_g"]);
  cube    aux_Sigma_g = as<cube>(starting_values["Sigma_g"]);
  mat     aux_A       = as<mat>(starting_values["A"]);
  mat     aux_V       = as<mat>(starting_values["V"]);
  mat     aux_V_inv   = inv_sympd( aux_V );
  mat     aux_Sigma   = as<mat>(starting_values["Sigma"]);
  mat     aux_Sigma_inv = inv_sympd( aux_Sigma );
  double  aux_nu      = as<double>(starting_values["nu"]);
  double  aux_m       = as<double>(starting_values["m"]);
  double  aux_w       = as<double>(starting_values["w"]);
  double  aux_s       = as<double>(starting_values["s"]);
  vec     aux_ga      = as<vec>(starting_values["group_allocation"]) - 1;
  
  const int G         = aux_A_g.n_slices;
  const int C         = aux_A_c.n_slices;
  const int N         = aux_A.n_cols;
  const int K         = aux_A.n_rows;
  const int SS        = floor(S / thin);
  
  field<cube> posterior_A_c_cpp(SS);
  field<cube> posterior_Sigma_c_cpp(SS);
  field<cube> posterior_A_g_cpp(SS);
  field<cube> posterior_Sigma_g_cpp(SS);
  cube        posterior_A(K, N, SS);
  cube        posterior_V(K, K, SS);
  cube        posterior_Sigma(N, N, SS);
  mat         posterior_ga(C, SS);
  vec         posterior_nu(SS);
  vec         posterior_nu_S(S);
  vec         posterior_m(SS);
  vec         posterior_w(SS);
  vec         posterior_s(SS);
  
  cube    aux_Sigma_g_inv(N, N, G);
  cube    aux_Sigma_c_inv(N, N, C);
  for (int g=0; g<G; g++) {
    aux_Sigma_g_inv.slice(g) = inv_sympd( aux_Sigma_g.slice(g) );
  }
  
  mat y_tmp             = as<mat>(Y[0]);
  int T                 = y_tmp.n_rows;
  
  cube yt(N, T, C);           // store provided data matrices
  cube xt(K, T, C);           // store provided data matrices
  
  for (int c=0; c<C; c++) {
    
    aux_Sigma_c_inv.slice(c) = aux_Sigma_g_inv.slice(aux_ga(c));
    
    yt.slice(c)         = trans(as<mat>(Y[c]));
    xt.slice(c)         = trans(as<mat>(X[c]));
    
  } // END c loop
  vec   scale(S);
  int   ss = 0;
  
  // the initial value for the adaptive_scale is set to the negative inverse of 
  // Hessian for the posterior log_kenel for nu
  double adaptive_scale = cov_nu(aux_nu, C, N);
  vec aux_nu_tmp(2);
  
  for (int s=0; s<S; s++) {
    
    // sample aux_m, aux_w, aux_s
    aux_m       = sample_m( aux_A, aux_V, aux_s, aux_w, prior );
    aux_w       = sample_w( aux_V, prior );
    aux_s       = sample_s( aux_A, aux_V, aux_Sigma, aux_m, prior );
    
    // sample aux_nu
    aux_nu_tmp  = sample_nu ( aux_nu, adaptive_scale, aux_Sigma_c, aux_Sigma_c_inv, aux_Sigma, prior, s, adptive_alpha_gamma );
    aux_nu      = aux_nu_tmp(0);
    scale(s)    = aux_nu_tmp(1);
    
    // sample aux_Sigma
    aux_Sigma     = sample_Sigma( aux_Sigma_g_inv, aux_s, aux_nu, prior );
    aux_Sigma_inv = inv_sympd( aux_Sigma );
    
    // sample aux_A, aux_V
    field<mat> tmp_AV     = sample_AV( aux_A_g, aux_Sigma_g_inv, aux_s, aux_m, aux_w, prior );
    aux_A       = tmp_AV(0);  
    aux_V       = tmp_AV(1);
    aux_V_inv   = inv_sympd( aux_V );
    
    // sample aux_ga
    // if ( estimate_groups ) {
    //   aux_ga    = sample_group_allocation ( aux_ga, yt, xt, aux_A_g, aux_Sigma_g, aux_A, aux_V_inv, aux_Sigma, aux_Sigma_inv, aux_nu );
    // }
    
    // sample aux_A_c, aux_Sigma_c
    for (int g=0; g<G; g++) {
      
      uvec which_in_g_cur = find(aux_ga == g);
      mat YG              = tcube_to_mat_by_slices( yt.slices(which_in_g_cur) );
      mat XG              = tcube_to_mat_by_slices( xt.slices(which_in_g_cur) );
      
      field<mat> tmp_A_g_Sigma_g  = sample_A_c_Sigma_c( YG, XG, aux_A, aux_V, aux_Sigma, aux_nu );
      
      aux_A_g.slice(g)            = tmp_A_g_Sigma_g(0);
      aux_Sigma_g.slice(g)        = tmp_A_g_Sigma_g(1);
      aux_Sigma_g_inv.slice(g)    = inv_sympd( aux_Sigma_g.slice(g) );
      
    } // END g loop
    
    for (int c=0; c<C; c++) {
      aux_A_c.slice(c)            = aux_A_g.slice(aux_ga(c));
      aux_Sigma_c.slice(c)        = aux_Sigma_g.slice(aux_ga(c));
    } // END c loop
    
    if (s % thin == 0) {
      posterior_A_c_cpp(ss)     = aux_A_c;
      posterior_Sigma_c_cpp(ss) = aux_Sigma_c;
      posterior_A_g_cpp(ss)     = aux_A_g;
      posterior_Sigma_g_cpp(ss) = aux_Sigma_g;
      posterior_A.slice(ss)     = aux_A;
      posterior_V.slice(ss)     = aux_V;
      posterior_Sigma.slice(ss) = aux_Sigma;
      posterior_ga.col(ss)      = aux_ga;
      posterior_nu(ss)          = aux_nu;
      posterior_m(ss)           = aux_m;
      posterior_w(ss)           = aux_w;
      posterior_s(ss)           = aux_s;
      
      ss++;
    }
  } // END s loop
  
  return List::create(
    _["last_draw"]  = List::create(
      _["A_c"]      = aux_A_c,
      _["Sigma_c"]  = aux_Sigma_c,
      _["A_g"]      = aux_A_g,
      _["Sigma_g"]  = aux_Sigma_g,
      _["A"]        = aux_A,
      _["V"]        = aux_V,
      _["Sigma"]    = aux_Sigma,
      _["nu"]       = aux_nu,
      _["m"]        = aux_m,
      _["w"]        = aux_w,
      _["s"]        = aux_s,
      _["group_allocation"] = aux_ga + 1
    ),
    _["posterior"]  = List::create(
      _["A_c_cpp"]  = posterior_A_c_cpp,
      _["Sigma_c_cpp"]  = posterior_Sigma_c_cpp,
      _["A_g_cpp"]  = posterior_A_g_cpp,
      _["Sigma_g_cpp"]  = posterior_Sigma_g_cpp,
      _["A"]        = posterior_A,
      _["V"]        = posterior_V,
      _["Sigma"]    = posterior_Sigma,
      _["nu"]       = posterior_nu,
      _["m"]        = posterior_m,
      _["w"]        = posterior_w,
      _["s"]        = posterior_s,
      _["scale"]    = scale,
      _["group_allocation"] = posterior_ga + 1
    )
  );
} // END bvarGroupPANEL_noprog



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List bvarGroupPANEL_just_sv_out (
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,                    // a C-list of T_cxN elements
    const Rcpp::List&             X,                    // a C-list of T_cxK elements
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false // whether to estimate group-specific parameters
) {
  
  // this function is just created for memory management, when just 
  // starting_values are needed from the estimation
  List post   = bvarGroupPANEL_noprog( S, Y, X, prior, starting_values, adptive_alpha_gamma, estimate_groups );
  List sv_out = post["last_draw"];
  
  return sv_out;
} // END bvarGroupPANEL_just_sv_out





// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
Rcpp::List bvars_cpp_noprog(
    const int&                    S,          // No. of posterior draws
    const Rcpp::List&             Y,          // a C-list of T_cxN elements
    const Rcpp::List&             X,          // a C-list of T_cxK elements
    const Rcpp::List&             prior,      // a list of priors
    const Rcpp::List&             starting_values,
    const arma::vec&              adptive_alpha_gamma, // 2x1 vector with target acceptance rate and step size
    const bool                    type_objective = false
) {
  
  const int thin = 1;
  
  cube    aux_A_c     = as<cube>(starting_values["A_c"]);
  cube    aux_Sigma_c = as<cube>(starting_values["Sigma_c"]);
  vec     aux_nu      = as<vec>(starting_values["nu"]);
  vec     aux_m       = as<vec>(starting_values["m"]);
  vec     aux_w       = as<vec>(starting_values["w"]);
  vec     aux_s       = as<vec>(starting_values["s"]);
  
  const int C         = aux_A_c.n_slices;
  const int N         = aux_A_c.n_cols;
  const int K         = aux_A_c.n_rows;
  
  mat     prior_M     = as<mat>(prior["M"]);
  mat     prior_W     = as<mat>(prior["W"]);
  mat     prior_W_inv = inv_sympd(prior_W);
  
  mat     prior_S_inv = as<mat>(prior["S_inv"]);
  mat     prior_S(N, N);
  if ( !type_objective ) {
    prior_S           = inv_sympd(prior_S_inv);
  }
  
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
    
    // sample aux_m, aux_w, aux_s
    if ( !type_objective ) {
      aux_m       = sample_m_bvars(aux_A_c, aux_Sigma_c_inv, aux_w, prior);
      aux_w       = sample_w_bvars(aux_A_c, aux_Sigma_c_inv, aux_m, prior);
      aux_s       = sample_s_bvars(aux_Sigma_c_inv, aux_nu, prior);
    }
    
    // sample aux_nu
    if ( !type_objective ) {
      aux_nu_tmp  = sample_nu_bvars ( aux_nu, adaptive_scale, aux_s, aux_Sigma_c, aux_Sigma_c_inv, prior, s, adptive_alpha_gamma );
      aux_nu          = as<vec>(aux_nu_tmp["aux_nu"]);
      adaptive_scale  = as<vec>(aux_nu_tmp["adaptive_scale"]);
    }
    
    // sample aux_A_c, aux_Sigma_c
    mat aux_V_inv(K, K);
    
    for (int c=0; c<C; c++) {
      
      if ( !type_objective ) {
        aux_V_inv = prior_W_inv / aux_w(c);
      }
      
      field<mat> tmp_A_c_Sigma_c  = sample_A_c_Sigma_c_bvars( y(c), x(c), aux_m(c) * prior_M, aux_V_inv, aux_s(c) * prior_S, aux_nu(c) );
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
} // END bvars_cpp_noprog




// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List bvars_just_sv_out (
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,                    // a C-list of T_cxN elements
    const Rcpp::List&             X,                    // a C-list of T_cxK elements
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    type_objective = false // whether to estimate group-specific parameters
) {
  
  // this function is just created for memory management, when just 
  // starting_values are needed from the estimation
  List post   = bvars_cpp_noprog(S, Y, X, prior, starting_values, adptive_alpha_gamma, type_objective);
  List sv_out = post["last_draw"];
  
  return sv_out;
} // END bvars_just_sv_out





// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
Rcpp::List bvarGroupPriorPANEL_noprog(
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,                    // a C-list of T_cxN elements
    const Rcpp::List&             X,                    // a C-list of T_cxK elements
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false // whether to estimate group-specific parameters
) {
  
  const int thin = 1;
  
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
  
  
  mat y_tmp             = as<mat>(Y[0]);
  int T                 = y_tmp.n_rows;
  
  cube    aux_Sigma_c_inv(N, N, C);
  cube y(T, N, C);           // store provided data matrices
  cube x(T, K, C);           // store provided data matrices
  
  for (int c=0; c<C; c++) {
    
    aux_Sigma_c_inv.slice(c) = inv_sympd( aux_Sigma_c.slice(c) );
    
    y.slice(c)         = as<mat>(Y[c]);
    x.slice(c)         = as<mat>(X[c]);
    
  } // END c loop
  vec   scale(S);
  int   ss = 0;
  
  // the initial value for the adaptive_scale is set to the negative inverse of 
  // Hessian for the posterior log_kenel for nu
  double adaptive_scale = cov_nu(aux_nu, C, N);
  vec aux_nu_tmp(2);
  
  for (int s=0; s<S; s++) {
    // Rcout << "Iteration: " << s << endl;
    
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
    aux_V       = sample_V_gg( aux_A_c, aux_Sigma_c_inv, aux_A_g, aux_ga, aux_s, aux_m, aux_w, prior ); 
    aux_V_inv   = inv_sympd( aux_V );
    
    // sample aux_Sigma_g
    // Rcout << "  sample aux_Sigma_g" << endl;
    aux_Sigma_g = sample_Sigma_g( aux_Sigma_c_inv, aux_ga, aux_s, aux_nu, prior, G );
    
    // sample aux_A_g
    // Rcout << "  sample aux_A" << endl;
    aux_A_g   = sample_A_g( aux_A_c, aux_Sigma_c_inv, aux_V, aux_ga, aux_s, aux_m, prior, G );
    
    // sample aux_ga
    if ( estimate_groups ) {
      aux_ga    = sample_group_allocation_gg( aux_ga, aux_A_g, aux_Sigma_g, aux_A_c, aux_Sigma_c_inv, aux_V_inv, aux_nu, aux_m, aux_s, prior );
    }
    
    // sample aux_A_c, aux_Sigma_c
    // Rcout << "  sample aux_A_c, aux_Sigma_c" << endl;
    for (int c=0; c<C; c++) {
      int gac                     = aux_ga(c);
      field<mat> tmp_A_c_Sigma_c  = sample_A_c_Sigma_c( y.slice(c), x.slice(c), aux_A_g.slice(gac), aux_V, aux_Sigma_g.slice(gac), aux_nu );
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
      
      ss++;
    }
  } // END s loop
  
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
      _["group_allocation"] = aux_ga + 1
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
      _["group_allocation"] = posterior_ga + 1
    )
  );
} // END bvarGroupPriorPANEL_noprog





// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List bvarGroupPriorPANEL_just_sv_out (
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,                    // a C-list of T_cxN elements
    const Rcpp::List&             X,                    // a C-list of T_cxK elements
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false // whether to estimate group-specific parameters
) {
  
  // this function is just created for memory management, when just 
  // starting_values are needed from the estimation
  List post   = bvarGroupPriorPANEL_noprog( S, Y, X, prior, starting_values, adptive_alpha_gamma, estimate_groups );
  List sv_out = post["last_draw"];
  
  return sv_out;
} // END bvars_just_sv_out




// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List YX_subset_TT_head_rows (
    const Rcpp::List  Y,
    const int         TT,
    const int         beginning = 0
) {
  
  mat yy_tmp      = as<mat>(Y[0]);
  const int C     = Y.length();
  List YY(C);
  
  for (int c=0; c<C; c++) {
    yy_tmp        = as<mat>(Y[c]);
    mat yyy_tmp   = yy_tmp.rows(0, TT - 1);
    YY[c]         = yyy_tmp;
  } // END c loop
  
  return YY;
} // END YX_subset_TT_head_rows




// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List forecast_bvarPANEL_noprog (
    arma::field<arma::cube>&  posterior_A_c_cpp,      // (S)(K, N, C)
    arma::field<arma::cube>&  posterior_Sigma_c_cpp,  // (S)(N, N, C)
    Rcpp::List&               X_c,                    // (C)(T_c, K)
    Rcpp::List&               cond_forecasts,         // (C)(horizon, N)
    Rcpp::List&               exog_forecasts,         // (C)(horizon, d)
    const int                 horizon,
    arma::vec                 LB,                     // Nx1 lower bounds for truncation
    arma::vec                 UB                     // Nx1 upper bounds for truncation
) {
  
  const int       S = posterior_A_c_cpp.n_elem;
  const int       N = posterior_A_c_cpp(0).n_cols;
  const int       K = posterior_A_c_cpp(0).n_rows;
  const int       C = posterior_A_c_cpp(0).n_slices;
  
  mat     EXcc    = as<mat>(exog_forecasts[0]);
  const int       d = EXcc.n_cols;
  
  field<cube>     forecasts(C);               // of (horizon, N, S) cubes
  field<cube>     out_forecast_mean(C);       // of (horizon, N, S) cubes
  field<cube>     out_forecast_cov(C,S);      // of (N, N, horizon) cubes
  
  for (int c=0; c<C; c++) {
    
    mat     XXcc    = as<mat>(X_c[c]);
    mat     EXcc    = as<mat>(exog_forecasts[c]);
    bool    do_exog = EXcc.is_finite();
    mat     cond_fc = as<mat>(cond_forecasts[c]);
    
    rowvec  x_t;
    if ( do_exog ) {
      x_t = XXcc.tail_rows(1).cols(0, K - 1 - d);
    } else {
      x_t = XXcc.tail_rows(1).cols(0, K - 1);
    }
    
    vec     Xt(K);
    cube    forecasts_c(horizon, N, S);
    cube    meanCS(horizon, N, S);
    
    for (int s=0; s<S; s++) {
      
      
      if ( do_exog ) {
        Xt          = trans(join_rows(x_t, EXcc.row(0)));
      } else {
        Xt          = trans(x_t);
      }
      
      mat Sigma_cs  = posterior_Sigma_c_cpp(s).slice(c);
      mat A_cs      = trans(posterior_A_c_cpp(s).slice(c));
      
      cube  SigmaCS(N, N, horizon);
      
      for (int h=0; h<horizon; h++) {
        
        vec   cond_fc_h   = trans(cond_fc.row(h));
        uvec  nonf_el     = find_nonfinite(cond_fc_h);
        int   nonf_no     = nonf_el.n_elem;
        
        mat   fore_mean   = A_cs * Xt;
        meanCS.slice(s).row(h) = fore_mean.t();
        
        if ( nonf_no == N ) {
          forecasts_c.slice(s).row(h) = trans(
            mvnrnd_truncated( fore_mean, Sigma_cs, LB, UB )
          );
        } else {
          forecasts_c.slice(s).row(h) = trans(
            mvnrnd_cond_truncated( cond_fc_h, fore_mean, Sigma_cs, LB, UB )   // does not work if cond_fc_h is all nan
          );
        }
        
        if ( h != horizon - 1 ) {
          if ( do_exog ) {
            Xt          = trans(join_rows(forecasts_c.slice(s).row(h), Xt.subvec(N, K - 1 - d).t(), EXcc.row(h + 1)));
          } else {
            Xt          = trans(join_rows(forecasts_c.slice(s).row(h), Xt.subvec(N, K - 1).t()));
          }
        }
        
        SigmaCS.slice(h) = Sigma_cs;
        
      } // END h loop
      
      out_forecast_cov(c,s) = SigmaCS;
      
    } // END s loop
    
    forecasts(c)          = forecasts_c;
    out_forecast_mean(c)  = meanCS;
    
  } // END c loop
  
  return List::create(
    _["forecasts_cpp"]      = forecasts,
    _["forecast_mean_cpp"]  = out_forecast_mean,
    _["forecast_cov_cpp"]   = out_forecast_cov
  );
} // END forecast_bvarPANEL_noprog




// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
Rcpp::List forecast_pseudo_out_of_sample_bvarPANEL (
    const int&                    S,                  // No. of posterior draws
    const int&                    S_burn,             // No. of posterior draws
    const arma::ivec              horizons,           // a vector for forecasting horizons for the application
    const int&                    training_sample,    // No. of observations for estimation (R_training_sample--)
    const Rcpp::List              Y,                  // a C-list of T_cxN elements
    const Rcpp::List              X,                  // a C-list of T_cxK elements
    Rcpp::List&                   cond_forecasts,     // (C)(horizon, N)
    Rcpp::List&                   exog_forecasts,     // (C)(horizon, d)
    const Rcpp::List&             prior,              // a list of priors
    const Rcpp::List&             starting_values,    // a list of starting values for bvarPANEL
    const arma::vec               LB,                 // Nx1 lower bounds for truncation
    const arma::vec               UB,                 // Nx1 upper bounds for truncation
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma,// 2x1 vector with target acceptance rate and step size
    const bool                    type_wozniak = true
) {

  // progress bar initiation
  if (show_progress) {
    Rcout << "**************************************************|" << endl;
    Rcout << " bpvars: Forecasting with Bayesian Panel VARs     |" << endl;
    Rcout << "**************************************************|" << endl;
    Rcout << " Recursive pseudo-out-of-sample forecasting using" << endl;
    Rcout << "         expanding window samples." << endl;
    Rcout << " Press Esc to interrupt the computations" << endl;
    Rcout << "**************************************************|" << endl;
  }
  
  // read and create objects
  const int max_horizon = max(horizons);
  mat yy_tmp            = as<mat>(Y[0]);
  const int T           = yy_tmp.n_rows;
  const int forecasting_sample = T - max_horizon - training_sample + 1;
  const int C           = Y.length();
  
  const List YY = Y;
  const List XX = X;
  
  field<cube>   forecasts(C);         //of (horizon, N, S) cubes
  field<cube>   forecast_mean(C);     // of (horizon, N, S) cubes
  field<cube>   forecast_cov(C, S);   // of (N, N, horizon) cubes
  field<mat>    estimation_data(C);   // of (N, TT) cubes
  field<mat>    evaluation_data(C);   // of (N, horizon) cubes
  
  List out(forecasting_sample);
  List fore;
  List foreout;
  
  // full sample estimation - for starting values
  if (show_progress) {
    Rcout << " Step 1: Estimate a model for a full sample to get" << endl;
    Rcout << "         starting values for subsequent steps." << endl;
  }
  List initial_estimation = bvarPANEL_just_sv_out( 
                              S, Y, X, prior, starting_values, 
                                adptive_alpha_gamma, type_wozniak );

  if (show_progress) {
    std::string string_iter;
    if ( forecasting_sample == 1 ) {
      string_iter = " sample.";
    } else {
      string_iter = " samples.";
    }
    
    Rcout << " Step 2: Recursive pseudo out-of-sample" << endl;
    Rcout << "         forecasting performed for " << forecasting_sample << string_iter << endl;
    Rcout << "**************************************************|" << endl;
  }
  
  // progress bar setup
  vec prog_rep_points = arma::round(arma::linspace(0, forecasting_sample, 10));
  Progress pp(10, show_progress);
  
  // forecasting performance loop to be parallelised using openMP
  for (int i = 0; i < forecasting_sample; i++) {
  
    // Increment progress bar
    if (any(prog_rep_points == i)) pp.increment();
    // Check for user interrupts
    // checkUserInterrupt();
    
    List Y_i    = YX_subset_TT_head_rows(YY, training_sample + i);
    List X_i    = YX_subset_TT_head_rows(XX, training_sample + i);
    
    List burn   = bvarPANEL_just_sv_out( 
                    S_burn, Y_i, X_i, prior, initial_estimation, 
                      adptive_alpha_gamma, type_wozniak );
    
    List post   = bvarPANEL_noprog( 
                    S, Y_i, X_i, prior, burn, 
                      adptive_alpha_gamma, type_wozniak );
    
    List posterior                    = as<List>(post["posterior"]);
    field<cube> posterior_A_c_cpp     = as<field<cube>>(posterior["A_c_cpp"]);
    field<cube> posterior_Sigma_c_cpp = as<field<cube>>(posterior["Sigma_c_cpp"]);
    
    fore   = forecast_bvarPANEL_noprog (
                    posterior_A_c_cpp, posterior_Sigma_c_cpp, 
                      X_i, cond_forecasts, exog_forecasts, 
                        max_horizon, LB, UB );        
    
    forecasts                         = as<field<cube>>(fore["forecasts_cpp"]);
    forecast_mean                     = as<field<cube>>(fore["forecast_mean_cpp"]);
    field<cube> forecast_cov_tmp      = as<field<cube>>(fore["forecast_cov_cpp"]);

    int ind = 0;
    for (int c=0; c<C; c++) {
      
      for (int s=0; s<S; s++) {
        ind = s*C + c;
        // Rcout << " c, s, ind: " << c  << " " << s << " "  << ind << endl;
        forecast_cov(c,s) = forecast_cov_tmp(ind);
      }
      
      estimation_data(c)  = as<mat>(Y_i[c]);
      mat Yc_tmp          = as<mat>(Y[c]);
      mat YYc_tmp         = Yc_tmp.rows(
                              training_sample + i ,
                              training_sample + i + max_horizon - 1
                            );
      evaluation_data(c)  = YYc_tmp;
      
    } // END c loop
    
    foreout = List::create(
      _["forecasts_cpp"]       = forecasts,
      _["forecast_mean_cpp"]   = forecast_mean,
      _["forecast_cov_cpp"]    = forecast_cov,
      _["estimation_data_cpp"] = estimation_data,
      _["evaluation_data_cpp"] = evaluation_data
    );
    
    out[i] = foreout;
    
  } // END of i loop
  
  return out;
} // END forecast_pseudo_out_of_sample_bvarPANEL



// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
Rcpp::List forecast_pseudo_out_of_sample_bvarGroupPANEL (
    const int&                    S,                  // No. of posterior draws
    const int&                    S_burn,             // No. of posterior draws
    const arma::ivec              horizons,           // a vector for forecasting horizons for the application
    const int&                    training_sample,    // No. of observations for estimation (R_training_sample--)
    const Rcpp::List              Y,                  // a C-list of T_cxN elements
    const Rcpp::List              X,                  // a C-list of T_cxK elements
    Rcpp::List&                   cond_forecasts,     // (C)(horizon, N)
    Rcpp::List&                   exog_forecasts,     // (C)(horizon, d)
    const Rcpp::List&             prior,              // a list of priors
    const Rcpp::List&             starting_values,    // a list of starting values for bvarPANEL
    const arma::vec               LB,                 // Nx1 lower bounds for truncation
    const arma::vec               UB,                 // Nx1 upper bounds for truncation
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma,      // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false   // whether to estimate group-specific parameters
) {
  
  // progress bar initiation
  if (show_progress) {
    Rcout << "**************************************************|" << endl;
    Rcout << " bpvars: Forecasting with Bayesian Panel VARs     |" << endl;
    Rcout << "**************************************************|" << endl;
    Rcout << " Recursive pseudo-out-of-sample forecasting using" << endl;
    Rcout << "         expanding window samples." << endl;
    Rcout << " Press Esc to interrupt the computations" << endl;
    Rcout << "**************************************************|" << endl;
  }
  
  // read and create objects
  const int max_horizon = max(horizons);
  mat yy_tmp            = as<mat>(Y[0]);
  const int T           = yy_tmp.n_rows;
  const int forecasting_sample = T - max_horizon - training_sample + 1;
  const int C           = Y.length();
  
  const List YY = Y;
  const List XX = X;
  
  field<cube>   forecasts(C);         //of (horizon, N, S) cubes
  field<cube>   forecast_mean(C);     // of (horizon, N, S) cubes
  field<cube>   forecast_cov(C, S);   // of (N, N, horizon) cubes
  field<mat>    estimation_data(C);   // of (N, TT) cubes
  field<mat>    evaluation_data(C);   // of (N, horizon) cubes
  
  List out(forecasting_sample);
  List fore;
  List foreout;
  
  // full sample estimation - for starting values
  if (show_progress) {
    Rcout << " Step 1: Estimate a model for a full sample to get" << endl;
    Rcout << "         starting values for subsequent steps." << endl;
  }
  
  List initial_estimation = bvarGroupPANEL_just_sv_out (S, Y, X, prior, starting_values,
                                                          adptive_alpha_gamma, estimate_groups);
    
    
  if (show_progress) {
    std::string string_iter;
    if ( forecasting_sample == 1 ) {
      string_iter = " sample.";
    } else {
      string_iter = " samples.";
    }
    
    Rcout << " Step 2: Recursive pseudo out-of-sample" << endl;
    Rcout << "         forecasting performed for " << forecasting_sample << string_iter << endl;
    Rcout << "**************************************************|" << endl;
  }
  
  // progress bar setup
  vec prog_rep_points = arma::round(arma::linspace(0, forecasting_sample, 10));
  Progress pp(10, show_progress);
  
  // forecasting performance loop to be parallelised using openMP
  for (int i = 0; i < forecasting_sample; i++) {
    
    // Increment progress bar
    if (any(prog_rep_points == i)) pp.increment();
    // Check for user interrupts
    // checkUserInterrupt();
    
    List Y_i    = YX_subset_TT_head_rows(YY, training_sample + i);
    List X_i    = YX_subset_TT_head_rows(XX, training_sample + i);
    
    List burn   = bvarGroupPANEL_just_sv_out (
                    S_burn, Y_i, X_i, prior, initial_estimation,
                      adptive_alpha_gamma, estimate_groups);
      
      
    List post   = bvarGroupPANEL_noprog(
                    S, Y_i, X_i, prior, burn, 
                      adptive_alpha_gamma, estimate_groups );
    
    List posterior                    = as<List>(post["posterior"]);
    field<cube> posterior_A_c_cpp     = as<field<cube>>(posterior["A_c_cpp"]);
    field<cube> posterior_Sigma_c_cpp = as<field<cube>>(posterior["Sigma_c_cpp"]);
    
    fore   = forecast_bvarPANEL_noprog (
              posterior_A_c_cpp, posterior_Sigma_c_cpp, 
                X_i, cond_forecasts, exog_forecasts, 
                  max_horizon, LB, UB );        
    
    forecasts                         = as<field<cube>>(fore["forecasts_cpp"]);
    forecast_mean                     = as<field<cube>>(fore["forecast_mean_cpp"]);
    field<cube> forecast_cov_tmp      = as<field<cube>>(fore["forecast_cov_cpp"]);
    
    int ind = 0;
    for (int c=0; c<C; c++) {
      
      for (int s=0; s<S; s++) {
        ind = s*C + c;
        // Rcout << " c, s, ind: " << c  << " " << s << " "  << ind << endl;
        forecast_cov(c,s) = forecast_cov_tmp(ind);
      }
      
      estimation_data(c)  = as<mat>(Y_i[c]);
      mat Yc_tmp          = as<mat>(Y[c]);
      mat YYc_tmp         = Yc_tmp.rows(
        training_sample + i ,
        training_sample + i + max_horizon - 1
      );
      evaluation_data(c)  = YYc_tmp;
      
    } // END c loop
    
    foreout = List::create(
      _["forecasts_cpp"]       = forecasts,
      _["forecast_mean_cpp"]   = forecast_mean,
      _["forecast_cov_cpp"]    = forecast_cov,
      _["estimation_data_cpp"] = estimation_data,
      _["evaluation_data_cpp"] = evaluation_data
    );
    
    out[i] = foreout;
    
  } // END of i loop
  
  return out;
} // END forecast_pseudo_out_of_sample_bvarGroupPANEL



// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
Rcpp::List forecast_pseudo_out_of_sample_bvars (
    const int&                    S,                  // No. of posterior draws
    const int&                    S_burn,             // No. of posterior draws
    const arma::ivec              horizons,           // a vector for forecasting horizons for the application
    const int&                    training_sample,    // No. of observations for estimation (R_training_sample--)
    const Rcpp::List              Y,                  // a C-list of T_cxN elements
    const Rcpp::List              X,                  // a C-list of T_cxK elements
    Rcpp::List&                   cond_forecasts,     // (C)(horizon, N)
    Rcpp::List&                   exog_forecasts,     // (C)(horizon, d)
    const Rcpp::List&             prior,              // a list of priors
    const Rcpp::List&             starting_values,    // a list of starting values for bvarPANEL
    const arma::vec               LB,                 // Nx1 lower bounds for truncation
    const arma::vec               UB,                 // Nx1 upper bounds for truncation
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma, // 2x1 vector with target acceptance rate and step size
    const bool                    type_objective = false
) {
  
  // progress bar initiation
  if (show_progress) {
    Rcout << "**************************************************|" << endl;
    Rcout << " bpvars: Forecasting with Bayesian Panel VARs     |" << endl;
    Rcout << "**************************************************|" << endl;
    Rcout << " Recursive pseudo-out-of-sample forecasting using" << endl;
    Rcout << "         expanding window samples." << endl;
    Rcout << " Press Esc to interrupt the computations" << endl;
    Rcout << "**************************************************|" << endl;
  }
  
  // read and create objects
  const int max_horizon = max(horizons);
  mat yy_tmp            = as<mat>(Y[0]);
  const int T           = yy_tmp.n_rows;
  const int forecasting_sample = T - max_horizon - training_sample + 1;
  const int C           = Y.length();
  
  const List YY = Y;
  const List XX = X;
  
  field<cube>   forecasts(C);         //of (horizon, N, S) cubes
  field<cube>   forecast_mean(C);     // of (horizon, N, S) cubes
  field<cube>   forecast_cov(C, S);   // of (N, N, horizon) cubes
  field<mat>    estimation_data(C);   // of (N, TT) cubes
  field<mat>    evaluation_data(C);   // of (N, horizon) cubes
  
  List out(forecasting_sample);
  List fore;
  List foreout;
  
  // full sample estimation - for starting values
  if (show_progress) {
    Rcout << " Step 1: Estimate a model for a full sample to get" << endl;
    Rcout << "         starting values for subsequent steps." << endl;
  }
  List initial_estimation = bvars_just_sv_out(S, Y, X, prior, starting_values, adptive_alpha_gamma, type_objective);
  
  if (show_progress) {
    std::string string_iter;
    if ( forecasting_sample == 1 ) {
      string_iter = " sample.";
    } else {
      string_iter = " samples.";
    }
    
    Rcout << " Step 2: Recursive pseudo out-of-sample" << endl;
    Rcout << "         forecasting performed for " << forecasting_sample << string_iter << endl;
    Rcout << "**************************************************|" << endl;
  }
  
  // progress bar setup
  vec prog_rep_points = arma::round(arma::linspace(0, forecasting_sample, 10));
  Progress pp(10, show_progress);
  
  // forecasting performance loop to be parallelised using openMP
  for (int i = 0; i < forecasting_sample; i++) {
    
    // Increment progress bar
    if (any(prog_rep_points == i)) pp.increment();
    // Check for user interrupts
    // checkUserInterrupt();
    
    List Y_i    = YX_subset_TT_head_rows(YY, training_sample + i);
    List X_i    = YX_subset_TT_head_rows(XX, training_sample + i);
    
    List burn   = bvars_just_sv_out(
      S_burn, Y_i, X_i, prior, initial_estimation,
      adptive_alpha_gamma, type_objective);
    
    List post   = bvars_cpp_noprog(
      S, Y_i, X_i, prior, burn, 
      adptive_alpha_gamma, type_objective);
      
    List posterior                    = as<List>(post["posterior"]);
    field<cube> posterior_A_c_cpp     = as<field<cube>>(posterior["A_c_cpp"]);
    field<cube> posterior_Sigma_c_cpp = as<field<cube>>(posterior["Sigma_c_cpp"]);
    
    fore   = forecast_bvarPANEL_noprog (
      posterior_A_c_cpp, posterior_Sigma_c_cpp, 
      X_i, cond_forecasts, exog_forecasts, 
      max_horizon, LB, UB );        
    
    forecasts                         = as<field<cube>>(fore["forecasts_cpp"]);
    forecast_mean                     = as<field<cube>>(fore["forecast_mean_cpp"]);
    field<cube> forecast_cov_tmp      = as<field<cube>>(fore["forecast_cov_cpp"]);
    
    int ind = 0;
    for (int c=0; c<C; c++) {
      
      for (int s=0; s<S; s++) {
        ind = s*C + c;
        // Rcout << " c, s, ind: " << c  << " " << s << " "  << ind << endl;
        forecast_cov(c,s) = forecast_cov_tmp(ind);
      }
      
      estimation_data(c)  = as<mat>(Y_i[c]);
      mat Yc_tmp          = as<mat>(Y[c]);
      mat YYc_tmp         = Yc_tmp.rows(
        training_sample + i ,
        training_sample + i + max_horizon - 1
      );
      evaluation_data(c)  = YYc_tmp;
      
    } // END c loop
    
    foreout = List::create(
      _["forecasts_cpp"]       = forecasts,
      _["forecast_mean_cpp"]   = forecast_mean,
      _["forecast_cov_cpp"]    = forecast_cov,
      _["estimation_data_cpp"] = estimation_data,
      _["evaluation_data_cpp"] = evaluation_data
    );
    
    out[i] = foreout;
    
  } // END of i loop
  
  return out;
} // END forecast_pseudo_out_of_sample_bvars






// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
Rcpp::List forecast_pseudo_out_of_sample_bvarGroupPriorPANEL (
    const int&                    S,                  // No. of posterior draws
    const int&                    S_burn,             // No. of posterior draws
    const arma::ivec              horizons,           // a vector for forecasting horizons for the application
    const int&                    training_sample,    // No. of observations for estimation (R_training_sample--)
    const Rcpp::List              Y,                  // a C-list of T_cxN elements
    const Rcpp::List              X,                  // a C-list of T_cxK elements
    Rcpp::List&                   cond_forecasts,     // (C)(horizon, N)
    Rcpp::List&                   exog_forecasts,     // (C)(horizon, d)
    const Rcpp::List&             prior,              // a list of priors
    const Rcpp::List&             starting_values,    // a list of starting values for bvarPANEL
    const arma::vec               LB,                 // Nx1 lower bounds for truncation
    const arma::vec               UB,                 // Nx1 upper bounds for truncation
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma,      // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false   // whether to estimate group-specific parameters
) {
  
  // progress bar initiation
  if (show_progress) {
    Rcout << "**************************************************|" << endl;
    Rcout << " bpvars: Forecasting with Bayesian Panel VARs     |" << endl;
    Rcout << "**************************************************|" << endl;
    Rcout << " Recursive pseudo-out-of-sample forecasting using" << endl;
    Rcout << "         expanding window samples." << endl;
    Rcout << " Press Esc to interrupt the computations" << endl;
    Rcout << "**************************************************|" << endl;
  }
  
  // read and create objects
  const int max_horizon = max(horizons);
  mat yy_tmp            = as<mat>(Y[0]);
  const int T           = yy_tmp.n_rows;
  const int forecasting_sample = T - max_horizon - training_sample + 1;
  const int C           = Y.length();
  
  const List YY = Y;
  const List XX = X;
  
  field<cube>   forecasts(C);         //of (horizon, N, S) cubes
  field<cube>   forecast_mean(C);     // of (horizon, N, S) cubes
  field<cube>   forecast_cov(C, S);   // of (N, N, horizon) cubes
  field<mat>    estimation_data(C);   // of (N, TT) cubes
  field<mat>    evaluation_data(C);   // of (N, horizon) cubes
  
  List out(forecasting_sample);
  List fore;
  List foreout;
  
  // full sample estimation - for starting values
  if (show_progress) {
    Rcout << " Step 1: Estimate a model for a full sample to get" << endl;
    Rcout << "         starting values for subsequent steps." << endl;
  }
  
  List initial_estimation = bvarGroupPriorPANEL_just_sv_out( S, Y, X, prior, starting_values, 
                                                             adptive_alpha_gamma, estimate_groups );
  
  if (show_progress) {
    std::string string_iter;
    if ( forecasting_sample == 1 ) {
      string_iter = " sample.";
    } else {
      string_iter = " samples.";
    }
    
    Rcout << " Step 2: Recursive pseudo out-of-sample" << endl;
    Rcout << "         forecasting performed for " << forecasting_sample << string_iter << endl;
    Rcout << "**************************************************|" << endl;
  }
  
  // progress bar setup
  vec prog_rep_points = arma::round(arma::linspace(0, forecasting_sample, 10));
  Progress pp(10, show_progress);
  
  // forecasting performance loop to be parallelised using openMP
  for (int i = 0; i < forecasting_sample; i++) {
    
    // Increment progress bar
    if (any(prog_rep_points == i)) pp.increment();
    // Check for user interrupts
    // checkUserInterrupt();
    
    List Y_i    = YX_subset_TT_head_rows(YY, training_sample + i);
    List X_i    = YX_subset_TT_head_rows(XX, training_sample + i);
    
    List burn   = bvarGroupPriorPANEL_just_sv_out( 
      S_burn, Y_i, X_i, prior, initial_estimation,
      adptive_alpha_gamma, estimate_groups );
    
    List post   = bvarGroupPriorPANEL_noprog(
      S, Y_i, X_i, prior, burn, 
      adptive_alpha_gamma, estimate_groups );
    
    List posterior                    = as<List>(post["posterior"]);
    field<cube> posterior_A_c_cpp     = as<field<cube>>(posterior["A_c_cpp"]);
    field<cube> posterior_Sigma_c_cpp = as<field<cube>>(posterior["Sigma_c_cpp"]);
    
    fore   = forecast_bvarPANEL_noprog (
      posterior_A_c_cpp, posterior_Sigma_c_cpp, 
      X_i, cond_forecasts, exog_forecasts, 
      max_horizon, LB, UB );        
    
    forecasts                         = as<field<cube>>(fore["forecasts_cpp"]);
    forecast_mean                     = as<field<cube>>(fore["forecast_mean_cpp"]);
    field<cube> forecast_cov_tmp      = as<field<cube>>(fore["forecast_cov_cpp"]);
    
    int ind = 0;
    for (int c=0; c<C; c++) {
      
      for (int s=0; s<S; s++) {
        ind = s*C + c;
        // Rcout << " c, s, ind: " << c  << " " << s << " "  << ind << endl;
        forecast_cov(c,s) = forecast_cov_tmp(ind);
      }
      
      estimation_data(c)  = as<mat>(Y_i[c]);
      mat Yc_tmp          = as<mat>(Y[c]);
      mat YYc_tmp         = Yc_tmp.rows(
        training_sample + i ,
        training_sample + i + max_horizon - 1
      );
      evaluation_data(c)  = YYc_tmp;
      
    } // END c loop
    
    foreout = List::create(
      _["forecasts_cpp"]       = forecasts,
      _["forecast_mean_cpp"]   = forecast_mean,
      _["forecast_cov_cpp"]    = forecast_cov,
      _["estimation_data_cpp"] = estimation_data,
      _["evaluation_data_cpp"] = evaluation_data
    );
    
    out[i] = foreout;
    
  } // END of i loop
  
  return out;
} // END forecast_pseudo_out_of_sample_bvarGroupPriorPANEL









// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
arma::field<arma::cube> fourDarray_to_field_cube (
    Rcpp::NumericVector arr
) {
  // returns field of cubes (S)(N,I,H) from a 4D array (N,I,H,S)
  
  IntegerVector dims    = arr.attr("dim");
  int N = dims[0], I = dims[1], H = dims[2], S = dims[3];
  arma::field<arma::cube> out(S);
  
  for (int s = 0; s < S; ++s) {
    
    cube cc(N, I, H);
    for (int h = 0; h < H; ++h) {
      for (int i = 0; i < I; ++i) {
        for (int n = 0; n < N; ++n) {
          
          int idx       = n + N * (i + I * (h + H * s));
          cc(n, i, h)  = arr[idx] ;
        } // END n loop
      } // END i loop
    } // END h loop
    
    out(s) = cc;
    
  } // END s loop
  
  return out;
} // END fourDarray_to_field_cube




// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
double log_dnormm_joint_s (
    arma::vec& x,
    arma::vec& mu,
    arma::mat& sigma
) {
  
  int N         =  x.n_elem;
  double ld     = log_det_sympd(sigma);
  double joint  = -0.5 * N * log(2 * M_PI);
  joint        -= 0.5 * ld;
  joint        -= 0.5 * as_scalar((x - mu).t() * inv_sympd(sigma) * (x - mu));
  
  return joint;
} // END log_dnormm_joint_s




// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
arma::cube log_dnormm_marginal (
    arma::mat&            x,      // (N, horizon)
    arma::cube&           mu,     // (N, horizon, S)
    arma::field<arma::cube>&  sigma   // array (N, N, horizon, S)&  Sigma   // array (N, N, horizon, S)
) {
  
  int N           = mu.n_rows;
  int horizon     = mu.n_cols;
  int S           = mu.n_slices;
  
  cube marginal(N, horizon, S);

  for (int s=0; s<S; s++) {
    for (int h=0; h<horizon; h++) {
      
      vec xh      = x.col(h);
      vec muh     = mu.slice(s).col(h);
      vec sigmah  = sqrt(diagvec(sigma(s).slice(h)));
      vec lp_tmp  = log_normpdf(xh, muh, sigmah);
      marginal.slice(s).col(h) = lp_tmp;
      
    } // END h loop
  } // END s loop
  
  return marginal;
} // END log_dnormm_marginal


// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
arma::mat log_dnormm_joint (
    arma::mat&            x,      // (N, horizon)
    arma::cube&           mu,     // (N, horizon, S)
    arma::field<arma::cube>&  sigma   // array (N, N, horizon, S)
) {
  
  int horizon     = mu.n_cols;
  int S           = mu.n_slices;
  mat joint(horizon, S);
  
  for (int s=0; s<S; s++) {
    for (int h=0; h<horizon; h++) {
      
      vec xh      = x.col(h);
      vec muh     = mu.slice(s).col(h);
      mat sigmah  = sigma(s).slice(h);
      bool sympd  = sigmah.is_sympd();
      if (!sympd) continue;
      
      joint(h,s)  = log_dnormm_joint_s(xh, muh, sigmah);
    } // END h loop
  } // END s loop
  
  return joint;
} // END log_dnormm_joint




/* This function was copied from package bsvars on 2025-07-07 and subsequently modified.
 * location: bsvars/src/utils.cpp
 */
// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
double log_mean (
    arma::vec     log_density
) {
  double N              = log_density.n_elem;
  double c_log_den      = log_density.max();
  double log_numerator  = c_log_den - log(N) + log( accu(exp(log_density - c_log_den)) );
  return log_numerator;
} // log_mean 
