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
#> [1,]  0.0003933648  0.0001363003 -7.812285e-04
#> [2,] -0.0003224930 -0.0005940180 -4.373803e-05
#> [3,] -0.0015669379  0.0009669682 -6.746382e-04
#> [4,] -0.0008097974 -0.0002802628  7.601261e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]         [,3]
#> [1,]  0.0002042472  0.0005348767 0.0001024123
#> [2,] -0.0025998796  0.0011899806 0.0023313079
#> [3,]  0.0001744324 -0.0002434119 0.0006730934
#> [4,]  0.0005452212 -0.0015842665 0.0001874675
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  3.1419962 -0.7357781 -3.833014
#> [2,] -0.7357781  1.8094526  2.169818
#> [3,] -3.8330137  2.1698181  5.819838
#> 
#> , , 2
#> 
#>             [,1]       [,2]        [,3]
#> [1,]  0.34047975 -0.1919695  0.08178324
#> [2,] -0.19196953  4.9706475 -1.46044323
#> [3,]  0.08178324 -1.4604432  2.38569819
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  0.9995790329 -2.452354e-04 -0.0021633846
#> [2,] -0.0019261097  9.998651e-01 -0.0008570051
#> [3,]  0.0009171005 -4.128681e-04  0.9977429153
#> [4,] -0.0003980882 -2.718106e-05 -0.0011550101
#> 
#> $V
#>            [,1]       [,2]       [,3]       [,4]
#> [1,]  0.6474062 -1.2807312 -0.0495636 -0.6629626
#> [2,] -1.2807312  5.1060879 -0.8522691  3.6779647
#> [3,] -0.0495636 -0.8522691  4.4980632  0.5375226
#> [4,] -0.6629626  3.6779647  0.5375226  3.5990408
#> 
#> $Sigma
#>           [,1]      [,2]      [,3]
#> [1,]  1.790105  1.052737 -1.219289
#> [2,]  1.052737  1.133765 -1.087557
#> [3,] -1.219289 -1.087557  3.503118
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.001330705
#> 
#> $w
#> [1] 0.3480616
#> 
#> $s
#> [1] 1.971673
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
