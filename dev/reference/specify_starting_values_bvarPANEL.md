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
#> [1,]  0.0002950021 -4.288231e-04 -0.0001382322
#> [2,] -0.0018164388  2.902855e-05 -0.0001597715
#> [3,]  0.0002503083  1.457927e-03 -0.0006923248
#> [4,] -0.0002545509  1.099885e-03  0.0007776664
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0002709351  0.0002879379  0.0003481190
#> [2,] -0.0020641114 -0.0006252345  0.0011875447
#> [3,] -0.0015213309  0.0010281829 -0.0010371305
#> [4,] -0.0009836266 -0.0002893103 -0.0008409546
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]     [,2]      [,3]
#> [1,]  6.082436 1.669284 -2.092172
#> [2,]  1.669284 3.835009  0.952332
#> [3,] -2.092172 0.952332  1.411684
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  1.686219 -1.319930  3.773467
#> [2,] -1.319930  4.269931 -1.016283
#> [3,]  3.773467 -1.016283 13.500198
#> 
#> 
#> $A
#>              [,1]          [,2]          [,3]
#> [1,]  0.997562981 -0.0015855517 -0.0002735693
#> [2,] -0.001027745  0.9994927538 -0.0002050516
#> [3,] -0.001450371 -0.0000987619  1.0020408840
#> [4,] -0.000781373  0.0001397707 -0.0019029919
#> 
#> $V
#>           [,1]      [,2]      [,3]      [,4]
#> [1,]  8.804475 -4.139385 -3.872634  2.602323
#> [2,] -4.139385  8.442197  0.128121 -1.349703
#> [3,] -3.872634  0.128121  5.716726 -1.357035
#> [4,]  2.602323 -1.349703 -1.357035  4.589245
#> 
#> $Sigma
#>             [,1]       [,2]       [,3]
#> [1,]  1.60671530 -0.8306318 0.05238703
#> [2,] -0.83063181  1.0578468 0.39991487
#> [3,]  0.05238703  0.3999149 0.98962145
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0003093887
#> 
#> $w
#> [1] 0.5251384
#> 
#> $s
#> [1] 1.237122
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
