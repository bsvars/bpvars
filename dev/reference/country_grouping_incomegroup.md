# A vector with country grouping by income group for 189 countries

Each of the country is classified into one of the 4 categories according
to their geographical location. The categories are:

- 1:

  Low-income countries

- 2:

  Lower-middle-income countries

- 3:

  Upper-middle-income countries

- 4:

  High-income countries

Last data update was implemented on 2025-09-26.

## Usage

``` r
data(country_grouping_incomegroup)
```

## Format

A numeric vector with values from `1` to `4`

## Source

International Labour Organization. (2020). ILO modelled estimates
database, ILOSTAT \[database\]. Available from
<https://ilostat.ilo.org/data/>.

## Examples

``` r
data(country_grouping_incomegroup)   # upload the data

# setup a fixed group allocation Panel VAR model
spec = specify_bvarGroupPANEL$new(
         ilo_dynamic_panel,
         group_allocation = country_grouping_incomegroup
)
#> Country groupings have been pre-specified and will not be estimated.
```
