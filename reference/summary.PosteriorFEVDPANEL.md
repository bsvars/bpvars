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
#> 1  61.92785  6.847123 18.03564 13.18938
#> 2  47.76518  9.386804 24.73955 18.10847
#> 3  40.68414 10.655298 28.08995 20.57062
#> 4  36.53824 11.398004 30.05161 22.01215
#> 
#> $variable2
#>      shock1     shock2   shock3   shock4
#> 0 99.770674  0.2293261  0.00000  0.00000
#> 1 24.994009 13.4466268 35.41305 26.14631
#> 2  6.191528 16.8584849 44.39190 32.55809
#> 3  5.581244 16.9359161 44.67408 32.80876
#> 4  5.677230 16.9169960 44.63133 32.77445
#> 
#> $variable3
#>      shock1    shock2     shock3   shock4
#> 0 99.032562  0.218516  0.7489219  0.00000
#> 1  1.995132 17.548688 46.4088960 34.04728
#> 2  2.024759 17.535199 46.3851493 34.05489
#> 3  3.913601 17.202667 45.4834763 33.40025
#> 4  5.541382 16.926221 44.7058978 32.82650
#> 
#> $variable4
#>     shock1   shock2   shock3   shock4
#> 0 1.351344 16.59710 45.47142 36.58014
#> 1 2.926321 17.46990 45.97059 33.63320
#> 2 2.671342 17.51165 46.08804 33.72897
#> 3 2.485148 17.54189 46.17334 33.79962
#> 4 2.348044 17.56440 46.23637 33.85119
#> 
```
