# R6 Class representing the specification of the BVARPANEL model

The class BVARPANEL presents complete specification for the Bayesian
Panel Vector Autoregression.

## References

Jarocinski (2010). Responses to monetary policy shocks in the east and
the west of Europe: a comparison. *Journal of Applied Econometrics*,
**25**(5), 833-868,
[doi:10.1002/jae.1082](https://doi.org/10.1002/jae.1082) .

Dieppe, Legrand, Roye (2016). The BEAR toolbox, *ECB Working Papers*,
**1934**, [doi:10.2866/292952](https://doi.org/10.2866/292952) .

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

- [`specify_bvarPANEL$new()`](#method-BVARPANEL-new)

- [`specify_bvarPANEL$set_to_Jarocinski()`](#method-BVARPANEL-set_to_Jarocinski)

- [`specify_bvarPANEL$get_data_matrices()`](#method-BVARPANEL-get_data_matrices)

- [`specify_bvarPANEL$get_prior()`](#method-BVARPANEL-get_prior)

- [`specify_bvarPANEL$get_starting_values()`](#method-BVARPANEL-get_starting_values)

- [`specify_bvarPANEL$get_type()`](#method-BVARPANEL-get_type)

- [`specify_bvarPANEL$set_global2pooled()`](#method-BVARPANEL-set_global2pooled)

- [`specify_bvarPANEL$set_adaptiveMH()`](#method-BVARPANEL-set_adaptiveMH)

- [`specify_bvarPANEL$clone()`](#method-BVARPANEL-clone)

------------------------------------------------------------------------

### Method `new()`

Create a new specification of the Bayesian Panel VAR model BVARPANEL.

#### Usage

    specify_bvarPANEL$new(
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

### Method `set_to_Jarocinski()`

Sets the model in line with the specification by Jarocinski (2010) as
presented by Dieppe, Legrand, Roye (2016).

#### Usage

    specify_bvarPANEL$set_to_Jarocinski()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$set_to_Jarocinski()

------------------------------------------------------------------------

### Method `get_data_matrices()`

Returns the data matrices as the DataMatricesBVARPANEL object.

#### Usage

    specify_bvarPANEL$get_data_matrices()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$get_data_matrices()

------------------------------------------------------------------------

### Method `get_prior()`

Returns the prior specification as the PriorBVARPANEL object.

#### Usage

    specify_bvarPANEL$get_prior()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$get_prior()

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the starting values as the StartingValuesBVARPANEL object.

#### Usage

    specify_bvarPANEL$get_starting_values()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$get_starting_values()

------------------------------------------------------------------------

### Method `get_type()`

Returns the type of the model.

#### Usage

    specify_bvarPANEL$get_type()

#### Examples

    spec = specify_bvarPANEL$new(
       data = ilo_dynamic_panel
    )
    spec$get_type()

------------------------------------------------------------------------

### Method `set_global2pooled()`

Sets the prior mean of the global autoregressive parameters to the OLS
pooled panel estimator following Zellner, Hong (1989).

#### Usage

    specify_bvarPANEL$set_global2pooled(x)

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

    specify_bvarPANEL$set_adaptiveMH(x)

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

    specify_bvarPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)


## ------------------------------------------------
## Method `specify_bvarPANEL$set_to_Jarocinski`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$set_to_Jarocinski()
#> Setting the model in line with the specification by Jarocinski (2010).


## ------------------------------------------------
## Method `specify_bvarPANEL$get_data_matrices`
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
## Method `specify_bvarPANEL$get_prior`
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
## Method `specify_bvarPANEL$get_starting_values`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$get_starting_values()
#> <StartingValuesBVARPANEL>
#>   Public:
#>     A: 0.999184654246418 -0.000122955529859343 -0.0002204288885 ...
#>     A_c: 0.000958987646831118 0.00146119924438324 0.0002753157311 ...
#>     Sigma: 6.04172025905973 3.85999096391708 1.55229459646048 -4.01 ...
#>     Sigma_c: 4.10681795427254 1.66364242529196 -0.888757149982237 1.0 ...
#>     V: 3.78855061508357 1.70506270146202 -3.43491714686499 1.48 ...
#>     clone: function (deep = FALSE) 
#>     get_starting_values: function () 
#>     initialize: function (C, N, p, d = 0) 
#>     m: -0.000163403232322895
#>     nu: 5.1
#>     s: 1.53561682665133
#>     set_starting_values: function (last_draw) 
#>     w: 0.833380257705374


## ------------------------------------------------
## Method `specify_bvarPANEL$get_type`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$get_type()
#> [1] "wozniak"


## ------------------------------------------------
## Method `specify_bvarPANEL$set_global2pooled`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$set_global2pooled()


## ------------------------------------------------
## Method `specify_bvarPANEL$set_adaptiveMH`
## ------------------------------------------------

spec = specify_bvarPANEL$new(
   data = ilo_dynamic_panel
)
spec$set_adaptiveMH(c(0.6, 0.4, 10, 0.1))
```
