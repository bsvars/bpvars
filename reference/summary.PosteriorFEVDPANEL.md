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
#>      shock1    shock2   shock3   shock4
#> 0 100.00000  0.000000  0.00000  0.00000
#> 1  52.47700  8.667721 22.42000 16.43528
#> 2  42.60683 10.471100 27.08710 19.83497
#> 3  38.19962 11.279071 29.17345 21.34786
#> 4  35.67999 11.742537 30.36712 22.21035
#> 
#> $variable2
#>     shock1     shock2   shock3   shock4
#> 0 99.68962  0.3103785  0.00000  0.00000
#> 1 58.50565  6.9938721 19.82316 14.67732
#> 2 41.52526  9.8030863 27.91465 20.75701
#> 3 38.90548 10.2634199 29.08355 21.74755
#> 4 38.61655 10.4703426 29.14046 21.77265
#> 
#> $variable3
#>      shock1     shock2    shock3   shock4
#> 0 97.763863  0.5462981  1.689839  0.00000
#> 1  2.658713 17.6973106 46.261517 33.38246
#> 2  5.041860 17.2334653 45.084003 32.64067
#> 3  8.047810 16.6750020 43.633958 31.64323
#> 4 10.720598 16.1868823 42.353480 30.73904
#> 
#> $variable4
#>      shock1   shock2   shock3   shock4
#> 0 0.9971876 16.70805 45.33350 36.96126
#> 1 1.6850489 17.99715 46.34403 33.97377
#> 2 3.1276955 17.86940 45.77805 33.22485
#> 3 4.6597584 17.63606 45.08750 32.61668
#> 4 6.1210601 17.38820 44.40964 32.08110
#> 
```
