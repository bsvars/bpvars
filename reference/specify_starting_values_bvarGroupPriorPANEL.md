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
#> [1,]  0.0022679172 -4.086001e-05  0.0007299759
#> [2,] -0.0001493294 -1.981068e-04  0.0003717162
#> [3,] -0.0002692995  7.305678e-04  0.0006316775
#> [4,]  0.0001909800  8.685156e-04 -0.0001145154
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0008849382  0.0001634001 -0.0005731142
#> [2,] -0.0001613821 -0.0007290002  0.0008779167
#> [3,] -0.0010844371  0.0012395945  0.0018434339
#> [4,] -0.0011376588 -0.0005464326 -0.0017251301
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>             [,1]        [,2]       [,3]
#> [1,]  2.85825342 -0.08320443 0.92162940
#> [2,] -0.08320443  0.58363204 0.04383107
#> [3,]  0.92162940  0.04383107 2.36831564
#> 
#> , , 2
#> 
#>           [,1]       [,2]      [,3]
#> [1,] 6.9317946  0.9673126  0.193280
#> [2,] 0.9673126  3.1146798 -1.200256
#> [3,] 0.1932800 -1.2002562  1.013965
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]         [,3]
#> [1,] -0.0004836335  0.0011894001 0.0008688274
#> [2,]  0.0006937438 -0.0007906842 0.0013709297
#> [3,]  0.0012144311 -0.0004215723 0.0005070696
#> [4,] -0.0006875245  0.0011308531 0.0004690688
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0002353822 -0.0006218638 -0.0010189565
#> [2,]  0.0018355113  0.0018552278 -0.0008602544
#> [3,] -0.0010191854  0.0006385461  0.0010573561
#> [4,] -0.0022634848  0.0006224219  0.0006815326
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>          [,1]      [,2]      [,3]
#> [1,] 2.258172 2.2673703 1.4416644
#> [2,] 2.267370 2.7132328 0.9185512
#> [3,] 1.441664 0.9185512 1.6537175
#> 
#> , , 2
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 13.193269 -1.3016977 -5.2177455
#> [2,] -1.301698  5.8237466  0.1695134
#> [3,] -5.217745  0.1695134  4.5975516
#> 
#> 
#> $V
#>            [,1]      [,2]      [,3]       [,4]
#> [1,]  3.6233429  1.871045 1.0267044 -0.6015694
#> [2,]  1.8710453  2.905577 1.1548317 -1.3686891
#> [3,]  1.0267044  1.154832 2.0483626  0.6653334
#> [4,] -0.6015694 -1.368689 0.6653334  6.3445732
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0005786572
#> 
#> $w
#> [1] 0.1128977
#> 
#> $s
#> [1] 1.380762
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
