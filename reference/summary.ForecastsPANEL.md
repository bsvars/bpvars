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
#> 1 27.08751 0.02471963    27.06204     27.11783
#> 2 27.12580 0.09966979    27.03980     27.25970
#> 3 27.11123 0.07353809    27.03973     27.19028
#> 4 27.09527 0.11145392    26.99266     27.21485
#> 5 27.12259 0.10613744    27.01343     27.24056
#> 
#> $variable2
#>       mean        sd 5% quantile 95% quantile
#> 1 7.930827 0.9760166  7.01101343     9.123122
#> 2 6.476074 2.4170099  3.73700874     8.851754
#> 3 7.050989 1.3820859  5.40248850     8.374198
#> 4 8.139375 3.3592301  3.74047560    10.868393
#> 5 6.792320 5.0074587 -0.06802794    10.364753
#> 
#> $variable3
#>       mean        sd 5% quantile 95% quantile
#> 1 56.41742 0.6652542    55.81525     57.21301
#> 2 57.66210 1.8962059    55.82390     59.86604
#> 3 57.14996 1.3012036    55.60660     58.46304
#> 4 55.59387 2.2123602    53.43406     57.99831
#> 5 56.62652 2.3095543    54.83989     59.74720
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.26340 0.5043928    60.69767     61.86819
#> 2 61.66110 0.6538028    60.88875     62.21691
#> 3 61.48591 0.5737147    60.73444     61.97980
#> 4 60.50699 1.0706045    59.44204     61.73572
#> 5 60.75990 0.9936233    59.61090     61.92503
#> 
```
