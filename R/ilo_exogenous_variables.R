
#' @title A 3-variable annual system for of dummy observations for 2008, 2020, 
#' and 2021 to be used in the estimation of the Panel VAR model for 
#' 189 countries from 1991 to 2024
#'
#' @description For each of the countries a time series of 33 observations on 3 
#' dummy variables for the years 2008, 2020, and 2021 is provided. 
#' Last data update was implemented on 2025-09-26.
#'
#' @usage data(ilo_exogenous_variables)
#' 
#' @format A list of 189 \code{ts} objects with time series of 34 observations 
#' on 3 variables:
#' \describe{
#'   \item{2008}{the aftermath of the Global Financial Crisis}
#'   \item{2020}{the COVID pandemic}
#'   \item{2021}{the aftermath of the COVID pandemic}
#' }
#' 
#' @examples 
#' data(ilo_exogenous_variables)   # upload the data
#' 
"ilo_exogenous_variables"
