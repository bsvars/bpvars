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
#> [1,] -0.0005015554  0.0007808593 -0.0003352589
#> [2,]  0.0001995498  0.0012491731 -0.0001026296
#> [3,] -0.0011213734  0.0001442885 -0.0007166034
#> [4,] -0.0014265580 -0.0035179622  0.0012203955
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0011854822  0.0011345439  0.0002806465
#> [2,] -0.0011400707 -0.0013759811 -0.0005450357
#> [3,] -0.0002185149  0.0007558173 -0.0004005377
#> [4,]  0.0009312591  0.0010951370 -0.0012203269
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>             [,1]        [,2]       [,3]
#> [1,]  0.43923247  0.06100123 -0.4358746
#> [2,]  0.06100123  2.94308950 -0.1955245
#> [3,] -0.43587456 -0.19552453  1.3858413
#> 
#> , , 2
#> 
#>           [,1]     [,2]      [,3]
#> [1,] 1.0426099 2.495828 0.4082801
#> [2,] 2.4958285 9.562671 2.3905114
#> [3,] 0.4082801 2.390511 3.1473449
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0007821200  1.535457e-04  0.0006687413
#> [2,] -0.0001402006  8.900046e-05  0.0005782761
#> [3,]  0.0007811265 -3.767206e-04 -0.0015732411
#> [4,]  0.0005859177  1.339413e-03  0.0013503826
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0018595472 -0.0018745246  0.0021674559
#> [2,] -0.0009170707  0.0008633796 -0.0005565099
#> [3,]  0.0005436097  0.0003559320  0.0009990298
#> [4,] -0.0007652771 -0.0005511687 -0.0015975778
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]       [,2]       [,3]
#> [1,]  6.785562 -1.4447041 -2.6757040
#> [2,] -1.444704  1.3883308 -0.1335593
#> [3,] -2.675704 -0.1335593  3.8019525
#> 
#> , , 2
#> 
#>           [,1]      [,2]      [,3]
#> [1,] 3.5919178 0.2597847 0.7084971
#> [2,] 0.2597847 1.8396626 0.4016342
#> [3,] 0.7084971 0.4016342 2.2536318
#> 
#> 
#> $V
#>           [,1]      [,2]       [,3]      [,4]
#> [1,]  6.986208 1.4184872 -2.5883706 5.0289358
#> [2,]  1.418487 4.8343424  0.5002493 0.2850082
#> [3,] -2.588371 0.5002493  3.5924177 0.6388054
#> [4,]  5.028936 0.2850082  0.6388054 7.7774828
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] -0.000990337
#> 
#> $w
#> [1] 3.205128
#> 
#> $s
#> [1] 2.99397
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
