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
#>               [,1]          [,2]          [,3]
#> [1,] -0.0010726537 -0.0006558797  0.0016177849
#> [2,]  0.0006169535  0.0028401894 -0.0007527245
#> [3,]  0.0001582157  0.0010102210  0.0003918036
#> [4,] -0.0003085564 -0.0009850158  0.0014088419
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0010726537 -0.0006558797  0.0016177849
#> [2,]  0.0006169535  0.0028401894 -0.0007527245
#> [3,]  0.0001582157  0.0010102210  0.0003918036
#> [4,] -0.0003085564 -0.0009850158  0.0014088419
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  2.0996159 0.4469976 -0.3531023
#> [2,]  0.4469976 3.2020361  1.9660848
#> [3,] -0.3531023 1.9660848  1.7495734
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  2.0996159 0.4469976 -0.3531023
#> [2,]  0.4469976 3.2020361  1.9660848
#> [3,] -0.3531023 1.9660848  1.7495734
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0010726537 -0.0006558797  0.0016177849
#> [2,]  0.0006169535  0.0028401894 -0.0007527245
#> [3,]  0.0001582157  0.0010102210  0.0003918036
#> [4,] -0.0003085564 -0.0009850158  0.0014088419
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0008924328 -0.0002745947 -0.0006524857
#> [2,] -0.0015296863  0.0005959539  0.0006384357
#> [3,]  0.0001752157  0.0005247636 -0.0005311058
#> [4,]  0.0007104503  0.0000248871 -0.0015784417
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  2.0996159 0.4469976 -0.3531023
#> [2,]  0.4469976 3.2020361  1.9660848
#> [3,] -0.3531023 1.9660848  1.7495734
#> 
#> , , 2
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  6.0872686  0.0409619 -2.007187
#> [2,]  0.0409619  6.7790849 -2.138009
#> [3,] -2.0071871 -2.1380093  1.622137
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  1.0012789335  0.0003760854  0.0005634164
#> [2,]  0.0004128759  1.0002383465 -0.0008656172
#> [3,] -0.0001916676  0.0009295051  0.9991990692
#> [4,]  0.0013727895 -0.0005027305 -0.0007118884
#> 
#> $V
#>            [,1]      [,2]       [,3]      [,4]
#> [1,]  2.6586107  4.554435 -0.8777004  1.843566
#> [2,]  4.5544352  9.869746 -1.9192373  2.959473
#> [3,] -0.8777004 -1.919237  2.8482106 -1.127678
#> [4,]  1.8435655  2.959473 -1.1276778  4.444475
#> 
#> $Sigma
#>            [,1]       [,2]       [,3]
#> [1,]  2.7853931 -3.0399739 -0.6047423
#> [2,] -3.0399739  3.7969494  0.8588764
#> [3,] -0.6047423  0.8588764  0.3225290
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0005370533
#> 
#> $w
#> [1] 0.4159634
#> 
#> $s
#> [1] 0.628982
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
