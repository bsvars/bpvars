# R6 Class Representing StartingValuesBVARGROUPPANEL

The class StartingValuesBVARGROUPPANEL presents starting values for the
Bayesian hierarchical panel VAR model with country grouping

## Super class

`bpvars::StartingValuesBVARPANEL` -\> `StartingValuesBVARGROUPPANEL`

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

- `A`:

  an `KxN` matrix of starting values for the global parameter
  \\\mathbf{A}\\.

- `V`:

  an `KxK` matrix of starting values for the global parameter
  \\\mathbf{V}\\.

- `Sigma`:

  an `NxN` matrix of starting values for the global parameter
  \\\mathbf{\Sigma}\\.

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

- [`specify_starting_values_bvarGroupPANEL$new()`](#method-StartingValuesBVARGROUPPANEL-new)

- [`specify_starting_values_bvarGroupPANEL$get_starting_values()`](#method-StartingValuesBVARGROUPPANEL-get_starting_values)

- [`specify_starting_values_bvarGroupPANEL$set_starting_values()`](#method-StartingValuesBVARGROUPPANEL-set_starting_values)

- [`specify_starting_values_bvarGroupPANEL$clone()`](#method-StartingValuesBVARGROUPPANEL-clone)

------------------------------------------------------------------------

### Method `new()`

Create new starting values StartingValuesBVARGROUPPANEL

#### Usage

    specify_starting_values_bvarGroupPANEL$new(
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

Starting values StartingValuesBVARGROUPPANEL

#### Examples

    # starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
    sv = specify_starting_values_bvarGroupPANEL$new(C = 2, N = 3, p = 1)

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the elements of the starting values StartingValuesBVARGROUPPANEL
as a `list`.

#### Usage

    specify_starting_values_bvarGroupPANEL$get_starting_values()

#### Examples

    # starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
    sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
    sv$get_starting_values()   # show starting values as list

------------------------------------------------------------------------

### Method `set_starting_values()`

Returns the elements of the starting values StartingValuesBVARGROUPPANEL
as a `list`.

#### Usage

    specify_starting_values_bvarGroupPANEL$set_starting_values(last_draw)

#### Arguments

- `last_draw`:

  a list containing the same elements as object
  StartingValuesBVARGROUPPANEL

#### Returns

An object of class StartingValuesBVARGROUPPANEL including the last draw
of the current MCMC as the starting value to be passed to the
continuation of the MCMC estimation.

#### Examples

    sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)

    # Modify the starting values by:
    sv_list = sv$get_starting_values()   # getting them as list
    sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
    sv$set_starting_values(sv_list)      # providing to the class object

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_starting_values_bvarGroupPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
# starting values for a Bayesian Panel VAR
sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, G = 1, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPANEL$new`
## ------------------------------------------------

# starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
sv = specify_starting_values_bvarGroupPANEL$new(C = 2, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPANEL$get_starting_values`
## ------------------------------------------------

# starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
sv$get_starting_values()   # show starting values as list
#> $group_allocation
#> [1] 1 1
#> 
#> $A_c
#> , , 1
#> 
#>              [,1]          [,2]          [,3]
#> [1,] 0.0016860818 -0.0003088479 -0.0011403395
#> [2,] 0.0007977034 -0.0004500043 -0.0006436148
#> [3,] 0.0016534063 -0.0001349406 -0.0007088088
#> [4,] 0.0013713083  0.0001928349  0.0017923485
#> 
#> , , 2
#> 
#>              [,1]          [,2]          [,3]
#> [1,] 0.0016860818 -0.0003088479 -0.0011403395
#> [2,] 0.0007977034 -0.0004500043 -0.0006436148
#> [3,] 0.0016534063 -0.0001349406 -0.0007088088
#> [4,] 0.0013713083  0.0001928349  0.0017923485
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]     [,2]      [,3]
#> [1,]  2.075662 1.038548 -1.728535
#> [2,]  1.038548 3.233662  5.046581
#> [3,] -1.728535 5.046581 20.770036
#> 
#> , , 2
#> 
#>           [,1]     [,2]      [,3]
#> [1,]  2.075662 1.038548 -1.728535
#> [2,]  1.038548 3.233662  5.046581
#> [3,] -1.728535 5.046581 20.770036
#> 
#> 
#> $A_g
#> , , 1
#> 
#>              [,1]          [,2]          [,3]
#> [1,] 0.0016860818 -0.0003088479 -0.0011403395
#> [2,] 0.0007977034 -0.0004500043 -0.0006436148
#> [3,] 0.0016534063 -0.0001349406 -0.0007088088
#> [4,] 0.0013713083  0.0001928349  0.0017923485
#> 
#> , , 2
#> 
#>              [,1]          [,2]          [,3]
#> [1,] 0.0009060524 -0.0002965164  8.038298e-04
#> [2,] 0.0012043226 -0.0012039358 -6.934490e-04
#> [3,] 0.0009729893 -0.0003432903  2.035650e-04
#> [4,] 0.0010815928 -0.0003300619  6.797035e-05
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]     [,2]      [,3]
#> [1,]  2.075662 1.038548 -1.728535
#> [2,]  1.038548 3.233662  5.046581
#> [3,] -1.728535 5.046581 20.770036
#> 
#> , , 2
#> 
#>           [,1]      [,2]     [,3]
#> [1,]  5.928473 -1.925869 2.303893
#> [2,] -1.925869  4.434928 3.302554
#> [3,]  2.303893  3.302554 9.109933
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  0.9991202760 -0.0005524014 -0.0011701283
#> [2,]  0.0012846187  1.0015057267  0.0005864505
#> [3,]  0.0001002139 -0.0012956886  1.0000807217
#> [4,] -0.0009289870  0.0007889948  0.0012598499
#> 
#> $V
#>            [,1]      [,2]       [,3]       [,4]
#> [1,]  3.9003799  2.572603 -0.8553888  0.1835568
#> [2,]  2.5726030  6.332141 -1.3002247  1.9854408
#> [3,] -0.8553888 -1.300225  8.3584767 -1.4617415
#> [4,]  0.1835568  1.985441 -1.4617415  2.1286706
#> 
#> $Sigma
#>           [,1]      [,2]      [,3]
#> [1,]  2.976947 -4.405514  2.799985
#> [2,] -4.405514 14.331649 -7.975509
#> [3,]  2.799985 -7.975509  5.758237
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.000780444
#> 
#> $w
#> [1] 0.2960391
#> 
#> $s
#> [1] 0.1673768
#> 


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPANEL$set_starting_values`
## ------------------------------------------------

sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)

# Modify the starting values by:
sv_list = sv$get_starting_values()   # getting them as list
sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
sv$set_starting_values(sv_list)      # providing to the class object
```
