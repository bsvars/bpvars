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
#>      shock1   shock2   shock3   shock4
#> 0 100.00000 0.000000  0.00000  0.00000
#> 1  55.14564 8.333962 21.01598 15.50442
#> 2  51.25294 9.049484 22.83205 16.86553
#> 3  50.67966 9.150187 23.09440 17.07575
#> 4  50.91502 9.102225 22.97937 17.00338
#> 
#> $variable2
#>      shock1     shock2   shock3   shock4
#> 0 99.757687  0.2423133  0.00000  0.00000
#> 1 16.590224 15.1098584 39.03328 29.26663
#> 2  7.456284 17.1833199 43.42945 31.93094
#> 3  6.097043 17.5627570 44.11028 32.22992
#> 4  5.433189 17.7415733 44.44758 32.37765
#> 
#> $variable3
#>      shock1    shock2    shock3   shock4
#> 0 89.214273  3.636383  7.149345  0.00000
#> 1  7.528932 17.211336 43.412698 31.84703
#> 2  8.115889 17.086502 43.130839 31.66677
#> 3  8.422017 17.029023 42.986806 31.56215
#> 4  8.591678 17.007768 42.910908 31.48965
#> 
#> $variable4
#>     shock1   shock2   shock3   shock4
#> 0 5.770586 16.29000 43.22620 34.71321
#> 1 6.291287 17.57632 44.01894 32.11345
#> 2 6.009583 17.64004 44.16063 32.18975
#> 3 5.786061 17.68467 44.26866 32.26061
#> 4 5.630155 17.71505 44.34344 32.31136
#> 
```
