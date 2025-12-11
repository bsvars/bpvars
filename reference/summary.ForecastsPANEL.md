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
#> 1 27.03641 0.02829323    26.99835     27.05802
#> 2 27.01438 0.06117335    26.95161     27.09118
#> 3 27.05369 0.10503594    26.95074     27.18682
#> 4 27.09670 0.17503681    26.92149     27.30557
#> 5 27.16611 0.14377707    27.04320     27.32374
#> 
#> $variable2
#>        mean       sd 5% quantile 95% quantile
#> 1 10.285044 1.106622    9.327825     11.75103
#> 2 12.530766 2.046181   10.484122     14.93248
#> 3 11.306446 3.357011    7.523635     15.27200
#> 4 10.759775 3.884238    5.532724     13.89893
#> 5  9.039554 1.895303    6.549782     10.76140
#> 
#> $variable3
#>       mean        sd 5% quantile 95% quantile
#> 1 54.89488 0.7302086    53.89151     55.40525
#> 2 53.51174 1.6815064    51.76769     55.37876
#> 3 54.29652 2.1776693    51.87629     56.88723
#> 4 54.86982 2.7399047    52.73474     58.59866
#> 5 56.35627 1.3595349    54.75725     57.81213
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.16617 0.2509655    60.88345     61.38903
#> 2 61.16252 0.5790109    60.65265     61.85269
#> 3 61.21450 0.3050971    60.89070     61.59532
#> 4 61.45749 0.5370547    60.84571     62.09435
#> 5 61.94325 0.8064033    61.20477     62.95122
#> 
```
