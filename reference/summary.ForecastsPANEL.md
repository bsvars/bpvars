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

# forecast 6 years ahead
predictive    = forecast(
      posterior, 
      5, 
      exogenous_forecast = ilo_exogenous_forecasts[1:5])
summary(predictive, which_c = "ARG")
#>  **************************************************|
#>  bsvars: Bayesian Structural Vector Autoregressions|
#>  **************************************************|
#>    Posterior summary of forecasts                  |
#>  **************************************************|
#> $variable1
#>       mean         sd 5% quantile 95% quantile
#> 1 27.07228 0.06880631    27.00333     27.15093
#> 2 27.06002 0.05332932    26.99200     27.10518
#> 3 27.05165 0.04213968    27.00449     27.10211
#> 4 27.05797 0.09876323    26.95617     27.18348
#> 5 27.06793 0.12579569    26.91082     27.18420
#> 
#> $variable2
#>       mean       sd 5% quantile 95% quantile
#> 1 7.905068 1.575064    6.325968     9.685855
#> 2 8.176553 2.324930    6.268385    11.219602
#> 3 9.240634 2.082671    7.812547    12.048069
#> 4 7.679040 2.619033    4.396341    10.384781
#> 5 7.740259 4.156198    3.128157    12.499499
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 56.80972 1.317962    55.18750     58.11797
#> 2 56.31285 2.124656    53.67648     58.26947
#> 3 55.38677 1.944075    53.22786     57.74344
#> 4 56.35612 1.579298    55.22937     58.52218
#> 5 56.24435 2.027067    54.20592     58.59895
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.70506 0.4275920    61.13905     62.08207
#> 2 61.33720 0.8841376    60.51442     62.28884
#> 3 61.02962 1.2811792    59.77073     62.68212
#> 4 61.04867 1.0187228    60.13735     62.38091
#> 5 60.95840 0.7038092    60.43864     61.91664
#> 
```
