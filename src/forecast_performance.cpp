
#include <RcppArmadillo.h>
#include "progress.hpp"

#include "bvarPANEL.h"
#include "forecast_panel.h"

using namespace Rcpp;
using namespace arma;



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List bvarPANEL_just_sv_out (
    const int&                    S,          // No. of posterior draws
    const Rcpp::List&             Y,          // a C-list of T_cxN elements
    const Rcpp::List&             X,          // a C-list of T_cxK elements
    const Rcpp::List&             prior,      // a list of priors
    const Rcpp::List&             starting_values, 
    const int                     thin, // introduce thinning
    const arma::vec&              adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
) {
  
  // this function is just created for memory management, when just 
  // starting_values are needed from the estimation
  List post   = bvarPANEL( S, Y, X, prior, starting_values,
                  thin, false, adptive_alpha_gamma );
  List sv_out = post["starting_values"];
  return sv_out;
} // END bvarPANEL_just_sv_out



// [[Rcpp::interfaces(cpp)]]
// [[Rcpp::export]]
Rcpp::List YX_subset_TT_head_cols (
    Rcpp::List        Y,
    const int         TT,
    const int         beginning = 0
) {
  mat yy_tmp      = as<mat>(Y[0]);
  const int C     = Y.length();
  
  for (int c=0; c<C; c++) {
    yy_tmp        = as<mat>(Y[c]);
    Y[c]          = yy_tmp.head_cols(TT);
  } // END c loop
  
  return Y;
} // END YX_subset_TT_head_rows



// [[Rcpp::interfaces(cpp,r)]]
// [[Rcpp::export]]
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
    const int                     thin,               // introduce thinning
    const bool                    show_progress,
    const arma::vec&              adptive_alpha_gamma // 2x1 vector with target acceptance rate and step size
) {

  // progress bar initiation
  if (show_progress) {
    Rcout << "**************************************************|" << endl;
    Rcout << " bpvars: Forecasting with Bayesian Panel VARs     |" << endl;
    Rcout << "**************************************************|" << endl;
    Rcout << " Recursive pseudo-out-of-sample forecasting using" << endl;
    Rcout << "         expanding window samples." << endl;
    Rcout << " Press Esc to interrupt the computations" << endl;
    Rcout << "**************************************************|" << endl;
  }
  Progress p(50, show_progress);
  
  // read and create objects
  const int max_horizon = max(horizons);
  mat yy_tmp            = as<mat>(Y[0]);
  const int T           = yy_tmp.n_rows;
  const int C           = Y.length();
  const int forecasting_sample = T - max_horizon - training_sample + 1;
  
  // progress bar setup
  vec prog_rep_points = arma::round(arma::linspace(0, T - max_horizon, 50));
  
  field<cube>   forecasts(forecasting_sample, C);         //of (horizon, N, S) cubes
  field<cube>   forecast_mean(forecasting_sample, C);     // of (horizon, N, S) cubes
  field<cube>   forecast_cov(forecasting_sample, C, S);   // of (N, N, horizon) cubes
  field<mat>    estimation_data(forecasting_sample, C);   // of (N, TT) cubes
  field<mat>    evaluation_data(forecasting_sample, C);   // of (N, horizon) cubes
  
  // full sample estimation - for starting values
  Rcout << " Step 1: Estimate a model for a full sample to get" << endl;
  Rcout << "         starting values for subsequent steps." << endl;
  
  List initial_estimation = bvarPANEL_just_sv_out( 
                              S, Y, X, prior, starting_values, 
                                thin, adptive_alpha_gamma );

  Rcout << " Step 2: Recursive pseudo out-of-sample" << endl;
  Rcout << "         forecasting performed for " << forecasting_sample << " samples." << endl;
  Rcout << "**************************************************|" << endl;
  
  // forecasting performance loop to be parallelised using openMP
  for (int i = 0; i < forecasting_sample; i++) {
    
    // Increment progress bar
    if (any(prog_rep_points == i)) p.increment();
    // Check for user interrupts
    checkUserInterrupt();
    
    List Y_i    = YX_subset_TT_head_cols(Y, training_sample + i);
    List X_i    = YX_subset_TT_head_cols(X, training_sample + i);
    
    List burn   = bvarPANEL_just_sv_out( 
                    S_burn, Y_i, X_i, prior, initial_estimation, 
                      thin, adptive_alpha_gamma );
    
    List post   = bvarPANEL( 
                    S, Y_i, X_i, prior, burn, 
                      thin, false, adptive_alpha_gamma );
    
    List posterior                    = as<List>(post["posterior"]);
    field<cube> posterior_A_c_cpp     = as<field<cube>>(posterior["A_c_cpp"]);
    field<cube> posterior_Sigma_c_cpp = as<field<cube>>(posterior["Sigma_c_cpp"]);
    
    List fore   = forecast_bvarPANEL (
                    posterior_A_c_cpp, posterior_Sigma_c_cpp, 
                      X_i, cond_forecasts, exog_forecasts, 
                        max_horizon, LB, UB, show_progress );        
    
    field<cube> forecasts_cpp         = as<field<cube>>(fore["forecasts_cpp"]);
    field<cube> forecast_mean_cpp     = as<field<cube>>(fore["forecast_mean_cpp"]);
    field<cube> forecast_cov_cpp      = as<field<cube>>(fore["forecast_cov_cpp"]);
    
    for (int c=0; c<C; c++) {

      forecasts(i, c) = forecasts_cpp(c);
      forecast_mean(i,c) = forecast_mean_cpp(c);
      estimation_data (i, c)  = as<mat>(Y_i[c]);
      mat Yc_tmp              = as<mat>(Y[c]);
      evaluation_data(i, c)   = Yc_tmp.cols(
                                  training_sample + i, 
                                  training_sample + i + horizons(c) - 1
                                );          
      
      for (int s=0; s<S; s++) {
        forecast_cov(i, c, s) = forecast_cov_cpp(c, s);
      } // END s loop
      
      
    } // END c loop
    
    // just notes
    // field<cube>   forecasts(forecasting_sample, C);         //of (horizon, N, S) cubes
    // field<cube>   forecast_mean(forecasting_sample, C);     // of (horizon, N, S) cubes
    // field<cube>   forecast_cov(forecasting_sample, C, S);   // of (N, N, horizon) cubes
    // field<mat>    estimation_data(forecasting_sample, C);   // of (N, TT) cubes
    // field<mat>    evaluation_data(forecasting_sample, C);   // of (N, horizon) cubes
    // forecasts_cpp       // (C)(horizon, N, S)
    // forecast_mean_cpp   // (C)(horizon, N, S)
    // forecast_cov_cpp    // (C,S)(N, N, horizon)
    
  } // END of i loop
  
  // outputs
  return List::create(
    _["forecasts_cpp"]       = forecasts,
    _["forecast_mean_cpp"]   = forecast_mean,
    _["forecast_cov_cpp"]    = forecast_cov,
    _["estimation_data_cpp"] = estimation_data,
    _["evaluation_data_cpp"] = evaluation_data
  );
} // END forecast_pseudo_out_of_sample_bvarPANEL