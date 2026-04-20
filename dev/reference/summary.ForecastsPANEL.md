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

[`forecast.PosteriorBVARPANEL`](http://bsvars.org/bpvars/dev/reference/forecast.PosteriorBVARPANEL.md),
[`plot`](https://rdrr.io/r/graphics/plot.default.html)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
# specify the model
specification = specify_bvarPANEL$new(
      ilo_dynamic_panel[1:5], 
      exogenous = ilo_exogenous_variables[1:5])
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

# forecast 3 years ahead
predictive    = forecast(
      posterior, 
      3, 
      exogenous_forecast = ilo_exogenous_forecasts[1:5])
summary(predictive, which_c = "ARG")
#>  **************************************************|
#>  bsvars: Bayesian Structural Vector Autoregressions|
#>  **************************************************|
#>    Posterior summary of forecasts                  |
#>  **************************************************|
#> $variable1
#>       mean         sd 5% quantile 95% quantile
#> 1 27.02015 0.05804131    26.94511     27.06942
#> 2 26.97173 0.07865364    26.90613     27.07722
#> 3 27.02153 0.03161139    26.99918     27.06500
#> 
#> $variable2
#>       mean       sd 5% quantile 95% quantile
#> 1 10.39498 2.199967    8.059430     13.07439
#> 2 11.76428 2.258356    9.169877     14.35083
#> 3 11.87212 1.644141   10.248399     13.94224
#> 
#> $variable3
#>       mean        sd 5% quantile 95% quantile
#> 1 55.25583 1.7234375    53.27320     57.25994
#> 2 53.87417 1.4793744    51.99018     55.26153
#> 3 54.69416 0.8507214    53.75775     55.70444
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.68101 0.5427252    61.19131     62.39734
#> 2 61.00667 0.3906075    60.60663     61.43406
#> 3 62.05601 0.6427828    61.35009     62.58525
#> 
```
