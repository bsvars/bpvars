# Computes forecasting performance measures for recursive pseudo-out-of-sample forecasts

Computes forecasting performance measures selected from: log-predictive
score `"lps"`, root-mean-squared-forecast error `"rmsfe"`,
mean-absolute-forecast error `"mafe"` from the output of the recursive
pseudo-out-of-sample forecastinge exercise performed using function
[`forecast_poos_recursively`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.md).
See Sanchez-Martinez & Woźniak (2026).

## Usage

``` r
compute_forecast_performance(forecasts, measures = c("pls", "rmsfe", "mafe"))
```

## Arguments

- forecasts:

  an object containing the outcome of Bayesian recursive
  pseudo-out-of-sample forecasting exercise using expanding window
  samples generated using function
  [`forecast_poos_recursively`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.md).

- measures:

  a character vector with any of the values `"lps"`, `"rmsfe"`, `"mafe"`
  indicating the forecasting performance measures to be computed.

## Value

An object of class `ForecastingPerformance`

## References

Sanchez-Martinez & Woźniak (2026). Forecasting with Bayesian Panel
Vector Autoregressions Using the R Package bpvars. University of
Melbourne Working Paper, 1-39,
[doi:10.48550/arXiv.2606.14143](https://doi.org/10.48550/arXiv.2606.14143)
.

## See also

[`forecast_poos_recursively`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.md),
[`forecast_poos_recursively.BVARPANEL`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.BVARPANEL.md),
[`forecast_poos_recursively.BVARGROUPPANEL`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.BVARGROUPPANEL.md)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
spec = specify_bvarPANEL$new(ilo_dynamic_panel[1:5])               # specify the model
poos = specify_poosf_exercise$new(spec, 2, 5, 1, 30)    # specify the forecasting  exercise
fore = forecast_poos_recursively(spec, poos)                  # perform the forecasting  exercise
#> **************************************************|
#>  bpvars: Forecasting with Bayesian Panel VARs     |
#> **************************************************|
#>  Recursive pseudo-out-of-sample forecasting using
#>          expanding window samples.
#>  Press Esc to interrupt the computations
#> **************************************************|
#>  Step 1: Estimate a model for a full sample to get
#>          starting values for subsequent steps.
#>  Step 2: Recursive pseudo out-of-sample
#>          forecasting performed for 4 samples.
#> **************************************************|
fp   = compute_forecast_performance(fore, "pls")   # compute forecasting performance measures
```
