# A vector with country grouping by subregion for 189 countries

Each of the country is classified into one of the 11 categories
according to their geographical location. The categories are:

- 1:

  Southern Asia

- 2:

  Sub-Saharan Africa

- 3:

  Northern, Southern and Western Europe

- 4:

  Arab States

- 5:

  Latin America and the Caribbean

- 6:

  Central and Western Asia

- 7:

  South-Eastern Asia and the Pacific

- 8:

  Eastern Europe

- 9:

  Northern America

- 10:

  Eastern Asia

- 11:

  Northern Africa

Last data update was implemented on 2025-09-26.

## Usage

``` r
data(country_grouping_subregionbroad)
```

## Format

A numeric vector with values from `1` to `11`

## Source

International Labour Organization. (2020). ILO modelled estimates
database, ILOSTAT \[database\]. Available from
<https://ilostat.ilo.org/data/>.

## Examples

``` r
data(country_grouping_subregionbroad)   # upload the data

# setup a fixed group allocation Panel VAR model
spec = specify_bvarGroupPANEL$new(
         ilo_dynamic_panel,
         group_allocation = country_grouping_subregionbroad
)
#> Country groupings have been pre-specified and will not be estimated.
```
