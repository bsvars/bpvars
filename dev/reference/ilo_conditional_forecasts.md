# Data containing future observations for 189 countries from 2025 to 2027 to be used for conditional forecasts given the future values of gdp.

For each of the countries a time series of 3 observations on the future
values of gdp is provided. These future values are taken from IMF
projections. The future values of other variables are set to `NA`. Last
data update was implemented on 2026-04-18.

## Usage

``` r
data(ilo_conditional_forecasts)
```

## Format

A list of 189 `ts` objects with time series of 3 observations on 4
variables:

- gdp:

  logarithm of gross domestic product

- UR:

  annual unemployment rate

- EPR:

  annual employment rate

- LFPR:

  annual labour force participation rate

## Examples

``` r
data(ilo_conditional_forecasts)   # upload the data
```
