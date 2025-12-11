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
#>               [,1]         [,2]          [,3]
#> [1,]  0.0005385806 7.694680e-04 -0.0023579810
#> [2,]  0.0005269846 5.377245e-05  0.0006260353
#> [3,]  0.0004112499 8.074527e-04  0.0020011955
#> [4,] -0.0009427246 1.055469e-03 -0.0019980985
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  2.402999e-05 -6.700889e-05 -6.518857e-06
#> [2,] -2.449304e-04  7.838391e-04  2.145737e-04
#> [3,]  3.659161e-04  2.064477e-03  6.168114e-04
#> [4,]  2.176597e-03 -3.407649e-04 -1.099331e-03
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  3.388701  2.796547 -1.731035
#> [2,]  2.796547  9.896878 -2.278741
#> [3,] -1.731035 -2.278741  0.996372
#> 
#> , , 2
#> 
#>          [,1]       [,2]       [,3]
#> [1,] 5.251162  1.4870709  0.5195840
#> [2,] 1.487071  1.5678421 -0.1390394
#> [3,] 0.519584 -0.1390394  4.1014264
#> 
#> 
#> $A
#>               [,1]         [,2]          [,3]
#> [1,]  0.9993281606 0.0006020265 -0.0008069469
#> [2,]  0.0014400837 1.0008567119  0.0009034242
#> [3,] -0.0008388617 0.0014305482  1.0005370052
#> [4,] -0.0005172022 0.0002455481  0.0018760925
#> 
#> $V
#>            [,1]       [,2]       [,3]       [,4]
#> [1,]  1.8906154 -0.9945585 -0.9845579 -2.6235414
#> [2,] -0.9945585  0.8776218  0.4190235  1.0508560
#> [3,] -0.9845579  0.4190235  2.9149605  0.3897837
#> [4,] -2.6235414  1.0508560  0.3897837  5.1192490
#> 
#> $Sigma
#>           [,1]      [,2]     [,3]
#> [1,] 7.3841623 0.6990159 1.275020
#> [2,] 0.6990159 2.4495639 1.011746
#> [3,] 1.2750197 1.0117458 2.926518
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0005752496
#> 
#> $w
#> [1] 1.223774
#> 
#> $s
#> [1] 0.8498171
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
