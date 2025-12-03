# A vector with country grouping by detailed subregion for 189 countries

Each of the country is classified into one of the 20 categories
according to their geographical location. The categories are:

- 1:

  Southern Asia

- 2:

  Central Africa

- 3:

  Southern Europe

- 4:

  Arab States

- 5:

  South America

- 6:

  Western Asia

- 7:

  Pacific Islands

- 8:

  Western Europe

- 9:

  Eastern Africa

- 10:

  Western Africa

- 11:

  Eastern Europe

- 12:

  Caribbean

- 13:

  Central America

- 14:

  South-Eastern Asia

- 15:

  Southern Africa

- 16:

  Northern America

- 17:

  Northern Europe

- 18:

  Eastern Asia

- 19:

  Northern Africa

- 20:

  Central Asia

Last data update was implemented on 2025-09-26.

## Usage

``` r
data(country_grouping_subregiondetailed)
```

## Format

A numeric vector with values from `1` to `20`

## Source

International Labour Organization. (2020). ILO modelled estimates
database, ILOSTAT \[database\]. Available from
<https://ilostat.ilo.org/data/>.

## Examples

``` r
data(country_grouping_subregiondetailed)   # upload the data

# setup a fixed group allocation Panel VAR model
spec = specify_bvarGroupPANEL$new(
         ilo_dynamic_panel,
         group_allocation = country_grouping_subregiondetailed
)
#> Country groupings have been pre-specified and will not be estimated.
```
