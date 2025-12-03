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
#> [1,]  0.0003202659  4.872833e-04  0.0003108599
#> [2,] -0.0002051044  1.321674e-03 -0.0008642844
#> [3,] -0.0014590120  1.851001e-03  0.0004556745
#> [4,]  0.0001970714 -2.871539e-05  0.0009725133
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0003202659  4.872833e-04  0.0003108599
#> [2,] -0.0002051044  1.321674e-03 -0.0008642844
#> [3,] -0.0014590120  1.851001e-03  0.0004556745
#> [4,]  0.0001970714 -2.871539e-05  0.0009725133
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]     [,2]       [,3]
#> [1,]  3.4995931 1.253339 -0.7214792
#> [2,]  1.2533390 4.836461  1.0214678
#> [3,] -0.7214792 1.021468  2.3910081
#> 
#> , , 2
#> 
#>            [,1]     [,2]       [,3]
#> [1,]  3.4995931 1.253339 -0.7214792
#> [2,]  1.2533390 4.836461  1.0214678
#> [3,] -0.7214792 1.021468  2.3910081
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0003202659  4.872833e-04  0.0003108599
#> [2,] -0.0002051044  1.321674e-03 -0.0008642844
#> [3,] -0.0014590120  1.851001e-03  0.0004556745
#> [4,]  0.0001970714 -2.871539e-05  0.0009725133
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0012063817 -0.0003510410  0.0005446088
#> [2,] -0.0009244833 -0.0011105833 -0.0016486521
#> [3,]  0.0018053435 -0.0015002747  0.0002455263
#> [4,]  0.0009173974 -0.0001953946 -0.0025070550
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]     [,2]       [,3]
#> [1,]  3.4995931 1.253339 -0.7214792
#> [2,]  1.2533390 4.836461  1.0214678
#> [3,] -0.7214792 1.021468  2.3910081
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  0.8988796 -1.143265 -0.7556042
#> [2,] -1.1432649  4.267104  1.2314125
#> [3,] -0.7556042  1.231412  2.1974997
#> 
#> 
#> $A
#>              [,1]          [,2]          [,3]
#> [1,] 9.994854e-01 -7.214642e-04  0.0003238201
#> [2,] 3.695198e-05  9.989689e-01 -0.0023811831
#> [3,] 1.053764e-03 -3.692607e-04  0.9995045025
#> [4,] 1.550264e-04  5.334411e-05  0.0002807296
#> 
#> $V
#>           [,1]      [,2]      [,3]      [,4]
#> [1,]  1.898028  1.113366 -2.579309  2.746690
#> [2,]  1.113366  1.045075 -1.663733  1.544166
#> [3,] -2.579309 -1.663733  3.789709 -4.701205
#> [4,]  2.746690  1.544166 -4.701205 13.331019
#> 
#> $Sigma
#>            [,1]        [,2]        [,3]
#> [1,]  0.4593075 -0.19180847  0.46462579
#> [2,] -0.1918085  1.93865898 -0.09294709
#> [3,]  0.4646258 -0.09294709  3.31438298
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -1.736522e-05
#> 
#> $w
#> [1] 2.316998
#> 
#> $s
#> [1] 1.220757
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
