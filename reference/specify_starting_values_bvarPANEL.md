# R6 Class Representing StartingValuesBVARPANEL

The class StartingValuesBVARPANEL presents starting values for the
Bayesian hierarchical panel VAR model.

## Public fields

- `A_c`:

  an `KxNxC` array of starting values for the local parameter
  \\\mathbf{A}\_c\\.

- `Sigma_c`:

  an `NxNxC` array of starting values for the local parameter
  \\\mathbf{\Sigma}\_c\\.

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

- [`specify_starting_values_bvarPANEL$new()`](#method-StartingValuesBVARPANEL-new)

- [`specify_starting_values_bvarPANEL$get_starting_values()`](#method-StartingValuesBVARPANEL-get_starting_values)

- [`specify_starting_values_bvarPANEL$set_starting_values()`](#method-StartingValuesBVARPANEL-set_starting_values)

- [`specify_starting_values_bvarPANEL$clone()`](#method-StartingValuesBVARPANEL-clone)

------------------------------------------------------------------------

### Method `new()`

Create new starting values StartingValuesBVARPANEL

#### Usage

    specify_starting_values_bvarPANEL$new(C, N, p, d = 0)

#### Arguments

- `C`:

  a positive integer - the number of countries in the data.

- `N`:

  a positive integer - the number of dependent variables in the model.

- `p`:

  a positive integer - the autoregressive lag order of the SVAR model.

- `d`:

  a positive integer - the number of `exogenous` variables in the model.

#### Returns

Starting values StartingValuesBVARPANEL

#### Examples

    # starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
    sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 4)

------------------------------------------------------------------------

### Method `get_starting_values()`

Returns the elements of the starting values StartingValuesBVARPANEL as a
`list`.

#### Usage

    specify_starting_values_bvarPANEL$get_starting_values()

#### Examples

    # starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
    sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)
    sv$get_starting_values()   # show starting values as list

------------------------------------------------------------------------

### Method `set_starting_values()`

Returns the elements of the starting values StartingValuesBVARPANEL as a
`list`.

#### Usage

    specify_starting_values_bvarPANEL$set_starting_values(last_draw)

#### Arguments

- `last_draw`:

  a list containing the same elements as object StartingValuesBVARPANEL.

#### Returns

An object of class StartingValuesBVARPANEL including the last draw of
the current MCMC as the starting value to be passed to the continuation
of the MCMC estimation.

#### Examples

    sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)

    # Modify the starting values by:
    sv_list = sv$get_starting_values()   # getting them as list
    sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
    sv$set_starting_values(sv_list)      # providing to the class object

------------------------------------------------------------------------

### Method `clone()`

The objects of this class are cloneable with this method.

#### Usage

    specify_starting_values_bvarPANEL$clone(deep = FALSE)

#### Arguments

- `deep`:

  Whether to make a deep clone.

## Examples

``` r
# starting values for a Bayesian Panel VAR
sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)


## ------------------------------------------------
## Method `specify_starting_values_bvarPANEL$new`
## ------------------------------------------------

# starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 4)


## ------------------------------------------------
## Method `specify_starting_values_bvarPANEL$get_starting_values`
## ------------------------------------------------

# starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)
sv$get_starting_values()   # show starting values as list
#> $A_c
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  4.103322e-05  0.0001609013 -0.0004383053
#> [2,] -2.053233e-04 -0.0005401923  0.0002881040
#> [3,] -8.095521e-05  0.0007078659 -0.0001890340
#> [4,] -6.685817e-04  0.0002886082  0.0006314404
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0014946206 -0.0010630109 -0.0015437275
#> [2,] -0.0013547263 -0.0020060035 -0.0004503248
#> [3,]  0.0002364524 -0.0005999495  0.0010669858
#> [4,] -0.0004321832  0.0015327599  0.0007390915
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  9.7778048 -0.9476349  3.101619
#> [2,] -0.9476349  5.7023967 -2.863197
#> [3,]  3.1016192 -2.8631973  2.305088
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  2.4967944 -3.177795 -0.4745694
#> [2,] -3.1777955  9.245078  5.2670122
#> [3,] -0.4745694  5.267012  5.6085809
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  1.0012716660  0.0007051472  0.0007547030
#> [2,]  0.0012071432  1.0003373449  0.0024295955
#> [3,] -0.0004381663  0.0009919973  1.0004259834
#> [4,] -0.0001289210 -0.0005894926 -0.0003959481
#> 
#> $V
#>            [,1]       [,2]       [,3]      [,4]
#> [1,]  3.8915648 -0.8095719 -0.2931084  2.877889
#> [2,] -0.8095719  4.8249828  4.0849339 -1.289821
#> [3,] -0.2931084  4.0849339  5.8705319 -2.991855
#> [4,]  2.8778889 -1.2898207 -2.9918553  4.286539
#> 
#> $Sigma
#>            [,1]     [,2]       [,3]
#> [1,]  6.7349748 1.796124 -0.1622133
#> [2,]  1.7961238 6.583329  3.2736620
#> [3,] -0.1622133 3.273662  2.3251030
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.0001028082
#> 
#> $w
#> [1] 3.442208
#> 
#> $s
#> [1] 0.04077891
#> 


## ------------------------------------------------
## Method `specify_starting_values_bvarPANEL$set_starting_values`
## ------------------------------------------------

sv = specify_starting_values_bvarPANEL$new(C = 2, N = 3, p = 1)

# Modify the starting values by:
sv_list = sv$get_starting_values()   # getting them as list
sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
sv$set_starting_values(sv_list)      # providing to the class object
```
