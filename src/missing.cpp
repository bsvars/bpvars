#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;


// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List mean_field (
    arma::field<arma::cube>  postY    // (C, S)(T_c, N)
) {
  // computes the means of the aux_Y draws
  int C       = postY(0).n_slices;
  int S       = postY.n_elem;
  List out(C);
  for (int c=0; c<C; c++) {
    mat Ymean(size(postY(0).slice(0)));
    for (int s=0; s<S; s++) {
      Ymean += postY(s).slice(c);
    }
    Ymean /= S;
    out[c] = Ymean;
  }
  return out;
}




// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::mat create_bigA (
    arma::cube  A,
    int         T
) {
  
  int N = A.n_rows;
  int p = A.n_slices;
  
  mat sA      = zeros<mat>(N,N);
  mat ee      = eye<mat>(T,T);
  mat out     = eye<mat>(N*T,N*T);
  
  // out.submat(N,0,2 * N - 1, N-1) -= A;
  for (int i=0; i<p; i++) {
    sA        = A.slice(i);
    mat eee   = ee.submat(0,0,T-2-i,T-2-i);
    mat ia    = kron(eee, sA);
    out.submat((i+1)*N,0,N*T-1,N*(T-1-i)-1) -= ia;
  }
  
  return out;
} // END create_bigA




// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::mat mvnrnd_cond (
    arma::vec x,        // Nx1 vector to be filled with conditional normal draws when missing == 1
    arma::vec mu,       // Nx1 mean vector
    arma::mat Sigma,    // NxN covariance matrix
    arma::vec missing   // Nx1 with 1 for missing observations
) {
  int   N         = missing.n_elem;
  uvec  ind       = find( missing == 0 );
  uvec  ind_miss  = find(missing);
  mat   aj        = eye(N, N);
  
  vec   x2        = x(ind); 
  
  vec   mu1       = mu(ind_miss);
  vec   mu2       = mu(ind);
  mat   Sigma11   = Sigma(ind_miss, ind_miss);
  mat   Sigma12   = Sigma(ind_miss, ind);
  mat   Sigma22   = Sigma(ind, ind);
  mat   Sigma22_inv = inv_sympd(Sigma22);
  
  vec   mu_cond     = mu1 + Sigma12 * Sigma22_inv * (x2 - mu2);
  mat   Sigma_cond  = Sigma11 - Sigma12 * Sigma22_inv * Sigma12.t();
  Sigma_cond      = 0.5 * (Sigma_cond + Sigma_cond.t()); 
  vec   draw      = mvnrnd( mu_cond, Sigma_cond );
  
  vec   out       = aj.cols(ind_miss) * draw + aj.cols(ind) * x2;
  return out;
} // END mvnrnd_cond



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::mat sample_missing (
    arma::mat&            aux_Y,      // (T + p, N)
    arma::mat&            missing,    // (T, N) with 1 for missing values and 0 otherwise
    arma::mat&            exogenous,  // (T + p, d + 1)
    arma::mat&            A_c,        // (K, N)
    arma::mat&            Sigma_c,    // (N, N)
    arma::mat&            A_c_prior_mean, // (K, N)
    arma::mat&            Sigma_c_prior
) {
  const int T     = missing.n_rows;
  const int Tp    = aux_Y.n_rows;
  const int p     = Tp - T;
  const int N     = missing.n_cols;
  const int K     = A_c.n_rows;
  
  mat Ad          = trans(A_c.rows(p * N, A_c.n_rows - 1));
  mat Ad_prior    = trans(A_c_prior_mean.rows(p * N, A_c_prior_mean.n_rows - 1));
  cube A(N, N, p);
  mat A_prior     = -trans(A_c_prior_mean.rows(0, N - 1));
  for (int i=0; i<p; i++) {
    A.slice(i)    = trans(A_c.rows(i * N, (i + 1) * N - 1));
    if ( i != 0 ) A_prior = join_horiz(-trans(A_c_prior_mean.rows(i * N, (i + 1) * N - 1)), A_prior);
  }
  A_prior         = join_horiz(A_prior, eye<mat>(N,N));
  mat bigA        = create_bigA(A, Tp);
  for (int i=0; i<p; i++) {
    bigA.submat(i * N, i * N, i * N + N - 1, i * N + N * (p + 1) - 1) = A_prior;
  }
  vec mu          = vectorise(join_horiz(
    Ad_prior * trans(exogenous.rows(0, p - 1)),
    Ad * trans(exogenous.rows(p, Tp - 1))
  ));
  
  vec miss_mean   = solve(bigA, mu);
  mat Schol       = chol(Sigma_c, "lower");
  mat Schol_prior = chol(Sigma_c_prior, "lower");
  mat L           = kron(eye<mat>(Tp, Tp), Schol);
  for (int i=0; i<p; i++) {
    L.submat(i * N, i * N, i * N + N - 1, i * N + N - 1) = Schol_prior;
  }
  
  mat miss_L      = solve(bigA, L);
  mat miss_Sigma  = miss_L * miss_L.t();
  miss_Sigma    = 0.5 * (miss_Sigma + miss_Sigma.t());
  vec all_missing = vectorise( trans( join_cols( ones<mat>(p,N), missing ) ) );
  
  mat aux_Y_vec   = mvnrnd_cond ( vectorise( trans( aux_Y ) ), miss_mean, miss_Sigma, all_missing );
  aux_Y_vec.reshape(N, Tp);
  return aux_Y_vec.t();
} // END sample_missing



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::field<arma::mat> Y_c_and_X_c (
    arma::mat&      aux_Y,      // (T + p, N)
    arma::mat&      exogenous,  // (T + p, d + 1)
    const int       p
) {
  
  const int   Tp = aux_Y.n_rows;
  const int   T  = Tp - p;
  
  mat Y = aux_Y.rows(p, Tp - 1);
  mat X = exogenous.rows(p, Tp - 1);
  for (int i = 0; i < p; i++) {
    X = join_horiz( aux_Y.rows(i, T - 1 + i), X );
  }
  
  field<mat> out(2);
  out(0) = Y;
  out(1) = X;
  
  return out;
} // END Y_c_and_X_c
