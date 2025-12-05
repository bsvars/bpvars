# R6 Class Representing StartingValuesBVARGROUPPRIORPANEL

The class StartingValuesBVARGROUPPRIORPANEL presents starting values for
the Bayesian hierarchical panel VAR model with country grouping

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

- `V`:

  an `KxK` matrix of starting values for the global parameter
  \\\mathbf{V}\\.

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

- [`specify_starting_values_bvarGroupPriorPANEL$new()`](#method-StartingValuesBVARGROUPPRIORPANEL-new)

- [`specify_starting_values_bvarGroupPriorPANEL$get_starting_values()`](#method-StartingValuesBVARGROUPPRIORPANEL-get_starting_values)

- [`specify_starting_values_bvarGroupPriorPANEL$set_starting_values()`](#method-StartingValuesBVARGROUPPRIORPANEL-set_starting_values)

- [`specify_starting_values_bvarGroupPriorPANEL$clone()`](#method-StartingValuesBVARGROUPPRIORPANEL-clone)

------------------------------------------------------------------------

### Method `new()`

Create new starting values StartingValuesBVARGROUPPRIORPANEL

#### Usage

    specify_starting_values_bvarGroupPriorPANEL$new(
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

Starting values StartingValuesBVARGROUPPRIORPANEL

#### Examples

    # starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
    sv = specify_starting_values_bvarGroupPriorPANEL$new(C = 2, N = 3, p = 1)

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the elements of the starting values
StartingValuesBVARGROUPPRIORPANEL as a `list`.

#### Usage

    specify_starting_values_bvarGroupPriorPANEL$get_starting_values()

#### Examples

    # starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
    sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
    sv$get_starting_values()   # show starting values as list

------------------------------------------------------------------------

### Method `set_starting_values()`

Returns the elements of the starting values
StartingValuesBVARGROUPPRIORPANEL as a `list`.

#### Usage

    specify_starting_values_bvarGroupPriorPANEL$set_starting_values(last_draw)

#### Arguments

- `last_draw`:

  a list containing the same elements as object
  StartingValuesBVARGROUPPRIORPANEL

#### Returns

An object of class StartingValuesBVARGROUPPRIORPANEL including the last
draw of the current MCMC as the starting value to be passed to the
continuation of the MCMC estimation.

#### Examples

    sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, N = 3, p = 1)

    # Modify the starting values by:
    sv_list = sv$get_starting_values()   # getting them as list
    sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
    sv$set_starting_values(sv_list)      # providing to the class object

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_starting_values_bvarGroupPriorPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
# starting values for a Bayesian Panel VAR
sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, G = 1, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPriorPANEL$new`
## ------------------------------------------------

# starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
sv = specify_starting_values_bvarGroupPriorPANEL$new(C = 2, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPriorPANEL$get_starting_values`
## ------------------------------------------------

# starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
sv$get_starting_values()   # show starting values as list
#> $group_allocation
#> [1] 1 1
#> 
#> $A_c
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0001485371  0.0003471425 -0.0001665489
#> [2,] -0.0005169653 -0.0003357901  0.0011854410
#> [3,] -0.0001590471 -0.0002340229 -0.0006952977
#> [4,]  0.0002457112  0.0010362278  0.0002168378
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -1.703014e-03 -1.108769e-03  4.058815e-04
#> [2,]  1.764945e-03  8.770686e-04  1.119327e-03
#> [3,]  5.608428e-05 -1.458712e-03  4.470198e-04
#> [4,] -3.646041e-04  7.537954e-05 -9.436684e-05
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>             [,1]      [,2]        [,3]
#> [1,]  2.13973394 0.0100654 -0.05438048
#> [2,]  0.01006540 2.6502312  0.44317657
#> [3,] -0.05438048 0.4431766  3.51599853
#> 
#> , , 2
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  5.1264689 -0.4178403  1.2125687
#> [2,] -0.4178403  1.0314329 -0.3545680
#> [3,]  1.2125687 -0.3545680  0.9859515
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0003730824  0.0007098500  0.0010976344
#> [2,]  0.0009522680  0.0005833155  0.0027522446
#> [3,] -0.0019621873 -0.0004020533 -0.0003008683
#> [4,] -0.0001028593  0.0002105842 -0.0006879552
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0008670115 -0.0002133084 -3.730411e-04
#> [2,] -0.0005495888  0.0014830182  5.172556e-04
#> [3,] -0.0001031928 -0.0009042825 -8.533425e-05
#> [4,]  0.0015192214 -0.0010462488 -4.877513e-06
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]      [,2]       [,3]
#> [1,] 4.7676346  3.913091  0.7087611
#> [2,] 3.9130906  6.792561 -1.2025413
#> [3,] 0.7087611 -1.202541  2.4256555
#> 
#> , , 2
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 3.6101495 0.44117667 3.14358161
#> [2,] 0.4411767 0.46054842 0.06677186
#> [3,] 3.1435816 0.06677186 3.82020560
#> 
#> 
#> $V
#>            [,1]      [,2]       [,3]       [,4]
#> [1,]  5.7863144 1.4173644 -0.1796042  1.9725095
#> [2,]  1.4173644 4.6539954  3.4299206  0.6223542
#> [3,] -0.1796042 3.4299206  4.3406792 -0.6019996
#> [4,]  1.9725095 0.6223542 -0.6019996  1.0507350
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.000845889
#> 
#> $w
#> [1] 1.003923
#> 
#> $s
#> [1] 0.4157688
#> 


## ------------------------------------------------
## Method `specify_starting_values_bvarGroupPriorPANEL$set_starting_values`
## ------------------------------------------------

sv = specify_starting_values_bvarGroupPriorPANEL$new(rep(1,2), C = 2, N = 3, p = 1)

# Modify the starting values by:
sv_list = sv$get_starting_values()   # getting them as list
sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
sv$set_starting_values(sv_list)      # providing to the class object
```
