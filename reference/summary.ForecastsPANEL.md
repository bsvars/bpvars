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
#> 1 27.10637 0.04666965    27.04835     27.15089
#> 2 27.04348 0.12625091    26.94290     27.21313
#> 3 27.03562 0.13738077    26.90851     27.21608
#> 4 27.04991 0.15608898    26.87822     27.23880
#> 5 27.07711 0.16840130    26.91990     27.29790
#> 
#> $variable2
#>        mean       sd 5% quantile 95% quantile
#> 1  7.602137 1.943706    4.940062      8.91144
#> 2  9.077557 4.182266    3.341234     11.74002
#> 3 10.168671 4.845476    3.583674     13.54838
#> 4 10.431067 4.316381    4.618172     13.75399
#> 5 10.809647 4.197594    5.048498     13.16603
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 57.02699 1.080225    56.39492     58.49463
#> 2 56.06393 2.696888    54.05899     59.70017
#> 3 55.18501 2.961140    52.80601     59.18410
#> 4 54.99035 2.655413    53.11591     58.64958
#> 5 54.42285 3.033179    52.76087     58.60938
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.75160 0.1810844    61.55534     61.94345
#> 2 61.69960 0.3542697    61.29122     62.11123
#> 3 61.45266 0.4979080    60.95561     62.03894
#> 4 61.39995 0.5415328    60.78673     62.01505
#> 5 61.07437 0.5502407    60.58746     61.80904
#> 
```
