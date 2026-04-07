# R6 Class Representing StartingValuesBVARGROUPPANEL

The class StartingValuesBVARGROUPPANEL presents starting values for the
Bayesian hierarchical panel VAR model with country grouping

## Super class

`bpvars::StartingValuesBVARPANEL` -\> `StartingValuesBVARGROUPPANEL`

## Public fields

- `group_allocation`:

  a numeric vector with integer numbers denoting group allocations

- `A_c`:

  an `KxNxC` array of starting values for the local parameter
  \\\mathbf{A}\_c\\.

- `Sigma_c`:

  an `NxNxC` array of starting values for the local parameter
  \\\mathbf{\Sigma}\_c\\.

- `A_g`:

  an `KxNxG` array of starting values for the group parameter
  \\\mathbf{A}\_g\\.

- `Sigma_g`:

  an `NxNxG` array of starting values for the group parameter
  \\\mathbf{\Sigma}\_g\\.

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

- [`specify_starting_values_bvarGroupPANEL$new()`](#method-StartingValuesBVARGROUPPANEL-new)

- [`specify_starting_values_bvarGroupPANEL$get_starting_values()`](#method-StartingValuesBVARGROUPPANEL-get_starting_values)

- [`specify_starting_values_bvarGroupPANEL$set_starting_values()`](#method-StartingValuesBVARGROUPPANEL-set_starting_values)

- [`specify_starting_values_bvarGroupPANEL$clone()`](#method-StartingValuesBVARGROUPPANEL-clone)

------------------------------------------------------------------------

### Method `new()`

Create new starting values StartingValuesBVARGROUPPANEL

#### Usage

    specify_starting_values_bvarGroupPANEL$new(
      group_allocation = 1:C,
      C,
      G = C,
      N,
      p,
      d = 0
    )

#### Arguments

- `group_allocation`:

  a numeric vector with integer numbers denoting group allocations

- `C`:

  a positive integer - the number of countries in the data.

- `G`:

  a positive integer specifying the number of country groups.

- `N`:

  a positive integer - the number of dependent variables in the model.

- `p`:

  a positive integer - the autoregressive lag order of the SVAR model.

- `d`:

  a positive integer - the number of `exogenous` variables in the model.

#### Returns

Starting values StartingValuesBVARGROUPPANEL

#### Examples

    # starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
    sv = specify_starting_values_bvarGroupPANEL$new(C = 2, N = 3, p = 1)

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the elements of the starting values StartingValuesBVARGROUPPANEL
as a `list`.

#### Usage

    specify_starting_values_bvarGroupPANEL$get_starting_values()

#### Examples

    # starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
    sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
    sv$get_starting_values()   # show starting values as list

------------------------------------------------------------------------

### Method `set_starting_values()`

Returns the elements of the starting values StartingValuesBVARGROUPPANEL
as a `list`.

#### Usage

    specify_starting_values_bvarGroupPANEL$set_starting_values(last_draw)

#### Arguments

- `last_draw`:

  a list containing the same elements as object
  StartingValuesBVARGROUPPANEL

#### Returns

An object of class StartingValuesBVARGROUPPANEL including the last draw
of the current MCMC as the starting value to be passed to the
continuation of the MCMC estimation.

#### Examples

    sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)

    # Modify the starting values by:
    sv_list = sv$get_starting_values()   # getting them as list
    sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
    sv$set_starting_values(sv_list)      # providing to the class object

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_starting_values_bvarGroupPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
# starting values for a Bayesian Panel VAR
sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, G = 1, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPANEL$new`
## ------------------------------------------------

# starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
sv = specify_starting_values_bvarGroupPANEL$new(C = 2, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPANEL$get_starting_values`
## ------------------------------------------------

# starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
sv$get_starting_values()   # show starting values as list
#> $group_allocation
#> [1] 1 1
#> 
#> $A_c
#> , , 1
#> 
#>              [,1]          [,2]          [,3]
#> [1,] -0.001849869  8.329132e-05  9.986922e-04
#> [2,]  0.002706966 -6.268853e-04 -7.850960e-05
#> [3,]  0.002059111  3.354438e-04 -1.910819e-04
#> [4,] -0.001084513 -1.137376e-03  7.280453e-05
#> 
#> , , 2
#> 
#>              [,1]          [,2]          [,3]
#> [1,] -0.001849869  8.329132e-05  9.986922e-04
#> [2,]  0.002706966 -6.268853e-04 -7.850960e-05
#> [3,]  0.002059111  3.354438e-04 -1.910819e-04
#> [4,] -0.001084513 -1.137376e-03  7.280453e-05
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  7.3804397 -5.5545053 -0.6519231
#> [2,] -5.5545053  5.4725332  0.8756026
#> [3,] -0.6519231  0.8756026  0.9312190
#> 
#> , , 2
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  7.3804397 -5.5545053 -0.6519231
#> [2,] -5.5545053  5.4725332  0.8756026
#> [3,] -0.6519231  0.8756026  0.9312190
#> 
#> 
#> $A_g
#> , , 1
#> 
#>              [,1]          [,2]          [,3]
#> [1,] -0.001849869  8.329132e-05  9.986922e-04
#> [2,]  0.002706966 -6.268853e-04 -7.850960e-05
#> [3,]  0.002059111  3.354438e-04 -1.910819e-04
#> [4,] -0.001084513 -1.137376e-03  7.280453e-05
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0004242808  0.0001260967 -0.0001252438
#> [2,] -0.0010029252  0.0004349765  0.0002202022
#> [3,]  0.0005203954 -0.0001280960 -0.0021754574
#> [4,]  0.0001322600 -0.0007734846  0.0002244613
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  7.3804397 -5.5545053 -0.6519231
#> [2,] -5.5545053  5.4725332  0.8756026
#> [3,] -0.6519231  0.8756026  0.9312190
#> 
#> , , 2
#> 
#>           [,1]     [,2]      [,3]
#> [1,] 6.0008029 3.642100 0.6327192
#> [2,] 3.6421001 3.065069 1.6145054
#> [3,] 0.6327192 1.614505 4.6451398
#> 
#> 
#> $A
#>              [,1]          [,2]         [,3]
#> [1,] 1.0009074711  0.0012729041 0.0006758488
#> [2,] 0.0004045349  1.0000212533 0.0007196550
#> [3,] 0.0015498315 -0.0004536336 1.0000997993
#> [4,] 0.0004397918  0.0007811692 0.0005313644
#> 
#> $V
#>            [,1]       [,2]      [,3]      [,4]
#> [1,]  1.8470016 -0.3646504 0.8533333 2.3020771
#> [2,] -0.3646504  0.8843209 1.4778717 0.1302174
#> [3,]  0.8533333  1.4778717 9.7622572 2.2193646
#> [4,]  2.3020771  0.1302174 2.2193646 5.5416981
#> 
#> $Sigma
#>             [,1]        [,2]      [,3]
#> [1,]  2.23167555 -0.09615015  2.346802
#> [2,] -0.09615015  2.06978184 -0.754253
#> [3,]  2.34680179 -0.75425297  6.309201
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -6.671237e-05
#> 
#> $w
#> [1] 0.6867918
#> 
#> $s
#> [1] 0.6928005
#> 


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPANEL$set_starting_values`
## ------------------------------------------------

sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)

# Modify the starting values by:
sv_list = sv$get_starting_values()   # getting them as list
sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
sv$set_starting_values(sv_list)      # providing to the class object
```
