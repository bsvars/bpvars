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
#> [1,] -0.0021276863 -0.0006091903  0.0008734540
#> [2,]  0.0012858542 -0.0007902988  0.0016719418
#> [3,] -0.0007471381 -0.0023185307 -0.0017028813
#> [4,]  0.0009658804  0.0011265632 -0.0001271808
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0012939355 -0.0003649561 -0.0008881712
#> [2,]  0.0000953348 -0.0005804442 -0.0002238446
#> [3,] -0.0002935945  0.0002476521 -0.0001163070
#> [4,]  0.0012636581  0.0005203398 -0.0007533496
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>             [,1]       [,2]       [,3]
#> [1,]  6.58352024 -0.9660425 0.04052026
#> [2,] -0.96604246  0.9860933 1.08067592
#> [3,]  0.04052026  1.0806759 1.89385165
#> 
#> , , 2
#> 
#>           [,1]        [,2]        [,3]
#> [1,]  7.527815  1.04781963 -3.62303225
#> [2,]  1.047820  0.85662700 -0.06568065
#> [3,] -3.623032 -0.06568065  4.16581374
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  1.0008188555 -0.0004496362  0.0001856855
#> [2,]  0.0015938272  0.9991556029 -0.0001050047
#> [3,] -0.0005196827 -0.0002892931  1.0000593463
#> [4,] -0.0001796157  0.0005702388 -0.0016963025
#> 
#> $V
#>            [,1]       [,2]       [,3]      [,4]
#> [1,]  7.1289178  4.5609232 -0.8880403 3.8494111
#> [2,]  4.5609232  3.7770139 -0.8095498 3.4366620
#> [3,] -0.8880403 -0.8095498  2.0094311 0.7521728
#> [4,]  3.8494111  3.4366620  0.7521728 5.0021710
#> 
#> $Sigma
#>            [,1]       [,2]       [,3]
#> [1,]  1.7532247 -0.5113817 -1.7686079
#> [2,] -0.5113817  0.6539748  0.8810685
#> [3,] -1.7686079  0.8810685  2.0772669
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0006608409
#> 
#> $w
#> [1] 0.4581861
#> 
#> $s
#> [1] 0.02277056
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
