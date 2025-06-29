
#' @title Bayesian recursive pseudo-out-of-sample forecasting
#'
#' @description Performs the recursive pseudo-out-of-sample forecasting exercise
#' using expanding window samples.
#' 
#' @param model_spec an object generated using one of the \code{specify_*} 
#' functions containing model specification.
#' @param poos_spec an object of class \code{POOSForecastSetup} containing
#' specification of the recursive pseudo-out-of-sample forecasting exercise 
#' using expanding window samples.
#' @param show_progress a logical value, if \code{TRUE} the estimation progress bar is visible
#' 
#' @return An object of class \code{ForecastsPOOS} containing the outcome of Bayesian
#'  recursive pseudo-out-of-sample forecasting exercise  using expanding window 
#'  samples containing elements
#'
#' @author Tomasz Woźniak \email{wozniak.tom@pm.me}
#' 
#' @export
forecast_poos_recursively <- function(model_spec, poos_spec, show_progress = TRUE) {
  
  # check the inputs
  stopifnot("Argument poos_spec must be of class POOSForecastSetup." = class(poos_spec) == "POOSForecastSetup")
  stopifnot("Argument show_progress must be a logical value." = is.logical(show_progress))
  
  # call method
  UseMethod("forecast_poos_recursively", model_spec)
} # END forecast_poos_recursively



#' @inherit forecast_poos_recursively
#' @method forecast_poos_recursively BVARPANEL
#' @param model_spec an object of class \code{BVARPANEL} generated using the 
#' \code{specify_bvarPANEL} function and containing the Bayesian Panel VAR model 
#' specification.
#' 
#' @author Tomasz Woźniak \email{wozniak.tom@pm.me}
#' 
#' @export
forecast_poos_recursively.BVARPANEL <- function(
    model_spec, 
    poos_spec, 
    show_progress = TRUE
) {

  S                   = poos_spec$S
  S_burn              = poos_spec$S_burn
  horizons            = poos_spec$horizons
  training_sample     = poos_spec$training_sample
  
  prior               = model_spec$prior$get_prior()
  starting_values     = model_spec$starting_values$get_starting_values()
  data_matrices       = model_spec$data_matrices$get_data_matrices()
  adaptiveMH          = model_spec$adaptiveMH
  thin                = 1
  
  C                   = length(data_matrices$Y)
  country_names       = names(data_matrices$Y)
  T                   = nrow(model_spec$data_matrices$Y)
  forecasting_sample  = T - max(horizons) - training_sample + 1
  
  N                   = dim(model_spec$starting_values$Sigma)[1]
  type                = model_spec$data_matrices$type
  LB                  = rep(-Inf, N)
  UB                  = rep(Inf, N)
  rates_id            = which(type == "rate")
  if (length(rates_id) > 0) {
    LB[rates_id]      = 0
    UB[rates_id]      = 100
  }
  
  # still need to be specified
  cond_forecasts      = vector("list")
  exog_forecasts      = vector("list")
  
  foreout = .Call(`_bpvars_forecast_pseudo_out_of_sample_bvarPANEL`, S, S_burn, horizons, training_sample, data_matrices$Y, data_matrices$X, cond_forecasts, exog_forecasts, prior, starting_values, LB, UB, show_progress, adaptiveMH)
  
  out                 = vector("list", C)
  names(out)          = country_names
  class(out)          = "ForecastsPANELpoos"
  
  for (c in 1:C) {
    
    fore              = vector("list", forecasting_sample)
    
    for (i in 1:forecasting_sample) {
      
      fore_ci                   = list()
      fore_ci$forecasts         = aperm(foreout$forecasts_cpp[i, c][[1]], c(2,1,3))
      fore_ci$forecast_mean     = aperm(foreout$forecast_mean_cpp[i, c][[1]], c(2,1,3))
      fore_ci$forecast_cov      = foreout$forecast_cov_cpp[i, c][[1]]
      fore_ci$estimation_data   = foreout$estimation_data_cpp[i, c][[1]]
      fore_ci$evaluation_data   = foreout$evaluation_data_cpp[i, c][[1]]
      
      fore[[i]]                 = fore_ci
      
    } # END i loop
    
    out[[c]]          = fore
    
  } # END c loop
  
  return(out)
} # END forecast_poos_recursively.BVARPANEL
