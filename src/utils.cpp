#include <RcppArmadilloExtensions/sample.h>
#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::interfaces(cpp)]]
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




// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
arma::mat field_to_mat (
    const arma::field<arma::mat>&   Y,
    const arma::uvec&               which
) {
  int G = which.n_elem;
  int N = Y(0).n_cols;
  
  mat out(0, N);
  for (int g=0; g<G; g++) {
    out = join_cols( out, Y(which(g)) );
  }
  return out;
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
