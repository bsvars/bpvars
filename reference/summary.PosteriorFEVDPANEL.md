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
specification  = specify_bvarPANEL$new(ilo_dynamic_panel[1:5], p = 1)

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
summary(fevd, which_c = "ARG")
#>  **************************************************|
#>  bsvars: Bayesian Structural Vector Autoregressions|
#>  **************************************************|
#>    Posterior means of forecast error               |
#>      variance decompositions                       |
#>  **************************************************|
#> $variable1
#>      shock1   shock2   shock3    shock4
#> 0 100.00000 0.000000  0.00000  0.000000
#> 1  72.77365 5.102972 12.73066  9.392721
#> 2  67.78405 6.036292 15.06490 11.114759
#> 3  65.66377 6.431804 16.05656 11.847865
#> 4  64.48301 6.651353 16.60860 12.257038
#> 
#> $variable2
#>      shock1     shock2   shock3   shock4
#> 0 99.736648  0.2633523  0.00000  0.00000
#> 1  9.007672 16.0791802 42.58324 32.32991
#> 2 12.121941 15.3873893 41.05100 31.43967
#> 3 17.660891 14.3427157 38.41062 29.58577
#> 4 23.309536 13.3249531 35.73901 27.62650
#> 
#> $variable3
#>     shock1    shock2    shock3   shock4
#> 0 91.26447  3.121808  5.613717  0.00000
#> 1 10.28870 16.758941 42.294790 30.65757
#> 2 13.03463 16.164456 40.958034 29.84288
#> 3 15.80715 15.597889 39.622501 28.97246
#> 4 18.44381 15.076501 38.359779 28.11991
#> 
#> $variable4
#>      shock1   shock2   shock3   shock4
#> 0  2.703185 16.73408 44.53762 36.02511
#> 1  7.601039 16.75895 42.80877 32.83124
#> 2 12.021203 16.14153 40.86528 30.97198
#> 3 15.826869 15.49014 39.12603 29.55695
#> 4 19.427777 14.83017 37.45841 28.28364
#> 
```
