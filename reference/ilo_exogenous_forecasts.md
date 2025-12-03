# Data containing future observations for 189 United Nations countries from 2025 to 2029 to be used to forecast with models with `ilo_exogenous_variables`

For each of the countries a time series of 5 observations on On the
dummies is provided. These future values are all equal to zero. They
provide benchmark for the objects to be used when `exogenous_variables`
are used. Last data update was implemented on 2025-09-26.

## Usage

``` r
data(ilo_exogenous_forecasts)
```

## Format

A list of 189 `ts` objects with time series of 5 observations on 3
variables:

- 2008:

  the aftermath of the Global Financial Crisis

- 2020:

  the COVID pandemic

- 2021:

  the aftermath of the COVID pandemic

## Examples

``` r
data(ilo_exogenous_forecasts)   # upload the data
```
