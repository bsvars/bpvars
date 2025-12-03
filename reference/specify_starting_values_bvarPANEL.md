# R6 Class Representing StartingValuesBVARPANEL

The class StartingValuesBVARPANEL presents starting values for the
Bayesian hierarchical panel VAR model.

## Public fields

- `A_c`:

  an `KxNxC` array of starting values for the local parameter
  \\\mathbf{A}\_c\\.

- `Sigma_c`:

  an `NxNxC` array of starting values for the local parameter
  \\\mathbf{\Sigma}\_c\\.

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

- [`specify_starting_values_bvarPANEL$new()`](#method-StartingValuesBVARPANEL-new)

- [`specify_starting_values_bvarPANEL$get_starting_values()`](#method-StartingValuesBVARPANEL-get_starting_values)

- [`specify_starting_values_bvarPANEL$set_starting_values()`](#method-StartingValuesBVARPANEL-set_starting_values)

- [`specify_starting_values_bvarPANEL$clone()`](#method-StartingValuesBVARPANEL-clone)

------------------------------------------------------------------------

### Method `new()`

Create new starting values StartingValuesBVARPANEL

#### Usage

    specify_starting_values_bvarPANEL$new(C, N, p, d = 0)

#### Arguments

- `C`:

  a positive integer - the number of countries in the data.

- `N`:

  a positive integer - the number of dependent variables in the model.

- `p`:

  a positive integer - the autoregressive lag order of the SVAR model.

- `d`:

  a positive integer - the number of `exogenous` variables in the model.

#### Returns

Starting values StartingValuesBVARPANEL

#### Examples

    # starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
    sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 4)

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the elements of the starting values StartingValuesBVARPANEL as a
`list`.

#### Usage

    specify_starting_values_bvarPANEL$get_starting_values()

#### Examples

    # starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
    sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)
    sv$get_starting_values()   # show starting values as list

------------------------------------------------------------------------

### Method `set_starting_values()`

Returns the elements of the starting values StartingValuesBVARPANEL as a
`list`.

#### Usage

    specify_starting_values_bvarPANEL$set_starting_values(last_draw)

#### Arguments

- `last_draw`:

  a list containing the same elements as object StartingValuesBVARPANEL.

#### Returns

An object of class StartingValuesBVARPANEL including the last draw of
the current MCMC as the starting value to be passed to the continuation
of the MCMC estimation.

#### Examples

    sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)

    # Modify the starting values by:
    sv_list = sv$get_starting_values()   # getting them as list
    sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
    sv$set_starting_values(sv_list)      # providing to the class object

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_starting_values_bvarPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
# starting values for a Bayesian Panel VAR
sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarPANEL$new`
## ------------------------------------------------

# starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 4)


## ------------------------------------------------
## Method `specify_starting_values_bvarPANEL$get_starting_values`
## ------------------------------------------------

# starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)
sv$get_starting_values()   # show starting values as list
#> $A_c
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0019788431 -0.0000985027  0.0009878946
#> [2,] -0.0005364984 -0.0008746682 -0.0006730914
#> [3,] -0.0002630910  0.0006290781 -0.0008945055
#> [4,]  0.0001194168 -0.0005694621 -0.0017890381
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -1.395540e-04  0.0008279913  0.0007455030
#> [2,] -7.838023e-04 -0.0008698953  0.0018796956
#> [3,] -2.420372e-05 -0.0014610216 -0.0008464682
#> [4,] -5.206255e-04  0.0001582630  0.0009454074
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  7.166265 -3.312118 -2.623964
#> [2,] -3.312118  2.998951  3.435066
#> [3,] -2.623964  3.435066  7.362829
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  4.582131  1.392390 -4.145895
#> [2,]  1.392390  1.059551 -1.659516
#> [3,] -4.145895 -1.659516  6.945534
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  9.996739e-01 -0.0005971659 -2.356643e-04
#> [2,] -9.723908e-04  0.9988463378 -5.844611e-05
#> [3,] -7.326777e-05  0.0013654157  1.001977e+00
#> [4,]  8.364505e-04 -0.0019292896  8.096957e-04
#> 
#> $V
#>            [,1]      [,2]       [,3]       [,4]
#> [1,]  7.7051186 -3.539387 -2.8223807  0.7247632
#> [2,] -3.5393868  7.437664  5.6119321 -1.4046718
#> [3,] -2.8223807  5.611932  6.3976108  0.2276991
#> [4,]  0.7247632 -1.404672  0.2276991  3.6225593
#> 
#> $Sigma
#>           [,1]      [,2]      [,3]
#> [1,]  4.604939  2.215698 -1.227870
#> [2,]  2.215698  8.495456 -1.735591
#> [3,] -1.227870 -1.735591  1.840732
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0003293514
#> 
#> $w
#> [1] 0.1390834
#> 
#> $s
#> [1] 0.1530404
#> 


## ------------------------------------------------
## Method `specify_starting_values_bvarPANEL$set_starting_values`
## ------------------------------------------------

sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)

# Modify the starting values by:
sv_list = sv$get_starting_values()   # getting them as list
sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
sv$set_starting_values(sv_list)      # providing to the class object
```
