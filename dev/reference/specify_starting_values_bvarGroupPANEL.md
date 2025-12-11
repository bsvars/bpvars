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
#> [1,]  0.0011149933  2.829474e-04  0.0015440072
#> [2,]  0.0009974073  4.551574e-04 -0.0021686325
#> [3,] -0.0023387790  1.117707e-03 -0.0011214446
#> [4,] -0.0013601750 -6.657333e-05  0.0008612208
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0011149933  2.829474e-04  0.0015440072
#> [2,]  0.0009974073  4.551574e-04 -0.0021686325
#> [3,] -0.0023387790  1.117707e-03 -0.0011214446
#> [4,] -0.0013601750 -6.657333e-05  0.0008612208
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  1.6439868 -1.345763 -0.4002505
#> [2,] -1.3457631  3.150345  1.3028634
#> [3,] -0.4002505  1.302863  2.4250624
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  1.6439868 -1.345763 -0.4002505
#> [2,] -1.3457631  3.150345  1.3028634
#> [3,] -0.4002505  1.302863  2.4250624
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0011149933  2.829474e-04  0.0015440072
#> [2,]  0.0009974073  4.551574e-04 -0.0021686325
#> [3,] -0.0023387790  1.117707e-03 -0.0011214446
#> [4,] -0.0013601750 -6.657333e-05  0.0008612208
#> 
#> , , 2
#> 
#>               [,1]          [,2]         [,3]
#> [1,]  0.0002811764 -1.787840e-04 0.0007129066
#> [2,] -0.0008793643 -4.537466e-04 0.0012080060
#> [3,] -0.0016169866  6.352337e-05 0.0007681147
#> [4,] -0.0016419511 -1.358580e-04 0.0030452450
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  1.6439868 -1.345763 -0.4002505
#> [2,] -1.3457631  3.150345  1.3028634
#> [3,] -0.4002505  1.302863  2.4250624
#> 
#> , , 2
#> 
#>            [,1]       [,2]        [,3]
#> [1,]  3.7812104 0.29239074 -0.20301124
#> [2,]  0.2923907 0.87020745  0.03927032
#> [3,] -0.2030112 0.03927032  1.79323213
#> 
#> 
#> $A
#>               [,1]          [,2]         [,3]
#> [1,]  1.0000127832 -1.596513e-03 0.0022486874
#> [2,]  0.0015228844  1.000195e+00 0.0002305117
#> [3,]  0.0012826121  6.782383e-04 1.0018106473
#> [4,] -0.0006238685  5.424823e-05 0.0012431142
#> 
#> $V
#>             [,1]       [,2]       [,3]        [,4]
#> [1,]  2.09354872 -2.2097829  0.4474817  0.02207493
#> [2,] -2.20978293  6.0255429  1.3040804 -0.82416035
#> [3,]  0.44748166  1.3040804  2.3580809 -2.68631346
#> [4,]  0.02207493 -0.8241603 -2.6863135  6.99742890
#> 
#> $Sigma
#>           [,1]      [,2]      [,3]
#> [1,]  3.506231  1.075087 -3.086627
#> [2,]  1.075087  8.512686 -1.437564
#> [3,] -3.086627 -1.437564  5.753801
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0009387176
#> 
#> $w
#> [1] 1.233574
#> 
#> $s
#> [1] 0.29134
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
