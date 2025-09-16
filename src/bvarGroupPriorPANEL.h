#ifndef _BVARGROUPPRIORPANEL_H_
#define _BVARGROUPPRIORPANEL_H_

#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;


Rcpp::List bvarGroupPriorPANEL(
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,                    // a C-list of T_cxN elements
    const Rcpp::List&             X,                    // a C-list of T_cxK elements
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const int                     thin,                 // introduce thinning
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false // whether to estimate group-specific parameters
);


#endif  // _BVARGROUPPRIORPANEL_H_
