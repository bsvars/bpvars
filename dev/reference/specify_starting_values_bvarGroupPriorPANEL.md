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
#> [1,] -0.0003326053 -0.0007886698 -3.992852e-05
#> [2,]  0.0011640386  0.0001517511  1.745196e-04
#> [3,]  0.0005125645  0.0001526930  4.152845e-05
#> [4,]  0.0016984344  0.0003655137 -9.178548e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0008321679 -0.0009670262 -9.327989e-04
#> [2,] -0.0001074376 -0.0001210835  4.917697e-04
#> [3,]  0.0007703658  0.0001293960 -1.508810e-05
#> [4,] -0.0020869179 -0.0002832178  1.991480e-06
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]     [,2]      [,3]
#> [1,] 1.5915844 1.342811 0.1518249
#> [2,] 1.3428107 6.682483 1.5029204
#> [3,] 0.1518249 1.502920 3.1227663
#> 
#> , , 2
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  8.0331161 -0.8605415 0.1014314
#> [2,] -0.8605415  4.5852916 5.4827462
#> [3,]  0.1014314  5.4827462 8.9548861
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]         [,3]
#> [1,]  0.0002586791 -0.0013477699 0.0006006642
#> [2,] -0.0008957872  0.0009540044 0.0009362015
#> [3,]  0.0006570200 -0.0004063641 0.0014791296
#> [4,] -0.0004087224 -0.0006928474 0.0004462777
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0012553971  7.987717e-06 -4.156055e-05
#> [2,] -0.0010449691  1.802388e-03 -3.828686e-04
#> [3,]  0.0008844084 -2.163429e-05  8.159016e-05
#> [4,] -0.0005022175 -3.499712e-04 -1.406375e-03
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  1.6571648 -0.5421225 -1.135215
#> [2,] -0.5421225  2.9440335  4.109294
#> [3,] -1.1352147  4.1092943  6.357437
#> 
#> , , 2
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  1.0255138  0.9217018 -0.4872349
#> [2,]  0.9217018  5.4724453 -2.9377782
#> [3,] -0.4872349 -2.9377782  2.8381651
#> 
#> 
#> $V
#>           [,1]        [,2]      [,3]       [,4]
#> [1,]  3.436960  1.99709019 -1.415587 2.82350535
#> [2,]  1.997090  3.06793538 -1.253216 0.01715039
#> [3,] -1.415587 -1.25321630  9.443178 1.43758827
#> [4,]  2.823505  0.01715039  1.437588 4.56837325
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.001250772
#> 
#> $w
#> [1] 1.465204
#> 
#> $s
#> [1] 1.057166
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
