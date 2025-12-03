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
#> 0 100.00000 0.000000  0.00000 0.000000
#> 1  74.52856 4.695738 11.91727 8.858427
#> 2  72.71220 5.028370 12.76662 9.492807
#> 3  72.00496 5.154603 13.09654 9.743896
#> 4  71.51919 5.239692 13.32276 9.918362
#> 
#> $variable2
#>     shock1     shock2   shock3   shock4
#> 0 99.76055  0.2394522  0.00000  0.00000
#> 1 11.72140 16.5172628 41.34511 30.41623
#> 2 14.13011 15.9552933 40.23915 29.67544
#> 3 18.29541 15.1912618 38.29563 28.21770
#> 4 23.17402 14.2841203 36.01141 26.53044
#> 
#> $variable3
#>      shock1     shock2    shock3   shock4
#> 0 97.961010  0.4672265  1.571763  0.00000
#> 1 23.960848 13.9602238 35.682775 26.39615
#> 2  5.167706 17.6132397 44.477368 32.74169
#> 3  7.167924 17.2275910 43.541209 32.06328
#> 4 11.164398 16.4711228 41.663754 30.70073
#> 
#> $variable4
#>      shock1   shock2   shock3   shock4
#> 0  5.279048 16.55401 43.56200 34.60494
#> 1  2.267532 18.07670 45.77931 33.87646
#> 2  4.832712 17.62205 44.59571 32.94953
#> 3  8.718613 16.90743 42.77834 31.59562
#> 4 11.855174 16.32785 41.30955 30.50742
#> 
```
