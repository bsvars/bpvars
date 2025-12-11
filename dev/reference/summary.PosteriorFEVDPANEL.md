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
#> 0 100.00000 0.000000  0.00000 0.000000
#> 1  78.36769 4.145173 10.10677 7.380365
#> 2  74.36504 4.906710 11.97650 8.751742
#> 3  72.62082 5.236436 12.79074 9.352007
#> 4  71.61947 5.424322 13.25778 9.698422
#> 
#> $variable2
#>     shock1     shock2   shock3   shock4
#> 0 99.79067  0.2093324  0.00000  0.00000
#> 1 36.21033 11.4787467 29.79434 22.51659
#> 2 38.47217 11.1835851 28.68396 21.66029
#> 3 41.57991 10.6725680 27.21573 20.53179
#> 4 44.28126 10.2062094 25.94867 19.56385
#> 
#> $variable3
#>     shock1     shock2    shock3   shock4
#> 0 97.14754  0.9013905  1.951069  0.00000
#> 1 36.37056 12.1531950 29.824734 21.65152
#> 2 35.77078 12.2065645 29.943071 22.07958
#> 3 35.41458 12.2579507 30.061982 22.26548
#> 4 35.30836 12.2700485 30.096138 22.32545
#> 
#> $variable4
#>      shock1    shock2   shock3   shock4
#> 0  8.025159 16.221353 42.01528 33.73820
#> 1 15.264398 15.332531 38.90865 30.49442
#> 2 30.527711 12.543261 31.90807 25.02096
#> 3 42.340137 10.381877 26.50591 20.77208
#> 4 49.213067  9.150889 23.37668 18.25937
#> 
```
