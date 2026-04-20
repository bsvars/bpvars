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
#>               [,1]          [,2]          [,3]
#> [1,]  0.0016251565 -1.386443e-03  9.671374e-04
#> [2,] -0.0001336065  9.251177e-06 -7.516424e-05
#> [3,] -0.0019459101 -1.562461e-03 -9.763072e-04
#> [4,] -0.0007406129  1.236710e-04 -6.417148e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0016251565 -1.386443e-03  9.671374e-04
#> [2,] -0.0001336065  9.251177e-06 -7.516424e-05
#> [3,] -0.0019459101 -1.562461e-03 -9.763072e-04
#> [4,] -0.0007406129  1.236710e-04 -6.417148e-04
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  9.4576732 -2.416149  0.4706724
#> [2,] -2.4161494  3.364787 -2.1756470
#> [3,]  0.4706724 -2.175647  1.6906320
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  9.4576732 -2.416149  0.4706724
#> [2,] -2.4161494  3.364787 -2.1756470
#> [3,]  0.4706724 -2.175647  1.6906320
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0016251565 -1.386443e-03  9.671374e-04
#> [2,] -0.0001336065  9.251177e-06 -7.516424e-05
#> [3,] -0.0019459101 -1.562461e-03 -9.763072e-04
#> [4,] -0.0007406129  1.236710e-04 -6.417148e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  5.007666e-04  1.469993e-03  0.0004539632
#> [2,] -1.326489e-04 -1.459472e-03  0.0007259877
#> [3,]  6.184156e-05  9.545721e-05 -0.0011872668
#> [4,]  1.110968e-04 -2.251484e-04 -0.0005218504
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  9.4576732 -2.416149  0.4706724
#> [2,] -2.4161494  3.364787 -2.1756470
#> [3,]  0.4706724 -2.175647  1.6906320
#> 
#> , , 2
#> 
#>            [,1]        [,2]       [,3]
#> [1,] 2.56345027  0.05932701  0.4474148
#> [2,] 0.05932701  3.87532428 -1.8925887
#> [3,] 0.44741484 -1.89258872  1.8659950
#> 
#> 
#> $A
#>              [,1]         [,2]          [,3]
#> [1,] 0.9983917650 0.0015078409 -0.0015933180
#> [2,] 0.0004874988 1.0006897539  0.0004027284
#> [3,] 0.0008525636 0.0003143477  1.0001398916
#> [4,] 0.0009566509 0.0006627397 -0.0010967779
#> 
#> $V
#>            [,1]       [,2]       [,3]       [,4]
#> [1,]  2.8750389 -1.6804947 -1.3548624 -0.2079613
#> [2,] -1.6804947  8.1748498 -0.2464288  3.4129870
#> [3,] -1.3548624 -0.2464288 10.1785280 -3.1014605
#> [4,] -0.2079613  3.4129870 -3.1014605  4.6064011
#> 
#> $Sigma
#>            [,1]      [,2]      [,3]
#> [1,]  4.0690341 0.3690185 -1.805224
#> [2,]  0.3690185 1.4908929  1.742971
#> [3,] -1.8052237 1.7429705  4.289474
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.000575607
#> 
#> $w
#> [1] 0.5447203
#> 
#> $s
#> [1] 0.6238935
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
