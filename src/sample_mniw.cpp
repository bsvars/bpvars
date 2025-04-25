#include <RcppArmadillo.h>
#include <RcppTN.h>
#include <bsvars.h>
#include "utils.h"

using namespace Rcpp;
using namespace arma;


// [[Rcpp:interface(cpp,r)]]
// [[Rcpp::export]]
arma::field<arma::mat> rmniw1(
    const arma::mat& A,     // KxN
    const arma::mat& V,     // KxK
    const arma::mat& S,     // NxN
    const double&    nu     // scalar
) {
  // Rcout << "  A: " << A << std::endl;
  // Rcout << "  V: " << V.is_sympd() << std::endl;
  // Rcout << "  S: " << S.is_sympd() << std::endl;
  // Rcout << "  nu: " << nu << std::endl;
  
  mat SS        = 0.5 * (S + S.t());
  mat Sigma     = iwishrnd(SS, nu);
  mat X_tmp     = mat(size(A), fill::randn);
  mat X         = A + chol(V).t() * X_tmp * chol(Sigma);
  
  field<mat> out(2);
  out(0)        = X;
  out(1)        = Sigma;
  return out;
} // END rmniw1


// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
double sample_m (
    const arma::mat&    aux_A,    // KxN
    const arma::mat&    aux_V,    // KxK
    const double&       aux_s,   // scalar
    const double&       aux_w,   // scalar
    const Rcpp::List&   prior
) {
  
  const int N       = aux_A.n_cols;
  mat prior_S_inv   = as<mat>(prior["S_inv"]);
  mat prior_S       = inv_sympd(prior_S_inv);
  double prior_mu_m = as<double>(prior["mu_m"]);
  double prior_sigma2_m = as<double>(prior["sigma2_m"]);
  
  double precision_tmp  = (1 / prior_sigma2_m);
  double mean_tmp       = (prior_mu_m / prior_sigma2_m);
  for (int n = 0; n < N; n++) {
    precision_tmp  += 1 / (aux_s * aux_w * prior_S(n, n) * aux_V(n, n));
    mean_tmp       += aux_A(n, n) / (aux_s * aux_w * prior_S(n, n) * aux_V(n, n));
  }
  double sigma2_m_bar   = 1 / precision_tmp;
  double mu_m_bar       = sigma2_m_bar * mean_tmp;
  
  double out        = randn( distr_param(mu_m_bar, pow(sigma2_m_bar, 0.5)) );
  return out;
} // END sample_m


// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
double sample_w (
    const arma::mat&    aux_V,    // KxK
    const Rcpp::List&   prior
) {
  
  int K             = aux_V.n_cols;
  mat prior_W       = as<mat>(prior["W"]);
  double prior_s_w  = as<double>(prior["s_w"]);
  double prior_a_w  = as<double>(prior["a_w"]);
  double prior_eta  = as<double>(prior["eta"]);
  
  mat aux_V_inv     = inv_sympd(aux_V);
  double s_w_bar    = prior_s_w + 0.5 * trace(aux_V_inv * prior_W);
  double a_w_bar    = prior_a_w + 0.5 * K * prior_eta;
  
  double out        = randg( distr_param(a_w_bar, s_w_bar) );
  return out;
} // END sample_w


// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
double sample_s (
    const arma::mat&    aux_A,      // KxN
    const arma::mat&    aux_V,      // KxK
    const arma::mat&    aux_Sigma,  // NxN
    const double&       aux_m,      // scalar
    const Rcpp::List&   prior
) {
  
  int N             = aux_A.n_cols;
  int K             = aux_A.n_rows;
  mat prior_M       = as<mat>(prior["M"]);
  mat prior_S_inv   = as<mat>(prior["S_inv"]);
  mat prior_S_Sigma_inv = as<mat>(prior["S_Sigma_inv"]);
  double prior_s_s  = as<double>(prior["s_s"]);
  double prior_nu_s = as<double>(prior["nu_s"]);
  double prior_mu_Sigma = as<double>(prior["mu_Sigma"]);
  
  mat quad_tmp1     = (aux_A - aux_m * prior_M) * prior_S_inv * trans(aux_A - aux_m * prior_M);
  
  double s_s_bar    = prior_s_s + trace(solve(aux_V, quad_tmp1)) + trace(prior_S_Sigma_inv * aux_Sigma);
  double nu_s_bar   = prior_nu_s + K * N + N * prior_mu_Sigma;
  
  double out        = s_s_bar / chi2rnd( nu_s_bar );
  return out;
} // END sample_s



// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
double log_kernel_nu (
    const double&       aux_nu,           // scalar
    const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::mat&    aux_Sigma,        // NxN
    const double&       prior_lambda,     // scalar
    const int&          C,                // scalar
    const int&          N,                // scalar
    const int&          K                 // scalar
) {
  
  double log_kernel_nu = 0;
  
  log_kernel_nu      -= 0.5 * C * N * (K + aux_nu) * log(2);
  log_kernel_nu      += 0.5 * C * N * aux_nu * log(aux_nu - N - 1);
  log_kernel_nu      -= prior_lambda * aux_nu;
  
  double ldS          = log_det_sympd(aux_Sigma);
  log_kernel_nu      += 0.5 * C * aux_nu * ldS;
  
  mat sum_aux_Sigma_c_inv(N, N);
  for (int c = 0; c < C; c++) {
    double ldSc       = log_det_sympd(aux_Sigma_c_cpp.slice(c));
    log_kernel_nu    -= 0.5 * (aux_nu + N + K + 1) * ldSc;
    
    sum_aux_Sigma_c_inv += aux_Sigma_c_inv.slice(c);
  }
  log_kernel_nu      -= 0.5 * (aux_nu - N - 1) * trace(aux_Sigma * sum_aux_Sigma_c_inv);
  
  for (int n = 1; n < N + 1; n++) {
    log_kernel_nu    -= C * R::lgammafn(0.5 * (aux_nu + 1 - n));
  } // EDN n loop
  
  return log_kernel_nu;
} // END log_kernel_nu




// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
double cov_nu (
    const double&   aux_nu,
    const int&      C,
    const int&      N
) {
  
  double Cov_nu       = 0;
  for (int n = 1; n < N + 1; n++) {
    Cov_nu           += R::psigamma( 0.5 * (aux_nu + 1 - n), 1);
  } // END n loop
  Cov_nu             /= N;
  Cov_nu             += (4 * (N + 1) - 2 * aux_nu) * pow(N + 1 - aux_nu, -2);
  Cov_nu             *= (C * N / 4);
  Cov_nu              = sqrt(1 / Cov_nu);
  return Cov_nu;
}



// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
arma::vec sample_nu (
    double&             aux_nu,           // scalar
    double&             adaptive_scale,
    const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::mat&    aux_Sigma,        // NxN
    const Rcpp::List&   prior,
    const int&          iteration,        // MCMC iteration passed
    const arma::vec&    adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
) {
  
  double prior_lambda = as<double>(prior["lambda"]);
  mat prior_M         = as<mat>(prior["M"]);
  int K               = prior_M.n_rows;
  int C               = aux_Sigma_c_cpp.n_slices;
  int N               = aux_Sigma.n_rows;
  
  // negative inverted Hessian of full conditional log-kernel
  double Cov_nu       = cov_nu(aux_nu, C, N);
  
  // Metropolis-Hastings
  double aux_nu_star  = RcppTN::rtn1( aux_nu, adaptive_scale * Cov_nu, N + 1, R_PosInf );
  double lk_nu_star   = log_kernel_nu ( aux_nu_star, aux_Sigma_c_cpp, aux_Sigma_c_inv, aux_Sigma, prior_lambda, C, N, K );
  double lk_nu_old    = log_kernel_nu ( aux_nu, aux_Sigma_c_cpp, aux_Sigma_c_inv, aux_Sigma, prior_lambda, C, N, K );
  double cgd_ratio    = RcppTN::dtn1( aux_nu_star, aux_nu, adaptive_scale * Cov_nu, N + 1, R_PosInf ) / 
    RcppTN::dtn1( aux_nu, aux_nu_star, adaptive_scale * Cov_nu, N + 1, R_PosInf );
  
  double alpha        = 1;
  double kernel_ratio = exp(lk_nu_star - lk_nu_old) * cgd_ratio;
  if ( kernel_ratio < 1 ) alpha = kernel_ratio;
  
  double u            = randu();
  if ( u < alpha ) {
    aux_nu            = aux_nu_star;
  }
  
  if (iteration > 1) {
    adaptive_scale = exp( log(adaptive_scale) + 0.5 * log( 1 + pow(iteration, - adptive_alpha_gamma(1)) * (alpha - adptive_alpha_gamma(0))) );
  }
  
  vec out = {aux_nu, adaptive_scale};
  return out;
} // END sample_nu

