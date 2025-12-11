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
#> [1,]  0.0020451393  0.0004965037 -0.0003728032
#> [2,] -0.0002702563  0.0005020127  0.0002422922
#> [3,] -0.0012768255 -0.0010399399 -0.0015184510
#> [4,]  0.0010613305  0.0007793300  0.0004250963
#> 
#> , , 2
#> 
#>               [,1]         [,2]          [,3]
#> [1,]  6.051461e-05 0.0016199643 -0.0008788840
#> [2,] -5.377549e-04 0.0005606681 -0.0003193911
#> [3,]  1.040491e-03 0.0006994739 -0.0008213249
#> [4,]  4.905058e-04 0.0010812325 -0.0010326295
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>           [,1]     [,2]      [,3]
#> [1,] 4.1966385 2.385857 0.6460942
#> [2,] 2.3858567 4.070663 3.0261089
#> [3,] 0.6460942 3.026109 7.6673435
#> 
#> , , 2
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  0.5311315 -0.6671718 -0.4060376
#> [2,] -0.6671718  2.8605027  2.2119050
#> [3,] -0.4060376  2.2119050  4.2589574
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0004480547  0.0007083164  0.0002119796
#> [2,]  0.0004254906  0.0010679395 -0.0006597962
#> [3,]  0.0000553545  0.0006219025 -0.0005489873
#> [4,]  0.0004392436 -0.0008161045 -0.0003616569
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,] -0.0014430809  0.0005596102  8.019185e-04
#> [2,] -0.0000949583 -0.0004392130 -2.594575e-04
#> [3,] -0.0009551923 -0.0006336498 -5.050476e-05
#> [4,] -0.0009121014  0.0009825083  4.811193e-04
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>           [,1]      [,2]      [,3]
#> [1,] 0.9462163 0.5908122 0.1122672
#> [2,] 0.5908122 6.3230897 2.3585968
#> [3,] 0.1122672 2.3585968 1.8201840
#> 
#> , , 2
#> 
#>            [,1]      [,2]       [,3]
#> [1,] 13.9082802 -5.410356 -0.7909062
#> [2,] -5.4103565  4.137030  2.7725416
#> [3,] -0.7909062  2.772542  3.5125537
#> 
#> 
#> $V
#>            [,1]      [,2]       [,3]       [,4]
#> [1,]  7.0078101  3.774476 -1.7438346 -0.7689369
#> [2,]  3.7744760 14.561875  4.0742435  1.0099462
#> [3,] -1.7438346  4.074243  2.9695319  0.6613022
#> [4,] -0.7689369  1.009946  0.6613022  1.4923635
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.0006998389
#> 
#> $w
#> [1] 0.22463
#> 
#> $s
#> [1] 0.4051467
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
