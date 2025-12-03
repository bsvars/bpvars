# Bayesian estimation of a Bayesian Hierarchical Panel Vector Autoregression using Gibbs sampler

Estimates the Bayesian Hierarchical Panel VAR using the Gibbs sampler
proposed by Sanchez-Martinez & Woźniak (2024).

## Usage

``` r
# S3 method for class 'PosteriorBVARPANEL'
estimate(specification, S, thin = 1, show_progress = TRUE)
```

## Arguments

- specification:

  an object of class `PosteriorBVARPANEL` generated using the
  [`estimate.BVARPANEL()`](http://bsvars.org/bpvars/reference/estimate.BVARPANEL.md)
  function. This setup facilitates the continuation of the MCMC sampling
  starting from the last draw of the previous run.

- S:

  a positive integer, the number of posterior draws to be generated

- thin:

  a positive integer, specifying the frequency of MCMC output thinning

- show_progress:

  a logical value, if `TRUE` the estimation progress bar is visible

## Value

An object of class `PosteriorBVARPANEL` containing the Bayesian
estimation output and containing two elements:

- `posterior`:

  a list with a collection of `S` draws from the posterior distribution
  generated via Gibbs sampler. Elements of the list correspond to the
  parameters of the model listed in section **Details** and are named
  respectively: `A_c`, `Sigma_c`, `A`, `Sigma`, `V`, `nu`, `m`, `w`,
  `s`.

- `last_draw`:

  an object of class `BVARPANEL` with the last draw of the current MCMC
  run as the starting value to be passed to the continuation of the MCMC
  estimation using the
  [`estimate()`](https://bsvars.org/bsvars/reference/estimate.html)
  method.

## Details

The Bayesian Hierarchical Panel Vector Autoregressive model described in
[`bpvars`](http://bsvars.org/bpvars/reference/bpvars-package.md) is
estimated using the Gibbs sampler. In this estimation procedure all the
parameters of the model are estimated jointly. The list of parameters of
the model includes:

- \\\mathbf{A}\_c\\:

  a `KxN` country-specific autoregressive parameters matrix for each of
  the countries \\c = 1,\dots,C\\

- \\\mathbf{\Sigma}\_c\\:

  an `NxN` country-specific covariance matrix for each of the countries
  \\c = 1,\dots,C\\

- \\\mathbf{A}\\:

  a `KxN` global autoregressive parameters matrix

- \\\mathbf{\Sigma}\\:

  an `NxN` global covariance matrix

- \\\mathbf{V}\\:

  a `KxK` covariance matrix of prior for global autoregressive
  parameters

- \\\nu\\:

  prior degrees of freedom parameter

- \\m\\:

  prior average global persistence parameter

- \\w\\:

  prior scaling parameter

- \\s\\:

  prior scaling parameter

**Gibbs sampler** is an algorithm to sample random draws from the
posterior distribution of the parameters of the model given the data.
The algorithm is briefly explained on an example of a two-parameter
model with parameters \\\theta_1\\ and \\\theta_2\\. In order to sample
from the joint posterior distribution
\\p(\theta_1,\theta_2\|\mathbf{Y})\\ the Gibbs sampler proceeds by
sampling from full-conditional posterior distributions of each parameter
given data and all the other parameters, denoted by
\\p(\theta_1\|\theta_2,\mathbf{Y})\\ and
\\p(\theta_2\|\theta_1,\mathbf{Y})\\. These distributions are available
from derivations and should be in a form of distributions that are easy
to sample random numbers from.

To obtain `S` draws from the posterior distribution:

1.  Set the initial values of the parameters \\\theta_2^{(0)}\\

2.  At each of the `s` iterations:

    1.  Sample \\\theta_1^{(s)}\\ from
        \\p(\theta_1\|\theta_2^{(s-1)},\mathbf{Y})\\

    2.  Sample \\\theta_2^{(s)}\\ from
        \\p(\theta_2\|\theta_1^{(s)},\mathbf{Y})\\

3.  Repeat step 2. `S` times. Return
    \\\\\theta_1^{(s)},\theta_2^{(s)}\\\_{s=1}^{S}\\ as a sample drawn
    from the posterior distribution
    \\p(\theta_1,\theta_2\|\mathbf{Y})\\.

The [`estimate()`](https://bsvars.org/bsvars/reference/estimate.html)
function returns the draws from the posterior distribution of the
parameters of the hierarchical panel VAR model listed above.

**Thinning.** Thinning is a procedure to reduce the dependence in the
returned sample from the posterior distribution. It is obtained by
returning every `thin` draw in the final sample. This procedure reduces
the number of draws returned by the
[`estimate()`](https://bsvars.org/bsvars/reference/estimate.html)
function.

## See also

[`bpvars`](http://bsvars.org/bpvars/reference/bpvars-package.md),
[`specify_bvarPANEL`](http://bsvars.org/bpvars/reference/specify_bvarPANEL.md),
[`specify_posterior_bvarPANEL`](http://bsvars.org/bpvars/reference/specify_posterior_bvarPANEL.md),
[`summary.PosteriorBVARPANEL`](http://bsvars.org/bpvars/reference/summary.PosteriorBVARPANEL.md),
[`forecast.PosteriorBVARPANEL`](http://bsvars.org/bpvars/reference/forecast.PosteriorBVARPANEL.md)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
# specify the model
specification = specify_bvarPANEL$new(
  ilo_dynamic_panel[1:5], 
  exogenous = ilo_exogenous_variables[1:5]
)
burn_in       = estimate(specification, 10)             # run the burn-in; use say S = 10000
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 10 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
posterior     = estimate(burn_in, 10)                   # estimate the model; use say S = 10000
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 10 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
```
