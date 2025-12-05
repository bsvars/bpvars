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
#> [1,] -0.0016746413 -1.054270e-03  0.0020631421
#> [2,]  0.0025508012  2.040317e-03 -0.0002380164
#> [3,]  0.0004583049  1.780498e-03  0.0003554092
#> [4,]  0.0004036618  3.752105e-05 -0.0007362368
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0016746413 -1.054270e-03  0.0020631421
#> [2,]  0.0025508012  2.040317e-03 -0.0002380164
#> [3,]  0.0004583049  1.780498e-03  0.0003554092
#> [4,]  0.0004036618  3.752105e-05 -0.0007362368
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 7.6262884 3.80813762 0.12951747
#> [2,] 3.8081376 4.44421452 0.04465512
#> [3,] 0.1295175 0.04465512 1.89590372
#> 
#> , , 2
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 7.6262884 3.80813762 0.12951747
#> [2,] 3.8081376 4.44421452 0.04465512
#> [3,] 0.1295175 0.04465512 1.89590372
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0016746413 -1.054270e-03  0.0020631421
#> [2,]  0.0025508012  2.040317e-03 -0.0002380164
#> [3,]  0.0004583049  1.780498e-03  0.0003554092
#> [4,]  0.0004036618  3.752105e-05 -0.0007362368
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0007109369  0.0008392392 -0.0003851143
#> [2,]  0.0005595603 -0.0007858144  0.0009108523
#> [3,]  0.0033483189 -0.0007729957  0.0018382094
#> [4,] -0.0001961334 -0.0008954718 -0.0002302812
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 7.6262884 3.80813762 0.12951747
#> [2,] 3.8081376 4.44421452 0.04465512
#> [3,] 0.1295175 0.04465512 1.89590372
#> 
#> , , 2
#> 
#>           [,1]        [,2]        [,3]
#> [1,] 4.2456446  0.59831718  1.61664118
#> [2,] 0.5983172  1.36025740 -0.08863039
#> [3,] 1.6166412 -0.08863039  1.20763786
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  0.9997430567 -0.0003010367 -0.0014097718
#> [2,] -0.0005357368  1.0002392562 -0.0001793681
#> [3,] -0.0014787259 -0.0002882958  0.9991802214
#> [4,] -0.0012993720  0.0013768331  0.0003046661
#> 
#> $V
#>            [,1]       [,2]      [,3]       [,4]
#> [1,]  7.7909087  4.0624189 -2.700143 -0.3170697
#> [2,]  4.0624189  3.4795801 -1.401161  0.2468921
#> [3,] -2.7001431 -1.4011611  6.032157  2.2342589
#> [4,] -0.3170697  0.2468921  2.234259  3.8926141
#> 
#> $Sigma
#>           [,1]       [,2]       [,3]
#> [1,]  6.120808  2.3784746 -3.2004441
#> [2,]  2.378475  5.2491561 -0.1042415
#> [3,] -3.200444 -0.1042415  2.6732166
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0003371766
#> 
#> $w
#> [1] 0.3743645
#> 
#> $s
#> [1] 1.361106
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
