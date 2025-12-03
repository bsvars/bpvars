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
#> [1,] -0.0009702613 -3.331361e-05 -0.0009904848
#> [2,]  0.0008702908  4.547561e-04 -0.0007912835
#> [3,] -0.0003046002  1.870807e-03 -0.0002534883
#> [4,]  0.0012986430 -8.230725e-05 -0.0009930967
#> 
#> , , 2
#> 
#>              [,1]          [,2]          [,3]
#> [1,] -0.001154619  0.0003115414 -0.0004770882
#> [2,] -0.001005747  0.0000893884 -0.0002001114
#> [3,]  0.002327669 -0.0010403796 -0.0010052118
#> [4,]  0.001210882 -0.0009716711 -0.0009266087
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>          [,1]     [,2]     [,3]
#> [1,] 5.993492 4.116542 2.171344
#> [2,] 4.116542 8.789481 2.318662
#> [3,] 2.171344 2.318662 1.210627
#> 
#> , , 2
#> 
#>            [,1]        [,2]       [,3]
#> [1,]  6.1672485 -0.57921531 1.43667964
#> [2,] -0.5792153  2.04812191 0.03511273
#> [3,]  1.4366796  0.03511273 2.27560419
#> 
#> 
#> $A_g
#> , , 1
#> 
#>              [,1]          [,2]          [,3]
#> [1,] 0.0004974423 -0.0011528139  1.967120e-04
#> [2,] 0.0017009711 -0.0014303563  2.089145e-04
#> [3,] 0.0007859148  0.0005700911 -4.499543e-05
#> [4,] 0.0003571581  0.0005144635 -1.000943e-03
#> 
#> , , 2
#> 
#>               [,1]         [,2]          [,3]
#> [1,] -0.0005662147 0.0008216497  0.0008396002
#> [2,] -0.0003606009 0.0011249293 -0.0015784189
#> [3,] -0.0002654665 0.0003483165  0.0005978864
#> [4,] -0.0005323181 0.0004010320 -0.0010653583
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 2.3706823  0.3343245  1.0130254
#> [2,] 0.3343245  2.0088064 -0.4041108
#> [3,] 1.0130254 -0.4041108  1.8683838
#> 
#> , , 2
#> 
#>          [,1]     [,2]     [,3]
#> [1,] 3.936351 1.767419 1.354535
#> [2,] 1.767419 3.813019 1.163393
#> [3,] 1.354535 1.163393 4.732242
#> 
#> 
#> $V
#>            [,1]       [,2]      [,3]      [,4]
#> [1,]  1.0310837  1.8372602 -1.510685 0.4368167
#> [2,]  1.8372602  6.3638904 -5.356401 0.7330565
#> [3,] -1.5106845 -5.3564007  7.138006 4.1224978
#> [4,]  0.4368167  0.7330565  4.122498 9.0638322
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -1.40037e-05
#> 
#> $w
#> [1] 0.3627758
#> 
#> $s
#> [1] 0.3771633
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
