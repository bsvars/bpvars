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
#>              [,1]          [,2]          [,3]
#> [1,] 4.959917e-04 -0.0001261445 -0.0011286078
#> [2,] 5.488361e-05  0.0002237654  0.0025362249
#> [3,] 1.973081e-03  0.0003533741 -0.0012090882
#> [4,] 5.062517e-04 -0.0006597012  0.0001515618
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  8.781812e-04  0.0007695887 -0.0012993604
#> [2,]  4.960108e-05  0.0001202317  0.0012244111
#> [3,] -2.031923e-05  0.0005241317  0.0003070427
#> [4,]  7.787544e-04 -0.0010974396  0.0006283338
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  2.6810377 -0.6055892 -3.3287059
#> [2,] -0.6055892  8.0621576  0.4825678
#> [3,] -3.3287059  0.4825678  5.3074204
#> 
#> , , 2
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  5.4427898  0.9320581 -1.9409032
#> [2,]  0.9320581  5.5615783 -0.8140666
#> [3,] -1.9409032 -0.8140666  0.8918158
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0015411176 -0.0014536561 -3.470135e-05
#> [2,]  0.0001350347  0.0013186049  1.944058e-03
#> [3,]  0.0004543041 -0.0007955113 -1.930526e-03
#> [4,] -0.0003145199  0.0001393424  2.952993e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0012847610  2.330695e-04 -0.0001289235
#> [2,] -0.0008973402  9.494426e-05  0.0017055523
#> [3,]  0.0001360947 -3.429044e-04 -0.0013333443
#> [4,]  0.0005770136 -1.365487e-03 -0.0003095518
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]     [,2]      [,3]
#> [1,] 10.202622 1.847299 -1.551377
#> [2,]  1.847299 1.420476  1.086001
#> [3,] -1.551377 1.086001  3.684806
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  2.094719 -1.505970 -1.205167
#> [2,] -1.505970  7.636419  5.780482
#> [3,] -1.205167  5.780482  4.838128
#> 
#> 
#> $V
#>           [,1]       [,2]       [,3]       [,4]
#> [1,] 3.3287004  0.6474273  0.5210789  2.1039486
#> [2,] 0.6474273  5.9347290 -3.2659674  0.1402783
#> [3,] 0.5210789 -3.2659674  3.7195731 -0.7692314
#> [4,] 2.1039486  0.1402783 -0.7692314  4.8593762
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0006929803
#> 
#> $w
#> [1] 0.4076107
#> 
#> $s
#> [1] 2.063179
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
