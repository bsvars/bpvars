#ifndef _MISSING_H_
#define _MISSING_H_

#include <RcppArmadillo.h>

arma::mat create_bigA (
    arma::cube  A,
    int         T
);


arma::mat mvnrnd_cond (
    arma::vec x,        // Nx1 vector to be filled with conditional normal draws when missing == 1
    arma::vec mu,       // Nx1 mean vector
    arma::mat Sigma,    // NxN covariance matrix
    arma::vec missing   // Nx1 with 1 for missing observations
);


arma::mat sample_missing (
    arma::mat&            aux_Y,      // (T + p, N)
    arma::mat&            missing,    // (T, N) with 1 for missing values and 0 otherwise
    arma::mat&            exogenous,  // (T + p, d)
    arma::mat&            A_c,        // (K, N)
    arma::mat&            Sigma_c,    // (N, N)
    arma::mat&            A_c_prior_mean, // (K, N)
    arma::mat&            Sigma_c_prior
);


arma::field<arma::mat> Y_c_and_X_c (
    arma::mat&      aux_Y,      // (T + p, N)
    arma::mat&      exogenous,  // (T + p, d + 1)
    const int       p
);


#endif  // _MISSING_H_
