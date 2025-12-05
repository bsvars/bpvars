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
#>              [,1]          [,2]          [,3]
#> [1,] 7.278243e-05 -0.0010117950  0.0011157771
#> [2,] 1.032757e-04 -0.0006104872 -0.0021989244
#> [3,] 2.662012e-04  0.0013670263  0.0021306382
#> [4,] 9.273017e-04 -0.0005989197  0.0005084554
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0010004460 -0.0001669747  0.0002048504
#> [2,] -0.0002423509 -0.0012170076  0.0014623986
#> [3,]  0.0007043587  0.0013394394 -0.0015817893
#> [4,]  0.0001968925  0.0013038063  0.0005714757
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>          [,1]     [,2]     [,3]
#> [1,] 9.865342 4.780915 6.538184
#> [2,] 4.780915 3.133129 3.284564
#> [3,] 6.538184 3.284564 5.149788
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,] 1.6567458 1.3817559 0.9520036
#> [2,] 1.3817559 3.0186444 0.5556742
#> [3,] 0.9520036 0.5556742 2.0623919
#> 
#> 
#> $A
#>              [,1]          [,2]          [,3]
#> [1,] 1.0011131761  0.0024419657 -0.0002605362
#> [2,] 0.0009863104  1.0003640454  0.0006386024
#> [3,] 0.0010496366 -0.0003686885  1.0003967553
#> [4,] 0.0005672600 -0.0007656492 -0.0016467449
#> 
#> $V
#>            [,1]       [,2]       [,3]       [,4]
#> [1,]  2.6755676 -2.5191481 -0.3476462  0.1100225
#> [2,] -2.5191481  4.2876082  0.2755792  0.4107831
#> [3,] -0.3476462  0.2755792  1.2964504 -0.3593219
#> [4,]  0.1100225  0.4107831 -0.3593219  0.4682852
#> 
#> $Sigma
#>           [,1]      [,2]      [,3]
#> [1,]  3.935450  2.907509 -1.268022
#> [2,]  2.907509  2.958424 -0.921284
#> [3,] -1.268022 -0.921284  0.928992
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0007513928
#> 
#> $w
#> [1] 0.5934184
#> 
#> $s
#> [1] 2.580068
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
