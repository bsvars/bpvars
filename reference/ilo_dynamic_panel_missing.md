# A 4-variable annual system for forecasting labour market outcomes for 189 countries to 2024 containing only actual observations

For each of the countries a time series of observations on 4 variables
including the logarithm of Gross Domestic Product (gdp), as well as the
labour market outcomes including the unemployment rate (UR), employment
rate (EPR), labour force participation rate (LFPR). The series are of
various lengths and contain missing values due to data availability.
Last data update was implemented on 2025-09-26.

## Usage

``` r
data(ilo_dynamic_panel_missing)
```

## Format

A list of 189 `ts` objects with time series on 4 variables:

- gdp:

  logarithm of gross domestic product

- UR:

  annual unemployment rate

- EPR:

  annual employment rate

- LFPR:

  annual labour force participation rate

## Source

International Labour Organization. (2020). ILO modelled estimates
database, ILOSTAT \[database\]. Available from
<https://ilostat.ilo.org/data/>.

## Examples

``` r
data(ilo_dynamic_panel_missing)   # upload the data
```
