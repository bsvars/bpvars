# R6 Class representing the specification of the BVARs model

The class BVARs presents complete specification for the Bayesian Vector
Autoregressions for cubic data.

## References

Zellner (1971). *An Introduction to Bayesian Inference in Econometrics*.
John Wiley & Sons.

Zellner, Hong (1989). Forecasting international growth rates using
Bayesian shrinkage and other procedures. *Journal of Econometrics*,
**40**(1), 183–202,
[doi:10.1016/0304-4076(89)90036-5](https://doi.org/10.1016/0304-4076%2889%2990036-5)
.

## Public fields

- `p`:

  a non-negative integer specifying the autoregressive lag order of the
  model.

- `prior`:

  an object PriorBSVAR with the prior specification.

- `data_matrices`:

  an object DataMatricesBVARPANEL with the data matrices.

- `starting_values`:

  an object StartingValuesBVARPANEL with the starting values.

- `adaptiveMH`:

  a vector of four values setting the adaptive MH sampler for nu:
  adaptive rate, target acceptance rate, the iteration at which to start
  adapting, the initial scaling rate

## Methods

### Public methods

- [`specify_bvars$new()`](#method-BVARs-new)

- [`specify_bvars$get_data_matrices()`](#method-BVARs-get_data_matrices)

- [`specify_bvars$get_prior()`](#method-BVARs-get_prior)

- [`specify_bvars$get_starting_values()`](#method-BVARs-get_starting_values)

- [`specify_bvars$get_type()`](#method-BVARs-get_type)

- [`specify_bvars$set_prior2objective()`](#method-BVARs-set_prior2objective)

- [`specify_bvars$set_global2pooled()`](#method-BVARs-set_global2pooled)

- [`specify_bvars$set_adaptiveMH()`](#method-BVARs-set_adaptiveMH)

- [`specify_bvars$clone()`](#method-BVARs-clone)

------------------------------------------------------------------------

### Method `new()`

Create a new specification of the Bayesian Panel VAR model BVARPANEL.

#### Usage

    specify_bvars$new(
      data,
      p = 1L,
      exogenous = NULL,
      stationary = rep(FALSE, ncol(data[[1]])),
      type = rep("real", ncol(data[[1]]))
    )

#### Arguments

- `data`:

  a list with `C` elements of `(T_c+p)xN` matrices with time series
  data.

- `p`:

  a positive integer providing model's autoregressive lag order.

- `exogenous`:

  a `(T+p)xd` matrix of exogenous variables.

- `stationary`:

  an `N` logical vector - its element set to `FALSE` sets the prior mean
  for the autoregressive parameters of the `N`th equation to the white
  noise process, otherwise to random walk.

- `type`:

  an `N` character vector with elements set to "rate" or "real"
  determining the truncation of the predictive density to `[0, 100]` and
  `(-Inf, Inf)` (no truncation) for each of the variables.

#### Returns

A new complete specification for the Bayesian Panel VAR model BVARPANEL.

------------------------------------------------------------------------

### Method `get_data_matrices()`

Returns the data matrices as the DataMatricesBVARPANEL object.

#### Usage

    specify_bvars$get_data_matrices()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$get_data_matrices()

------------------------------------------------------------------------

### Method `get_prior()`

Returns the prior specification as the PriorBVARPANEL object.

#### Usage

    specify_bvars$get_prior()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$get_prior()

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the starting values as the StartingValuesBVARPANEL object.

#### Usage

    specify_bvars$get_starting_values()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$get_starting_values()

------------------------------------------------------------------------

### Method `get_type()`

Returns the type of the model.

#### Usage

    specify_bvars$get_type()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$get_type()

------------------------------------------------------------------------

### Method `set_prior2objective()`

Sets the VAR model priors to objective prior by Zellner (1972).

#### Usage

    specify_bvars$set_prior2objective()

#### Examples

    spec = specify_bvars$new(
       data = ilo_dynamic_panel
    )
    spec$set_prior2objective()

------------------------------------------------------------------------

### Method `set_global2pooled()`

Sets the prior mean of the global autoregressive parameters to the OLS
pooled panel estimator following Zellner, Hong (1989).

#### Usage

    specify_bvars$set_global2pooled(x)

#### Arguments

- `x`:

  a vector of four values setting the adaptive MH sampler for nu:
  adaptive rate, target acceptance rate, the iteration at which to start
  adapting, the initial scaling rate

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$set_global2pooled()

------------------------------------------------------------------------

### Method `set_adaptiveMH()`

Sets the parameters of adaptive Metropolis-Hastings sampler for the
parameter nu.

#### Usage

    specify_bvars$set_adaptiveMH(x)

#### Arguments

- `x`:

  a vector of four values setting the adaptive MH sampler for nu:
  adaptive rate, target acceptance rate, the iteration at which to start
  adapting, the initial scaling rate

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$set_adaptiveMH(c(0.6, 0.4, 10, 0.1))

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_bvars$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
spec = specify_bvars$new(
   data = ilo_dynamic_panel
)


## ------------------------------------------------
## Method `specify_bvars$get_data_matrices`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$get_data_matrices()
#> <DataMatricesBVARPANEL>
#>   Public:
#>     Y: list
#>     clone: function (deep = FALSE) 
#>     exogenous: list
#>     get_data_matrices: function () 
#>     initialize: function (data, p = 1L, exogenous = NULL, type = rep("real", 
#>     missing: list
#>     type: real real real real


## ------------------------------------------------
## Method `specify_bvars$get_prior`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$get_prior()
#> <PriorBVARPANEL>
#>   Public:
#>     M: 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0
#>     S_Sigma_inv: 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1
#>     S_inv: 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1
#>     W: 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 10
#>     a_w: 1
#>     clone: function (deep = FALSE) 
#>     eta: 5
#>     get_prior: function () 
#>     initialize: function (C, N, p, d = 0, stationary = rep(FALSE, N)) 
#>     lambda: 72
#>     mu_Sigma: 5
#>     mu_m: 1
#>     nu_s: 3
#>     s_s: 1
#>     s_w: 1
#>     sigma2_m: 1


## ------------------------------------------------
## Method `specify_bvars$get_starting_values`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$get_starting_values()
#> <StartingValuesBVARPANEL>
#>   Public:
#>     A: 0.999484509020105 0.000301987260622982 -0.00015600973335 ...
#>     A_c: -0.000209075913579391 0.000207887796294898 0.00011838536 ...
#>     Sigma: 7.91979829973189 -0.480799582456285 -1.65567890818491 0. ...
#>     Sigma_c: 5.93331381179812 -7.46446023578263 -1.06431233760195 0.0 ...
#>     V: 3.31483080822823 -1.47638933652599 -0.010256570678192 1. ...
#>     clone: function (deep = FALSE) 
#>     get_starting_values: function () 
#>     initialize: function (C, N, p, d = 0) 
#>     m: -0.00219072501021409
#>     nu: 5.1
#>     s: 0.23014745331408
#>     set_starting_values: function (last_draw) 
#>     w: 0.471185393453785


## ------------------------------------------------
## Method `specify_bvars$get_type`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$get_type()
#> [1] "wozniak"


## ------------------------------------------------
## Method `specify_bvars$set_prior2objective`
## ------------------------------------------------

spec = specify_bvars$new(
   data = ilo_dynamic_panel
)
spec$set_prior2objective()
#> Setting the model priors to objective prior by Zellner (1972).


## ------------------------------------------------
## Method `specify_bvars$set_global2pooled`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$set_global2pooled()


## ------------------------------------------------
## Method `specify_bvars$set_adaptiveMH`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$set_adaptiveMH(c(0.6, 0.4, 10, 0.1))
```
