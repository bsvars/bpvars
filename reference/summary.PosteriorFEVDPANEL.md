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
#>      shock1   shock2   shock3   shock4
#> 0 100.00000 0.000000 0.000000 0.000000
#> 1  92.01773 1.489338 3.764526 2.728402
#> 2  88.89019 2.073795 5.242622 3.793395
#> 3  87.15418 2.398340 6.064017 4.383461
#> 4  86.04829 2.605084 6.587549 4.759078
#> 
#> $variable2
#>     shock1     shock2   shock3   shock4
#> 0 99.80440  0.1955989  0.00000  0.00000
#> 1 47.15633 10.2021509 24.98482 17.65670
#> 2 42.58891 10.7794446 27.16183 19.46982
#> 3 45.20733 10.1865894 25.89788 18.70820
#> 4 48.25579  9.5776889 24.44221 17.72431
#> 
#> $variable3
#>     shock1   shock2   shock3   shock4
#> 0 84.84273  4.78400 10.37327  0.00000
#> 1 41.05127 10.78645 27.96811 20.19417
#> 2 42.02000 10.53729 27.41532 20.02740
#> 3 39.13782 11.11680 28.78072 20.96467
#> 4 37.74574 11.43203 29.44223 21.38001
#> 
#> $variable4
#>     shock1   shock2   shock3   shock4
#> 0  1.72972 16.85206 45.20519 36.21303
#> 1 13.44329 15.55381 40.42832 30.57458
#> 2 21.05218 14.24410 36.90563 27.79809
#> 3 27.72322 13.06935 33.79856 25.40887
#> 4 33.57647 12.03802 31.07483 23.31068
#> 
```
