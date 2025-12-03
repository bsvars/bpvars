# Plots fitted values of dependent variables

Plots of fitted values of dependent variables including their median and
percentiles.

## Usage

``` r
# S3 method for class 'ForecastsPANEL'
plot(
  x,
  which_c,
  probability = 0.9,
  data_in_plot = 1,
  col = "#1614B1",
  main,
  xlab,
  mar.multi = c(1, 4.6, 0, 2.1),
  oma.multi = c(6, 0, 5, 0),
  ...
)
```

## Arguments

- x:

  an object of class `ForecastsPANEL` obtained using the
  [`forecast()`](https://generics.r-lib.org/reference/forecast.html)
  function containing posterior draws of fitted values of dependent
  variables.

- which_c:

  a positive integer or a character string specifying the country for
  which the forecast should be plotted.

- probability:

  a parameter determining the interval to be plotted. The interval
  stretches from the `0.5 * (1 - probability)` to
  `1 - 0.5 * (1 - probability)` percentile of the posterior
  distribution.

- data_in_plot:

  a fraction value in the range (0, 1) determining how many of the last
  observations in the data should be plotted with the forecasts.

- col:

  a colour of the plot line and the ribbon

- main:

  an alternative main title for the plot

- xlab:

  an alternative x-axis label for the plot

- mar.multi:

  the default `mar` argument setting in
  [`graphics::par`](https://rdrr.io/r/graphics/par.html). Modify with
  care!

- oma.multi:

  the default `oma` argument setting in
  [`graphics::par`](https://rdrr.io/r/graphics/par.html). Modify with
  care!

- ...:

  additional arguments affecting the summary produced.

## See also

[`forecast.PosteriorBVARPANEL`](http://bsvars.org/bpvars/reference/forecast.PosteriorBVARPANEL.md)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
specification = specify_bvarPANEL$new(ilo_dynamic_panel)  # specify the model
burn_in       = estimate(specification, 10)               # run the burn-in
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 10 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
posterior     = estimate(burn_in, 10)                     # estimate the model
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 10 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|

# forecast 5 years ahead
predictive    = forecast(posterior, 6)
plot(predictive, which_c = "POL")                                # plot forecasts


# workflow with the pipe |>
############################################################
ilo_dynamic_panel |>
  specify_bvarPANEL$new() |>
  estimate(S = 10) |> 
  estimate(S = 10) |> 
  forecast(horizon = 5) |>
  plot(which_c = 135)
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 10 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 10 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|

```
