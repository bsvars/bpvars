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
#>               [,1]          [,2]         [,3]
#> [1,] -0.0002931272 -0.0010591641 0.0014403048
#> [2,]  0.0013418715  0.0003323653 0.0006450013
#> [3,]  0.0010090068 -0.0008638433 0.0006907284
#> [4,]  0.0004296830 -0.0008893614 0.0009815040
#> 
#> , , 2
#> 
#>               [,1]          [,2]         [,3]
#> [1,] -0.0002931272 -0.0010591641 0.0014403048
#> [2,]  0.0013418715  0.0003323653 0.0006450013
#> [3,]  0.0010090068 -0.0008638433 0.0006907284
#> [4,]  0.0004296830 -0.0008893614 0.0009815040
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]      [,2]     [,3]
#> [1,] 3.8110140 0.9206841 3.760625
#> [2,] 0.9206841 2.9992414 1.592066
#> [3,] 3.7606247 1.5920655 4.497659
#> 
#> , , 2
#> 
#>           [,1]      [,2]     [,3]
#> [1,] 3.8110140 0.9206841 3.760625
#> [2,] 0.9206841 2.9992414 1.592066
#> [3,] 3.7606247 1.5920655 4.497659
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]         [,3]
#> [1,] -0.0002931272 -0.0010591641 0.0014403048
#> [2,]  0.0013418715  0.0003323653 0.0006450013
#> [3,]  0.0010090068 -0.0008638433 0.0006907284
#> [4,]  0.0004296830 -0.0008893614 0.0009815040
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0002371628 -0.0010781678  0.0014765262
#> [2,]  0.0014083525  0.0001731320 -0.0011950086
#> [3,] -0.0001314970  0.0020126559 -0.0001211993
#> [4,]  0.0001405531  0.0003297795 -0.0008456444
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]      [,2]     [,3]
#> [1,] 3.8110140 0.9206841 3.760625
#> [2,] 0.9206841 2.9992414 1.592066
#> [3,] 3.7606247 1.5920655 4.497659
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  7.924206  2.126269 -1.878950
#> [2,]  2.126269  3.485184 -2.541433
#> [3,] -1.878950 -2.541433  4.817971
#> 
#> 
#> $A
#>               [,1]          [,2]         [,3]
#> [1,]  1.0000150721 -0.0006161309  0.001764266
#> [2,]  0.0009408093  1.0006034559 -0.001008718
#> [3,]  0.0004775646  0.0002667782  0.998495034
#> [4,] -0.0010849599 -0.0007301084  0.001076887
#> 
#> $V
#>            [,1]       [,2]      [,3]      [,4]
#> [1,]  7.4888896  1.5484614 0.1773179 -1.588362
#> [2,]  1.5484614  4.0821409 0.1764684 -1.509506
#> [3,]  0.1773179  0.1764684 5.8799247  3.017547
#> [4,] -1.5883616 -1.5095056 3.0175469  3.161169
#> 
#> $Sigma
#>            [,1]       [,2]      [,3]
#> [1,]  1.8087615 -0.7563708 0.3423239
#> [2,] -0.7563708  1.3983176 0.1359319
#> [3,]  0.3423239  0.1359319 0.7203925
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0001245968
#> 
#> $w
#> [1] 0.9443319
#> 
#> $s
#> [1] 0.9828766
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
