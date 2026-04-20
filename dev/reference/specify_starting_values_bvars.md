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
#> [1,] -0.0013487613  0.0008185816  8.397951e-06
#> [2,] -0.0011437095 -0.0008334800  3.609359e-04
#> [3,] -0.0001938439 -0.0004990170  4.693957e-04
#> [4,]  0.0009864291  0.0014105373 -9.447709e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  2.553654e-06  0.0012048049 -0.0007401245
#> [2,] -6.155809e-04 -0.0002498665 -0.0007577137
#> [3,]  1.069419e-03  0.0009445053  0.0012844683
#> [4,]  2.150503e-04  0.0008135425 -0.0004498825
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  8.7946418 -3.531536  0.4423101
#> [2,] -3.5315364  2.503513 -3.4711475
#> [3,]  0.4423101 -3.471148 15.9601436
#> 
#> , , 2
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  3.6681493 -0.4935804  0.246140
#> [2,] -0.4935804  3.5439079 -4.319215
#> [3,]  0.2461400 -4.3192149  9.609096
#> 
#> 
#> $nu
#> [1] 4.1 4.1
#> 
#> $m
#> [1] -2.431569e-05 -1.667458e-03
#> 
#> $w
#> [1] 3.0274314 0.6296556
#> 
#> $s
#> [1] 0.1817438 0.2195946
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
