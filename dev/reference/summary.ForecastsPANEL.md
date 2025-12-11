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
#> 1 27.10839 0.03032856    27.07282     27.14338
#> 2 27.13243 0.07449837    27.06658     27.23073
#> 3 27.16510 0.06335474    27.10486     27.24732
#> 4 27.15318 0.06917980    27.09329     27.24440
#> 5 27.18809 0.05946788    27.14084     27.26869
#> 
#> $variable2
#>        mean        sd 5% quantile 95% quantile
#> 1  8.158194 2.1836640    6.392169    11.113220
#> 2  8.901007 0.7829381    8.047328     9.729676
#> 3  7.997534 2.7132309    4.868596    11.109808
#> 4 10.297849 3.1405706    7.412558    14.454665
#> 5  9.659831 4.3575139    6.060833    15.476701
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 56.48998 1.128174    55.15690     57.74475
#> 2 56.10092 0.936432    55.17545     57.29597
#> 3 57.01213 1.607106    55.73307     59.19425
#> 4 54.97601 1.556532    53.45564     56.98368
#> 5 55.41443 2.364415    52.20087     57.19567
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.54200 0.4828453    61.07182     62.14385
#> 2 61.58031 1.2760068    60.83791     63.34566
#> 3 61.97458 1.2710915    60.77016     63.63605
#> 4 61.28141 1.1624067    60.02411     62.58948
#> 5 61.32100 0.6909877    60.81079     62.21876
#> 
```
