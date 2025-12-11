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
#> 1  76.80679 4.527049 10.87857  7.787591
#> 2  72.38872 5.390142 12.95445  9.266696
#> 3  70.52143 5.754196 13.83236  9.892020
#> 4  69.50057 5.952687 14.31253 10.234214
#> 
#> $variable2
#>     shock1    shock2   shock3    shock4
#> 0 99.76671  0.233294  0.00000  0.000000
#> 1 75.35201  4.129105 11.44495  9.073933
#> 2 46.65358 11.154031 25.20396 16.988420
#> 3 37.73641 13.007585 29.48036 19.775649
#> 4 36.17285 13.350616 30.23699 20.239545
#> 
#> $variable3
#>     shock1    shock2    shock3   shock4
#> 0 87.33092  3.917518  8.751565  0.00000
#> 1 17.69196 16.149691 38.968385 27.18996
#> 2 23.20075 15.010779 36.321781 25.46669
#> 3 28.45582 13.947167 33.809472 23.78755
#> 4 32.73424 13.096640 31.769349 22.39977
#> 
#> $variable4
#>     shock1   shock2   shock3   shock4
#> 0 14.90064 14.91793 38.70686 31.47457
#> 1 12.78404 17.35410 41.08824 28.77362
#> 2 13.47204 17.34021 40.84352 28.34423
#> 3 14.23894 17.23460 40.50940 28.01705
#> 4 14.91345 17.12631 40.20574 27.75451
#> 
```
