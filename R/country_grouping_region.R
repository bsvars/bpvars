
#' @title A vector with country grouping by region for 189 countries
#' 
#' @description Each of the country is classified into one of the 5 categories
#' according to their geographical location. The categories are:
#' \describe{
#'   \item{1}{Asia and the Pacific}
#'   \item{2}{Africa}
#'   \item{3}{Europe and Central Asia}
#'   \item{4}{Arab States}
#'   \item{5}{Americas}
#' }
#' Last data update was implemented on 2025-09-26.
#' 
#' @usage data(country_grouping_region)
#' 
#' @format A numeric vector with values from \code{1} to \code{5} 
#' 
#' @source 
#' International Labour Organization. (2020). ILO modelled estimates database, 
#' ILOSTAT [database]. Available from \url{https://ilostat.ilo.org/data/}.
#' 
#' @examples 
#' data(country_grouping_region)   # upload the data
#' 
#' # setup a fixed group allocation Panel VAR model
#' spec = specify_bvarGroupPANEL$new(
#'          ilo_dynamic_panel,
#'          group_allocation = country_grouping_region
#' )
"country_grouping_region"