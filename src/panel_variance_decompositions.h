#ifndef _PANEL_VARIANCE_DECOMPOSITIONS_H_
#define _PANEL_VARIANCE_DECOMPOSITIONS_H_

#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;


arma::cube Sigma2B_c (
    arma::cube&   posterior_Sigma_c,    // (N, N, S)
    const bool    lower = true
);


arma::cube flip_cube_rows_cols (
    arma::cube&   x   // (N, K, S)
);


arma::field<arma::cube> panel_variance_decompositions (
    arma::field<arma::cube>&  posterior_Sigma,    // (S)(N, N, C)
    arma::field<arma::cube>&  posterior_A,        // (S)(K, N, C)
    const int     horizon,
    const int     p,
    const bool    lower = true
);


#endif  // _PANEL_VARIANCE_DECOMPOSITIONS_H_