// // [[Rcpp:interface(cpp)]]
// // [[Rcpp::export]]
// double sample_nu (
//     const double&       aux_nu,           // scalar
//     const arma::vec&    posterior_nu,     // sx1
//     const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
//     const arma::cube&   aux_Sigma_c_inv,  // NxNxC
//     const arma::mat&    aux_Sigma,        // NxN
//     const Rcpp::List&   prior,
//     const int&          iteration,        // MCMC iteration passed
//     arma::vec&          scale,            // (Sx1) adaptive scaling
//     const arma::vec&    rate_target_start_initial
// ) {
//   
//   double prior_lambda = as<double>(prior["lambda"]);
//   mat prior_M         = as<mat>(prior["M"]);
//   int K               = prior_M.n_rows;
//   int C               = aux_Sigma_c_cpp.n_slices;
//   int N               = aux_Sigma.n_rows;
//   
//   // negative inverted Hessian of full conditional log-kernel
//   double Cov_nu       = 0;
//   for (int n = 1; n < N + 1; n++) {
//     Cov_nu           += R::psigamma( 0.5 * (aux_nu + 1 - n), 1);
//   } // END n loop
//   Cov_nu             *= (C / 4);  
//   Cov_nu             -= (C * N * aux_nu) * (2 * pow(aux_nu - N - 1, 2));
//   Cov_nu              = sqrt(0.01 / Cov_nu);
//   
//   // Adaptive MH scaling
//   double scale_s      = rate_target_start_initial(3);
//   if (iteration > rate_target_start_initial(2)) {
//     vec    nu_to_s    = posterior_nu.head(iteration - 1);
//     double alpha_s    = mcmc_accpetance_rate1( nu_to_s );
//     scale_s           = scale(iteration - 1) + pow(iteration, - rate_target_start_initial(0)) * (alpha_s - rate_target_start_initial(1));
//   }
//   scale(iteration)    = scale_s;
//   
//   // Metropolis-Hastings
//   double aux_nu_star  = RcppTN::rtn1( aux_nu, pow(scale_s, 2) * Cov_nu, N + 1, R_PosInf );
//   double lk_nu_star   = log_kernel_nu ( aux_nu_star, aux_Sigma_c_cpp, aux_Sigma_c_inv, aux_Sigma, prior_lambda, C, N, K );
//   double lk_nu_old    = log_kernel_nu ( aux_nu, aux_Sigma_c_cpp, aux_Sigma_c_inv, aux_Sigma, prior_lambda, C, N, K );
//   double cgd_ratio    = RcppTN::dtn1( aux_nu_star, aux_nu, pow(scale_s, 2) * Cov_nu, N + 1, R_PosInf ) / 
//                           RcppTN::dtn1( aux_nu, aux_nu_star, pow(scale_s, 2) * Cov_nu, N + 1, R_PosInf );
//   
//   double u            = randu();
//   double out          = 0;
//   if (u < exp(lk_nu_star - lk_nu_old) * cgd_ratio) {
//     out               = aux_nu_star;
//   } else {
//     out               = aux_nu;
//   } // 
//   
//   return out;
// } // END sample_nu



// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
arma::mat sample_Sigma (
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const double&       aux_s,            // scalar
    const double&       aux_nu,           // scalar
    const Rcpp::List&   prior
) {
  
  int C             = aux_Sigma_c_inv.n_slices;
  int N             = aux_Sigma_c_inv.n_rows;
  mat prior_S_Sigma_inv = as<mat>(prior["S_Sigma_inv"]);
  double prior_mu_Sigma = as<double>(prior["mu_Sigma"]);
  
  mat sum_aux_Sigma_c_inv(N, N);
  for (int c = 0; c < C; c++) {
    sum_aux_Sigma_c_inv += aux_Sigma_c_inv.slice(c);
  }
  
  mat S_Sigma_inv_  = (prior_S_Sigma_inv / aux_s) + (aux_nu - N - 1) * sum_aux_Sigma_c_inv;
  mat S_Sigma_bar   = inv_sympd(S_Sigma_inv_);
  double mu_bar     = C * aux_nu + prior_mu_Sigma;
  
  mat out           = wishrnd( S_Sigma_bar, mu_bar );
  return out;
} // END sample_Sigma


// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
arma::field<arma::mat> sample_AV (
    const arma::cube&   aux_A_c_cpp,      // KxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const double&       aux_s,            // scalar
    const double&       aux_m,            // scalar
    const double&       aux_w,            // scalar
    const Rcpp::List&   prior
) {
  
  int C             = aux_A_c_cpp.n_slices;
  int N             = aux_A_c_cpp.n_cols;
  int K             = aux_A_c_cpp.n_rows;
  
  mat prior_S_inv   = as<mat>(prior["S_inv"]);
  mat prior_M       = as<mat>(prior["M"]);
  mat prior_W       = as<mat>(prior["W"]);
  double prior_eta  = as<double>(prior["eta"]);
  
  mat sum_Sc_inv(N, N);
  mat sum_Sc_invAt(N, K);
  mat sum_ASc_invAt(K, K);
  for (int c = 0; c < C; c++) {
    sum_Sc_inv     += aux_Sigma_c_inv.slice(c);
    mat Sc_invAt    = aux_Sigma_c_inv.slice(c) * aux_A_c_cpp.slice(c).t();
    sum_Sc_invAt   += Sc_invAt;
    sum_ASc_invAt  += aux_A_c_cpp.slice(c) * Sc_invAt;
  } // END c loop
  
  mat S_bar_inv     = (prior_S_inv / aux_s) + sum_Sc_inv;
  mat S_bar         = inv_sympd(S_bar_inv);
  mat M_bar_trans   = S_bar * ( (aux_m / aux_s) * (prior_S_inv * prior_M.t()) + sum_Sc_invAt);
  mat W_bar         = (aux_w * prior_W) + (pow(aux_m, 2) / aux_s) * (prior_M * prior_S_inv * prior_M.t())
    + sum_ASc_invAt - M_bar_trans.t() * S_bar_inv * M_bar_trans;
  double eta_bar    = C * N + prior_eta;  
  
  arma::field<arma::mat> aux_AV = rmniw1( M_bar_trans, S_bar, W_bar, eta_bar );
  aux_AV(0)         = trans(aux_AV(0));
  return aux_AV;
} // END sample_AV


// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
arma::field<arma::mat> sample_A_c_Sigma_c (
    const arma::mat&    Y_c,              // T_cxN
    const arma::mat&    X_c,              // T_cxK
    const arma::mat&    aux_A,            // KxN
    const arma::mat&    aux_V,            // KxK
    const arma::mat&    aux_Sigma,        // NxN
    const double&       aux_nu            // scalar
) {
  int T_c           = Y_c.n_rows;
  int N             = Y_c.n_cols;
  
  mat aux_V_inv     = inv_sympd( aux_V );
  mat V_bar_inv     = X_c.t() * X_c + aux_V_inv;
  mat V_bar         = inv_sympd( V_bar_inv );
  mat A_bar         = V_bar * ( X_c.t() * Y_c + aux_V_inv * aux_A );
  mat Sigma_bar     = (aux_nu - N - 1) * aux_Sigma + Y_c.t() * Y_c + aux_A.t() * aux_V_inv * aux_A - A_bar.t() * V_bar_inv * A_bar;
  double nu_bar     = T_c + aux_nu;
  
  // Rcout << "  nu_bar: " << nu_bar << std::endl;
  // Rcout << "  Sigma_bar: " << Sigma_bar.is_sympd() << std::endl;
  arma::field<arma::mat> aux_A_c_Sigma_c = rmniw1( A_bar, V_bar, Sigma_bar, nu_bar );
  return aux_A_c_Sigma_c;
} // END sample_A_c_Sigma_c



