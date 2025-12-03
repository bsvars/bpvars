# Bayesian recursive pseudo-out-of-sample forecasting

Performs the recursive pseudo-out-of-sample forecasting exercise using
expanding window samples.

## Usage

``` r
forecast_poos_recursively(model_spec, poos_spec, show_progress = TRUE)
```

## Arguments

- model_spec:

  an object generated using one of the `specify_*` functions containing
  model specification.

- poos_spec:

  an object of class `POOSForecastSetup` containing specification of the
  recursive pseudo-out-of-sample forecasting exercise using expanding
  window samples.

- show_progress:

  a logical value, if `TRUE` the estimation progress bar is visible

## Value

An object of class `ForecastsPOOS` containing the outcome of Bayesian
recursive pseudo-out-of-sample forecasting exercise using expanding
window samples. The object is a list with `forecasting_sample` elements,
where `forecasting_sample` is equal to the sample size less the maximum
of `horizons` and the `training_sample` plus one. Each element of the
list is an object of class `ForecastsPANEL` containing the forecasts for
each country, see
[`forecast.PosteriorBVARPANEL`](http://bsvars.org/bpvars/reference/forecast.PosteriorBVARPANEL.md).

## See also

[`forecast.PosteriorBVARPANEL`](http://bsvars.org/bpvars/reference/forecast.PosteriorBVARPANEL.md),
[`specify_bvarPANEL`](http://bsvars.org/bpvars/reference/specify_bvarPANEL.md),
[`specify_poosf_exercise`](http://bsvars.org/bpvars/reference/specify_poosf_exercise.md),
[`estimate.BVARPANEL`](http://bsvars.org/bpvars/reference/estimate.BVARPANEL.md)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
spec = specify_bvarPANEL$new(ilo_dynamic_panel[1:5])   # specify the model
poos = specify_poosf_exercise$new(                # specify the forecasting exercise
         spec, 
         S = 5,                                   # use at least S = 5000
         S_burn = 2,                              # use at least S_burn = 1000
         horizons = 1,
         training_sample = 30
       )   
fore = forecast_poos_recursively(spec, poos)      # execute the forecasting exercise
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
```
