#ifndef _BVARS_H_
#define _BVARS_H_

#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;


Rcpp::List bvars_cpp(
    const int&                    S,          // No. of posterior draws
    const Rcpp::List&             Y,          // a C-list of (T_c + p)xN elements
    const Rcpp::List&             missing,    // a C-list of T_cxN elements - 1 for missing
    const Rcpp::List&             exogenous,  // a C-list of (T_c + p)x(d+1) - with intercept
    const Rcpp::List&             prior,      // a list of priors
    const Rcpp::List&             starting_values,
    const int                     thin, // introduce thinning
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma, // 2x1 vector with target acceptance rate and step size
    const bool                    type_objective,
    const int                     p           // autoregressive lag order
);


#endif  // _BVARS_H_
