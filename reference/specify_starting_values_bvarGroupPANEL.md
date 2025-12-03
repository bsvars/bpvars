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
#> [1,] -0.0008349259 -0.0004758211 -7.343929e-04
#> [2,]  0.0012372670 -0.0009582690 -2.432759e-04
#> [3,] -0.0003167514  0.0008478495  8.476603e-04
#> [4,] -0.0012428715  0.0010790355  5.167692e-07
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0008349259 -0.0004758211 -7.343929e-04
#> [2,]  0.0012372670 -0.0009582690 -2.432759e-04
#> [3,] -0.0003167514  0.0008478495  8.476603e-04
#> [4,] -0.0012428715  0.0010790355  5.167692e-07
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  5.271087 -3.029125 -1.012919
#> [2,] -3.029125  3.749122 -0.643130
#> [3,] -1.012919 -0.643130  1.730964
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  5.271087 -3.029125 -1.012919
#> [2,] -3.029125  3.749122 -0.643130
#> [3,] -1.012919 -0.643130  1.730964
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0008349259 -0.0004758211 -7.343929e-04
#> [2,]  0.0012372670 -0.0009582690 -2.432759e-04
#> [3,] -0.0003167514  0.0008478495  8.476603e-04
#> [4,] -0.0012428715  0.0010790355  5.167692e-07
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0002232894 -4.714393e-04  0.0002490231
#> [2,] -0.0004384417  7.678221e-04 -0.0015175280
#> [3,]  0.0001828302 -1.478956e-03 -0.0002550055
#> [4,] -0.0001453979 -9.784603e-05 -0.0008949876
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  5.271087 -3.029125 -1.012919
#> [2,] -3.029125  3.749122 -0.643130
#> [3,] -1.012919 -0.643130  1.730964
#> 
#> , , 2
#> 
#>          [,1]       [,2]       [,3]
#> [1,] 8.335952  6.1835203  1.0669699
#> [2,] 6.183520  5.8659236 -0.6827536
#> [3,] 1.066970 -0.6827536  3.2038158
#> 
#> 
#> $A
#>               [,1]         [,2]         [,3]
#> [1,]  1.0002410414 1.912142e-04 0.0004009606
#> [2,] -0.0009565886 9.985418e-01 0.0004395404
#> [3,] -0.0011466726 2.730866e-04 0.9994737596
#> [4,] -0.0003001316 3.219134e-05 0.0007752416
#> 
#> $V
#>            [,1]       [,2]      [,3]       [,4]
#> [1,]  4.9562141  0.4654637  1.646979 -1.6243435
#> [2,]  0.4654637  4.9665310  3.570936 -1.0001355
#> [3,]  1.6469793  3.5709362  8.497924 -1.6500669
#> [4,] -1.6243435 -1.0001355 -1.650067  0.7481961
#> 
#> $Sigma
#>           [,1]        [,2]        [,3]
#> [1,]  1.976513 -1.44032347 -1.13508658
#> [2,] -1.440323  4.47429651 -0.02332217
#> [3,] -1.135087 -0.02332217  3.88661945
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0008563285
#> 
#> $w
#> [1] 0.8279929
#> 
#> $s
#> [1] 3.662062
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
