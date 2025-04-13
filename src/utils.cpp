#include <RcppArmadilloExtensions/sample.h>
#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
arma::mat tcube_to_mat_by_slices (
    arma::cube  Y             // TRANSPOSED cube (T,N,C_g) - not (N,T,C_g) - to use reshape
) {
  int N = Y.n_rows;
  int T = Y.n_cols;
  int S = Y.n_slices;
  
  cube y = Y.reshape( N, T*S, 1);
  return y.slice(0).t(); // a (T x C_g, N) matrix
} // END tcube_to_mat_by_slices

// this function is based on function csample_num1 that was copied from the bsvars package 
// from file src/sample.cpp on 2025-04-13 and modified
// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
int sample_arma (
    arma::vec y,
    arma::vec probabilities
) {
  NumericVector x     = wrap(y);
  NumericVector prob  = wrap( probabilities);
  NumericVector ret   = Rcpp::RcppArmadillo::sample(x, 1, false, prob);
  int out             = ret(0);
  return out;
} // END sample_arma
