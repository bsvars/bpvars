#ifndef _FORECAST_PERFORMANCE_H_
#define _FORECAST_PERFORMANCE_H_

#include <RcppArmadillo.h>


Rcpp::List bvarPANEL_just_sv_out (
    const int&                    S,          // No. of posterior draws
    const Rcpp::List&             Y,          // a C-list of T_cxN elements
    const Rcpp::List&             X,          // a C-list of T_cxK elements
    const Rcpp::List&             prior,      // a list of priors
    const Rcpp::List&             starting_values, 
    const int                     thin, // introduce thinning
    const arma::vec&              adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
);


Rcpp::List YX_subset_TT_head_cols (
    Rcpp::List        Y,
    const int         TT,
    const int         beginning = 0
);


Rcpp::List forecast_pseudo_out_of_sample_bvarPANEL (
    const int&                    S,                  // No. of posterior draws
    const int&                    S_burn,             // No. of posterior draws
    const arma::ivec              horizons,           // a vector for forecasting horizons for the application
    const int&                    training_sample,    // No. of observations for estimation (R_training_sample--)
    const Rcpp::List&             Y,                  // a C-list of T_cxN elements
    const Rcpp::List&             X,                  // a C-list of T_cxK elements
    Rcpp::List&                   cond_forecasts,     // (C)(horizon, N)
    Rcpp::List&                   exog_forecasts,     // (C)(horizon, d)
    const Rcpp::List&             prior,              // a list of priors
    const Rcpp::List&             starting_values,    // a list of starting values for bvarPANEL
    const arma::vec               LB,                 // Nx1 lower bounds for truncation
    const arma::vec               UB,                 // Nx1 upper bounds for truncation
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
);


#endif  // _FORECAST_PERFORMANCE_H_
