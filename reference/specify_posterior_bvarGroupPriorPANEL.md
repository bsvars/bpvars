# R6 Class Representing PosteriorBVARGROUPPRIORPANEL

The class PosteriorBVARGROUPPRIORPANEL contains posterior output and the
specification including the last MCMC draw for the Bayesian Panel VAR
model with country grouping. Note that due to the thinning of the MCMC
output the starting value in element `last_draw` might not be equal to
the last draw provided in element `posterior`.

## See also

[`specify_bvarGroupPriorPANEL`](http://bsvars.org/bpvars/reference/specify_bvarGroupPriorPANEL.md)

## Super classes

`PosteriorBVARPANEL` -\> `PosteriorBVARGROUPPANEL` -\>
`PosteriorBVARGROUPPRIORPANEL`

## Public fields

- `last_draw`:

  an object of class BVARGROUPPRIORPANEL with the last draw of the
  current MCMC run as the starting value to be passed to the
  continuation of the MCMC estimation using
  [`estimate()`](https://bsvars.org/bsvars/reference/estimate.html).

- `posterior`:

  a list containing Bayesian estimation output.

## Methods

### Public methods

- [`PosteriorBVARGROUPPRIORPANEL$new()`](#method-PosteriorBVARGROUPPRIORPANEL-initialize)

- [`PosteriorBVARGROUPPRIORPANEL$clone()`](#method-PosteriorBVARGROUPPRIORPANEL-clone)

Inherited methods

- `PosteriorBVARPANEL$get_last_draw()`
- `PosteriorBVARPANEL$get_posterior()`

------------------------------------------------------------------------

### `PosteriorBVARGROUPPRIORPANEL$new()`

Create a new posterior output PosteriorBVARGROUPPRIORPANEL.

#### Usage

    PosteriorBVARGROUPPRIORPANEL$new(specification, posterior)

#### Arguments

- `specification`:

  an object of class BVARGROUPPRIORPANEL with the last draw of the
  current MCMC run as the starting value.

- `posterior`:

  a list containing Bayesian estimation output.

#### Returns

A posterior output PosteriorBVARGROUPPRIORPANEL.

------------------------------------------------------------------------

### `PosteriorBVARGROUPPRIORPANEL$clone()`

The objects of this class are cloneable with this method.

#### Usage

    PosteriorBVARGROUPPRIORPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
spec = specify_bvarGroupPriorPANEL$new(
   data = ilo_dynamic_panel[1:5],
   G = 2
)
#> Country groupings will be estimated.
#posterior       = estimate(specification, 5)
#class(posterior)
```
