# Provides posterior summary of forecast error variance decompositions

Provides posterior means of the forecast error variance decompositions
of each variable at all horizons.

## Usage

``` r
# S3 method for class 'PosteriorFEVDPANEL'
summary(object, which_c, ...)
```

## Arguments

- object:

  an object of class `PosteriorFEVDPANEL` obtained using the
  [`compute_variance_decompositions()`](https://bsvars.org/bsvars/reference/compute_variance_decompositions.html)
  function containing draws from the posterior distribution of the
  forecast error variance decompositions.

- which_c:

  a positive integer or a character string specifying the country for
  which the forecast should be plotted.

- ...:

  additional arguments affecting the summary produced.

## Value

A list reporting the posterior mean of the forecast error variance
decompositions of each variable at all horizons.

## See also

[`compute_variance_decompositions.PosteriorBVARPANEL`](http://bsvars.org/bpvars/reference/compute_variance_decompositions.PosteriorBVARPANEL.md),
[`plot`](https://rdrr.io/r/graphics/plot.default.html)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
# specify the model and set seed
specification  = specify_bvarPANEL$new(ilo_dynamic_panel, p = 1)

# run the burn-in
burn_in        = estimate(specification, 5)
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|

# estimate the model
posterior      = estimate(burn_in, 5)
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|

# compute forecast error variance decomposition 4 years ahead
fevd           = compute_variance_decompositions(posterior, horizon = 4)
summary(fevd, which_c = "POL")
#>  **************************************************|
#>  bsvars: Bayesian Structural Vector Autoregressions|
#>  **************************************************|
#>    Posterior means of forecast error               |
#>      variance decompositions                       |
#>  **************************************************|
#> $variable1
#>      shock1     shock2    shock3    shock4
#> 0 100.00000 0.00000000 0.0000000 0.0000000
#> 1  99.59812 0.06772478 0.2125492 0.1216021
#> 2  99.45324 0.09218893 0.2891802 0.1653911
#> 3  99.38073 0.10444518 0.3275450 0.1872812
#> 4  99.33713 0.11182316 0.3506194 0.2004240
#> 
#> $variable2
#>     shock1     shock2   shock3   shock4
#> 0 99.52470  0.4753016  0.00000  0.00000
#> 1 41.79728 10.6651609 30.31614 17.22142
#> 2 39.16076 11.1170395 31.77679 17.94541
#> 3 40.18405 10.9165639 31.35720 17.54219
#> 4 42.03202 10.5777624 30.49259 16.89763
#> 
#> $variable3
#>     shock1    shock2   shock3   shock4
#> 0 65.27792  6.594273 28.12781  0.00000
#> 1 32.21698 11.237817 33.50312 23.04208
#> 2 42.64930  9.585919 28.51257 19.25221
#> 3 52.32955  8.022830 23.89672 15.75090
#> 4 59.80043  6.803949 20.28602 13.10961
#> 
#> $variable4
#>     shock1    shock2   shock3   shock4
#> 0 11.36900 13.226675 42.05641 33.34792
#> 1 17.58202 12.167679 38.59639 31.65391
#> 2 34.68870  9.595301 30.26002 25.45599
#> 3 52.47720  6.971404 21.85938 18.69202
#> 4 66.41838  4.937447 15.41068 13.23350
#> 

# workflow with the pipe |>
############################################################
ilo_dynamic_panel |>
  specify_bvarPANEL$new(p = 1) |>
  estimate(S = 5) |> 
  estimate(S = 5) |> 
  compute_variance_decompositions(horizon = 4) |> 
  summary(which_c = "COL")
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
#>    Posterior means of forecast error               |
#>      variance decompositions                       |
#>  **************************************************|
#> $variable1
#>      shock1    shock2    shock3    shock4
#> 0 100.00000 0.0000000 0.0000000 0.0000000
#> 1  99.34101 0.1436800 0.3060778 0.2092293
#> 2  98.60471 0.3050962 0.6484033 0.4417860
#> 3  97.93265 0.4530401 0.9611559 0.6531493
#> 4  97.32124 0.5879804 1.2458985 0.8448825
#> 
#> $variable2
#>     shock1    shock2   shock3   shock4
#> 0 95.55691  4.443086  0.00000  0.00000
#> 1 34.68620 13.806434 30.21847 21.28890
#> 2 33.40147 14.207752 30.77032 21.62045
#> 3 33.60323 14.234388 30.67289 21.48949
#> 4 35.11282 13.966472 29.99428 20.92643
#> 
#> $variable3
#>     shock1   shock2   shock3   shock4
#> 0 71.46275  9.22731 19.30994  0.00000
#> 1 30.04119 15.49471 32.94110 21.52300
#> 2 31.19309 15.16039 32.28098 21.36554
#> 3 33.11932 14.69911 31.32902 20.85256
#> 4 35.43518 14.16762 30.21931 20.17788
#> 
#> $variable4
#>      shock1   shock2   shock3   shock4
#> 0  1.958007 19.19473 43.81183 35.03543
#> 1 26.906438 15.42877 33.46219 24.20260
#> 2 26.758225 15.89042 33.86430 23.48706
#> 3 26.005417 16.32925 34.45434 23.21099
#> 4 25.616855 16.56772 34.77934 23.03609
#> 
```
