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
#>               [,1]          [,2]         [,3]
#> [1,] -6.032948e-05 -5.349215e-05 3.424267e-04
#> [2,] -1.838823e-03 -1.489636e-03 9.741050e-04
#> [3,]  9.159927e-04  1.342188e-03 2.922645e-05
#> [4,] -5.879317e-04  6.510351e-04 8.835247e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0001260629 -0.0002873085 -0.0000198551
#> [2,] -0.0004770500  0.0010292392 -0.0003822558
#> [3,] -0.0005862405 -0.0013832749 -0.0021480650
#> [4,] -0.0005860822  0.0000856788 -0.0014333620
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  2.7291683 -0.9508608  1.944283
#> [2,] -0.9508608  1.2895854 -1.062072
#> [3,]  1.9442829 -1.0620721  4.145970
#> 
#> , , 2
#> 
#>           [,1]     [,2]     [,3]
#> [1,] 10.265387 2.007704 1.277269
#> [2,]  2.007704 5.337685 4.693265
#> [3,]  1.277269 4.693265 8.953219
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0006391397  0.0004483043 -4.087378e-04
#> [2,]  0.0003799604 -0.0005180053 -1.305278e-03
#> [3,]  0.0011744363 -0.0007364540 -3.108336e-05
#> [4,] -0.0001441329 -0.0007866849 -6.159218e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -6.058252e-04  0.0003997688  1.063177e-03
#> [2,]  8.282608e-05  0.0007317225 -1.725117e-03
#> [3,] -2.427779e-04 -0.0003788915  1.874578e-03
#> [4,]  2.776325e-03 -0.0015890966  9.366396e-05
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>          [,1]       [,2]       [,3]
#> [1,] 7.077737  3.1400561  2.3092604
#> [2,] 3.140056  5.0375442 -0.4184487
#> [3,] 2.309260 -0.4184487  4.1413367
#> 
#> , , 2
#> 
#>           [,1]       [,2]       [,3]
#> [1,]  9.980228 -1.0302256 -1.7582319
#> [2,] -1.030226  3.2116102  0.6555256
#> [3,] -1.758232  0.6555256  3.6068535
#> 
#> 
#> $V
#>           [,1]     [,2]     [,3]      [,4]
#> [1,]  3.539065 1.083681 2.212776 -1.387121
#> [2,]  1.083681 1.701451 2.861557  1.793537
#> [3,]  2.212776 2.861557 5.754884  2.006751
#> [4,] -1.387121 1.793537 2.006751  9.472338
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.002761011
#> 
#> $w
#> [1] 0.05818075
#> 
#> $s
#> [1] 1.498629
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
