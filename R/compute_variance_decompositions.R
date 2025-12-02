
#' @title Computes posterior draws of the forecast error variance decomposition
#' @description For each country, each of the draws from the posterior estimation 
#' of the model is transformed into a draw from the posterior distribution of the forecast 
#' error variance decomposition.
#' 
#' @method compute_variance_decompositions PosteriorBVARPANEL
#' 
#' @param posterior posterior estimation outcome - an object of class 
#' \code{PosteriorBVARPANEL} obtained by running the \code{estimate} function.
#' 
#' @param horizon a positive integer number denoting the forecast horizon for 
#' the forecast error variance decompositions.
#' 
#' @return  An object of class \code{PosteriorFEVDPANEL}, that is, a list with 
#' \code{C} elements containing \code{NxNx(horizon+1)xS} arrays of class 
#' \code{PosteriorFEVD} with \code{S} draws of country-specific forecast error 
#' variance decompositions.
#' 
#' @seealso \code{\link{estimate.PosteriorBVARPANEL}}, 
#' \code{\link{summary.PosteriorFEVDPANEL}}, 
#' \code{\link{plot.PosteriorFEVDPANEL}}
#'
#' @author Tomasz Woźniak \email{wozniak.tom@pm.me}
#' 
#' @references 
#' Lütkepohl, H. (2017). Structural VAR Tools, Chapter 4, In: Structural vector autoregressive analysis. Cambridge University Press.
#' 
#' @examples
#' # specify the model and set seed
#' specification  = specify_bvarPANEL$new(ilo_dynamic_panel, p = 1)
#' 
#' # run the burn-in
#' burn_in        = estimate(specification, 5)
#' 
#' # estimate the model
#' posterior      = estimate(burn_in, 5)
#' 
#' # compute forecast error variance decomposition 4 years ahead
#' fevd           = compute_variance_decompositions(posterior, horizon = 4)
#' 
#' # workflow with the pipe |>
#' ############################################################
#' ilo_dynamic_panel |>
#'   specify_bvarPANEL$new(p = 1) |>
#'   estimate(S = 5) |> 
#'   estimate(S = 5) |> 
#'   compute_variance_decompositions(horizon = 4) -> fevd
#' 
#' @export
compute_variance_decompositions.PosteriorBVARPANEL <- function(posterior, horizon) {

  posterior_Sigma = posterior$posterior$Sigma_c_cpp
  posterior_A     = posterior$posterior$A_c_cpp
  N               = dim(posterior$last_draw$data_matrices$Y[[1]])[2]
  C               = length(posterior$last_draw$data_matrices$Y)
  S               = dim(posterior_A)[1]
  p               = posterior$last_draw$p
  Y               = posterior$last_draw$data_matrices$Y
  c_names         = names(posterior$last_draw$data_matrices$Y)
  
  fff             = .Call(`_bpvars_panel_variance_decompositions`, 
                          posterior_Sigma, 
                          posterior_A, 
                          horizon, 
                          p, 
                          TRUE
                    )
  
  fevd            = list()
  for (c in 1:C) {
    fevd_c          = array(NA, c(N, N, horizon + 1, S), dimnames = list(colnames(Y[[1]]), colnames(Y[[1]]), 0:horizon, 1:S))
    for (s in 1:S) {
      fevd_c[,,,s]  = fff[c, s][[1]]
    }
    na_check        = apply(fevd_c, 4, function(x) any(is.na(x)))
    fevd_c          = fevd_c[,,, !na_check]
    class(fevd_c)   = "PosteriorFEVD"
    fevd[[c]]       = fevd_c
  }
  
  names(fevd) = c_names
  
  class(fevd) <- "PosteriorFEVDPANEL"
  return(fevd)
}






