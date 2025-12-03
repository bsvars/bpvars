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
#> [1,] -0.0012576559 -0.0017851656 -0.0019623238
#> [2,]  0.0015968892 -0.0015567254 -0.0023546802
#> [3,] -0.0004403525  0.0004142685  0.0009504332
#> [4,]  0.0012600479 -0.0012836355  0.0002983287
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  4.282736e-05  0.0002268945 -0.0005453077
#> [2,] -1.474812e-03 -0.0006920332 -0.0001450515
#> [3,] -5.145133e-04  0.0003988822 -0.0003616118
#> [4,] -2.430275e-04  0.0012934377  0.0004133631
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  0.4465638 -0.6850451 -0.7088593
#> [2,] -0.6850451  4.2654989  0.0161032
#> [3,] -0.7088593  0.0161032  2.1101964
#> 
#> , , 2
#> 
#>           [,1]       [,2]      [,3]
#> [1,]  7.535075 -4.5445675 2.2200959
#> [2,] -4.544568  5.7856083 0.9039373
#> [3,]  2.220096  0.9039373 4.1534356
#> 
#> 
#> $nu
#> [1] 4.1 4.1
#> 
#> $m
#> [1] 0.0001071347 0.0003018421
#> 
#> $w
#> [1] 1.022757 2.472307
#> 
#> $s
#> [1] 0.1367404 0.8850580
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
