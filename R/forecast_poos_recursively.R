
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
#'  samples. The object is a list with \code{forecasting_sample} elements, where
#'  \code{forecasting_sample} is equal to the sample size less the maximum of
#'  \code{horizons} and the \code{training_sample} plus one. Each element of the
#'  list is an object of class \code{ForecastsPANEL} containing the forecasts for 
#'  each country, see \code{\link{forecast.PosteriorBVARPANEL}}.
#'
#' @seealso \code{\link{forecast.PosteriorBVARPANEL}}, \code{\link{specify_bvarPANEL}},
#' \code{\link{specify_poosf_exercise}}, \code{\link{estimate.BVARPANEL}}
#'
#' @author Tomasz Woźniak \email{wozniak.tom@pm.me}
#' 
#' @examples
#' spec = specify_bvarPANEL$new(ilo_dynamic_panel)           # specify the model
#' poos = specify_poosf_exercise$new(                        # specify the forecasting exercise
#'          spec, 
#'          S = 10,                                          # use at least S = 5000
#'          S_burn = 5,                                      # use at least S_burn = 1000
#'          horizons = 1:2,
#'          training_sample = 28
#'        )   
#' fore = forecast_poos_recursively(spec, poos)              # execute the forecasting exercise
#' 
#' @export
forecast_poos_recursively <- function(model_spec, poos_spec, show_progress = TRUE) {
  
  # check the inputs
  stopifnot("Argument poos_spec must be of class POOSForecastSetup." = any(class(poos_spec) == "POOSForecastSetup"))
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
  T                   = nrow(model_spec$data_matrices$Y[[1]])
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
  # this will not be used for forecasting, but needs to be provided
  exogenous_forecast = list()
  for (c in 1:C) exogenous_forecast[[c]] = matrix(NA, max(horizons), 1)
  conditional_forecast = list()
  for (c in 1:C) conditional_forecast[[c]] = matrix(NA, max(horizons), N)
  
  # form an output object
  
  
  foreout = .Call(`_bpvars_forecast_pseudo_out_of_sample_bvarPANEL`, S, S_burn, horizons, training_sample, data_matrices$Y, data_matrices$X, conditional_forecast, exogenous_forecast, prior, starting_values, LB, UB, show_progress, adaptiveMH)
  
  
  out                 = vector("list", forecasting_sample)
  for (i in 1:forecasting_sample) {

    forecasts         = vector("list", C)
    for (c in 1:C) {
      
      fore            = list()
      
      fore$forecasts         = aperm(foreout[[i]]$forecasts_cpp[c,1][[1]], c(2,1,3))
      fore$forecast_mean     = aperm(foreout[[i]]$forecast_mean_cpp[c,1][[1]], c(2,1,3))
      
      cov_array = array(NA, c(N, N, max(horizons), S))
      for (s in 1:S) {
        cov_array[,,,s]       = foreout[[i]]$forecast_cov_cpp[c,s][[1]]
      }
      fore$forecast_cov       = cov_array
      
      fore$Y                  = foreout[[i]]$estimation_data_cpp[c,1][[1]]
      fore$evaluation_data    = t(foreout[[i]]$evaluation_data_cpp[c,1][[1]])
      
      class(fore)             = "Forecasts"
      forecasts[[c]]          = fore
      
    } # END c loop

    names(forecasts)  = country_names
    class(forecasts)  = "ForecastsPANEL"
    out[[i]]          = forecasts

  } # END i loop
  
  class(out)          = "ForecastsPANELpoos"
  
  return(out)
} # END forecast_poos_recursively.BVARPANEL
