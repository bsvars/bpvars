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
#> [1,]  1.262627e-03  0.0000971847  0.0010752417
#> [2,] -8.157192e-04 -0.0012368408  0.0006739890
#> [3,] -1.282331e-05  0.0007670313 -0.0004407719
#> [4,]  1.482750e-03  0.0011100666 -0.0011833105
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0001838934 -0.0022997788 -0.0001823184
#> [2,]  0.0002049109  0.0007738487 -0.0010611966
#> [3,] -0.0021905606 -0.0007998816 -0.0009033857
#> [4,] -0.0017677032  0.0004939544 -0.0009762960
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  3.1659878 -0.5095565 -1.2090556
#> [2,] -0.5095565  2.8274591  0.2376851
#> [3,] -1.2090556  0.2376851  4.6287206
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  6.1076001 -5.571099 -0.3564721
#> [2,] -5.5710994 12.715989  1.7242102
#> [3,] -0.3564721  1.724210  1.9272894
#> 
#> 
#> $nu
#> [1] 4.1 4.1
#> 
#> $m
#> [1]  0.0006600541 -0.0012697254
#> 
#> $w
#> [1] 0.2424652 0.3594846
#> 
#> $s
#> [1] 0.5641769 0.9638294
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
