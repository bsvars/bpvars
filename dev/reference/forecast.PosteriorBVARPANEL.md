# Forecasting using Hierarchical Panel Vector Autoregressions

Samples from the joint predictive density of the dependent variables for
all countries at forecast horizons from 1 to `horizon` specified as an
argument of the function. Also implements conditional forecasting based
on the provided projections for some of the variables.

## Usage

``` r
# S3 method for class 'PosteriorBVARPANEL'
forecast(
  object,
  horizon = 1,
  exogenous_forecast = NULL,
  conditional_forecast = NULL,
  ...
)
```

## Arguments

- object:

  posterior estimation outcome - an object of class `PosteriorBVARPANEL`
  obtained by running the `estimate` function.

- horizon:

  a positive integer, specifying the forecasting horizon.

- exogenous_forecast:

  not used here ATM; included for compatibility with generic `forecast`.

- conditional_forecast:

  a list of length `C` containing `horizon x N` matrices with forecasted
  values for selected variables. These matrices should only contain
  `numeric` or `NA` values. The entries with `NA` values correspond to
  the values that are forecasted conditionally on the realisations
  provided as `numeric` values.

- ...:

  not used

## Value

A list of class `ForecastsPANEL` with `C` elements containing the draws
from the country-specific predictive density and data in a form of
object class `Forecasts` that includes:

- forecasts:

  an `NxhorizonxS` array with the draws from the country-specific
  predictive density

- forecast_mean:

  an `NxhorizonxS` array with the mean of the country-specific
  predictive density

- forecast_cov:

  an `NxNxhorizonxS` array with the covariance of the country-specific
  predictive density

- Y:

  a `T_cxN` matrix with the country-specific data

## Details

The package provides a range of options regarding the forecasting
procedure. They are dependent on the model and forecast specifications
and include Bayesian forecasting many periods ahead, conditional
forecasting, and forecasting for models with exogenous variables.

**One-period-ahead predictive density.** The model assumptions provided
in the documentation for
[`bpvars`](http://bsvars.org/bpvars/dev/reference/bpvars-package.md)
determine the country-specific one-period ahead conditional predictive
density for the unknown vector \\\mathbf{y}\_{c.t+1}\\ given the data
available at time \\t\\ and the parameters of the model. It is
multivariate normal with the mean \\\mathbf{A}\_c' \mathbf{x}\_{c.t+1}\\
and the covariance matrix \\\mathbf{\Sigma}\_c\\
\$\$p(\mathbf{y}\_{c.t+1} \| \mathbf{x}\_{c.t+1}, \mathbf{A}\_c,
\mathbf{\Sigma}\_c) = N_N(\mathbf{A}\_c' \mathbf{x}\_{c.t+1},
\mathbf{\Sigma}\_c)\$\$ where \\\mathbf{x}\_{c.t+1}\\ includes the
lagged values of \\\mathbf{y}\_{c.t+1}\\, the constant term, and,
potentially, exogenous variables if they were specified by the user.

**Bayesian predictive density.** The one-period ahead predictive density
is used to sample from the joint predictive density of the unknown
future values. This predictive density is defined as a joint density of
\\\mathbf{y}\_{c.t+h}\\ at horizons \\h = 1,\dots,H\\, where \\H\\
corresponds to the value of argument `horizon`, given the data available
at time \\t\\: \$\$p( \mathbf{y}\_{c.T_c + H}, \dots,
\mathbf{y}\_{c.T_c + 1} \| \mathbf{Y}\_c, \mathbf{X}\_c) = \int
p(\mathbf{y}\_{c.T_c + H}, \dots, \mathbf{y}\_{c.T_c + 1} \|
\mathbf{Y}\_c, \mathbf{X}\_c, \mathbf{A}\_c, \boldsymbol\Sigma_c) p(
\mathbf{A}\_c, \boldsymbol\Sigma_c \| \mathbf{Y}\_c, \mathbf{X}\_c)
d(\mathbf{A}\_c, \boldsymbol\Sigma_c)\$\$ Therefore, the Bayesian
forecast does not depend on the parameter values as the parameters are
integrated out with respect to their posterior distribution.
Consequently, Bayesian forecasts incorporate the uncertainty with
respect to estimation. Sampling from the density is facilitated using
the draws from the posterior density and sequential sampling from the
one-period ahead predictive density.

**Conditional forecasting** of some of the variables given the future
values of the remaining variables is implemented following Waggoner and
Zha (1999) and is based on the conditional normal density given the
future projections of some of the variables created basing on the
one-period ahead predictive density.

**Exogenous variables.** Forecasting with models for which specification
argument `exogenous_variables` was specified required providing the
future values of these exogenous variables in the argument
`exogenous_forecast` of the `forecast.PosteriorBVARPANEL` function.

**Truncated forecasts for variables of type 'rate'.** The package
provides the option to truncate the forecasts for variables of for which
the corresponding element of argument `type` of the function
`specify_bvarPANEL$new()` is set to `"rate"`. The one-period-ahead
predictive normal density for such variables is truncated to values from
interval \\\[0,100\]\\.

## References

Waggoner, D. F., & Zha, T. (1999) Conditional forecasts in dynamic
multivariate models, *Review of Economics and Statistics*, **81**(4),
639-651,
[doi:10.1162/003465399558508](https://doi.org/10.1162/003465399558508) .

## See also

[`specify_bvarPANEL`](http://bsvars.org/bpvars/dev/reference/specify_bvarPANEL.md),
[`estimate.PosteriorBVARPANEL`](http://bsvars.org/bpvars/dev/reference/estimate.PosteriorBVARPANEL.md),
[`summary.ForecastsPANEL`](http://bsvars.org/bpvars/dev/reference/summary.ForecastsPANEL.md),
[`plot.ForecastsPANEL`](http://bsvars.org/bpvars/dev/reference/plot.ForecastsPANEL.md)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
# specify the model
specification = specify_bvarPANEL$new(
  ilo_dynamic_panel[1:5], 
  exogenous = ilo_exogenous_variables[1:5]
)
burn_in       = estimate(specification, 5)             # run the burn-in; use say S = 10000
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
posterior     = estimate(burn_in, 5)                   # estimate the model; use say S = 10000
#> **************************************************|
#> bpvars: Forecasting with Bayesian Panel VARs      |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|

# forecast 5 years ahead
predictive    = forecast(posterior, 5, exogenous_forecast = ilo_exogenous_forecasts[1:5])
```
