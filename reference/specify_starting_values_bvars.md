# R6 Class Representing StartingValuesBVARs

The class StartingValuesBVARs presents starting values for the Bayesian
hierarchical panel VAR model.

## Public fields

- `A_c`:

  an `KxNxC` array of starting values for the local parameter
  \\\mathbf{A}\_c\\.

- `Sigma_c`:

  an `NxNxC` array of starting values for the local parameter
  \\\mathbf{\Sigma}\_c\\.

- `nu`:

  a `C`-vector of positive starting values for the parameter \\\nu\\.

- `m`:

  a `C`-vector of starting values for the parameter \\m\\.

- `w`:

  a `C`-vector of positive starting values for the parameter \\w\\.

- `s`:

  a `C`-vector of positive starting values for the parameter \\s\\.

## Methods

### Public methods

- [`specify_starting_values_bvars$new()`](#method-StartingValuesBVARs-new)

- [`specify_starting_values_bvars$get_starting_values()`](#method-StartingValuesBVARs-get_starting_values)

- [`specify_starting_values_bvars$set_starting_values()`](#method-StartingValuesBVARs-set_starting_values)

- [`specify_starting_values_bvars$clone()`](#method-StartingValuesBVARs-clone)

------------------------------------------------------------------------

### Method `new()`

Create new starting values StartingValuesBVARs

#### Usage

    specify_starting_values_bvars$new(C, N, p, d = 0)

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

Starting values StartingValuesBVARs

#### Examples

    # starting values for Bayesian VARs 2-country model with 4 lags for a 3-variable system.
    sv = specify_starting_values_bvars$new(C = 2, N = 3, p = 4)

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the elements of the starting values StartingValuesBVARs as a
`list`.

#### Usage

    specify_starting_values_bvars$get_starting_values()

#### Examples

    # starting values for bvars with 1 lag for a 3-variable system
    sv = specify_starting_values_bvars$new(C = 2, N = 3, p = 1)
    sv$get_starting_values()   # show starting values as list

------------------------------------------------------------------------

### Method `set_starting_values()`

Returns the elements of the starting values StartingValuesBVARs as a
`list`.

#### Usage

    specify_starting_values_bvars$set_starting_values(last_draw)

#### Arguments

- `last_draw`:

  a list containing the same elements as object StartingValuesBVARs.

#### Returns

An object of class StartingValuesBVARs including the last draw of the
current MCMC as the starting value to be passed to the continuation of
the MCMC estimation.

#### Examples

    sv = specify_starting_values_bvars$new(C = 2, N = 3, p = 1)

    # Modify the starting values by:
    sv_list = sv$get_starting_values()   # getting them as list
    sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
    sv$set_starting_values(sv_list)      # providing to the class object

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_starting_values_bvars$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
# starting values for a Bayesian Panel VAR
sv = specify_starting_values_bvars$new(C = 2, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvars$new`
## ------------------------------------------------

# starting values for Bayesian VARs 2-country model with 4 lags for a 3-variable system.
sv = specify_starting_values_bvars$new(C = 2, N = 3, p = 4)


## ------------------------------------------------
## Method `specify_starting_values_bvars$get_starting_values`
## ------------------------------------------------

# starting values for bvars with 1 lag for a 3-variable system
sv = specify_starting_values_bvars$new(C = 2, N = 3, p = 1)
sv$get_starting_values()   # show starting values as list
#> $A_c
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -1.172718e-04 -2.953200e-04  0.0001022192
#> [2,] -1.651018e-04 -2.166427e-05  0.0007725040
#> [3,]  4.048728e-05  1.163668e-03  0.0006454053
#> [4,] -5.985753e-04 -5.905910e-04 -0.0012722871
#> 
#> , , 2
#> 
#>              [,1]          [,2]         [,3]
#> [1,] -0.001031881 -0.0003648394 0.0008110920
#> [2,] -0.001806345  0.0004752089 0.0005205368
#> [3,]  0.001844824  0.0003679355 0.0002741926
#> [4,]  0.000650460 -0.0020362373 0.0014343366
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]     [,2]      [,3]
#> [1,]  7.653187 3.433307 -3.656945
#> [2,]  3.433307 8.786300  4.615386
#> [3,] -3.656945 4.615386 10.325281
#> 
#> , , 2
#> 
#>           [,1]       [,2]       [,3]
#> [1,]  4.256029  2.8531450 -1.1467303
#> [2,]  2.853145  2.3590809 -0.1941034
#> [3,] -1.146730 -0.1941034  2.8848083
#> 
#> 
#> $nu
#> [1] 4.1 4.1
#> 
#> $m
#> [1] -0.0001321332  0.0016537245
#> 
#> $w
#> [1] 0.5422867 1.6341190
#> 
#> $s
#> [1] 0.3723654 0.5753813
#> 


## ------------------------------------------------
## Method `specify_starting_values_bvars$set_starting_values`
## ------------------------------------------------

sv = specify_starting_values_bvars$new(C = 2, N = 3, p = 1)

# Modify the starting values by:
sv_list = sv$get_starting_values()   # getting them as list
sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
sv$set_starting_values(sv_list)      # providing to the class object
```
