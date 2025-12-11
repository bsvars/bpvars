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
#> [1,] -1.180656e-03  1.472375e-03 -0.0021866212
#> [2,]  2.645393e-05  4.805755e-04  0.0001341493
#> [3,] -3.131613e-04 -8.742601e-04 -0.0007548127
#> [4,] -8.282135e-04  8.180268e-05 -0.0013614213
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0008814713  0.0010270118  0.0011702615
#> [2,]  0.0006213608 -0.0001332637 -0.0006804733
#> [3,]  0.0011011200  0.0005233351 -0.0006669178
#> [4,]  0.0011177702  0.0005904214 -0.0005000062
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>             [,1]        [,2]     [,3]
#> [1,]  1.77810228 -0.04419595 1.631230
#> [2,] -0.04419595  1.11557368 1.780899
#> [3,]  1.63122994  1.78089941 4.569892
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,] 2.4999980 0.2337386 0.6435294
#> [2,] 0.2337386 3.7649351 1.5946413
#> [3,] 0.6435294 1.5946413 2.1653559
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0003770355  0.0013850169  4.796212e-04
#> [2,] -0.0010411384 -0.0009596247 -8.308636e-05
#> [3,] -0.0004514432 -0.0001078488 -7.273594e-04
#> [4,] -0.0005825044  0.0003080230  9.116179e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -2.889892e-04 -0.0000228634 -0.0010667794
#> [2,] -7.314975e-05  0.0012914836  0.0010076413
#> [3,]  4.895530e-04  0.0020736402 -0.0011118369
#> [4,]  7.540867e-04 -0.0003321624 -0.0002228225
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  0.5650330 -2.0145559 -0.4344754
#> [2,] -2.0145559  8.5460642  0.8216758
#> [3,] -0.4344754  0.8216758  6.1855751
#> 
#> , , 2
#> 
#>             [,1]        [,2]       [,3]
#> [1,]  4.35836705  0.03401709 -3.6556899
#> [2,]  0.03401709  1.55292122 -0.1528956
#> [3,] -3.65568986 -0.15289558  6.7477852
#> 
#> 
#> $V
#>           [,1]      [,2]     [,3]      [,4]
#> [1,]  2.449653 -1.923825 1.344963 -2.287337
#> [2,] -1.923825 13.954510 2.330857  9.012048
#> [3,]  1.344963  2.330857 4.484272  2.196746
#> [4,] -2.287337  9.012048 2.196746  8.457608
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.001015963
#> 
#> $w
#> [1] 1.145154
#> 
#> $s
#> [1] 0.1839193
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
