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
#> [1,] -0.0008440736 -0.0010570009  0.0013218345
#> [2,]  0.0001356895  0.0013494694  0.0007421787
#> [3,]  0.0011945959 -0.0002554048 -0.0016742426
#> [4,]  0.0002958495 -0.0008440394 -0.0004807163
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0006568324 -0.0005098224  0.0002384746
#> [2,]  0.0016225729 -0.0003646728 -0.0001158583
#> [3,] -0.0001079059  0.0001997682  0.0006022128
#> [4,]  0.0003112034  0.0024802930  0.0013062551
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  4.7801347 -2.5775625  0.5468356
#> [2,] -2.5775625  1.7150682 -0.8931806
#> [3,]  0.5468356 -0.8931806  2.9584934
#> 
#> , , 2
#> 
#>           [,1]        [,2]       [,3]
#> [1,]  3.146677 -1.35866627 1.09308069
#> [2,] -1.358666  7.55892577 0.07491042
#> [3,]  1.093081  0.07491042 2.29358027
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -2.708253e-03  0.0023140618 -0.0001932390
#> [2,]  1.645178e-03 -0.0009248597  0.0003773051
#> [3,]  8.981861e-05 -0.0004404852 -0.0010468477
#> [4,]  1.394071e-04 -0.0004503193 -0.0005331848
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0002207762  9.431802e-04  0.0009686025
#> [2,]  0.0006304984 -2.146290e-04 -0.0010000418
#> [3,]  0.0004564505 -6.104443e-05 -0.0002144141
#> [4,] -0.0005680083  4.535862e-04 -0.0004589080
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]      [,2]      [,3]
#> [1,] 1.8228239 0.1408428 0.4474921
#> [2,] 0.1408428 3.6965666 1.9716372
#> [3,] 0.4474921 1.9716372 2.5773454
#> 
#> , , 2
#> 
#>           [,1]       [,2]     [,3]
#> [1,] 3.0520167  0.6750894 2.879523
#> [2,] 0.6750894 12.8291124 2.886999
#> [3,] 2.8795230  2.8869994 4.313840
#> 
#> 
#> $V
#>             [,1]       [,2]        [,3]      [,4]
#> [1,]  3.64952296 -1.0465755 -0.01211782  4.766347
#> [2,] -1.04657555  7.7801725  0.59916647  0.750847
#> [3,] -0.01211782  0.5991665  4.11638571  4.789159
#> [4,]  4.76634661  0.7508470  4.78915850 12.365382
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0001866777
#> 
#> $w
#> [1] 0.09034129
#> 
#> $s
#> [1] 1.220361
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
