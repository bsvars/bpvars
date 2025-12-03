# Computes posterior draws of the forecast error variance decomposition

For each country, each of the draws from the posterior estimation of the
model is transformed into a draw from the posterior distribution of the
forecast error variance decomposition.

## Usage

``` r
# S3 method for class 'PosteriorBVARs'
compute_variance_decompositions(posterior, horizon)
```

## Arguments

- posterior:

  posterior estimation outcome - an object of class `PosteriorBVARs`
  obtained by running the `estimate` function.

- horizon:

  a positive integer number denoting the forecast horizon for the
  forecast error variance decompositions.

## Value

An object of class `PosteriorFEVDPANEL`, that is, a list with `C`
elements containing `NxNx(horizon+1)xS` arrays of class `PosteriorFEVD`
with `S` draws of country-specific forecast error variance
decompositions.

## References

Lütkepohl, H. (2017). Structural VAR Tools, Chapter 4, In: Structural
vector autoregressive analysis. Cambridge University Press.

## See also

[`estimate.PosteriorBVARs`](http://bsvars.org/bpvars/reference/estimate.PosteriorBVARs.md),
[`summary.PosteriorFEVDPANEL`](http://bsvars.org/bpvars/reference/summary.PosteriorFEVDPANEL.md),
[`plot.PosteriorFEVDPANEL`](http://bsvars.org/bpvars/reference/plot.PosteriorFEVDPANEL.md)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
# specify the model and set seed
specification  = specify_bvars$new(ilo_dynamic_panel) # specify the model

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

# workflow with the pipe |>
############################################################
ilo_dynamic_panel |>
  specify_bvars$new() |>
  estimate(S = 5) |> 
  estimate(S = 5) |> 
  compute_variance_decompositions(horizon = 4) -> fevd
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
```
