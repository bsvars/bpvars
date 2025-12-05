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
#> 1 27.09760 0.04813109    27.05145     27.15254
#> 2 27.06879 0.08070299    26.97915     27.14869
#> 3 27.03338 0.02946982    26.99851     27.06190
#> 4 27.05491 0.09874415    26.92934     27.15369
#> 5 27.03679 0.11983245    26.87401     27.12340
#> 
#> $variable2
#>        mean       sd 5% quantile 95% quantile
#> 1  8.267546 1.827436    6.078876     10.07446
#> 2  9.457618 1.972955    7.010355     11.57388
#> 3 11.038463 2.817099    7.179987     13.04984
#> 4 10.151153 2.354297    7.109141     12.17128
#> 5 11.559145 2.673594    8.972867     14.51574
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 56.45722 1.337316    54.85656     57.96457
#> 2 55.31364 1.053445    54.18556     56.55200
#> 3 54.45345 1.594813    52.97255     56.54000
#> 4 55.23215 1.618986    53.33140     57.03158
#> 5 54.10277 1.774283    51.71525     55.62728
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.54629 0.6557943    60.75968     62.27944
#> 2 61.10136 0.7965747    60.33326     62.03883
#> 3 61.21190 1.1085319    60.55323     62.73297
#> 4 61.46600 1.4212658    60.36055     63.39028
#> 5 61.18552 1.7154426    59.65981     63.39693
#> 
```
