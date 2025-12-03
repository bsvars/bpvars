# A vector with country grouping by region for 189 countries

Each of the country is classified into one of the 5 categories according
to their geographical location. The categories are:

- 1:

  Asia and the Pacific

- 2:

  Africa

- 3:

  Europe and Central Asia

- 4:

  Arab States

- 5:

  Americas

Last data update was implemented on 2025-09-26.

## Usage

``` r
data(country_grouping_region)
```

## Format

A numeric vector with values from `1` to `5`

## Source

International Labour Organization. (2020). ILO modelled estimates
database, ILOSTAT \[database\]. Available from
<https://ilostat.ilo.org/data/>.

## Examples

``` r
data(country_grouping_region)   # upload the data

# setup a fixed group allocation Panel VAR model
spec = specify_bvarGroupPANEL$new(
         ilo_dynamic_panel,
         group_allocation = country_grouping_region
)
#> Country groupings have been pre-specified and will not be estimated.
```
