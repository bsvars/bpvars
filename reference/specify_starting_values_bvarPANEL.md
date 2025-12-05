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
#> [1,] -0.0011700552 -0.0001348476 -1.877055e-05
#> [2,] -0.0014380405 -0.0006970827 -6.143585e-05
#> [3,]  0.0000185431 -0.0016119701  1.221955e-03
#> [4,]  0.0007744435 -0.0015878642  2.899085e-04
#> 
#> , , 2
#> 
#>               [,1]         [,2]          [,3]
#> [1,]  0.0005424244  0.001156553 -0.0016004054
#> [2,] -0.0006850651 -0.001004641 -0.0005388915
#> [3,] -0.0004259665 -0.001016713  0.0019746570
#> [4,] -0.0003109295 -0.001070659  0.0009177656
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  2.9770574 -2.4548393 -0.4471247
#> [2,] -2.4548393  2.9315354  0.5274042
#> [3,] -0.4471247  0.5274042  3.9292745
#> 
#> , , 2
#> 
#>             [,1]        [,2]       [,3]
#> [1,]  1.85048072 -0.07357885 -3.1570435
#> [2,] -0.07357885  4.26905638 -0.8445047
#> [3,] -3.15704353 -0.84450471  8.0512517
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  1.0009016791 -0.0006348984  1.319750e-03
#> [2,] -0.0001099186  1.0004562514 -8.559671e-05
#> [3,]  0.0001460109  0.0004127499  9.998265e-01
#> [4,]  0.0020273301 -0.0004708795 -1.835929e-04
#> 
#> $V
#>            [,1]       [,2]       [,3]       [,4]
#> [1,]  1.4606768 -0.5589876  0.9974400 -1.2902584
#> [2,] -0.5589876  0.6518435 -0.2419283  0.7191557
#> [3,]  0.9974400 -0.2419283  1.8092646 -0.2590250
#> [4,] -1.2902584  0.7191557 -0.2590250  2.7583706
#> 
#> $Sigma
#>             [,1]        [,2]      [,3]
#> [1,]  0.50113977 -0.07573404 0.2338827
#> [2,] -0.07573404  6.53249434 1.0800762
#> [3,]  0.23388274  1.08007616 0.8329567
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.001093507
#> 
#> $w
#> [1] 1.565745
#> 
#> $s
#> [1] 0.2374017
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
