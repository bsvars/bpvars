
#' @title A vector with country grouping by subregion for 189 countries
#' 
#' @description Each of the country is classified into one of the 11 categories
#' according to their geographical location. The categories are:
#' \describe{
#'   \item{1}{Southern Asia}
#'   \item{2}{Sub-Saharan Africa}
#'   \item{3}{Northern, Southern and Western Europe}
#'   \item{4}{Arab States}
#'   \item{5}{Latin America and the Caribbean}
#'   \item{6}{Central and Western Asia}
#'   \item{7}{South-Eastern Asia and the Pacific}
#'   \item{8}{Eastern Europe}
#'   \item{9}{Northern America}
#'   \item{10}{Eastern Asia}
#'   \item{11}{Northern Africa}
#' }
#' Last data update was implemented on 2025-09-26.
#' 
#' @usage data(country_grouping_subregionbroad)
#' 
#' @format A numeric vector with values from \code{1} to \code{11} 
#' 
#' @source 
#' International Labour Organization. (2020). ILO modelled estimates database, 
#' ILOSTAT [database]. Available from \url{https://ilostat.ilo.org/data/}.
#' 
#' @examples 
#' data(country_grouping_subregionbroad)   # upload the data
#' 
#' # setup a fixed group allocation Panel VAR model
#' spec = specify_bvarGroupPANEL$new(
#'          ilo_dynamic_panel,
#'          group_allocation = country_grouping_subregionbroad
#' )
"country_grouping_subregionbroad"