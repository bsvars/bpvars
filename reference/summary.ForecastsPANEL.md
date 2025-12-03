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
      ilo_dynamic_panel, 
      exogenous = ilo_exogenous_variables)
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
      exogenous_forecast = ilo_exogenous_forecasts)
summary(predictive, which_c = "POL")
#>  **************************************************|
#>  bsvars: Bayesian Structural Vector Autoregressions|
#>  **************************************************|
#>    Posterior summary of forecasts                  |
#>  **************************************************|
#> $variable1
#>       mean         sd 5% quantile 95% quantile
#> 1 27.24175 0.02504637    27.22708     27.27579
#> 2 27.28670 0.04414447    27.24539     27.33462
#> 3 27.30494 0.04388292    27.24996     27.34948
#> 4 27.34015 0.05314228    27.28276     27.40050
#> 5 27.35601 0.06930886    27.28174     27.43370
#> 
#> $variable2
#>        mean       sd 5% quantile 95% quantile
#> 1 0.7336667 2.727069   -2.116437     3.501981
#> 2 0.7878285 1.951534   -1.455667     2.784948
#> 3 1.3851524 2.740630   -1.169884     4.967626
#> 4 1.1375020 3.645662   -1.992394     5.961892
#> 5 0.8950954 3.728830   -2.761829     5.700516
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 58.16190 1.498528    56.56132     59.81196
#> 2 58.40850 1.406058    56.79214     59.92131
#> 3 58.40105 1.331775    56.85346     59.68158
#> 4 58.73217 2.026466    56.45101     60.81520
#> 5 59.06388 2.031253    57.03972     61.51685
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 58.70691 0.5565945    58.19262     59.43588
#> 2 58.97353 0.7930272    58.00159     59.74540
#> 3 59.33967 1.0685041    58.18483     60.33818
#> 4 59.56886 0.9808795    58.53137     60.55522
#> 5 59.76329 1.2883659    58.30024     61.06603
#> 

# workflow with the pipe |>
############################################################
ilo_dynamic_panel |>
  specify_bvarPANEL$new() |>
  estimate(S = 5) |> 
  estimate(S = 5) |> 
  forecast(horizon = 5, exogenous_forecast = ilo_exogenous_forecasts) |> 
  summary(which_c = "POL")
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
#>  **************************************************|
#>  bsvars: Bayesian Structural Vector Autoregressions|
#>  **************************************************|
#>    Posterior summary of forecasts                  |
#>  **************************************************|
#> $variable1
#>       mean         sd 5% quantile 95% quantile
#> 1 27.26533 0.02740395    27.24312     27.30167
#> 2 27.30709 0.03098421    27.26846     27.33742
#> 3 27.33935 0.07226716    27.24747     27.41280
#> 4 27.37530 0.05494014    27.31885     27.44517
#> 5 27.41002 0.03116555    27.37348     27.44347
#> 
#> $variable2
#>        mean       sd 5% quantile 95% quantile
#> 1 2.3975877 1.960150   0.8891908     5.042508
#> 2 1.1535888 2.462546  -0.8348252     4.464444
#> 3 0.6903875 3.498628  -2.0888593     5.377697
#> 4 0.4259480 3.047560  -3.1887909     3.749321
#> 5 0.1035913 3.470566  -4.5518602     2.981222
#> 
#> $variable3
#>       mean       sd 5% quantile 95% quantile
#> 1 57.24179 1.024238    55.84169     57.91800
#> 2 57.98832 1.393367    56.09878     58.87391
#> 3 58.24541 2.050600    55.42296     59.61120
#> 4 58.81288 1.508505    56.81845     60.20078
#> 5 59.00675 1.892386    56.78582     61.18777
#> 
#> $variable4
#>       mean        sd 5% quantile 95% quantile
#> 1 58.69132 0.4033913    58.27449     59.19246
#> 2 58.73736 0.3168240    58.41936     59.07667
#> 3 58.73265 0.8326323    58.02086     59.80941
#> 4 59.19425 0.9339533    58.26140     60.25718
#> 5 59.17598 1.3475470    58.07524     60.69009
#> 
```
