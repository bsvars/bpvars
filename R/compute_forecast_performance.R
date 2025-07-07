
#' @title Computes forecasting performance measures for recursive 
#' pseudo-out-of-sample forecasts
#'
#' @description Computes forecasting performance measures selected from:
#' log-predictive score \code{"lps"}, root-mean-squared-forecast error \code{"rmsfe"}, 
#' mean-absolute-forecast error \code{"mafe"} from the output of the recursive 
#' pseudo-out-of-sample forecastinge exercise performed using function 
#' \code{\link{forecast_poos_recursively}}.
#' 
#' @param forecasts an object containing the
#' outcome of Bayesian recursive pseudo-out-of-sample forecasting exercise
#' using expanding window samples generated using function \code{\link{forecast_poos_recursively}}.
#' @param measures a character vector with any of the values \code{"lps"},
#' \code{"rmsfe"}, \code{"mafe"} indicating the forecasting performance measures
#' to be computed.
#' 
#' @return An object of class \code{ForecastingPerformance} 
#'
#' @seealso \code{\link{forecast_poos_recursively}}, 
#' \code{\link{forecast_poos_recursively.BVARPANEL}},
#' \code{\link{forecast_poos_recursively.BVARGROUPPANEL}}
#'
#' @author Tomasz Woźniak \email{wozniak.tom@pm.me}

#' @export
compute_forecast_performance <- function(
    forecasts, 
    measures = c("lps", "rmsfe", "mafe")
) {
  # check the inputs
  stopifnot("Argument measures must contain any of the values `lps`, `rmsfe`, `mafe`" 
            = any(c(unique(measures) == "lps", unique(measures) == "rmsfe", unique(measures) == "mafe")))
  
  # call method
  UseMethod("compute_forecast_performance", forecasts)
} # END compute_forecast_performance





#' @inherit compute_forecast_performance
#' @method compute_forecast_performance ForecastsPANELpoos
#' @param forecasts an object of class \code{ForecastsPANELpoos} containing the
#' outcome of Bayesian recursive pseudo-out-of-sample forecasting exercise
#' using expanding window samples generated using function 
#' \code{\link{forecast_poos_recursively}}.
#' 
#' @export
compute_forecast_performance.ForecastsPANELpoos <- function(
    forecasts, 
    measures = c("lps", "rmsfe", "mafe")
) {
  
  
  forecasting_sample  = length(forecasts)
  C                   = length(forecasts[[1]])
  dims                = dim(forecasts[[1]][[1]]$forecast_mean)
  N                   = dims[1]
  H                   = dims[2]
  S                   = dims[3]
  
  # RMSFE and MAFE computations
  forecast_error      = sapply(
    1:forecasting_sample,
    function(i) {
      sapply( 
        1:C, 
        function(c) {
          forecasts[[i]][[c]]$evaluation_data - apply(forecasts[[i]][[c]]$forecasts, 1:2, mean)
        },
        simplify = "array"
      )
    },
    simplify = "array"
  )
  
  rmsfe_array               = array(NA, c(N + 1, H, C + 1)) 
  rmsfe_array[1:N,,1:C]     = apply(forecast_error, 1:3, function(x) sqrt(mean(x^2)))
  rmsfe_array[N + 1,,1:C]   = apply(rmsfe_array[1:N,,1:C], 2:3, function(x) sqrt(mean(x^2)))
  rmsfe_array[1:N,,C + 1]   = apply(rmsfe_array[1:N,,1:C], 1:2, function(x) sqrt(mean(x^2)))
  rmsfe_array[N + 1,,C + 1] = apply(rmsfe_array[N + 1,,1:C], 1, function(x) sqrt(mean(x^2)))
  
  mafe_array                = array(NA, c(N + 1, H, C + 1))
  mafe_array[1:N,,1:C]      = apply(forecast_error, 1:3, function(x) mean(abs(x)))
  mafe_array[N + 1,,1:C]    = apply(mafe_array[1:N,,1:C], 2:3, mean)
  mafe_array[1:N,,C + 1]    = apply(mafe_array[1:N,,1:C], 2, mean)
  mafe_array[N + 1,,C + 1]  = apply(mafe_array[N + 1,,1:C], 1, mean)
    
  # PLS computations
  log_norm            = sapply(
    1:forecasting_sample,
    function(i) {
      sapply( 
        1:C, 
        function(c) {
          log_dnormm_ic           = array(NA, c(N + 1, H, S))
          forecast_cov_ic         = .Call(`_bpvars_fourDarray_to_field_cube`, 
                                          forecasts[[i]][[c]]$forecast_cov
                                    )
          log_dnormm_ic[1:N,,]    = .Call(`_bpvars_log_dnormm_marginal`,  # (N, H, S)
                                          forecasts[[i]][[c]]$evaluation_data,
                                          forecasts[[i]][[c]]$forecast_mean,
                                          forecast_cov_ic      
                                    )
          log_dnormm_ic[N + 1,,]  = .Call(`_bpvars_log_dnormm_joint`,  # (H, S)
                                          forecasts[[i]][[c]]$evaluation_data,
                                          forecasts[[i]][[c]]$forecast_mean,
                                          forecast_cov_ic      
                                    )     
          return(log_dnormm_ic)       
        },
        simplify = "array"
      )
    },
    simplify = "array"
  )
  
  log_mean            = function(x) {.Call("_bpvars_log_mean", as.numeric(x))}
  lps_tmp             = apply(log_norm, c(1,2,4), log_mean)
  pls_array           = array(NA, c(N + 1, H, C + 1))
  pls_array[,,1:C]    = lps_tmp
  pls_array[,,C + 1]  = apply(lps_tmp, c(1,2), log_mean)
  
  # output
  country_names       = names(forecasts[[1]])
  horizons            = colnames(forecasts[[1]][[1]]$evaluation_data)
  variable_names      = c(rownames(forecasts[[1]][[1]]$evaluation_data), "joint")
  
  RMSFE = vector("list", C + 1) 
  MAFE = vector("list", C + 1)
  PLS = vector("list", C + 1)
  
  names(RMSFE) = names(MAFE) = names(PLS) = c(country_names, "Global")
  
  for (c in 1:(C + 1)) {
    
    RMSFE[[c]] = rmsfe_array[,,c]
    rownames(RMSFE[[c]]) = variable_names
    colnames(RMSFE[[c]]) = horizons
    
    MAFE[[c]]  = mafe_array[,,c]
    rownames(MAFE[[c]]) = variable_names
    colnames(MAFE[[c]]) = horizons
    
    PLS[[c]]   = pls_array[,,c]
    rownames(PLS[[c]]) = variable_names
    colnames(PLS[[c]]) = horizons

  }# END c loop
  
  out = list(
    RMSFE = RMSFE,
    MAFE = MAFE,
    PLS = PLS
  )
  
  return(out)
}# END compute_forecast_performance.ForecastsPANELpoos