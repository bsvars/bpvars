
#' R6 Class Representing specification of the pseudo-out-of-sample forecasting 
#' exercise
#'
#' @description
#' The class \code{POOSForecastSetup} presents the specification of the 
#' recursive pseudo-out-of-sample forecasting exercise using expanding window
#' samples.
#' 
#' @examples 
#' spec = specify_bvarPANEL$new(ilo_dynamic_panel)
#' poos = specify_poosf_exercise$new(spec, 5000, 1000, 1:2, 10)
#' 
#' @export
specify_poosf_exercise = R6::R6Class(
  "POOSForecastSetup",
  
  public = list(
    
    #' @field S a positive integer number - the number of MCMC draws from the 
    #' posterior distribution in the estimation for each forecasts
    S = NA,
    
    #' @field S_burn a positive integer number - the number of MCMC draws from
    #' to achieve convergence in the estimation for each forecasts
    S_burn = NA,
    
    #' @field horizons a vector with positive integer numbers - the forecast
    #' horizons used in the forecast performance evaluation
    horizons = numeric(),
    
    #' @field training_sample a positive integer number - the number of of the
    #' first observations to be used in the estimation for the first forecast
    training_sample = NA,
    
    #' @description
    #' Create a new specification \code{POOSForecastSetup} of the 
    #' recursive pseudo-out-of-sample forecasting exercise using expanding window
    #' samples.
    #' 
    #' @param spec a model specification object of class \code{BVARPANEL} or
    #' \code{BVARGROUPPANEL}.
    #' @param S a positive integer - number of draws from the posterior 
    #' distribution for model estimation for each of the forecasts
    #' @param S_burn a positive integer - number of draws from the posterior 
    #' distribution to obtain convergence for model estimation for each of the 
    #' forecasts
    #' @param horizons a vector with positive integers - forecast horizons at 
    #' which forecasting performance is to be verified
    #' @param training_sample a positive integer - the number of the first 
    #' observations to be used for estimation for the first forecast. The number 
    #' of observations to be used for remaining forecasts increases recursively 
    #' by one for each forecast.
    #' 
    #' @return A new specification \code{POOSForecastSetup} of the 
    #' recursive pseudo-out-of-sample forecasting exercise using expanding window
    #' samples.
    #' 
    #' @examples 
    #' spec = specify_bvarPANEL$new(ilo_dynamic_panel)
    #' poos = specify_poosf_exercise$new(spec, 5000, 1000, 1:2, 10)
    #' 
    initialize = function(
      spec,
      S,
      S_burn,
      horizons = 1L,
      training_sample = 1L
    ) {
      
      stopifnot("Argument spec must be of class BVARPANEL, BVARGROUPPANEL, or BVARs." 
                = any(c(class(spec) == "BVARPANEL", class(spec) == "BVARGROUPPANEL", class(spec) == "BVARs")))
      stopifnot("Argument S must be a positive integer number." 
                = S > 0 & S %% 1 == 0)
      stopifnot("Argument S_burn must be a positive integer number." 
                = S_burn > 0 & S_burn %% 1 == 0)
      stopifnot("Argument horizons must be a numeric vector with positive integer numbers." 
                = is.numeric(horizons) & all(horizons > 0) & all(horizons %% 1 == 0))
      stopifnot("Argument training_sample must be a positive integer number." 
                = training_sample > 0 & training_sample %% 1 == 0)
      stopifnot("Argument training_sample must be less than time series dimension 
                minus the maximun forecasting horizon." 
                = training_sample <= dim(spec$data_matrices$Y[[1]])[1] - max(horizons))
      
      self$S                = S
      self$S_burn           = S_burn
      self$horizons         = horizons
      self$training_sample  = training_sample
      
    } # END initialize
  ) # END public
) # END specify_poosf_exercise
