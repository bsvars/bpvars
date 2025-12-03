
#' @title Bayesian estimation of a Bayesian Hierarchical Vector 
#' Autoregressions for cubic data using Gibbs sampler
#'
#' @description Estimates the Bayesian Hierarchical VARs for cubic data using the Gibbs 
#' sampler proposed by Sanchez-Martinez & Woźniak (2024).
#' 
#' @details 
#' The Bayesian Hierarchical Vector Autoregressive models described in 
#' \code{\link{bpvars}} is estimated using the Gibbs sampler. In this 
#' estimation procedure all the parameters of the model are estimated jointly.
#' The list of parameters of the model includes:
#' \describe{
#'  \item{\eqn{\mathbf{A}_c}}{a \code{KxN} country-specific autoregressive 
#'  parameters matrix for each of the countries \eqn{c = 1,\dots,C}}
#'  \item{\eqn{\mathbf{\Sigma}_c}}{an \code{NxN} country-specific covariance 
#'  matrix for each of the countries \eqn{c = 1,\dots,C}}
#'  \item{\eqn{\nu}}{prior degrees of freedom parameter}
#'  \item{\eqn{m}}{prior average global persistence parameter}
#'  \item{\eqn{w}}{prior scaling parameter}
#'  \item{\eqn{s}}{prior scaling parameter}
#' }
#' 
#' \strong{Gibbs sampler}
#' is an algorithm to sample random draws from the posterior distribution of the
#' parameters of the model given the data. The algorithm is briefly explained 
#' on an example of a two-parameter model with parameters \eqn{\theta_1} and 
#' \eqn{\theta_2}. In order to sample from the joint posterior distribution 
#' \eqn{p(\theta_1,\theta_2|\mathbf{Y})} the Gibbs sampler proceeds by sampling 
#' from full-conditional posterior distributions of each parameter given data 
#' and all the other parameters, denoted by \eqn{p(\theta_1|\theta_2,\mathbf{Y})} 
#' and \eqn{p(\theta_2|\theta_1,\mathbf{Y})}. These distributions are available 
#' from derivations and should be in a form of distributions that are easy to 
#' sample random numbers from.
#' 
#' To obtain \code{S} draws from the posterior distribution:
#' \enumerate{
#' \item Set the initial values of the parameters \eqn{\theta_2^{(0)}}
#' \item At each of the \code{s} iterations:
#' \enumerate{
#' \item Sample \eqn{\theta_1^{(s)}} from \eqn{p(\theta_1|\theta_2^{(s-1)},\mathbf{Y})}
#' \item Sample \eqn{\theta_2^{(s)}} from \eqn{p(\theta_2|\theta_1^{(s)},\mathbf{Y})}
#' } 
#' \item Repeat step 2. \code{S} times. Return \eqn{\{\theta_1^{(s)},\theta_2^{(s)}\}_{s=1}^{S}} 
#' as a sample drawn from the posterior distribution \eqn{p(\theta_1,\theta_2|\mathbf{Y})}.
#' }
#' The \code{estimate()} function returns the draws from the posterior distribution
#' of the parameters of the hierarchical VAR model listed above.
#' 
#' \strong{Thinning.} 
#' Thinning is a procedure to reduce the dependence in the returned sample from
#' the posterior distribution. It is obtained by returning every \code{thin} 
#' draw in the final sample. This procedure reduces the number of draws returned 
#' by the \code{estimate()} function.
#' 
#' @param specification an object of class \code{BVARs} generated using the 
#' \code{specify_bvars$new()} function.
#' @param S a positive integer, the number of posterior draws to be generated
#' @param thin a positive integer, specifying the frequency of MCMC output thinning
#' @param show_progress a logical value, if \code{TRUE} the estimation progress 
#' bar is visible
#' 
#' @return An object of class \code{PosteriorBVARs} containing the Bayesian 
#' estimation output and containing two elements:
#' 
#' \describe{
#'  \item{\code{posterior}}{a list with a collection of \code{S} draws from the 
#'  posterior distribution generated via Gibbs sampler. Elements of the list
#'  correspond to the parameters of the model listed in section \strong{Details}
#'  and are named respectively:
#'  \code{A_c}, \code{Sigma_c}, \code{nu}, \code{m}, \code{w}, \code{s}. 
#'  }
#'  \item{\code{last_draw}}{an object of class \code{BVARs} with the last draw of the 
#' current MCMC run as the starting value to be passed to the continuation of 
#' the MCMC estimation using the \code{estimate()} method. }
#' }
#'
#' @seealso \code{\link{bpvars}}, \code{\link{specify_bvars}}, 
#' \code{\link{specify_posterior_bvars}}, \code{\link{summary.PosteriorBVARs}},
#' \code{\link{forecast.PosteriorBVARs}}
#'
#' @author Tomasz Woźniak \email{wozniak.tom@pm.me}
#' 
#' @method estimate BVARs
#' 
#' @examples
#' # specify the model
#' specification = specify_bvars$new(
#'   ilo_dynamic_panel[1:5], 
#'   exogenous = ilo_exogenous_variables[1:5]
#' )
#' burn_in       = estimate(specification, 10)             # run the burn-in; use say S = 10000
#' posterior     = estimate(burn_in, 10)                   # estimate the model; use say S = 10000
#' 
#' @export
estimate.BVARs <- function(
    specification, 
    S, 
    thin = 1L, 
    show_progress = TRUE
) {
  
  # get the inputs to estimation
  prior               = specification$prior$get_prior()
  starting_values     = specification$starting_values$get_starting_values()
  data_matrices       = specification$data_matrices$get_data_matrices()
  adaptiveMH          = specification$adaptiveMH
  type_objective      = specification$get_type() == "zellner"
  p                   = specification$p
  
  # estimation
  qqq                 = .Call(`_bpvars_bvars_cpp`, S, data_matrices$Y, data_matrices$missing, data_matrices$exogenous, prior, starting_values, thin, show_progress, adaptiveMH, type_objective, p)
  
  specification$starting_values$set_starting_values(qqq$last_draw)
  output              = specify_posterior_bvars$new(specification, qqq$posterior)
  
  return(output)
} # END estimate.BVARs



#' @inherit estimate.BVARs
#' 
#' @method estimate PosteriorBVARs
#' 
#' @param specification an object of class \code{PosteriorBVARs} generated using 
#' the \code{estimate.BVARs()} function. This setup facilitates the 
#' continuation of the MCMC sampling starting from the last draw of the previous 
#' run.
#' 
#' @export
estimate.PosteriorBVARs <- function(
    specification, 
    S, 
    thin = 1, 
    show_progress = TRUE
) {
  
  # get the inputs to estimation
  prior               = specification$last_draw$prior$get_prior()
  starting_values     = specification$last_draw$starting_values$get_starting_values()
  data_matrices       = specification$last_draw$data_matrices$get_data_matrices()
  adaptiveMH          = specification$last_draw$adaptiveMH
  type_objective      = specification$last_draw$get_type() == "zellner"
  p                   = specification$last_draw$p
  
  # estimation
  qqq                 = .Call(`_bpvars_bvars_cpp`, S, data_matrices$Y, data_matrices$missing, data_matrices$exogenous, prior, starting_values, thin, show_progress, adaptiveMH, type_objective, p)
  
  specification$last_draw$starting_values$set_starting_values(qqq$last_draw)
  output              = specify_posterior_bvars$new(specification$last_draw, qqq$posterior)
  
  return(output)
} # END estimate.PosteriorBSVAR
