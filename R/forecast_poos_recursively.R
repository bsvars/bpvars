
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
#'  samples containing elements:
#' \describe{
#'  \item{forecasts}{an array with the draws from predictive density}
#'  \item{forecast_mean}{an array with the mean of the predictive densities}
#'  \item{forecast_cov}{an array with the covariances of the predictive densities}
#'  \item{estimation_data}{an array with data used for estimation for each forecasts}
#'  \item{evaluation_data}{an array with matched data for forecasting performance evaluation}
#' }
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
}