#' @title Computes posterior draws of the forecast error variance decomposition
#' @description For each country, each of the draws from the posterior estimation 
#' of the model is transformed into a draw from the posterior distribution of the forecast 
#' error variance decomposition.
#' 
#' @param posterior posterior estimation outcome - an object of class 
#' \code{PosteriorBVARGROUPPANEL} obtained by running the \code{estimate} function.
#' @param horizon a positive integer number denoting the forecast horizon for 
#' the forecast error variance decompositions.
#' 
#' @return  An object of class \code{PosteriorFEVDPANEL}, that is, a list with 
#' \code{C} elements containing \code{NxNx(horizon+1)xS} arrays of class 
#' \code{PosteriorFEVD} with \code{S} draws of country-specific forecast error 
#' variance decompositions.
#'
#' @author Tomasz Woźniak \email{wozniak.tom@pm.me}
#' 
#' @references 
#' Lütkepohl, H. (2017). Structural VAR Tools, Chapter 4, In: Structural vector autoregressive analysis. Cambridge University Press.
#' 
#' @method compute_variance_decompositions PosteriorBVARGROUPPANEL
#' 
#' @seealso \code{\link{estimate.PosteriorBVARGROUPPANEL}}, 
#' \code{\link{summary.PosteriorFEVDPANEL}}, 
#' \code{\link{plot.PosteriorFEVDPANEL}}
#' 
#' @examples
#' # specify the model and set seed
#' specification  = specify_bvarGroupPANEL$new(            # specify the model
#'                   ilo_dynamic_panel,
#'                   group_allocation = country_grouping_region
#'                 )
#' 
#' # run the burn-in
#' burn_in        = estimate(specification, 5)
#' 
#' # estimate the model
#' posterior      = estimate(burn_in, 5)
#' 
#' # compute forecast error variance decomposition 4 years ahead
#' fevd           = compute_variance_decompositions(posterior, horizon = 4)
#' 
#' # workflow with the pipe |>
#' ############################################################
#' ilo_dynamic_panel |>
#'   specify_bvarGroupPANEL$new(group_allocation = country_grouping_region) |>
#'   estimate(S = 5) |> 
#'   estimate(S = 5) |> 
#'   compute_variance_decompositions(horizon = 4) -> fevd
#' 
#' @export
compute_variance_decompositions.PosteriorBVARGROUPPANEL <- function(posterior, horizon) {
  
  posterior_Sigma = posterior$posterior$Sigma_c_cpp
  posterior_A     = posterior$posterior$A_c_cpp
  N               = dim(posterior$last_draw$data_matrices$Y[[1]])[2]
  C               = length(posterior$last_draw$data_matrices$Y)
  S               = dim(posterior_A)[1]
  p               = posterior$last_draw$p
  Y               = posterior$last_draw$data_matrices$Y
  c_names         = names(posterior$last_draw$data_matrices$Y)
  
  fff             = .Call(`_bpvars_panel_variance_decompositions`, 
                          posterior_Sigma, 
                          posterior_A, 
                          horizon, 
                          p, 
                          TRUE
  )
  
  fevd            = list()
  for (c in 1:C) {
    fevd_c          = array(NA, c(N, N, horizon + 1, S), dimnames = list(colnames(Y[[1]]), colnames(Y[[1]]), 0:horizon, 1:S))
    for (s in 1:S) {
      fevd_c[,,,s]  = fff[c, s][[1]]
    }
    na_check        = apply(fevd_c, 4, function(x) any(is.na(x)))
    fevd_c          = fevd_c[,,, !na_check]
    class(fevd_c)   = "PosteriorFEVD"
    fevd[[c]]       = fevd_c
  }
  
  names(fevd) = c_names
  
  class(fevd) <- "PosteriorFEVDPANEL"
  return(fevd)
}





#' @title Computes posterior draws of the forecast error variance decomposition
#' @description For each country, each of the draws from the posterior estimation 
#' of the model is transformed into a draw from the posterior distribution of the forecast 
#' error variance decomposition.
#' 
#' @param posterior posterior estimation outcome - an object of class 
#' \code{PosteriorBVARs} obtained by running the \code{estimate} function.
#' @param horizon a positive integer number denoting the forecast horizon for 
#' the forecast error variance decompositions.
#' 
#' @return  An object of class \code{PosteriorFEVDPANEL}, that is, a list with 
#' \code{C} elements containing \code{NxNx(horizon+1)xS} arrays of class 
#' \code{PosteriorFEVD} with \code{S} draws of country-specific forecast error 
#' variance decompositions.
#'
#' @author Tomasz Woźniak \email{wozniak.tom@pm.me}
#' 
#' @references 
#' Lütkepohl, H. (2017). Structural VAR Tools, Chapter 4, In: Structural vector autoregressive analysis. Cambridge University Press.
#' 
#' @method compute_variance_decompositions PosteriorBVARs
#' 
#' @seealso \code{\link{estimate.PosteriorBVARs}}, 
#' \code{\link{summary.PosteriorFEVDPANEL}}, 
#' \code{\link{plot.PosteriorFEVDPANEL}}
#' 
#' @examples
#' # specify the model and set seed
#' specification  = specify_bvars$new(ilo_dynamic_panel) # specify the model
#' 
#' # run the burn-in
#' burn_in        = estimate(specification, 5)
#' 
#' # estimate the model
#' posterior      = estimate(burn_in, 5)
#' 
#' # compute forecast error variance decomposition 4 years ahead
#' fevd           = compute_variance_decompositions(posterior, horizon = 4)
#' 
#' # workflow with the pipe |>
#' ############################################################
#' ilo_dynamic_panel |>
#'   specify_bvars$new() |>
#'   estimate(S = 5) |> 
#'   estimate(S = 5) |> 
#'   compute_variance_decompositions(horizon = 4) -> fevd
#' 
#' @export
compute_variance_decompositions.PosteriorBVARs <- function(posterior, horizon) {
  
  posterior_Sigma = posterior$posterior$Sigma_c_cpp
  posterior_A     = posterior$posterior$A_c_cpp
  N               = dim(posterior$last_draw$data_matrices$Y[[1]])[2]
  C               = length(posterior$last_draw$data_matrices$Y)
  S               = dim(posterior_A)[1]
  p               = posterior$last_draw$p
  Y               = posterior$last_draw$data_matrices$Y
  c_names         = names(posterior$last_draw$data_matrices$Y)
  
  fff             = .Call(`_bpvars_panel_variance_decompositions`, 
                          posterior_Sigma, 
                          posterior_A, 
                          horizon, 
                          p, 
                          TRUE
  )
  
  fevd            = list()
  for (c in 1:C) {
    fevd_c          = array(NA, c(N, N, horizon + 1, S), dimnames = list(colnames(Y[[1]]), colnames(Y[[1]]), 0:horizon, 1:S))
    for (s in 1:S) {
      fevd_c[,,,s]  = fff[c, s][[1]]
    }
    na_check        = apply(fevd_c, 4, function(x) any(is.na(x)))
    fevd_c          = fevd_c[,,, !na_check]
    class(fevd_c)   = "PosteriorFEVD"
    fevd[[c]]       = fevd_c
  }
  
  names(fevd) = c_names
  
  class(fevd) <- "PosteriorFEVDPANEL"
  return(fevd)
}


