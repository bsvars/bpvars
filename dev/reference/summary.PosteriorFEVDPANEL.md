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

[`compute_variance_decompositions.PosteriorBVARPANEL`](http://bsvars.org/bpvars/dev/reference/compute_variance_decompositions.PosteriorBVARPANEL.md),
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
#>      shock1   shock2    shock3   shock4
#> 0 100.00000 0.000000  0.000000 0.000000
#> 1  79.93511 3.877991  9.599204 6.587692
#> 2  75.38226 4.755798 11.776970 8.084973
#> 3  73.25548 5.163007 12.793445 8.788067
#> 4  71.92934 5.414857 13.426604 9.229199
#> 
#> $variable2
#>     shock1     shock2   shock3   shock4
#> 0 99.11616  0.8838404  0.00000  0.00000
#> 1 24.19604 13.9027212 36.15280 25.74844
#> 2 35.29146 11.8278322 30.79779 22.08291
#> 3 44.80417 10.0664660 26.24912 18.88024
#> 4 52.27973  8.7197760 22.69414 16.30635
#> 
#> $variable3
#>     shock1     shock2    shock3   shock4
#> 0 97.13292  0.7069129  2.160164  0.00000
#> 1 38.21472 11.9593880 29.364472 20.46142
#> 2 48.86635 10.0683438 24.328229 16.73708
#> 3 58.81272  8.1606088 19.638191 13.38848
#> 4 66.13938  6.7220519 16.173237 10.96533
#> 
#> $variable4
#>      shock1   shock2   shock3   shock4
#> 0  2.045532 17.31837 45.54282 35.09328
#> 1  6.382634 17.20801 44.20574 32.20362
#> 2 10.160923 16.58500 42.50027 30.75381
#> 3 13.499662 16.00331 40.96070 29.53634
#> 4 16.388527 15.48891 39.61671 28.50586
#> 
```
