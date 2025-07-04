% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/country_grouping_incomegroup.R
\docType{data}
\name{country_grouping_incomegroup}
\alias{country_grouping_incomegroup}
\title{A vector with country grouping by income group for 189 countries}
\format{
A numeric vector with values from \code{1} to \code{4}
}
\source{
International Labour Organization. (2020). ILO modelled estimates database, 
ILOSTAT [database]. Available from \url{https://ilostat.ilo.org/data/}.
}
\usage{
data(country_grouping_incomegroup)
}
\description{
Each of the country is classified into one of the 4 categories
according to their geographical location. The categories are:
\describe{
  \item{1}{Low-income countries}
  \item{2}{Lower-middle-income countries}
  \item{3}{Upper-middle-income countries}
  \item{4}{High-income countries}
}
}
\examples{
data(country_grouping_incomegroup)   # upload the data

# setup a fixed group allocation Panel VAR model
spec = specify_bvarGroupPANEL$new(
         ilo_dynamic_panel,
         group_allocation = country_grouping_incomegroup
)
}
\keyword{datasets}
