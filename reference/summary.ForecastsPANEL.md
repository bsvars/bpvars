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
#> 1 27.00275 0.07159561    26.91128     27.07268
#> 2 26.95798 0.08905303    26.86153     27.05320
#> 3 26.98993 0.07106763    26.90997     27.06235
#> 4 27.02671 0.10097714    26.90797     27.10802
#> 5 27.05031 0.16995915    26.87750     27.24939
#> 
#> $variable2
#>       mean       sd 5% quantile 95% quantile
#> 1 8.670714 2.551170    5.397882     11.04419
#> 2 9.503132 1.630232    7.552005     11.18184
#> 3 9.118977 1.524169    7.766884     11.06856
#> 4 8.988245 2.351423    5.853196     10.96696
#> 5 8.664397 2.928960    5.712437     12.31983
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 55.59536 2.233550    53.32799     58.40529
#> 2 54.98893 1.516305    53.35327     56.74172
#> 3 55.28232 1.833600    53.00701     57.00237
#> 4 55.15417 2.809968    52.69275     58.74176
#> 5 55.54044 2.833994    51.73034     57.96267
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 60.87485 0.9020038    59.70895     61.75769
#> 2 60.76072 0.6749628    59.89296     61.43619
#> 3 60.85504 1.1319120    59.64284     61.90786
#> 4 60.62029 1.8272090    58.47709     62.46330
#> 5 60.82183 1.8892420    58.58892     62.73584
#> 
```
