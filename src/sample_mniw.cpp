#include <RcppArmadillo.h>
#include <RcppTN.h>
#include <bsvars.h>
#include "utils.h"

using namespace Rcpp;
using namespace arma;


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::field<arma::mat> rmniw1(
    const arma::mat& A,     // KxN
    const arma::mat& V,     // KxK
    const arma::mat& S,     // NxN
    const double&    nu     // scalar
) {
  mat SS        = 0.5 * (S + S.t());
  mat Sigma     = iwishrnd(SS, nu);
  mat X_tmp     = mat(size(A), fill::randn);
  mat X         = A + chol(V).t() * X_tmp * chol(Sigma);
  
  field<mat> out(2);
  out(0)        = X;
  out(1)        = Sigma;
  return out;
} // END rmniw1


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::mat rmn1(
    const arma::mat& A,     // KxN
    const arma::mat& V,     // KxK
    const arma::mat& S      // NxN
) {
  mat X_tmp     = mat(size(A), fill::randn);
  mat X         = A + chol(V).t() * X_tmp * chol(S);
  return X;
} // END rmn1


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
double sample_m (
    const arma::mat&    aux_A,    // KxN
    const arma::mat&    aux_V,    // KxK
    const double&       aux_s,   // scalar
    const double&       aux_w,   // scalar
    const Rcpp::List&   prior
) {
  
  mat prior_S_inv   = as<mat>(prior["S_inv"]);
  mat prior_S       = inv_sympd(prior_S_inv);
  mat prior_M       = as<mat>(prior["M"]);
  double prior_mu_m = as<double>(prior["mu_m"]);
  double prior_sigma2_m = as<double>(prior["sigma2_m"]);
  
  mat aux_V_inv     = inv_sympd(aux_V);
  vec aa            = vectorise(aux_A);
  vec mm            = vectorise(prior_M);
  double sigma2_m_bar = 1 / ((1 / prior_sigma2_m) + as_scalar(mm.t() * kron(prior_S_inv / aux_s, aux_V_inv / aux_w) * mm));
  double mu_m_bar       = sigma2_m_bar * ((prior_mu_m / prior_sigma2_m) + as_scalar(mm.t() * kron(prior_S_inv / aux_s, aux_V_inv / aux_w) * aa));
  
  double out        = randn( distr_param(mu_m_bar, pow(sigma2_m_bar, 0.5)) );
  return out;
} // END sample_m


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::vec sample_m_bvars (
    const arma::cube&   aux_A_c,    // KxNxC
    const arma::cube&   aux_Sigma_c_inv,    // KxKxC
    const arma::vec&    aux_w,   // scalar
    const Rcpp::List&   prior
) {
  
  const int C           = aux_A_c.n_slices;
  
  mat prior_M           = as<mat>(prior["M"]);
  mat prior_W           = as<mat>(prior["W"]);
  mat prior_W_inv       = diagmat(1 / prior_W.diag());
  double prior_mu_m     = as<double>(prior["mu_m"]);
  double prior_sigma2_m = as<double>(prior["sigma2_m"]);
  
  vec out(C);
  for (int c=0; c<C; c++) {
    
    vec    a_c            = vectorise(aux_A_c.slice(c));  
    vec    m_c            = vectorise(prior_M);
    double sigma2_m_bar   = 1 / (pow(prior_sigma2_m, -1) + as_scalar(m_c.t() * kron(aux_Sigma_c_inv.slice(c), prior_W_inv / aux_w(c)) * m_c));
    double mu_m_bar       = sigma2_m_bar * ((prior_mu_m / prior_sigma2_m) + as_scalar(m_c.t() * kron(aux_Sigma_c_inv.slice(c), prior_W_inv / aux_w(c)) * a_c));
    out(c)                = randn( distr_param(mu_m_bar, pow(sigma2_m_bar, 0.5)) );
    
  }
  
  return out;
} // END sample_m_bvar\




