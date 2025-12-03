# Provides posterior summary of country-specific Forecasts

Provides posterior summary of the forecasts including their mean,
standard deviations, as well as 5 and 95 percentiles.

## Usage

``` r
# S3 method for class 'ForecastsPANEL'
summary(object, which_c, ...)
```

## Arguments

- object:

  an object of class `ForecastsPANEL` obtained using the
  [`forecast()`](https://generics.r-lib.org/reference/forecast.html)
  function containing draws the predictive density.

- which_c:

  a positive integer or a character string specifying the country for
  which the forecast should be plotted.

- ...:

  additional arguments affecting the summary produced.

## Value

A list reporting the posterior mean, standard deviations, as well as 5
and 95 percentiles of the forecasts for each of the variables and
forecast horizons.

## See also

[`forecast.PosteriorBVARPANEL`](http://bsvars.org/bpvars/reference/forecast.PosteriorBVARPANEL.md),
[`plot`](https://rdrr.io/r/graphics/plot.default.html)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
# specify the model
specification = specify_bvarPANEL$new(
      ilo_dynamic_panel, 
      exogenous = ilo_exogenous_variables)
burn_in       = estimate(specification, 5)             # run the burn-in
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
posterior     = estimate(burn_in, 5)                   # estimate the model
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|

# forecast 6 years ahead
predictive    = forecast(
      posterior, 
      5, 
      exogenous_forecast = ilo_exogenous_forecasts)
summary(predictive, which_c = "POL")
#>  **************************************************|
#>  bsvars: Bayesian Structural Vector Autoregressions|
#>  **************************************************|
#>    Posterior summary of forecasts                  |
#>  **************************************************|
#> $variable1
#>       mean         sd 5% quantile 95% quantile
#> 1 27.24688 0.02231409    27.22456     27.27302
#> 2 27.28413 0.02732865    27.25986     27.31893
#> 3 27.31846 0.02576589    27.28672     27.34580
#> 4 27.34242 0.03571108    27.30414     27.38310
#> 5 27.36989 0.03855736    27.33655     27.42137
#> 
#> $variable2
#>        mean       sd 5% quantile 95% quantile
#> 1 2.3604819 3.692860   -2.091461     6.220512
#> 2 3.2686553 4.884934   -2.799624     8.050708
#> 3 1.3351533 5.634418   -6.416203     4.925067
#> 4 0.6957398 5.210294   -6.331567     4.845542
#> 5 1.6641785 6.270398   -6.284141     7.363814
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 57.56734 1.935734    55.48661     59.90496
#> 2 57.08392 2.966171    54.30796     60.82325
#> 3 58.48006 3.706586    55.82635     63.57239
#> 4 58.92124 3.746772    56.03006     63.89298
#> 5 58.57324 4.108621    55.32135     64.09827
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 59.02080 0.1550057    58.89998     59.23061
#> 2 59.07558 0.4801345    58.46771     59.56316
#> 3 59.43627 0.7502999    58.62436     60.36348
#> 4 59.56225 1.1613296    58.65053     61.08762
#> 5 59.73333 1.1425636    58.50127     61.14861
#> 
```
