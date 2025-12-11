# R6 Class Representing specification of the pseudo-out-of-sample forecasting exercise

The class `POOSForecastSetup` presents the specification of the
recursive pseudo-out-of-sample forecasting exercise using expanding
window samples.

## Public fields

- `S`:

  a positive integer number - the number of MCMC draws from the
  posterior distribution in the estimation for each forecasts

- `S_burn`:

  a positive integer number - the number of MCMC draws from to achieve
  convergence in the estimation for each forecasts

- `horizons`:

  a vector with positive integer numbers - the forecast horizons used in
  the forecast performance evaluation

- `training_sample`:

  a positive integer number - the number of of the first observations to
  be used in the estimation for the first forecast

## Methods

### Public methods

- [`specify_poosf_exercise$new()`](#method-POOSForecastSetup-new)

- [`specify_poosf_exercise$clone()`](#method-POOSForecastSetup-clone)

------------------------------------------------------------------------

### Method `new()`

Create a new specification `POOSForecastSetup` of the recursive
pseudo-out-of-sample forecasting exercise using expanding window
samples.

#### Usage

    specify_poosf_exercise$new(
      spec,
      S,
      S_burn,
      horizons = 1L,
      training_sample = 1L
    )

#### Arguments

- `spec`:

  a model specification object of class `BVARPANEL` or `BVARGROUPPANEL`.

- `S`:

  a positive integer - number of draws from the posterior distribution
  for model estimation for each of the forecasts

- `S_burn`:

  a positive integer - number of draws from the posterior distribution
  to obtain convergence for model estimation for each of the forecasts

- `horizons`:

  a vector with positive integers - forecast horizons at which
  forecasting performance is to be verified

- `training_sample`:

  a positive integer - the number of the first observations to be used
  for estimation for the first forecast. The number of observations to
  be used for remaining forecasts increases recursively by one for each
  forecast.

#### Returns

A new specification `POOSForecastSetup` of the recursive
pseudo-out-of-sample forecasting exercise using expanding window
samples.

#### Examples

    spec = specify_bvarPANEL$new(ilo_dynamic_panel)
    poos = specify_poosf_exercise$new(spec, 5000, 1000, 1:2, 10)

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_poosf_exercise$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
spec = specify_bvarPANEL$new(ilo_dynamic_panel)
poos = specify_poosf_exercise$new(spec, 5000, 1000, 1:2, 10)


## ------------------------------------------------
## Method `specify_poosf_exercise$new`
## ------------------------------------------------

spec = specify_bvarPANEL$new(ilo_dynamic_panel)
poos = specify_poosf_exercise$new(spec, 5000, 1000, 1:2, 10)
```
