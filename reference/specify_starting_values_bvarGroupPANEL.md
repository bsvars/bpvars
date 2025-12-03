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
#> [1,] -0.0003649729 -0.0018730745 -0.0007096651
#> [2,] -0.0011041102  0.0006943406  0.0009787613
#> [3,]  0.0024417510  0.0007520201  0.0014204926
#> [4,] -0.0005457388  0.0004241076  0.0013029121
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0003649729 -0.0018730745 -0.0007096651
#> [2,] -0.0011041102  0.0006943406  0.0009787613
#> [3,]  0.0024417510  0.0007520201  0.0014204926
#> [4,] -0.0005457388  0.0004241076  0.0013029121
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 2.6373094  0.4484512  0.5887090
#> [2,] 0.4484512  2.3352697 -0.5224646
#> [3,] 0.5887090 -0.5224646  1.7953879
#> 
#> , , 2
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 2.6373094  0.4484512  0.5887090
#> [2,] 0.4484512  2.3352697 -0.5224646
#> [3,] 0.5887090 -0.5224646  1.7953879
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0003649729 -0.0018730745 -0.0007096651
#> [2,] -0.0011041102  0.0006943406  0.0009787613
#> [3,]  0.0024417510  0.0007520201  0.0014204926
#> [4,] -0.0005457388  0.0004241076  0.0013029121
#> 
#> , , 2
#> 
#>              [,1]          [,2]          [,3]
#> [1,] 0.0011422897 -0.0005522978  1.098633e-03
#> [2,] 0.0021285656  0.0015832272  7.409742e-05
#> [3,] 0.0015343292 -0.0008727692  1.649199e-03
#> [4,] 0.0002278468 -0.0002303588 -2.301839e-03
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]       [,2]       [,3]
#> [1,] 2.6373094  0.4484512  0.5887090
#> [2,] 0.4484512  2.3352697 -0.5224646
#> [3,] 0.5887090 -0.5224646  1.7953879
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,]  5.650261  4.069318 -1.015179
#> [2,]  4.069318 10.037364 -1.466986
#> [3,] -1.015179 -1.466986  2.654245
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  1.0005918770 -0.0012778443 -0.0006161632
#> [2,] -0.0021515770  0.9986179364  0.0011129858
#> [3,]  0.0018255571 -0.0017392397  0.9984866434
#> [4,]  0.0002061657  0.0002700564  0.0003840768
#> 
#> $V
#>           [,1]       [,2]       [,3]      [,4]
#> [1,]  2.402530 -1.0977809 -2.0322075 -2.150446
#> [2,] -1.097781  7.9010518 -0.6541773 -4.397070
#> [3,] -2.032208 -0.6541773  3.0911188  5.371158
#> [4,] -2.150446 -4.3970696  5.3711576 11.829692
#> 
#> $Sigma
#>           [,1]       [,2]       [,3]
#> [1,] 5.3225310  2.5289638  0.8953774
#> [2,] 2.5289638  2.4495637 -0.8124254
#> [3,] 0.8953774 -0.8124254  7.9871442
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0008110867
#> 
#> $w
#> [1] 0.02589376
#> 
#> $s
#> [1] 1.150246
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
