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
#> 1 27.06480 0.08999006    26.96714     27.16201
#> 2 27.07298 0.14434763    26.93683     27.26208
#> 3 27.07421 0.14661555    26.96534     27.27317
#> 4 27.04394 0.16653654    26.93125     27.27249
#> 5 27.04350 0.15391824    26.87892     27.21233
#> 
#> $variable2
#>       mean       sd 5% quantile 95% quantile
#> 1 8.166919 1.370657    6.874687     9.908504
#> 2 7.717665 1.621338    5.930083     9.596467
#> 3 8.174659 2.272228    5.601438    10.815242
#> 4 8.734888 1.480095    6.830171    10.066609
#> 5 9.364680 2.495977    6.496305    11.742148
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 56.70970 1.188822    55.14589     57.72762
#> 2 56.79358 1.608959    54.94726     58.66228
#> 3 56.51938 1.871542    54.55259     58.46517
#> 4 56.00600 1.489460    54.32273     57.64752
#> 5 55.60308 2.248118    53.35898     58.27646
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 61.74935 0.4694815    61.14732     62.19449
#> 2 61.55432 0.7436046    60.71010     62.43762
#> 3 61.58356 1.0542905    60.48338     62.90940
#> 4 61.39414 1.1477210    60.17372     62.60142
#> 5 61.36559 1.3061237    59.72436     62.61571
#> 
```