// [[Rcpp::interfaces(cpp)]]
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


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::vec sample_w_bvars (
    const arma::cube&   aux_A_c,          // KxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::vec&    aux_m,
    const Rcpp::List&   prior
) {
  
  const int N       = aux_A_c.n_rows;
  const int K       = aux_A_c.n_cols;
  const int C       = aux_A_c.n_slices;
  
  mat prior_M       = as<mat>(prior["M"]);
  mat prior_W       = as<mat>(prior["W"]);
  mat prior_W_inv   = diagmat(1 / prior_W.diag());
  double prior_s_w  = as<double>(prior["s_w"]);
  double prior_nu_w = as<double>(prior["nu_w"]);
  
  vec out(C);
  double nu_w_bar   = prior_nu_w + N * K;
  for (int c=0; c<C; c++) {
    double s_w_bar  = prior_s_w + trace(aux_Sigma_c_inv.slice(c) * trans(aux_A_c.slice(c) - aux_m(c) * prior_M) * prior_W_inv * (aux_A_c.slice(c) - aux_m(c) * prior_M) );
    out(c)          = s_w_bar /  chi2rnd(nu_w_bar);
  }
  
  return out;
} // END sample_w_bvars


// [[Rcpp::interfaces(cpp)]]
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


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::vec sample_s_bvars (
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const arma::vec&    aux_nu,           // C
    const Rcpp::List&   prior
) {
  
  const int N       = aux_Sigma_c_inv.n_rows;
  const int C       = aux_Sigma_c_inv.n_slices;
  
  mat prior_S_inv   = as<mat>(prior["S_inv"]);
  mat prior_S       = inv_sympd(prior_S_inv);
  double prior_s_s  = as<double>(prior["s_s"]);
  double prior_a_s  = as<double>(prior["a_s"]);
  
  vec a_s_bar       = prior_a_s + aux_nu * N ;
  vec out(C);
  for (int c=0; c<C; c++) {
    double s_s_bar  = prior_s_s + trace(aux_Sigma_c_inv.slice(c) * prior_S);
    out(c)          = randg( distr_param(a_s_bar(c), s_s_bar) );
  }
  
  return out;
} // END sample_s_bvars



// [[Rcpp::interfaces(cpp)]]
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



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
double log_kernel_nu_bvars (
    const double&       aux_nu,           // scalar
    const double&       aux_s,
    const arma::mat&    aux_Sigma_c_cpp,  // NxNxC
    const arma::mat&    prior_S,        // NxN
    const double&       prior_lambda,     // scalar
    const int&          N,                // scalar
    const int&          K                 // scalar
) {
  
  double log_kernel_nu = 0;
  
  log_kernel_nu      -= 0.5 * N * (K + aux_nu) * log(2);
  log_kernel_nu      -= prior_lambda * aux_nu;
  
  double ldSc         = log_det_sympd(aux_Sigma_c_cpp);
  log_kernel_nu      -= 0.5 * (aux_nu + N + K + 1) * ldSc;
  
  double ldS          = log_det_sympd(aux_s * prior_S);
  log_kernel_nu      += 0.5 * aux_nu * ldS;
  
  for (int n = 1; n < N + 1; n++) {
    log_kernel_nu    -= R::lgammafn(0.5 * (aux_nu + 1 - n));
  } // EDN n loop
  
  return log_kernel_nu;
} // END log_kernel_nu_bvars



// [[Rcpp::interfaces(cpp)]]
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
} // END cov_nu



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
double cov_nu_bvars (
    const double&   aux_nu,
    const int&      N
) {
  
  double Cov_nu       = 0;
  for (int n = 1; n < N + 1; n++) {
    Cov_nu           += R::psigamma( 0.5 * (aux_nu + 1 - n), 1);
  } // END n loop
  Cov_nu             /= 4;
  Cov_nu              = sqrt(1 / Cov_nu);
  return Cov_nu;
} // END cov_nu_bvars



