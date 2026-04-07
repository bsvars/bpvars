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
#> 1 27.08426 0.09643248    26.98796     27.18834
#> 2 27.11891 0.09235275    26.99872     27.18997
#> 3 27.12180 0.08042337    27.02538     27.21042
#> 4 27.15213 0.10148440    27.03209     27.24871
#> 5 27.16099 0.08383510    27.09950     27.27439
#> 
#> $variable2
#>        mean       sd 5% quantile 95% quantile
#> 1  9.084358 2.074068    6.304809     10.69514
#> 2 10.354824 1.213720    9.460503     12.01587
#> 3 10.387878 1.865212    8.413359     12.49052
#> 4  9.871698 3.943323    5.911174     14.10372
#> 5  9.824249 3.953022    6.169397     14.64614
#> 
#> $variable3
#>       mean        sd 5% quantile 95% quantile
#> 1 55.75576 1.2910711    54.66667     57.33231
#> 2 54.97960 0.6108153    54.19126     55.53478
#> 3 54.59021 0.9052444    53.72192     55.74770
#> 4 55.13871 2.6263243    52.55812     58.24955
#> 5 55.16800 2.8370336    51.58878     57.96677
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.33847 0.3841134    61.04494     61.86194
#> 2 61.36352 0.5277770    60.63787     61.74206
#> 3 60.91901 0.4900601    60.35758     61.39909
#> 4 61.17752 0.6547480    60.53675     62.02677
#> 5 61.16318 0.7391216    60.26563     61.90476
#> 
```
