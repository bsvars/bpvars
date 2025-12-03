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
#>               [,1]         [,2]          [,3]
#> [1,]  0.0012025475 -0.000275210 -0.0005545753
#> [2,]  0.0003745516  0.001049865 -0.0009382179
#> [3,] -0.0005498476 -0.000775109  0.0003550318
#> [4,]  0.0003957470 -0.001653404  0.0001218497
#> 
#> , , 2
#> 
#>               [,1]         [,2]          [,3]
#> [1,]  0.0012025475 -0.000275210 -0.0005545753
#> [2,]  0.0003745516  0.001049865 -0.0009382179
#> [3,] -0.0005498476 -0.000775109  0.0003550318
#> [4,]  0.0003957470 -0.001653404  0.0001218497
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]      [,2]      [,3]
#> [1,] 13.186562 -3.590416  1.922137
#> [2,] -3.590416  1.793075 -1.509502
#> [3,]  1.922137 -1.509502  3.029128
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,] 13.186562 -3.590416  1.922137
#> [2,] -3.590416  1.793075 -1.509502
#> [3,]  1.922137 -1.509502  3.029128
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]         [,2]          [,3]
#> [1,]  0.0012025475 -0.000275210 -0.0005545753
#> [2,]  0.0003745516  0.001049865 -0.0009382179
#> [3,] -0.0005498476 -0.000775109  0.0003550318
#> [4,]  0.0003957470 -0.001653404  0.0001218497
#> 
#> , , 2
#> 
#>               [,1]         [,2]          [,3]
#> [1,]  1.834496e-03 0.0012760614  0.0003886509
#> [2,]  8.714386e-04 0.0017921817 -0.0005923349
#> [3,] -1.286577e-03 0.0009126986  0.0007816720
#> [4,]  1.598311e-06 0.0005831169  0.0000781791
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]      [,2]      [,3]
#> [1,] 13.186562 -3.590416  1.922137
#> [2,] -3.590416  1.793075 -1.509502
#> [3,]  1.922137 -1.509502  3.029128
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  1.3676125 0.2430097 -0.2363659
#> [2,]  0.2430097 7.0389503  8.0112772
#> [3,] -0.2363659 8.0112772 10.5941470
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  0.9996762389 -2.620754e-03  0.0012115308
#> [2,] -0.0002011910  1.000375e+00 -0.0004187909
#> [3,] -0.0013280628  7.143638e-05  1.0013212474
#> [4,]  0.0003016007  1.729054e-03  0.0004314147
#> 
#> $V
#>            [,1]       [,2]       [,3]     [,4]
#> [1,]  4.3790602 -0.5401307  5.1080384 1.757138
#> [2,] -0.5401307  1.5556607  0.0664427 1.367227
#> [3,]  5.1080384  0.0664427 12.2193558 6.404224
#> [4,]  1.7571382  1.3672268  6.4042243 5.367738
#> 
#> $Sigma
#>            [,1]        [,2]      [,3]
#> [1,] 1.95617205  0.05627367  1.006125
#> [2,] 0.05627367  4.05400467 -1.549504
#> [3,] 1.00612521 -1.54950379  1.167830
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 5.992388e-06
#> 
#> $w
#> [1] 0.5335486
#> 
#> $s
#> [1] 3.713516
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
