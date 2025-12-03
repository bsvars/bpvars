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
#> [1,] -0.0003967820  4.438638e-04  0.0007257579
#> [2,] -0.0011027454  2.260478e-03 -0.0003395310
#> [3,] -0.0010425425 -4.934533e-04 -0.0016291101
#> [4,] -0.0009956206 -8.050212e-06 -0.0020517201
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  3.193303e-04 -0.0007648629  0.0001264103
#> [2,]  3.355534e-07 -0.0004588011  0.0004654404
#> [3,] -1.051000e-04 -0.0012879506 -0.0020020111
#> [4,]  3.245233e-04  0.0001076986  0.0012203549
#> 
#> 
#> $Sigma_c
#> , , 1
#> 
#>            [,1]       [,2]      [,3]
#> [1,]  0.6067443 -0.9579717 -1.139506
#> [2,] -0.9579717  1.6293767  1.788610
#> [3,] -1.1395055  1.7886098  4.128845
#> 
#> , , 2
#> 
#>          [,1]      [,2]      [,3]
#> [1,] 1.595274 1.0290857 2.0168637
#> [2,] 1.029086 4.9234401 0.4393808
#> [3,] 2.016864 0.4393808 3.1847401
#> 
#> 
#> $A_g
#> , , 1
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0003271208 -0.0003368007  0.0009189034
#> [2,]  0.0003822793 -0.0014315075  0.0016208725
#> [3,] -0.0017745484 -0.0014985920  0.0003480416
#> [4,]  0.0011022135 -0.0022282775 -0.0005538515
#> 
#> , , 2
#> 
#>               [,1]          [,2]          [,3]
#> [1,]  0.0009030557  0.0007082255 -0.0006869366
#> [2,]  0.0016133073  0.0001284630 -0.0002456017
#> [3,] -0.0006931743 -0.0003765208 -0.0001773986
#> [4,] -0.0013486144  0.0005908624 -0.0009104227
#> 
#> 
#> $Sigma_g
#> , , 1
#> 
#>            [,1]       [,2]       [,3]
#> [1,]  0.7739362  1.3568013 -0.4935095
#> [2,]  1.3568013  4.2203088 -0.3959582
#> [3,] -0.4935095 -0.3959582  4.3369115
#> 
#> , , 2
#> 
#>            [,1]      [,2]      [,3]
#> [1,]  2.3718112 -2.282624 0.4740721
#> [2,] -2.2826239  5.757910 1.5487222
#> [3,]  0.4740721  1.548722 3.1328194
#> 
#> 
#> $V
#>           [,1]      [,2]     [,3]      [,4]
#> [1,] 6.3493179 0.7710818 2.031162  2.339671
#> [2,] 0.7710818 2.8892201 1.135428  2.114888
#> [3,] 2.0311622 1.1354279 6.638683  8.298305
#> [4,] 2.3396708 2.1148883 8.298305 10.740409
#> 
#> $nu
#> [1] 4.1
#> 
#> $m
#> [1] 0.001267778
#> 
#> $w
#> [1] 0.06645275
#> 
#> $s
#> [1] 0.1762876
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
