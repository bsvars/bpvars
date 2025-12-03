# Plots forecast error variance decompositions

Plots of the posterior means of the forecast error variance
decompositions.

## Usage

``` r
# S3 method for class 'PosteriorFEVDPANEL'
plot(
  x,
  which_c,
  cols,
  main,
  xlab,
  mar.multi = c(1, 4.6, 0, 4.6),
  oma.multi = c(6, 0, 5, 0),
  ...
)
```

## Arguments

- x:

  an object of class `PosteriorFEVDPANEL` obtained using the
  [`compute_variance_decompositions()`](https://bsvars.org/bsvars/reference/compute_variance_decompositions.html)
  function containing posterior draws of forecast error variance
  decompositions.

- which_c:

  a positive integer or a character string specifying the country for
  which the forecast should be plotted.

- cols:

  an `N`-vector with colours of the plot

- main:

  an alternative main title for the plot

- xlab:

  an alternative x-axis label for the plot

- mar.multi:

  the default `mar` argument setting in
  [`graphics::par`](https://rdrr.io/r/graphics/par.html). Modify with
  care!

- oma.multi:

  the default `oma` argument setting in
  [`graphics::par`](https://rdrr.io/r/graphics/par.html). Modify with
  care!

- ...:

  additional arguments affecting the summary produced.

## See also

[`compute_variance_decompositions.PosteriorBVARPANEL`](http://bsvars.org/bpvars/reference/compute_variance_decompositions.PosteriorBVARPANEL.md)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

set.seed(123) specification = specify_bvarPANEL\$new(ilo_dynamic_panel)

\# run the burn-in burn_in = estimate(specification, 10)

\# estimate the model posterior = estimate(burn_in, 20)

\# compute forecast error variance decomposition 4 years ahead fevd =
compute_variance_decompositions(posterior, horizon = 4) plot(fevd,
which_c = "POL")

\# workflow with the pipe \|\>
\############################################################
ilo_dynamic_panel \|\> specify_bvarPANEL\$new() \|\> estimate(S = 10)
\|\> estimate(S = 20) \|\> compute_variance_decompositions(horizon = 4)
\|\> plot(which_c = "POL")
