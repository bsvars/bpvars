
#' @title A vector with country grouping by income group for 189 countries
#' 
#' @description Each of the country is classified into one of the 4 categories
#' according to their geographical location. The categories are:
#' \describe{
#'   \item{1}{Low-income countries}
#'   \item{2}{Lower-middle-income countries}
#'   \item{3}{Upper-middle-income countries}
#'   \item{4}{High-income countries}
#' }
#' 
#' @usage data(country_grouping_incomegroup)
#' 
#' @format A numeric vector with values from \code{1} to \code{4} 
#' 
#' @source 
#' International Labour Organization. (2020). ILO modelled estimates database, 
#' ILOSTAT [database]. Available from \url{https://ilostat.ilo.org/data/}.
#' 
#' @examples 
#' data(country_grouping_incomegroup)   # upload the data
#' 
#' # setup a fixed group allocation Panel VAR model
#' spec = specify_bvarGroupPANEL$new(
#'          ilo_dynamic_panel,
#'          group_allocation = country_grouping_incomegroup
#' )
"country_grouping_incomegroup"