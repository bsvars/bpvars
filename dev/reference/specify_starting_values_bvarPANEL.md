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
#> [1,]  0.0004001185 -0.0004962203 -0.0002004333
#> [2,]  0.0003262801 -0.0001385552 -0.0013570091
#> [3,] -0.0005602820  0.0015411794  0.0006412756
#> [4,] -0.0002823015  0.0005469850 -0.0036401309
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0021335635 -0.0008887264 -0.0005931652
#> [2,] -0.0006096211  0.0026455297 -0.0011438241
#> [3,] -0.0009046304 -0.0008806867  0.0004711787
#> [4,]  0.0013583998 -0.0013662935  0.0009640682
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]      [,2]       [,3]
#> [1,] 4.2157749  2.877737  0.7898499
#> [2,] 2.8777372  5.118837 -3.0128911
#> [3,] 0.7898499 -3.012891  5.6680103
#> 
#> , , 2
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 6.8037608  0.1431585  1.3205079
#> [2,] 0.1431585  3.1179994 -0.1948515
#> [3,] 1.3205079 -0.1948515  6.0090850
#> 
#> 
#> $A
#>               [,1]         [,2]          [,3]
#> [1,]  1.0002237654 0.0025362249  4.960108e-05
#> [2,]  0.0003533741 0.9987909118 -2.031923e-05
#> [3,] -0.0006597012 0.0001515618  1.000779e+00
#> [4,] -0.0011286078 0.0008781812  7.695887e-04
#> 
#> $V
#>             [,1]       [,2]        [,3]        [,4]
#> [1,]  4.34729454 -2.2881799  0.05139827  2.68327834
#> [2,] -2.28817992  5.6255861  1.97624301 -0.57228643
#> [3,]  0.05139827  1.9762430  1.15376951 -0.01089984
#> [4,]  2.68327834 -0.5722864 -0.01089984  3.18469304
#> 
#> $Sigma
#>             [,1]        [,2]       [,3]
#> [1,]  2.00832516 -0.07567151  0.5028873
#> [2,] -0.07567151  1.60982689 -0.2264662
#> [3,]  0.50288729 -0.22646618  2.9687263
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -5.649954e-05
#> 
#> $w
#> [1] 0.3744295
#> 
#> $s
#> [1] 1.291841
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
