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
#> [1,] -0.0007639918 -0.0003230780  0.0027146465
#> [2,] -0.0008029080 -0.0006565096 -0.0005227097
#> [3,] -0.0004218313 -0.0005868535  0.0010797924
#> [4,]  0.0006311482  0.0015089688  0.0001229000
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0005830842 -0.0022336799 -0.0000932874
#> [2,]  0.0013361128  0.0001007835 -0.0023397055
#> [3,] -0.0013475700  0.0011915986  0.0005283630
#> [4,]  0.0005622487 -0.0002935950  0.0021753072
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  2.5433606 -2.084052 -0.8038839
#> [2,] -2.0840521  2.387845 -0.3274480
#> [3,] -0.8038839 -0.327448  4.5615809
#> 
#> , , 2
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  2.9616141  2.1009860 -0.8525848
#> [2,]  2.1009860  2.0542563 -0.9830452
#> [3,] -0.8525848 -0.9830452  1.2152528
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  1.001122e+00  5.130115e-04  0.0010077272
#> [2,] -1.357785e-05  9.997743e-01 -0.0005940332
#> [3,]  7.014189e-04 -9.542080e-04  0.9995242181
#> [4,]  1.975425e-05  5.044584e-05 -0.0001988790
#> 
#> $V
#>            [,1]        [,2]        [,3]       [,4]
#> [1,]  1.7905638  0.30962270 -0.86350697  0.3845798
#> [2,]  0.3096227  4.01614440 -0.05641114 -2.3949876
#> [3,] -0.8635070 -0.05641114  3.18947360 -2.3806774
#> [4,]  0.3845798 -2.39498764 -2.38067740  5.0965462
#> 
#> $Sigma
#>            [,1]      [,2]       [,3]
#> [1,]  0.3297025  1.045678 -0.4886108
#> [2,]  1.0456776  4.892960 -1.7070350
#> [3,] -0.4886108 -1.707035  0.8121312
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0009642101
#> 
#> $w
#> [1] 0.2318327
#> 
#> $s
#> [1] 2.063836
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
