
#' @title A vector with country grouping by detailed subregion for 189 countries
#' 
#' @description Each of the country is classified into one of the 20 categories
#' according to their geographical location. The categories are:
#' \describe{
#'   \item{1}{Southern Asia}
#'   \item{2}{Central Africa}
#'   \item{3}{Southern Europe}
#'   \item{4}{Arab States}
#'   \item{5}{South America}
#'   \item{6}{Western Asia}
#'   \item{7}{Pacific Islands}
#'   \item{8}{Western Europe}
#'   \item{9}{Eastern Africa}
#'   \item{10}{Western Africa}
#'   \item{11}{Eastern Europe}
#'   \item{12}{Caribbean}
#'   \item{13}{Central America}
#'   \item{14}{South-Eastern Asia}
#'   \item{15}{Southern Africa}
#'   \item{16}{Northern America}
#'   \item{17}{Northern Europe}
#'   \item{18}{Eastern Asia}
#'   \item{19}{Northern Africa}
#'   \item{20}{Central Asia}
#' }
#' 
#' @usage data(country_grouping_subregiondetailed)
#' 
#' @format A numeric vector with values from \code{1} to \code{20} 
#' 
#' @source 
#' International Labour Organization. (2020). ILO modelled estimates database, 
#' ILOSTAT [database]. Available from \url{https://ilostat.ilo.org/data/}.
#' 
#' @examples 
#' data(country_grouping_subregiondetailed)   # upload the data
#' 
#' # setup a fixed group allocation Panel VAR model
#' spec = specify_bvarGroupPANEL$new(
#'          ilo_dynamic_panel,
#'          group_allocation = country_grouping_subregiondetailed
#' )
"country_grouping_subregiondetailed"