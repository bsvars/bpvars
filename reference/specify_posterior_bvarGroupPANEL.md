# R6 Class Representing PosteriorBVARGROUPPANEL

The class PosteriorBVARGROUPPANEL contains posterior output and the
specification including the last MCMC draw for the Bayesian Panel VAR
model with country grouping. Note that due to the thinning of the MCMC
output the starting value in element `last_draw` might not be equal to
the last draw provided in element `posterior`.

## See also

[`specify_bvarGroupPANEL`](http://bsvars.org/bpvars/reference/specify_bvarGroupPANEL.md)

## Super class

`bpvars::PosteriorBVARPANEL` -\> `PosteriorBVARGROUPPANEL`

## Public fields

- `last_draw`:

  an object of class BVARGROUPPANEL with the last draw of the current
  MCMC run as the starting value to be passed to the continuation of the
  MCMC estimation using
  [`estimate()`](https://bsvars.org/bsvars/reference/estimate.html).

- `posterior`:

  a list containing Bayesian estimation output.

## Methods

### Public methods

- [`specify_posterior_bvarGroupPANEL$new()`](#method-PosteriorBVARGROUPPANEL-new)

- [`specify_posterior_bvarGroupPANEL$clone()`](#method-PosteriorBVARGROUPPANEL-clone)

Inherited methods

- [`bpvars::PosteriorBVARPANEL$get_last_draw()`](http://bsvars.org/bpvars/reference/PosteriorBVARPANEL.html#method-get_last_draw)
- [`bpvars::PosteriorBVARPANEL$get_posterior()`](http://bsvars.org/bpvars/reference/PosteriorBVARPANEL.html#method-get_posterior)

------------------------------------------------------------------------

### Method `new()`

Create a new posterior output PosteriorBVARGROUPPANEL.

#### Usage

    specify_posterior_bvarGroupPANEL$new(specification, posterior)

#### Arguments

- `specification`:

  an object of class BVARGROUPPANEL with the last draw of the current
  MCMC run as the starting value.

- `posterior`:

  a list containing Bayesian estimation output.

#### Returns

A posterior output PosteriorBVARGROUPPANEL.

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_posterior_bvarGroupPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
spec = specify_bvarGroupPANEL$new(
   data = ilo_dynamic_panel[1:5],
   G = 2
)
#> Country groupings will be estimated.
#posterior       = estimate(specification, 5)
#class(posterior)
```
