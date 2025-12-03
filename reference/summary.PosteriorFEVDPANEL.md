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
#>      shock1     shock2     shock3     shock4
#> 0 100.00000 0.00000000 0.00000000 0.00000000
#> 1  99.83585 0.02682889 0.08431266 0.05300554
#> 2  99.67847 0.05224017 0.16450330 0.10478298
#> 3  99.56014 0.07125628 0.22456785 0.14403857
#> 4  99.48440 0.08337824 0.26290372 0.16932244
#> 
#> $variable2
#>     shock1    shock2   shock3   shock4
#> 0 99.37742 0.6225757  0.00000  0.00000
#> 1 49.37474 8.0418340 26.35049 16.23294
#> 2 46.36159 8.4566029 27.89829 17.28352
#> 3 48.27001 8.1841703 26.83524 16.71059
#> 4 50.22249 7.9144370 25.77072 16.09235
#> 
#> $variable3
#>     shock1   shock2    shock3   shock4
#> 0 88.67535 2.219918  9.104734  0.00000
#> 1 52.13302 7.908355 24.939039 15.01959
#> 2 50.75247 8.067261 25.484042 15.69623
#> 3 46.86590 8.655342 27.426515 17.05224
#> 4 42.80855 9.286821 29.476047 18.42858
#> 
#> $variable4
#>     shock1    shock2   shock3   shock4
#> 0 18.45476 11.907125 38.95375 30.68437
#> 1 32.37528 10.383045 33.51708 23.72460
#> 2 38.60182  9.558236 30.71933 21.12062
#> 3 43.19425  8.892766 28.51016 19.40283
#> 4 46.84133  8.352305 26.72707 18.07929
#> 
```
