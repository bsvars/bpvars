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
#> [1,]  0.0001085472 -0.0003574513 -1.297095e-03
#> [2,]  0.0012785550 -0.0003575487  9.054618e-04
#> [3,] -0.0001174998 -0.0005501055  8.798010e-06
#> [4,]  0.0004671150  0.0006053677 -7.363619e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0001085472 -0.0003574513 -1.297095e-03
#> [2,]  0.0012785550 -0.0003575487  9.054618e-04
#> [3,] -0.0001174998 -0.0005501055  8.798010e-06
#> [4,]  0.0004671150  0.0006053677 -7.363619e-04
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  1.8627721  1.289372 -0.9940758
#> [2,]  1.2893722  5.969210 -2.4013515
#> [3,] -0.9940758 -2.401351  2.3939654
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  1.8627721  1.289372 -0.9940758
#> [2,]  1.2893722  5.969210 -2.4013515
#> [3,] -0.9940758 -2.401351  2.3939654
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0001085472 -0.0003574513 -1.297095e-03
#> [2,]  0.0012785550 -0.0003575487  9.054618e-04
#> [3,] -0.0001174998 -0.0005501055  8.798010e-06
#> [4,]  0.0004671150  0.0006053677 -7.363619e-04
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0001761084 -0.0006040318 -0.0017203200
#> [2,] -0.0003192152 -0.0010029240  0.0008293239
#> [3,]  0.0016753093  0.0002971455 -0.0006101773
#> [4,] -0.0023158785 -0.0003385959 -0.0013865751
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]      [,2]       [,3]
#> [1,]  1.8627721  1.289372 -0.9940758
#> [2,]  1.2893722  5.969210 -2.4013515
#> [3,] -0.9940758 -2.401351  2.3939654
#> 
#> , , 2
#> 
#>          [,1]        [,2]        [,3]
#> [1,] 1.197727  1.48964286  1.40836103
#> [2,] 1.489643  5.06862909 -0.03365159
#> [3,] 1.408361 -0.03365159  6.09104371
#> 
#> 
#> $A
#>               [,1]          [,2]          [,3]
#> [1,]  0.9992761231  0.0017846231 -1.166198e-03
#> [2,] -0.0011213490  1.0008541110  4.581534e-05
#> [3,] -0.0004704247 -0.0011322399  9.995515e-01
#> [4,]  0.0004628324  0.0007141077 -6.119991e-04
#> 
#> $V
#>            [,1]       [,2]       [,3]       [,4]
#> [1,]  3.4866825 -0.8525908 -1.3195683  1.6418394
#> [2,] -0.8525908 10.4890506 -4.4298160 -0.2646474
#> [3,] -1.3195683 -4.4298160  4.1299590 -0.8018115
#> [4,]  1.6418394 -0.2646474 -0.8018115  1.7862860
#> 
#> $Sigma
#>            [,1]       [,2]       [,3]
#> [1,]  3.1845934 -0.3406155 -0.5745434
#> [2,] -0.3406155  0.2734954  0.7974479
#> [3,] -0.5745434  0.7974479  4.2659897
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.002057734
#> 
#> $w
#> [1] 0.73523
#> 
#> $s
#> [1] 1.088701
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