// [[Rcpp::interfaces(cpp)]]
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



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List sample_nu_bvars (
    arma::vec&          aux_nu,           // C
    arma::vec&          adaptive_scale,   // C
    arma::vec&          aux_s,            // C
    const arma::cube&   aux_Sigma_c_cpp,  // NxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    const Rcpp::List&   prior,
    const int&          iteration,        // MCMC iteration passed
    const arma::vec&    adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
) {

  double  prior_lambda  = as<double>(prior["lambda"]);
  mat     prior_S_inv   = as<mat>(prior["S_inv"]);
  mat     prior_S       = inv_sympd(prior_S_inv);
  mat     prior_M       = as<mat>(prior["M"]);
  
  int C               = aux_Sigma_c_cpp.n_slices;
  int N               = aux_Sigma_c_cpp.n_rows;
  int K               = prior_M.n_rows;

  for (int c=0; c<C; c++) {
    
    // negative inverted Hessian of full conditional log-kernel
    double Cov_nu       = cov_nu_bvars(aux_nu(c), N);
    
    // Candidate generating
    double aux_nu_star  = RcppTN::rtn1( aux_nu(c), adaptive_scale(c) * Cov_nu, N + 1, R_PosInf );
    double lk_nu_star   = log_kernel_nu_bvars( aux_nu_star, aux_s(c), aux_Sigma_c_cpp.slice(c), prior_S, prior_lambda, N, K );
    double lk_nu_old    = log_kernel_nu_bvars( aux_nu(c), aux_s(c), aux_Sigma_c_cpp.slice(c), prior_S, prior_lambda, N, K );
    double cgd_ratio    = RcppTN::dtn1( aux_nu_star, aux_nu(c), adaptive_scale(c) * Cov_nu, N + 1, R_PosInf ) /
      RcppTN::dtn1( aux_nu(c), aux_nu_star, adaptive_scale(c) * Cov_nu, N + 1, R_PosInf );
    
    // Adaptive Metropolis-Hastings
    
    double alpha        = 1;
    double kernel_ratio = exp(lk_nu_star - lk_nu_old) * cgd_ratio;
    if ( kernel_ratio < 1 ) alpha = kernel_ratio;
    
    double u            = randu();
    if ( u < alpha ) {
      aux_nu(c)            = aux_nu_star;
    }
    
    if (iteration > 1) {
      adaptive_scale(c) = exp( log(adaptive_scale(c)) + 0.5 * log( 1 + pow(iteration, - adptive_alpha_gamma(1)) * (alpha - adptive_alpha_gamma(0))) );
    }
    
  }

  return List::create(
    _["aux_nu"]         = aux_nu,
    _["adaptive_scale"] = adaptive_scale
  );
} // END sample_nu_bvars


// [[Rcpp::interfaces(cpp)]]
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


// [[Rcpp::interfaces(cpp)]]
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


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::field<arma::mat> sample_AV_jaro (
    const arma::cube&   aux_A_c_cpp,      // KxNxC
    const arma::cube&   aux_Sigma_c_inv,  // NxNxC
    arma::mat&          aux_A,            // KxN
    double&             aux_s,            // scalar
    const Rcpp::List&   prior
) {
  
  int C             = aux_A_c_cpp.n_slices;
  int N             = aux_A_c_cpp.n_cols;
  int K             = aux_A_c_cpp.n_rows;
  
  mat     prior_W   = as<mat>(prior["W"]);
  double  prior_s_s = as<double>(prior["s_s"]);
  double  prior_nu_s = as<double>(prior["nu_s"]);
  
  mat sum_Sc_inv(N, N);
  mat sum_Sc_invAt(K, N);
  mat sum_ASc_invAt(K, K);
  for (int c = 0; c < C; c++) {
    sum_Sc_inv     += aux_Sigma_c_inv.slice(c);
    mat Sc_invAt    = aux_A_c_cpp.slice(c) * aux_Sigma_c_inv.slice(c);
    sum_Sc_invAt   += Sc_invAt;
    sum_ASc_invAt  += (aux_A - aux_A_c_cpp.slice(c)) * aux_Sigma_c_inv.slice(c) * trans(aux_A - aux_A_c_cpp.slice(c));
  } // END c loop
  
  double s_bar      = prior_s_s + trace( diagmat(1 / prior_W.diag()) * sum_ASc_invAt );
  aux_s             = (s_bar) / chi2rnd( prior_nu_s + C * N * K );
  
  mat S_bar_inv     = sum_Sc_inv;
  mat S_bar         = inv_sympd(S_bar_inv);
  mat A_bar         = sum_Sc_invAt * S_bar;
  aux_A             = rmn1(A_bar, aux_s * prior_W, S_bar);
  
  field<mat> aux_AVs(3);
  aux_AVs(0)        = aux_A;
  aux_AVs(1)        = aux_s * prior_W;
  aux_AVs(2)        = aux_s;
  return aux_AVs;
} // END sample_AV_jaro


