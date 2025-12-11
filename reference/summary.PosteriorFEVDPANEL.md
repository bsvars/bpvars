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
#> 1  93.49655 1.233838 3.059083 2.210526
#> 2  93.62044 1.211213 3.002291 2.166058
#> 3  93.78946 1.180585 2.923710 2.106241
#> 4  93.63686 1.211295 2.996031 2.155814
#> 
#> $variable2
#>     shock1     shock2   shock3   shock4
#> 0 99.81468  0.1853188  0.00000  0.00000
#> 1 21.20064 15.1912933 37.15150 26.45657
#> 2 18.76788 15.5783999 38.28773 27.36598
#> 3 21.38052 15.0621450 37.04493 26.51240
#> 4 24.93382 14.3735811 35.36000 25.33260
#> 
#> $variable3
#>     shock1    shock2    shock3   shock4
#> 0 89.85532  3.262663  6.882017  0.00000
#> 1 22.93704 14.562361 36.361489 26.13911
#> 2 10.80289 16.966454 42.057399 30.17326
#> 3 11.10793 16.926005 41.905657 30.06041
#> 4 12.43848 16.681064 41.273980 29.60648
#> 
#> $variable4
#>     shock1   shock2   shock3   shock4
#> 0 3.765592 17.03450 44.37188 34.82803
#> 1 3.451170 18.35241 45.47593 32.72049
#> 2 3.258445 18.40015 45.57429 32.76712
#> 3 3.907011 18.27808 45.26993 32.54498
#> 4 4.934603 18.08159 44.78573 32.19808
#> 
```
