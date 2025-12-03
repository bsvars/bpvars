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
#> 1  91.48994 1.581167 3.980771 2.948125
#> 2  92.33585 1.420122 3.583424 2.660602
#> 3  93.20997 1.258975 3.174750 2.356302
#> 4  93.55928 1.199534 3.012706 2.228477
#> 
#> $variable2
#>     shock1     shock2   shock3   shock4
#> 0 99.72783  0.2721722  0.00000  0.00000
#> 1 16.02301 15.3936594 39.27332 29.31001
#> 2 12.61728 16.4055113 40.96717 30.01003
#> 3 11.93560 16.6388505 41.30167 30.12388
#> 4 12.82127 16.5074444 40.89390 29.77738
#> 
#> $variable3
#>      shock1    shock2   shock3   shock4
#> 0 94.542155  1.966705  3.49114  0.00000
#> 1  7.375659 17.484085 43.42457 31.71569
#> 2  8.227434 17.305183 43.02298 31.44440
#> 3  8.774574 17.199575 42.76671 31.25914
#> 4  9.094480 17.146167 42.61822 31.14114
#> 
#> $variable4
#>     shock1   shock2   shock3   shock4
#> 0 3.802507 16.91672 44.28487 34.99590
#> 1 7.268911 17.62622 43.46892 31.63595
#> 2 7.995827 17.50314 43.13454 31.36650
#> 3 8.645774 17.38512 42.83168 31.13743
#> 4 9.268371 17.26995 42.54045 30.92123
#> 
```
