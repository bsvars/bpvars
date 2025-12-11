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
#> [1,] -1.747944e-03  7.272224e-04 -0.0018154588
#> [2,]  2.158987e-04 -7.126292e-05  0.0012884166
#> [3,]  8.749626e-05  5.314838e-04 -0.0002860749
#> [4,] -5.887764e-04 -1.573786e-03 -0.0001609573
#> 
#> , , 2
#> 
#>               [,1]          [,2]         [,3]
#> [1,] -0.0007467667 -0.0002234728 2.124251e-04
#> [2,] -0.0017971085  0.0002347082 2.416216e-04
#> [3,] -0.0008412467 -0.0002899310 1.223435e-03
#> [4,] -0.0001931980 -0.0015100012 4.130245e-05
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  6.2640369 -1.7305479 0.1867046
#> [2,] -1.7305479  5.5274890 0.7728585
#> [3,]  0.1867046  0.7728585 0.8636057
#> 
#> , , 2
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  3.8107824  0.9301838 -1.2155180
#> [2,]  0.9301838  2.7118549 -0.8660853
#> [3,] -1.2155180 -0.8660853  0.7685027
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  1.0004446834 -0.0007232218 -6.718497e-04
#> [2,]  0.0004878582  1.0014330785  2.279409e-05
#> [3,]  0.0006717321  0.0010135872  9.997689e-01
#> [4,] -0.0007579427 -0.0002816474  8.897188e-04
#> 
#> $V
#>            [,1]       [,2]      [,3]       [,4]
#> [1,]  7.5257736 -2.6551540 3.7976247 -0.4458565
#> [2,] -2.6551540  3.5247794 0.4885544  1.1913887
#> [3,]  3.7976247  0.4885544 3.9588498  0.1259825
#> [4,] -0.4458565  1.1913887 0.1259825  6.6583321
#> 
#> $Sigma
#>           [,1]      [,2]      [,3]
#> [1,]  5.811775  3.730395 -3.642561
#> [2,]  3.730395  4.749678 -1.608519
#> [3,] -3.642561 -1.608519  5.017827
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.001187005
#> 
#> $w
#> [1] 0.2966828
#> 
#> $s
#> [1] 0.2397762
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