// [[Rcpp:interface(cpp)]]
// [[Rcpp::export]]
Rcpp::List sample_A_g_Sigma_g_ga_c (
    const int           c,
    const arma::cube&   yt,               // (T, N, C)
    const arma::cube&   xt,               // (T, K, C)
    arma::cube          aux_A_g,          // (K, N, G)
    arma::cube          aux_Sigma_g,      // (N, N, G)
    arma::vec           aux_ga,           // Cx1
    double&             aux_log_kernel,   // scalar
    const arma::mat&    aux_A,            // KxN
    const arma::mat&    aux_V,            // KxK
    const arma::mat&    aux_V_inv,        // KxK
    const arma::mat&    aux_Sigma,        // NxN
    const arma::mat&    aux_Sigma_inv,    // NxN
    const double&       aux_nu            // scalar
) {
  
  int G               = aux_A_g.n_slices;
  int K               = aux_A_g.n_rows;
  int N               = aux_A_g.n_cols;
  int current_ga      = aux_ga(c);
  
  // sample the candidate ga
  mat candid_range_tmp(G, 1);
  for (int g = 0; g < G; g++) candid_range_tmp(g, 0) = g;
  candid_range_tmp.shed_row(c);
  vec candid_range    = candid_range_tmp.as_col();
  vec prob(G - 1, fill::value( pow(G - 1, -1) ));
  int candid_ga       = sample_arma(candid_range, prob);
  
  // sample A_g and Sigma_g for the current aux_ga
  uvec which_in_g_cur = find(aux_ga == current_ga);
  mat YG_cur          = tcube_to_mat_by_slices( yt.slices(which_in_g_cur) );
  mat XG_cur          = tcube_to_mat_by_slices( xt.slices(which_in_g_cur) );
  field<mat> AS_g     = sample_A_c_Sigma_c ( YG_cur, XG_cur, aux_A, aux_V, aux_Sigma, aux_nu );
  
  // sample A_g and Sigma_g for the candidate aux_ga
  uvec which_in_g_can = find(aux_ga == candid_ga);
  mat YG_can          = tcube_to_mat_by_slices( yt.slices(which_in_g_can) );
  mat XG_can          = tcube_to_mat_by_slices( xt.slices(which_in_g_can) );
  field<mat> AS_g_can = sample_A_c_Sigma_c ( YG_can, XG_can, aux_A, aux_V, aux_Sigma, aux_nu );
  
  // compute log-kernel for the current aux_ga
  mat EE              = YG_cur - XG_cur * AS_g(0);
  mat S_g_inv         = inv_sympd(AS_g(1));
  mat SEE             = S_g_inv * EE.t() * EE;
  double log_kernel_cur = accu( SEE.diag() );             // normal log-likelihood part
  
  mat AA              = AS_g(0) - aux_A;
  mat SAVA            = aux_Sigma_inv * AA.t() * aux_V_inv * AA;
  log_kernel_cur     += accu( SAVA.diag() );              // normal log-prior part
  
  double ld_S_g       = log_det_sympd(AS_g(1));
  log_kernel_cur     += (aux_nu + N + K + 1) * ld_S_g;    // IW log-prior part
  log_kernel_cur     += (N - aux_nu - 1) * accu( diagvec( S_g_inv * aux_Sigma ) );
  
  // compute log-kernel for the candid_ga
  EE                  = YG_can - XG_can * AS_g_can(0);
  mat S_g_can_inv     = inv_sympd(AS_g_can(1));
  SEE                 = S_g_can_inv * EE.t() * EE;
  double log_kernel_can = accu( SEE.diag() );             // log-likelihood part
  
  AA                  = AS_g_can(0) - aux_A;
  SAVA                = aux_Sigma_inv * AA.t() * aux_V_inv * AA;
  log_kernel_can     += accu( SAVA.diag() );              // normal log-prior part
  
  ld_S_g              = log_det_sympd(AS_g_can(1));
  log_kernel_can     += (aux_nu + N + K + 1) * ld_S_g;    // IW log-prior part
  log_kernel_can     += (N - aux_nu - 1) * accu( diagvec( S_g_can_inv * aux_Sigma ) );
  
  // multinomial sampler
  double p_can        = 1 / ( 1 + exp(log_kernel_cur - log_kernel_can) );
  
  mat     star_Ag, star_Sigma_g;
  int     star_ga;
  double  star_log_kernel;
  if ( randu() < p_can ) {
    star_Ag           = AS_g_can(0);
    star_Sigma_g      = AS_g_can(1);
    star_ga           = candid_ga;
    star_log_kernel   = p_can * log_kernel_can;
  } else {
    star_Ag           = AS_g(0);
    star_Sigma_g      = AS_g(1);
    star_ga           = current_ga;
    star_log_kernel   = (1 - p_can) * log_kernel_cur;
  }
  
  // MH gate
  if (randu() < exp(star_log_kernel - aux_log_kernel)) {
    aux_A_g.slice(c)        = star_Ag;
    aux_Sigma_g.slice(c)    = star_Sigma_g;
    aux_ga(c)               = star_ga;
    aux_log_kernel          = log_kernel_can;
  }
  
  return List::create(
    _["aux_A_g"]        = aux_A_g,
    _["aux_Sigma_g"]    = aux_Sigma_g,
    _["aux_ga"]         = aux_ga,
    _["aux_log_kernel"] = aux_log_kernel
  );
} // END sample_A_g_Sigma_g_ga_c



