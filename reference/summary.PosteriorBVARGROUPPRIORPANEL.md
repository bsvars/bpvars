# Provides posterior estimation summary for Bayesian Hierarchical Panel Vector Autoregressions with group-specific global prior

Provides posterior mean, standard deviations, as well as 5 and 95
percentiles of the parameters for all `C` countries.

## Usage

``` r
# S3 method for class 'PosteriorBVARGROUPPRIORPANEL'
summary(object, ...)
```

## Arguments

- object:

  an object of class `PosteriorBVARGROUPPRIORPANEL` obtained using the
  [`estimate()`](https://bsvars.org/bsvars/reference/estimate.html)
  function applied to Vector Autoregressions containing draws from the
  posterior distribution of the parameters.

- ...:

  additional arguments affecting the summary produced.

## Value

A list reporting the posterior mean, standard deviations, as well as 5
and 95 percentiles of the country-specific parameters.

## See also

[`estimate.BVARGROUPPRIORPANEL`](http://bsvars.org/bpvars/reference/estimate.BVARGROUPPRIORPANEL.md),
[`specify_bvarGroupPriorPANEL`](http://bsvars.org/bpvars/reference/specify_bvarGroupPriorPANEL.md)

## Author

Tomasz Woźniak <wozniak.tom@pm.me>

## Examples

``` r
# specify the model
specification = specify_bvarGroupPriorPANEL$new(
      data = ilo_dynamic_panel[1:5],
      group_allocation = country_grouping_region[1:5]
)
#> Country groupings have been pre-specified and will not be estimated.
burn_in       = estimate(specification, 5)             # run the burn-in
#> **************************************************|
#>  bpvars: Forecasting with Bayesian Panel VARs     |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
posterior     = estimate(burn_in, 5)                   # estimate the model
#> **************************************************|
#>  bpvars: Forecasting with Bayesian Panel VARs     |
#> **************************************************|
#>  Progress of the MCMC simulation for 5 draws
#>     Every draw is saved via MCMC thinning
#>  Press Esc to interrupt the computations
#> **************************************************|
summary(posterior)
#> $AFG
#> $AFG$Sigma
#> $AFG$Sigma$equation1
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01432484 0.01200091 0.004412061     0.030336
#> 
#> $AFG$Sigma$equation2
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.009240934 0.01484779 -0.02427502  0.009373834
#> Sigma[2,2]  0.204056262 0.05125380  0.15230739  0.269729390
#> 
#> $AFG$Sigma$equation3
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.006508545 0.02361511  -0.0260343   0.02085524
#> Sigma[3,2] -0.207787923 0.04817716  -0.2619662  -0.16148280
#> Sigma[3,3]  0.422939959 0.06464208   0.3484777   0.49295742
#> 
#> $AFG$Sigma$equation4
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.001779375 0.02033562 -0.02608365   0.01558106
#> Sigma[4,2] -0.134799601 0.03932045 -0.18168446  -0.09602008
#> Sigma[4,3]  0.374601313 0.05718646  0.30550031   0.43032666
#> Sigma[4,4]  0.357463964 0.05257305  0.29402851   0.40528125
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                   mean         sd 5% quantile 95% quantile
#> lag1_var1  0.974885927 0.02789308  0.94878003   1.01078168
#> lag1_var2 -0.004472757 0.04053528 -0.04026462   0.04462263
#> lag1_var3  0.002117092 0.06655907 -0.05680673   0.09108277
#> lag1_var4  0.002196633 0.05714422 -0.07376211   0.05317361
#> const      0.490312829 0.24388887  0.22882393   0.77531180
#> 
#> $AFG$A$equation2
#>                  mean         sd  5% quantile 95% quantile
#> lag1_var1   0.2498956 0.16164381   0.02956756    0.3754917
#> lag1_var2   1.7122146 0.11847288   1.56931281    1.8378086
#> lag1_var3   1.4843768 0.08449214   1.38596404    1.5747748
#> lag1_var4  -1.2682487 0.09484314  -1.38649938   -1.1681192
#> const     -15.8367953 3.32245778 -19.53250035  -12.1186844
#> 
#> $AFG$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.03827256 0.3516786  -0.3577573    0.4241422
#> lag1_var2 -1.32852500 0.2367125  -1.6544606   -1.1669651
#> lag1_var3 -1.06733865 0.2921721  -1.3614235   -0.6935006
#> lag1_var4  1.65584395 0.2764414   1.2740357    1.8353868
#> const     22.84331409 2.1214797  20.6622512   25.1537380
#> 
#> $AFG$A$equation4
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.08267351 0.3207861  -0.2166956    0.4992661
#> lag1_var2 -0.61740260 0.2109490  -0.9062197   -0.4659678
#> lag1_var3 -0.46244047 0.2760704  -0.7712771   -0.1313244
#> lag1_var4  1.25994389 0.2566303   0.9110730    1.4678099
#> const     10.66353994 2.0473330   8.2905544   13.0338986
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01727693 0.007801884 0.008111398   0.02560165
#> 
#> $AGO$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.02124732 0.01313596 -0.03805389 -0.009087473
#> Sigma[2,2]  0.15693062 0.02637119  0.13918261  0.192556559
#> 
#> $AGO$Sigma$equation3
#>                    mean         sd  5% quantile 95% quantile
#> Sigma[3,1]  0.004381142 0.01110272 -0.008167468   0.01626229
#> Sigma[3,2] -0.133120151 0.02135339 -0.157797145  -0.11177345
#> Sigma[3,3]  0.433942896 0.09837650  0.321083436   0.54913357
#> 
#> $AGO$Sigma$equation4
#>                    mean          sd 5% quantile 95% quantile
#> Sigma[4,1] -0.009056634 0.008940971 -0.01632578  0.002976905
#> Sigma[4,2] -0.020526576 0.016943393 -0.04247021 -0.003906476
#> Sigma[4,3]  0.388214603 0.101236496  0.27157064  0.505429278
#> Sigma[4,4]  0.433082137 0.119719921  0.29264243  0.571409419
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.8441546 0.09346396   0.7635102    0.9495126
#> lag1_var2  0.5380207 0.14644583   0.3764559    0.7147397
#> lag1_var3  0.7147698 0.18132598   0.4759557    0.8837035
#> lag1_var4 -0.6372586 0.14529183  -0.7733065   -0.4524047
#> const     -1.8704260 5.98616942  -8.5752689    3.2835986
#> 
#> $AGO$A$equation2
#>                   mean         sd  5% quantile 95% quantile
#> lag1_var1   0.05662502 0.08329524  -0.05591408    0.1197944
#> lag1_var2   0.71188769 0.25380806   0.43156691    0.9714974
#> lag1_var3  -0.22373291 0.31796985  -0.54733332    0.1760431
#> lag1_var4   0.36533844 0.27728679   0.00330401    0.6069529
#> const     -10.47624195 6.15977815 -16.69073742   -2.7694493
#> 
#> $AGO$A$equation3
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.06964241  0.2147040  -0.3539610   0.08667138
#> lag1_var2 -0.95085993  0.8813421  -1.5375028   0.25372780
#> lag1_var3 -0.55558558  1.1733744  -1.3552943   1.04554397
#> lag1_var4  1.07555230  0.9640418  -0.2416003   1.77046675
#> const     34.66020201 18.5166956  14.6890426  57.13912078
#> 
#> $AGO$A$equation4
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.1207230  0.2020498  -0.3921507   0.03487909
#> lag1_var2 -0.5652903  0.8143773  -1.2107301   0.54386437
#> lag1_var3 -0.9447131  1.0916926  -1.7742421   0.54739907
#> lag1_var4  1.6447346  0.9411127   0.3772949   2.44608809
#> const     23.3858615 17.1186733   7.4570777  45.18651327
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01126088 0.01751779 0.001812054   0.03522765
#> 
#> $ALB$Sigma$equation2
#>                  mean        sd 5% quantile 95% quantile
#> Sigma[2,1] -0.0979698 0.1049479  -0.2431799  -0.03542091
#> Sigma[2,2]  7.1185697 0.9785451   5.8372955   7.97229449
#> 
#> $ALB$Sigma$equation3
#>                   mean         sd  5% quantile 95% quantile
#> Sigma[3,1]  0.05374734 0.08322855 -0.002820088    0.1676769
#> Sigma[3,2] -3.95326766 1.01709937 -4.960655126   -2.8061251
#> Sigma[3,3]  4.30888827 1.38144820  2.761053837    5.5130860
#> 
#> $ALB$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.01533572 0.01876456 -0.03851886   0.00397629
#> Sigma[4,2]  1.03028265 0.88666062  0.26994252   2.20938550
#> Sigma[4,3]  1.94021639 0.88580713  1.01780482   2.90755726
#> Sigma[4,4]  3.16009597 0.85567271  2.11862295   4.00317028
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.99160333 0.1390808  0.79949634   1.07702470
#> lag1_var2 -0.07077312 0.1477910 -0.26878099   0.05739931
#> lag1_var3 -0.12490915 0.2279484 -0.43167852   0.06706746
#> lag1_var4  0.10091703 0.1792074 -0.05358075   0.34049717
#> const      1.59553452 6.1673992 -2.79335273   9.95970103
#> 
#> $ALB$A$equation2
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1 -3.783587  1.1673735   -4.969635    -2.348794
#> lag1_var2  2.897746  0.7902072    2.033725     3.752956
#> lag1_var3  3.975609  1.1423405    2.705249     5.036098
#> lag1_var4 -3.231479  1.1035351   -4.258023    -2.038351
#> const     49.672029 28.2187938   15.759818    76.941276
#> 
#> $ALB$A$equation3
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1  2.001689  0.6371584   1.2475511    2.6989018
#> lag1_var2 -1.856607  1.2497804  -3.0221549   -0.4284166
#> lag1_var3 -2.375040  1.8872615  -3.9931432   -0.1980688
#> lag1_var4  2.688186  1.5915349   0.8099422    4.0820237
#> const     -7.727175 31.0515817 -45.5056033   24.4293530
#> 
#> $ALB$A$equation4
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.6859509  0.5422296   -1.138932   0.03120851
#> lag1_var2 -0.2650955  1.2452028   -1.276733   1.29620455
#> lag1_var3 -0.1684318  1.9869223   -1.815370   2.32272459
#> lag1_var4  1.0539110  1.6906586   -1.055371   2.52495019
#> const     24.6707038 23.5771190    1.012435  49.95395795
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.001591186 0.0004618945 0.001124653   0.00207262
#> 
#> $ARE$Sigma$equation2
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.007401741 0.00080838 -0.00829108 -0.006541799
#> Sigma[2,2]  0.169349082 0.03213135  0.13872189  0.208434394
#> 
#> $ARE$Sigma$equation3
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[3,1]  0.0119470 0.005317968  0.00709272   0.01891188
#> Sigma[3,2] -0.1656647 0.034978719 -0.21172081  -0.13304959
#> Sigma[3,3]  0.3591533 0.082480221  0.25182450   0.43575183
#> 
#> $ARE$Sigma$equation4
#>                   mean          sd   5% quantile 95% quantile
#> Sigma[4,1]  0.00633765 0.005296416  0.0008931397   0.01293473
#> Sigma[4,2] -0.03403123 0.016128625 -0.0513249764  -0.01582810
#> Sigma[4,3]  0.23433412 0.073167044  0.1466760428   0.31538366
#> Sigma[4,4]  0.21217784 0.071341893  0.1298715396   0.29206052
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9423310 0.03546958   0.9038462    0.9855790
#> lag1_var2  0.2161952 0.03438159   0.1860083    0.2617191
#> lag1_var3  0.2454500 0.04235460   0.1943323    0.2929379
#> lag1_var4 -0.2458377 0.05097636  -0.3014075   -0.1831254
#> const      1.5133511 0.41940301   0.9689145    1.9133133
#> 
#> $ARE$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4867637 0.3408340   0.1155964    0.8655311
#> lag1_var2  0.2651890 0.3632215  -0.1672314    0.6573756
#> lag1_var3 -0.2813161 0.4005443  -0.7180208    0.1772403
#> lag1_var4  0.2535101 0.3943543  -0.1718663    0.6733741
#> const     -9.3775466 3.9333771 -13.4034738   -4.8155530
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4446444 0.3967123 -0.01690757    0.9039194
#> lag1_var2 -0.7860833 0.4112473 -1.26979013   -0.3444370
#> lag1_var3 -0.1681113 0.4857920 -0.72957445    0.3010254
#> lag1_var4  0.8840882 0.5039809  0.39401565    1.4538148
#> const      9.9320174 5.7330726  3.77517284   16.8649452
#> 
#> $ARE$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.8235833 0.3190493   0.4576914    1.1338532
#> lag1_var2 -0.6141478 0.1438624  -0.7996326   -0.4812439
#> lag1_var3 -0.4136000 0.2292611  -0.6404725   -0.1563014
#> lag1_var4  1.1323730 0.2556152   0.8409048    1.3673411
#> const      0.7686639 4.6705278  -4.2813016    5.9467020
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                  mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.00340386 0.0009240295 0.002650719  0.004653336
#> 
#> $ARG$Sigma$equation2
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.07182383 0.008503153  -0.0809206  -0.06135432
#> Sigma[2,2]  3.37743876 0.748362067   2.4630759   4.14131391
#> 
#> $ARG$Sigma$equation3
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[3,1]  0.06554206 0.008027103  0.05473331   0.07182579
#> Sigma[3,2] -2.66754378 0.729114140 -3.33048405  -1.74362998
#> Sigma[3,3]  2.87751858 0.550180214  2.14339967   3.35771391
#> 
#> $ARG$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.02516826 0.00937561  0.01264166   0.03327987
#> Sigma[4,2] -0.68688015 0.31350131 -0.99773756  -0.28238610
#> Sigma[4,3]  1.40781768 0.15808996  1.21524991   1.57249634
#> Sigma[4,4]  1.11283051 0.13621965  0.95494350   1.25959886
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.88940710 0.03743769  0.85570885   0.93679503
#> lag1_var2  0.03463412 0.05432736 -0.02203172   0.09862909
#> lag1_var3  0.05517520 0.09163208 -0.04073749   0.16265289
#> lag1_var4 -0.06204701 0.07860264 -0.15394155   0.01957787
#> const      3.39697666 0.88390286  2.51932915   4.53100033
#> 
#> $ARG$A$equation2
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -1.2813233  0.9681864   -2.444332   -0.2632006
#> lag1_var2  0.4436250  1.7173979   -1.725955    2.0023843
#> lag1_var3 -0.3206568  2.8650912   -3.943109    2.2423337
#> lag1_var4  0.8887402  2.4093247   -1.072178    4.0036496
#> const      3.7605976 43.6403298  -54.332801   42.2661770
#> 
#> $ARG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.2108475  1.010605  -0.3932634  1.582159306
#> lag1_var2  1.7805906  2.294831  -0.4563501  4.719220667
#> lag1_var3  3.4199276  3.827479  -0.3188909  8.321980929
#> lag1_var4 -3.0377527  3.229515  -7.2446750  0.009524635
#> const     28.7824726 37.675441  -5.0320551 79.007402651
#> 
#> $ARG$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.6488188  1.144369  -1.8152366    0.7931748
#> lag1_var2  2.2322503  1.661006   0.7680429    4.2443625
#> lag1_var3  3.5011373  2.816089   1.0365367    6.8963879
#> lag1_var4 -2.7054966  2.427869  -5.6213651   -0.5616156
#> const     28.9858050 28.337840  -3.8157375   52.0742858
#> 
#> 
#> 
```
