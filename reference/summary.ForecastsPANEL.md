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
#> 1 27.08648 0.01183613    27.07582     27.09967
#> 2 27.07692 0.09067762    26.97635     27.17756
#> 3 27.06742 0.11934175    26.95365     27.21370
#> 4 27.11363 0.10456369    27.03320     27.25573
#> 5 27.12218 0.15118981    26.97424     27.31840
#> 
#> $variable2
#>        mean       sd 5% quantile 95% quantile
#> 1  9.042472 2.131156    6.933762     11.43532
#> 2  9.887287 2.093453    8.217332     12.73672
#> 3 10.775459 2.685551    7.590136     13.43640
#> 4 10.389148 3.426879    7.231748     14.55496
#> 5 10.121677 2.905371    6.336987     12.92281
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 56.24097 1.425952    54.40097     57.55963
#> 2 55.99927 1.257603    54.34361     57.16273
#> 3 55.22960 1.583721    53.21634     56.84351
#> 4 55.70149 1.636326    53.83803     57.60791
#> 5 56.01960 2.113021    53.49861     58.11638
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.86763 0.4736857    61.33862     62.33492
#> 2 62.16360 0.5956629    61.77005     62.97420
#> 3 61.90822 0.8770091    61.24143     63.10618
#> 4 62.15880 1.3716069    60.56568     63.27081
#> 5 62.32731 1.9268359    59.98586     64.14921
#> 
```
