#ifndef _FORECAST_PERFORMANCE_H_
#define _FORECAST_PERFORMANCE_H_

#include <RcppArmadillo.h>


Rcpp::List bvarPANEL_noprog(
    const int&                    S,          // No. of posterior draws
    const Rcpp::List&             Y,          // a C-list of T_cxN elements
    const Rcpp::List&             X,          // a C-list of T_cxK elements
    const Rcpp::List&             prior,      // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
);


Rcpp::List bvarPANEL_just_sv_out (
    const int&                    S,          // No. of posterior draws
    const Rcpp::List&             Y,          // a C-list of T_cxN elements
    const Rcpp::List&             X,          // a C-list of T_cxK elements
    const Rcpp::List&             prior,      // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
);


Rcpp::List bvarGroupPANEL_noprog(
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,                    // a C-list of T_cxN elements
    const Rcpp::List&             X,                    // a C-list of T_cxK elements
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false // whether to estimate group-specific parameters
);


Rcpp::List bvarGroupPANEL_just_sv_out (
    const int&                    S,                    // No. of posterior draws
    const Rcpp::List&             Y,                    // a C-list of T_cxN elements
    const Rcpp::List&             X,                    // a C-list of T_cxK elements
    const Rcpp::List&             prior,                // a list of priors
    const Rcpp::List&             starting_values, 
    const arma::vec&              adptive_alpha_gamma,  // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false // whether to estimate group-specific parameters
);


Rcpp::List YX_subset_TT_head_cols (
    Rcpp::List        Y,
    const int         TT,
    const int         beginning = 0
);


Rcpp::List forecast_bvarPANEL_noprog (
    arma::field<arma::cube>&  posterior_A_c_cpp,      // (S)(K, N, C)
    arma::field<arma::cube>&  posterior_Sigma_c_cpp,  // (S)(N, N, C)
    Rcpp::List&               X_c,                    // (C)(T_c, K)
    Rcpp::List&               cond_forecasts,         // (C)(horizon, N)
    Rcpp::List&               exog_forecasts,         // (C)(horizon, d)
    const int                 horizon,
    arma::vec                 LB,                     // Nx1 lower bounds for truncation
    arma::vec                 UB                     // Nx1 upper bounds for truncation
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


Rcpp::List forecast_pseudo_out_of_sample_bvarGroupPANEL (
    const int&                    S,                  // No. of posterior draws
    const int&                    S_burn,             // No. of posterior draws
    const arma::ivec              horizons,           // a vector for forecasting horizons for the application
    const int&                    training_sample,    // No. of observations for estimation (R_training_sample--)
    const Rcpp::List              Y,                  // a C-list of T_cxN elements
    const Rcpp::List              X,                  // a C-list of T_cxK elements
    Rcpp::List&                   cond_forecasts,     // (C)(horizon, N)
    Rcpp::List&                   exog_forecasts,     // (C)(horizon, d)
    const Rcpp::List&             prior,              // a list of priors
    const Rcpp::List&             starting_values,    // a list of starting values for bvarPANEL
    const arma::vec               LB,                 // Nx1 lower bounds for truncation
    const arma::vec               UB,                 // Nx1 upper bounds for truncation
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma,      // 2x1 vector with target acceptance rate and step size
    const bool                    estimate_groups = false   // whether to estimate group-specific parameters
);


arma::field<arma::cube> fourDarray_to_field_cube (
    Rcpp::NumericVector arr
);


double log_dnormm_joint_s (
    arma::vec& x,
    arma::vec& mu,
    arma::mat& sigma
);


arma::cube log_dnormm_marginal (
    arma::mat&            x,      // (N, horizon)
    arma::cube&           mu,     // (N, horizon, S)
    arma::field<arma::cube>&  sigma   // array (N, N, horizon, S)&  Sigma   // array (N, N, horizon, S)
);


arma::mat log_dnormm_joint (
    arma::mat&            x,      // (N, horizon)
    arma::cube&           mu,     // (N, horizon, S)
    arma::field<arma::cube>&  sigma   // array (N, N, horizon, S)
);


double log_mean (
    arma::vec     log_density     // n x s matrix with log density ordinates
);


#endif  // _FORECAST_PERFORMANCE_H_
