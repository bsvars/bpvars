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
#>               [,1]         [,2]          [,3]
#> [1,]  5.811519e-04 -0.001268699  0.0004334318
#> [2,] -5.914354e-04 -0.001174404 -0.0007881967
#> [3,] -8.131545e-05  0.001234686  0.0002854650
#> [4,]  2.256895e-03  0.001490329  0.0001118782
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0027889894 -0.0008166366  0.0013596072
#> [2,] -0.0004736907  0.0011249736 -0.0001865234
#> [3,] -0.0006921315 -0.0003257880  0.0003963297
#> [4,]  0.0004132552 -0.0006973759  0.0028573538
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  4.0303942 -0.6326987 -1.6589056
#> [2,] -0.6326987  0.4396940 -0.5672315
#> [3,] -1.6589056 -0.5672315  3.9648184
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  5.9115202 1.4718929 -0.3740094
#> [2,]  1.4718929 2.3266894  0.3369307
#> [3,] -0.3740094 0.3369307  0.1262182
#> 
#> 
#> $nu
#> [1] 4.1 4.1
#> 
#> $m
#> [1] -0.0001983849  0.0016974783
#> 
#> $w
#> [1] 2.8725004 0.6518257
#> 
#> $s
#> [1] 1.5927845 0.1848204
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