// [[Rcpp::interfaces(cpp)]]
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


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::field<arma::mat> sample_A_c_Sigma_c_bvars (
    const arma::mat&    Y_c,              // T_cxN
    const arma::mat&    X_c,              // T_cxK
    const arma::mat&    aux_A,            // KxN
    const arma::mat&    aux_V_inv,            // KxK
    const arma::mat&    aux_Sigma,        // NxN
    const double&       aux_nu            // scalar
) {
  int T_c           = Y_c.n_rows;
  
  mat V_bar_inv     = X_c.t() * X_c + aux_V_inv;
  mat V_bar         = inv_sympd( V_bar_inv );
  V_bar             = 0.5 * (V_bar + V_bar.t());
  mat A_bar         = V_bar * ( X_c.t() * Y_c + aux_V_inv * aux_A );
  mat Sigma_bar     = aux_Sigma + Y_c.t() * Y_c + aux_A.t() * aux_V_inv * aux_A - A_bar.t() * V_bar_inv * A_bar;
  double nu_bar     = T_c + aux_nu;
  
  field<mat> aux_A_c_Sigma_c(2);
  try {
    aux_A_c_Sigma_c = rmniw1( A_bar, V_bar, Sigma_bar, nu_bar );
  } catch (std::runtime_error &e) {
    Sigma_bar += 0.2 * eye(size(Sigma_bar));
    aux_A_c_Sigma_c = rmniw1( A_bar, V_bar, Sigma_bar, nu_bar );
  }
  
  return aux_A_c_Sigma_c;
} // END sample_A_c_Sigma_c_bvars


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
double log_kernel_ga (
        const arma::mat&    YG,               // (C_g*T, N) - only group-specific
        const arma::mat&    XG,               // (C_g*T, K)
        const arma::mat     A_g,              // (K, N)
        const arma::mat     Sigma_g,          // (N, N)
        const arma::mat&    aux_A,            // KxN
        const arma::mat&    aux_V_inv,        // KxK
        const arma::mat&    aux_Sigma,        // NxN
        const arma::mat&    aux_Sigma_inv,    // NxN
        const double&       aux_nu            // scalar
) {
  
  int K               = A_g.n_rows;
  int N               = A_g.n_cols;
  
  // normal log-likelihood part
  mat EE              = YG - XG * A_g;
  mat S_g_inv         = inv_sympd(Sigma_g);
  mat SEE             = S_g_inv * EE.t() * EE;
  double log_kernel   = accu( SEE.diag() );
  
  // normal log-prior part
  mat AA              = A_g - aux_A;
  mat SAVA            = pow(N - aux_nu - 1, -1) * aux_Sigma_inv * AA.t() * aux_V_inv * AA;
  log_kernel         += accu( SAVA.diag() );
  
  // IW log-prior part
  double ld_S_g       = log_det_sympd(Sigma_g);
  log_kernel         += (aux_nu + N + K + 1) * ld_S_g;
  log_kernel         += (N - aux_nu - 1) * accu( diagvec( S_g_inv * aux_Sigma ) );
  
  return log_kernel;
} // END log_kernel_ga


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::vec sample_group_allocation (
    arma::vec&          aux_ga,           // (C, 1)
    const arma::cube&   yt,               // (T, N, C)
    const arma::cube&   xt,               // (T, K, C)
    const arma::cube    aux_A_g,          // (K, N, G)
    const arma::cube    aux_Sigma_g,      // (N, N, G)
    const arma::mat&    aux_A,            // KxN
    const arma::mat&    aux_V_inv,        // KxK
    const arma::mat&    aux_Sigma,        // NxN
    const arma::mat&    aux_Sigma_inv,    // NxN
    const double&       aux_nu            // scalar
) {
  
  int C       = aux_ga.n_rows;
  int G       = aux_A_g.n_slices;
  
  vec domain  = regspace(0, G - 1); 
  vec probabilities(G);
  vec log_kernel_c(G);
  
  for (int c=0; c<C; c++) {
    for (int g=0; g<G; g++) {
      
      uvec which_in_g = find(aux_ga == g);
      mat YG          = tcube_to_mat_by_slices( yt.slices(which_in_g) );
      mat XG          = tcube_to_mat_by_slices( xt.slices(which_in_g) );
      
      log_kernel_c(g) = log_kernel_ga ( 
                          YG, XG, 
                          aux_A_g.slice(g), 
                          aux_Sigma_g.slice(g), 
                          aux_A, aux_V_inv, aux_Sigma, aux_Sigma_inv, aux_nu 
                        );
      
    } // END g loop
    
    probabilities     = exp(log_kernel_c - max(log_kernel_c));
    probabilities     = probabilities / accu(probabilities);
    aux_ga(c)         = sample_arma ( domain, probabilities );
    
  } // END c loop
  
  return aux_ga;
} // END sample_group_allocation
