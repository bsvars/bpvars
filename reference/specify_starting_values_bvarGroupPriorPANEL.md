# R6 Class Representing StartingValuesBVARGROUPPRIORPANEL

The class StartingValuesBVARGROUPPRIORPANEL presents starting values for
the Bayesian hierarchical panel VAR model with country grouping

## Public fields

- `group_allocation`:

  a numeric vector with integer numbers denoting group allocations

- `A_c`:

  an `KxNxC` array of starting values for the local parameter
  \\\mathbf{A}\_c\\.

- `Sigma_c`:

  an `NxNxC` array of starting values for the local parameter
  \\\mathbf{\Sigma}\_c\\.

- `A_g`:

  an `KxNxG` array of starting values for the group parameter
  \\\mathbf{A}\_g\\.

- `Sigma_g`:

  an `NxNxG` array of starting values for the group parameter
  \\\mathbf{\Sigma}\_g\\.

- `V`:

  an `KxK` matrix of starting values for the global parameter
  \\\mathbf{V}\\.

- `nu`:

  a positive scalar with starting values for the global parameter
  \\\nu\\.

- `m`:

  a positive scalar with starting values for the global hyper-parameter
  \\m\\.

- `w`:

  a positive scalar with starting values for the global hyper-parameter
  \\w\\.

- `s`:

  a positive scalar with starting values for the global hyper-parameter
  \\s\\.

## Methods

### Public methods

- [`specify_starting_values_bvarGroupPriorPANEL$new()`](#method-StartingValuesBVARGROUPPRIORPANEL-new)

- [`specify_starting_values_bvarGroupPriorPANEL$get_starting_values()`](#method-StartingValuesBVARGROUPPRIORPANEL-get_starting_values)

- [`specify_starting_values_bvarGroupPriorPANEL$set_starting_values()`](#method-StartingValuesBVARGROUPPRIORPANEL-set_starting_values)

- [`specify_starting_values_bvarGroupPriorPANEL$clone()`](#method-StartingValuesBVARGROUPPRIORPANEL-clone)

------------------------------------------------------------------------

### Method `new()`

Create new starting values StartingValuesBVARGROUPPRIORPANEL

#### Usage

    specify_starting_values_bvarGroupPriorPANEL$new(
      group_allocation = 1:C,
      C,
      G = C,
      N,
      p,
      d = 0
    )

#### Arguments

- `group_allocation`:

  a numeric vector with integer numbers denoting group allocations

- `C`:

  a positive integer - the number of countries in the data.

- `G`:

  a positive integer specifying the number of country groups.

- `N`:

  a positive integer - the number of dependent variables in the model.

- `p`:

  a positive integer - the autoregressive lag order of the SVAR model.

- `d`:

  a positive integer - the number of `exogenous` variables in the model.

#### Returns

Starting values StartingValuesBVARGROUPPRIORPANEL

#### Examples

    # starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
    sv = specify_starting_values_bvarGroupPriorPANEL$new(C = 2, N = 3, p = 1)

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the elements of the starting values
StartingValuesBVARGROUPPRIORPANEL as a `list`.

#### Usage

    specify_starting_values_bvarGroupPriorPANEL$get_starting_values()

#### Examples

    # starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
    sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
    sv$get_starting_values()   # show starting values as list

------------------------------------------------------------------------

### Method `set_starting_values()`

Returns the elements of the starting values
StartingValuesBVARGROUPPRIORPANEL as a `list`.

#### Usage

    specify_starting_values_bvarGroupPriorPANEL$set_starting_values(last_draw)

#### Arguments

- `last_draw`:

  a list containing the same elements as object
  StartingValuesBVARGROUPPRIORPANEL

#### Returns

An object of class StartingValuesBVARGROUPPRIORPANEL including the last
draw of the current MCMC as the starting value to be passed to the
continuation of the MCMC estimation.

#### Examples

    sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, N = 3, p = 1)

    # Modify the starting values by:
    sv_list = sv$get_starting_values()   # getting them as list
    sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
    sv$set_starting_values(sv_list)      # providing to the class object

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_starting_values_bvarGroupPriorPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
# starting values for a Bayesian Panel VAR
sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, G = 1, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPriorPANEL$new`
## ------------------------------------------------

# starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
sv = specify_starting_values_bvarGroupPriorPANEL$new(C = 2, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPriorPANEL$get_starting_values`
## ------------------------------------------------

# starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
sv$get_starting_values()   # show starting values as list
#> $group_allocation
#> [1] 1 1
#> 
#> $A_c
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0011003661  0.0006001271  0.0001182690
#> [2,]  0.0008171051 -0.0001301168  0.0009465865
#> [3,] -0.0003676317 -0.0011533128 -0.0021120164
#> [4,] -0.0024841396  0.0006822916 -0.0009790050
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -6.592729e-05  0.0011109604  1.910629e-04
#> [2,] -6.506028e-04 -0.0006861017 -2.079917e-04
#> [3,]  4.075969e-04 -0.0003911923  7.054235e-05
#> [4,] -4.934374e-04 -0.0004688196 -1.033980e-03
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]       [,2]       [,3]
#> [1,]  6.252341 -3.6811414 -2.6851580
#> [2,] -3.681141  7.8984985 -0.6108036
#> [3,] -2.685158 -0.6108036  3.7461015
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  4.153735 -1.646584  2.876977
#> [2,] -1.646584  2.969162 -3.378243
#> [3,]  2.876977 -3.378243  6.349352
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]         [,2]          [,3]
#> [1,] -0.0008219457 0.0008905035  0.0010587674
#> [2,]  0.0005527502 0.0002662757  0.0017988898
#> [3,] -0.0003344043 0.0005475784 -0.0005457019
#> [4,]  0.0014638467 0.0010124334 -0.0013972984
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0004298641  0.0011260263  0.0006950837
#> [2,]  0.0010603571  0.0002877816  0.0012867668
#> [3,] -0.0001226077 -0.0009789860 -0.0006679526
#> [4,] -0.0001117256  0.0002176344  0.0001261971
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>             [,1]       [,2]        [,3]
#> [1,]  4.88885513  1.3321990 -0.06907003
#> [2,]  1.33219902  6.6928930 -0.64570615
#> [3,] -0.06907003 -0.6457062  1.38274153
#> 
#> , , 2
#> 
#>          [,1]      [,2]      [,3]
#> [1,] 2.172281 1.2765835 1.2436203
#> [2,] 1.276584 1.5865556 0.6518044
#> [3,] 1.243620 0.6518044 2.0115002
#> 
#> 
#> $V
#>            [,1]       [,2]       [,3]       [,4]
#> [1,]  3.5797681 -5.5881616 -0.8589817  0.1232808
#> [2,] -5.5881616 12.2950598 -0.6331375 -3.3095180
#> [3,] -0.8589817 -0.6331375  4.3137394  0.3298978
#> [4,]  0.1232808 -3.3095180  0.3298978  3.6741831
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0008459696
#> 
#> $w
#> [1] 1.32957
#> 
#> $s
#> [1] 0.5501601
#> 


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPriorPANEL$set_starting_values`
## ------------------------------------------------

sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, N = 3, p = 1)

# Modify the starting values by:
sv_list = sv$get_starting_values()   # getting them as list
sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
sv$set_starting_values(sv_list)      # providing to the class object
```
