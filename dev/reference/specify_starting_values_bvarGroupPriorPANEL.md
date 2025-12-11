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
#> [1,] -0.0010002601 -2.886745e-04  0.0004226483
#> [2,]  0.0017466399  1.317951e-03 -0.0022776509
#> [3,] -0.0001481622 -1.449427e-04  0.0005386325
#> [4,]  0.0010760182  4.898183e-05  0.0020660199
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0016956543 -4.869795e-04 -1.751703e-05
#> [2,]  0.0006356701 -7.486191e-04  1.613247e-03
#> [3,]  0.0005779130  8.359314e-05 -4.456217e-04
#> [4,] -0.0003931173  2.454280e-04  1.142188e-03
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>          [,1]     [,2]     [,3]
#> [1,] 8.926034 2.715502 3.545588
#> [2,] 2.715502 5.328392 3.926122
#> [3,] 3.545588 3.926122 6.685288
#> 
#> , , 2
#> 
#>           [,1]       [,2]      [,3]
#> [1,] 1.1268405  0.7746651  0.169830
#> [2,] 0.7746651  8.4762731 -3.551037
#> [3,] 0.1698300 -3.5510371  1.977368
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0005298784 -0.0005662429 -8.487356e-05
#> [2,] -0.0006074089 -0.0004491596 -7.924355e-05
#> [3,] -0.0009058177  0.0012650097  6.601221e-04
#> [4,]  0.0018608279 -0.0026884899 -1.350267e-03
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0012360006  0.0003160702 -0.0003291727
#> [2,]  0.0016803851  0.0002871262 -0.0001403803
#> [3,]  0.0002561073 -0.0004980391 -0.0001479118
#> [4,]  0.0008945388 -0.0002046329  0.0007768800
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]       [,2]      [,3]
#> [1,] 12.8243558  0.8822471 -2.923771
#> [2,]  0.8822471  3.0355205 -1.510230
#> [3,] -2.9237709 -1.5102297 12.461315
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  1.3447958 -1.329091 -0.5066557
#> [2,] -1.3290914  4.351199 -1.6045712
#> [3,] -0.5066557 -1.604571  4.7775023
#> 
#> 
#> $V
#>             [,1]       [,2]        [,3]       [,4]
#> [1,]  0.17757427 -0.2408406 -0.09678247 -0.1895986
#> [2,] -0.24084059  1.6889556 -0.82144624 -0.3380031
#> [3,] -0.09678247 -0.8214462  1.52011237  2.7900989
#> [4,] -0.18959861 -0.3380031  2.79009892 10.2682019
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0002777896
#> 
#> $w
#> [1] 1.252487
#> 
#> $s
#> [1] 1.879078
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
