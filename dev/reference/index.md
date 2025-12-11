# Package index

## bpvars: Forecasting with Bayesian Hierarchical Panel VARs

Browse package information

- [`bpvars-package`](http://bsvars.org/bpvars/dev/reference/bpvars-package.md)
  [`bpvars`](http://bsvars.org/bpvars/dev/reference/bpvars-package.md) :
  Forecasting with Bayesian Panel Vector Autoregressions

## Data

Upload sample data set

- [`ilo_dynamic_panel`](http://bsvars.org/bpvars/dev/reference/ilo_dynamic_panel.md)
  : A 4-variable annual system for forecasting labour market outcomes
  for 189 countries from 1991 to 2024

- [`ilo_dynamic_panel_missing`](http://bsvars.org/bpvars/dev/reference/ilo_dynamic_panel_missing.md)
  : A 4-variable annual system for forecasting labour market outcomes
  for 189 countries to 2024 containing only actual observations

- [`ilo_exogenous_forecasts`](http://bsvars.org/bpvars/dev/reference/ilo_exogenous_forecasts.md)
  :

  Data containing future observations for 189 United Nations countries
  from 2025 to 2029 to be used to forecast with models with
  `ilo_exogenous_variables`

- [`ilo_exogenous_variables`](http://bsvars.org/bpvars/dev/reference/ilo_exogenous_variables.md)
  : A 3-variable annual system for of dummy observations for 2008, 2020,
  and 2021 to be used in the estimation of the Panel VAR model for 189
  countries from 1991 to 2024

- [`ilo_exogenous_variables_missing`](http://bsvars.org/bpvars/dev/reference/ilo_exogenous_variables_missing.md)
  :

  A 3-variable annual system for of dummy observations for 2008, 2020,
  and 2021 to be used in the estimation of the Panel VAR model for 189
  countries to 2024 containing observations for matching periods from
  `ilo_dynamic_panel_missing`

- [`country_grouping_incomegroup`](http://bsvars.org/bpvars/dev/reference/country_grouping_incomegroup.md)
  : A vector with country grouping by income group for 189 countries

- [`country_grouping_region`](http://bsvars.org/bpvars/dev/reference/country_grouping_region.md)
  : A vector with country grouping by region for 189 countries

- [`country_grouping_subregionbroad`](http://bsvars.org/bpvars/dev/reference/country_grouping_subregionbroad.md)
  : A vector with country grouping by subregion for 189 countries

- [`country_grouping_subregiondetailed`](http://bsvars.org/bpvars/dev/reference/country_grouping_subregiondetailed.md)
  : A vector with country grouping by detailed subregion for 189
  countries

## Model specification

Choose a model to work with

- [`specify_bvarPANEL`](http://bsvars.org/bpvars/dev/reference/specify_bvarPANEL.md)
  : R6 Class representing the specification of the BVARPANEL model
- [`specify_bvarGroupPANEL`](http://bsvars.org/bpvars/dev/reference/specify_bvarGroupPANEL.md)
  : R6 Class representing the specification of the BVARGROUPPANEL model
- [`specify_bvarGroupPriorPANEL`](http://bsvars.org/bpvars/dev/reference/specify_bvarGroupPriorPANEL.md)
  : R6 Class representing the specification of the BVARGROUPPRIORPANEL
  model
- [`specify_bvars`](http://bsvars.org/bpvars/dev/reference/specify_bvars.md)
  : R6 Class representing the specification of the BVARs model

## More detailed model specification

Adjust or inspect the specified model

- [`specify_prior_bvarPANEL`](http://bsvars.org/bpvars/dev/reference/specify_prior_bvarPANEL.md)
  : R6 Class Representing PriorBVARPANEL
- [`specify_prior_bvars`](http://bsvars.org/bpvars/dev/reference/specify_prior_bvars.md)
  : R6 Class Representing PriorBVARs
- [`specify_starting_values_bvarGroupPANEL`](http://bsvars.org/bpvars/dev/reference/specify_starting_values_bvarGroupPANEL.md)
  : R6 Class Representing StartingValuesBVARGROUPPANEL
- [`specify_starting_values_bvarGroupPriorPANEL`](http://bsvars.org/bpvars/dev/reference/specify_starting_values_bvarGroupPriorPANEL.md)
  : R6 Class Representing StartingValuesBVARGROUPPRIORPANEL
- [`specify_starting_values_bvarPANEL`](http://bsvars.org/bpvars/dev/reference/specify_starting_values_bvarPANEL.md)
  : R6 Class Representing StartingValuesBVARPANEL
- [`specify_starting_values_bvars`](http://bsvars.org/bpvars/dev/reference/specify_starting_values_bvars.md)
  : R6 Class Representing StartingValuesBVARs
- [`specify_panel_data_matrices`](http://bsvars.org/bpvars/dev/reference/specify_panel_data_matrices.md)
  : R6 Class Representing DataMatricesBVARPANEL

## Estimation

Run Bayesian estimation of your model and inspect the outputs

- [`estimate(`*`<BVARGROUPPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/estimate.BVARGROUPPANEL.md)
  : Bayesian estimation of a Bayesian Hierarchical Panel Vector
  Autoregression with fixed or estimated country grouping
- [`estimate(`*`<BVARGROUPPRIORPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/estimate.BVARGROUPPRIORPANEL.md)
  : Bayesian estimation of a Bayesian Hierarchical Panel Vector
  Autoregression with fixed or estimated country grouping for global
  priors
- [`estimate(`*`<BVARPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/estimate.BVARPANEL.md)
  : Bayesian estimation of a Bayesian Hierarchical Panel Vector
  Autoregression using Gibbs sampler
- [`estimate(`*`<BVARs>`*`)`](http://bsvars.org/bpvars/dev/reference/estimate.BVARs.md)
  : Bayesian estimation of a Bayesian Hierarchical Vector
  Autoregressions for cubic data using Gibbs sampler
- [`estimate(`*`<PosteriorBVARGROUPPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/estimate.PosteriorBVARGROUPPANEL.md)
  : Bayesian estimation of a Bayesian Hierarchical Panel Vector
  Autoregression with fixed or estimated country grouping
- [`estimate(`*`<PosteriorBVARGROUPPRIORPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/estimate.PosteriorBVARGROUPPRIORPANEL.md)
  : Bayesian estimation of a Bayesian Hierarchical Panel Vector
  Autoregression with fixed or estimated country grouping for global
  priors
- [`estimate(`*`<PosteriorBVARPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/estimate.PosteriorBVARPANEL.md)
  : Bayesian estimation of a Bayesian Hierarchical Panel Vector
  Autoregression using Gibbs sampler
- [`estimate(`*`<PosteriorBVARs>`*`)`](http://bsvars.org/bpvars/dev/reference/estimate.PosteriorBVARs.md)
  : Bayesian estimation of a Bayesian Hierarchical Vector
  Autoregressions for cubic data using Gibbs sampler
- [`specify_posterior_bvarGroupPANEL`](http://bsvars.org/bpvars/dev/reference/specify_posterior_bvarGroupPANEL.md)
  : R6 Class Representing PosteriorBVARGROUPPANEL
- [`specify_posterior_bvarGroupPriorPANEL`](http://bsvars.org/bpvars/dev/reference/specify_posterior_bvarGroupPriorPANEL.md)
  : R6 Class Representing PosteriorBVARGROUPPRIORPANEL
- [`specify_posterior_bvarPANEL`](http://bsvars.org/bpvars/dev/reference/specify_posterior_bvarPANEL.md)
  : R6 Class Representing PosteriorBVARPANEL
- [`specify_posterior_bvars`](http://bsvars.org/bpvars/dev/reference/specify_posterior_bvars.md)
  : R6 Class Representing PosteriorBVARs

## Posterior summaries

Analyse the posterior summaries of the posterior estimation outcomes

- [`summary(`*`<ForecastsPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/summary.ForecastsPANEL.md)
  : Provides posterior summary of country-specific Forecasts
- [`summary(`*`<PosteriorBVARGROUPPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/summary.PosteriorBVARGROUPPANEL.md)
  : Provides posterior estimation summary for Bayesian Hierarchical
  Panel Vector Autoregressions
- [`summary(`*`<PosteriorBVARGROUPPRIORPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/summary.PosteriorBVARGROUPPRIORPANEL.md)
  : Provides posterior estimation summary for Bayesian Hierarchical
  Panel Vector Autoregressions with group-specific global prior
- [`summary(`*`<PosteriorBVARPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/summary.PosteriorBVARPANEL.md)
  : Provides posterior estimation summary for Bayesian Hierarchical
  Panel Vector Autoregressions
- [`summary(`*`<PosteriorBVARs>`*`)`](http://bsvars.org/bpvars/dev/reference/summary.PosteriorBVARs.md)
  : Provides posterior estimation summary for Bayesian Vector
  Autoregressions for dynamic panel data
- [`summary(`*`<PosteriorFEVDPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/summary.PosteriorFEVDPANEL.md)
  : Provides posterior summary of forecast error variance decompositions

## Forecasting

Predict future values of your variables

- [`forecast(`*`<PosteriorBVARGROUPPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/forecast.PosteriorBVARGROUPPANEL.md)
  : Forecasting using Hierarchical Panel Vector Autoregressions
- [`forecast(`*`<PosteriorBVARGROUPPRIORPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/forecast.PosteriorBVARGROUPPRIORPANEL.md)
  : Forecasting using Hierarchical Panel Vector Autoregressions
- [`forecast(`*`<PosteriorBVARPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/forecast.PosteriorBVARPANEL.md)
  : Forecasting using Hierarchical Panel Vector Autoregressions
- [`forecast(`*`<PosteriorBVARs>`*`)`](http://bsvars.org/bpvars/dev/reference/forecast.PosteriorBVARs.md)
  : Forecasting using Hierarchical Vector Autoregressions for Dynamic
  Panel Data

## Pseudo-out-of-sample Forecasting

Verify forecating performance of models.

- [`specify_poosf_exercise`](http://bsvars.org/bpvars/dev/reference/specify_poosf_exercise.md)
  : R6 Class Representing specification of the pseudo-out-of-sample
  forecasting exercise
- [`forecast_poos_recursively(`*`<BVARGROUPPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.BVARGROUPPANEL.md)
  : Bayesian recursive pseudo-out-of-sample forecasting
- [`forecast_poos_recursively(`*`<BVARGROUPPRIORPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.BVARGROUPPRIORPANEL.md)
  : Bayesian recursive pseudo-out-of-sample forecasting
- [`forecast_poos_recursively(`*`<BVARPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.BVARPANEL.md)
  : Bayesian recursive pseudo-out-of-sample forecasting
- [`forecast_poos_recursively(`*`<BVARs>`*`)`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.BVARs.md)
  : Bayesian recursive pseudo-out-of-sample forecasting
- [`forecast_poos_recursively()`](http://bsvars.org/bpvars/dev/reference/forecast_poos_recursively.md)
  : Bayesian recursive pseudo-out-of-sample forecasting
- [`compute_forecast_performance(`*`<ForecastsPANELpoos>`*`)`](http://bsvars.org/bpvars/dev/reference/compute_forecast_performance.ForecastsPANELpoos.md)
  : Computes forecasting performance measures for recursive
  pseudo-out-of-sample forecasts
- [`compute_forecast_performance()`](http://bsvars.org/bpvars/dev/reference/compute_forecast_performance.md)
  : Computes forecasting performance measures for recursive
  pseudo-out-of-sample forecasts

## Structural analyses

Compute interpretable outcomes

- [`compute_forecast_performance(`*`<ForecastsPANELpoos>`*`)`](http://bsvars.org/bpvars/dev/reference/compute_forecast_performance.ForecastsPANELpoos.md)
  : Computes forecasting performance measures for recursive
  pseudo-out-of-sample forecasts
- [`compute_forecast_performance()`](http://bsvars.org/bpvars/dev/reference/compute_forecast_performance.md)
  : Computes forecasting performance measures for recursive
  pseudo-out-of-sample forecasts
- [`compute_variance_decompositions(`*`<PosteriorBVARGROUPPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/compute_variance_decompositions.PosteriorBVARGROUPPANEL.md)
  : Computes posterior draws of the forecast error variance
  decomposition
- [`compute_variance_decompositions(`*`<PosteriorBVARPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/compute_variance_decompositions.PosteriorBVARPANEL.md)
  : Computes posterior draws of the forecast error variance
  decomposition
- [`compute_variance_decompositions(`*`<PosteriorBVARs>`*`)`](http://bsvars.org/bpvars/dev/reference/compute_variance_decompositions.PosteriorBVARs.md)
  : Computes posterior draws of the forecast error variance
  decomposition

## Plot your results

Prepare beautiful and informative plots for your analyses

- [`plot(`*`<ForecastsPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/plot.ForecastsPANEL.md)
  : Plots fitted values of dependent variables
- [`plot(`*`<PosteriorFEVDPANEL>`*`)`](http://bsvars.org/bpvars/dev/reference/plot.PosteriorFEVDPANEL.md)
  : Plots forecast error variance decompositions
