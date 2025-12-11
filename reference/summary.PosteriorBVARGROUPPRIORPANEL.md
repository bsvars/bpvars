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
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.005007027 0.0008163745 0.004241009  0.006061637
#> 
#> $AFG$Sigma$equation2
#>                    mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.009273023 0.005281139 -0.01376259 -0.002264511
#> Sigma[2,2]  0.396935114 0.155593421  0.20176180  0.550139445
#> 
#> $AFG$Sigma$equation3
#>                    mean         sd  5% quantile 95% quantile
#> Sigma[3,1]  0.007686873 0.01071528 -0.004612922   0.01882385
#> Sigma[3,2] -0.174481758 0.06930496 -0.269244711  -0.13253868
#> Sigma[3,3]  0.349151286 0.09529694  0.257656131   0.47332637
#> 
#> $AFG$Sigma$equation4
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.004461716 0.01282736 -0.01152155   0.01631330
#> Sigma[4,2] -0.012821059 0.08365456 -0.09395550   0.08963757
#> Sigma[4,3]  0.320684492 0.11250885  0.22692047   0.46974768
#> Sigma[4,4]  0.365979029 0.15879008  0.25780320   0.58352907
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9675846 0.02160247   0.9502015   0.99637704
#> lag1_var2  0.1353554 0.03074104   0.1013615   0.17264487
#> lag1_var3  0.3529013 0.07714760   0.2792926   0.45345737
#> lag1_var4 -0.3190334 0.07205842  -0.4138607  -0.25269264
#> const     -0.5414074 0.54459239  -1.2673491  -0.06426908
#> 
#> $AFG$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.8442748 0.4949868   0.1734320    1.2496406
#> lag1_var2 -0.5751769 0.9932842  -1.6891510    0.5980654
#> lag1_var3 -2.6899071 1.6869017  -4.8117535   -1.0559458
#> lag1_var4  2.1976578 1.4205315   0.9725496    4.0267635
#> const      6.4621724 5.9989622  -0.6522326   12.6020476
#> 
#> $AFG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.1812809 0.1437094  -0.3400803  -0.04907202
#> lag1_var2  1.0358245 0.5738066   0.3320342   1.50132397
#> lag1_var3  4.0732557 1.3956792   2.2596741   5.07026833
#> lag1_var4 -2.8741419 1.3002226  -3.7897504  -1.16921402
#> const     -2.1176944 3.3327087  -5.8062753   1.49892735
#> 
#> $AFG$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.1936281 0.2092145 -0.07355056    0.4067110
#> lag1_var2  0.5151605 0.7343224 -0.27638691    1.4236965
#> lag1_var3  2.3730337 1.5205499  0.55924607    4.1011248
#> lag1_var4 -1.3512298 1.3535816 -2.84403873    0.2977418
#> const     -0.7728583 4.7350846 -7.30273736    2.4731439
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.007912744 0.001672603 0.005705976  0.009399837
#> 
#> $AGO$Sigma$equation2
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.00725918 0.004756687 -0.01361161 -0.003259064
#> Sigma[2,2]  0.13006601 0.040580877  0.09924108  0.185637523
#> 
#> $AGO$Sigma$equation3
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.002161553 0.01181656 -0.01169576   0.01271153
#> Sigma[3,2] -0.096556069 0.04396322 -0.13453372  -0.03764541
#> Sigma[3,3]  0.450718605 0.14902586  0.30308571   0.64101147
#> 
#> $AGO$Sigma$equation4
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.001697553 0.01415111 -0.01791466   0.01140949
#> Sigma[4,2]  0.002983976 0.03735567 -0.03695553   0.04952048
#> Sigma[4,3]  0.424560383 0.16391257  0.25461726   0.62870911
#> Sigma[4,4]  0.484225336 0.17082244  0.30273921   0.69739791
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9430947 0.02951576  0.92033255   0.98332364
#> lag1_var2  0.2030133 0.11600705  0.04340368   0.27431920
#> lag1_var3  0.3020677 0.17613357  0.06124611   0.43136288
#> lag1_var4 -0.2589165 0.15960627 -0.36465990  -0.03914928
#> const     -1.3939882 0.63941818 -2.26517841  -0.92411363
#> 
#> $AGO$A$equation2
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.06758119 0.1161716  -0.0402291    0.2150367
#> lag1_var2  0.27085013 0.5870637  -0.4386181    0.8796186
#> lag1_var3 -1.04048640 0.7757644  -2.0003214   -0.2807544
#> lag1_var4  0.95657318 0.7218055   0.2056499    1.8126215
#> const      3.56543956 3.8725665  -0.8893020    8.1147467
#> 
#> $AGO$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.1131351 0.5768142   -0.713677     0.514994
#> lag1_var2  0.8316666 2.8498659   -1.861432     4.367046
#> lag1_var3  1.8257787 3.8524560   -1.963863     6.480313
#> lag1_var4 -0.8361633 3.5715001   -5.191468     2.605847
#> const      0.4049613 7.5192943   -7.838227     9.255937
#> 
#> $AGO$A$equation4
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.19652139 0.5346697  -0.7924534     0.375091
#> lag1_var2  1.03436811 2.6758258  -1.7323177     4.286021
#> lag1_var3  0.99178605 3.5945367  -2.8397954     5.236221
#> lag1_var4  0.01118467 3.3512972  -4.0021398     3.543780
#> const      0.15176837 5.8782238  -5.3630964     6.820885
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.003068362 0.001329171 0.002221348  0.004905227
#> 
#> $ALB$Sigma$equation2
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[2,1] 0.01275681 0.04563782 -0.01252424   0.07527647
#> Sigma[2,2] 7.78866261 1.57780858  5.68219775   9.18861421
#> 
#> $ALB$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1] -0.03375307 0.04591324 -0.09581954 -0.000285029
#> Sigma[3,2] -5.70926827 2.00785609 -7.36939358 -3.078480984
#> Sigma[3,3]  6.11693451 2.25820213  3.19054910  8.229149585
#> 
#> $ALB$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.03419589 0.02418221  -0.0649807 -0.009912809
#> Sigma[4,2] -0.79769836 1.35842633  -2.0715594  0.784705560
#> Sigma[4,3]  2.97881214 1.28994172   1.4416281  4.444920535
#> Sigma[4,4]  3.08697808 0.76132883   2.2489145  3.973346844
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                  mean         sd   5% quantile 95% quantile
#> lag1_var1  1.03933006 0.02989777  1.0042136887  1.063381199
#> lag1_var2 -0.05338841 0.05498292 -0.1109790364  0.006952379
#> lag1_var3 -0.09258432 0.08690358 -0.1833205968  0.001845802
#> lag1_var4  0.08058957 0.07511717 -0.0007150514  0.158578591
#> const     -0.16623335 0.31295429 -0.4574062574  0.229040604
#> 
#> $ALB$A$equation2
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 -2.253861  1.895853  -4.6028169   -0.2211547
#> lag1_var2  2.189600  3.237342  -0.7416305    6.4536694
#> lag1_var3  2.988365  5.017720  -1.4404950    9.6184092
#> lag1_var4 -2.186303  4.248933  -7.8302668    1.5442945
#> const     13.074365 11.043604  -0.9906348   22.8784760
#> 
#> $ALB$A$equation3
#>                  mean       sd 5% quantile 95% quantile
#> lag1_var1   1.7290391 1.882302  -0.5067208     3.760910
#> lag1_var2  -0.8146192 2.861651  -4.3897358     1.947086
#> lag1_var3  -0.9298408 4.470360  -6.4666662     3.377427
#> lag1_var4   1.3469712 3.809049  -2.2316881     6.065361
#> const     -10.2667623 8.927676 -20.2871370    -0.203188
#> 
#> $ALB$A$equation4
#>                  mean       sd 5% quantile 95% quantile
#> lag1_var1  0.08565497 1.295480   -1.141771    1.7812407
#> lag1_var2  0.53133544 1.695817   -1.727802    1.7545506
#> lag1_var3  0.95256525 2.793599   -2.809760    2.9898291
#> lag1_var4  0.11665207 2.370676   -1.542062    3.3094870
#> const     -5.69759266 4.772206  -10.719716    0.2749261
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.001400049 0.0004352475 0.001047918  0.001980758
#> 
#> $ARE$Sigma$equation2
#>                    mean          sd 5% quantile  95% quantile
#> Sigma[2,1] -0.004820611 0.004603647 -0.01061466 -0.0001316732
#> Sigma[2,2]  0.202143193 0.058284817  0.16181814  0.2814695320
#> 
#> $ARE$Sigma$equation3
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.007592925 0.005541652  0.002829305   0.01496064
#> Sigma[3,2] -0.178135224 0.047212560 -0.234217766  -0.13677683
#> Sigma[3,3]  0.348567183 0.088903855  0.247623045   0.43969989
#> 
#> $ARE$Sigma$equation4
#>                    mean          sd 5% quantile 95% quantile
#> Sigma[4,1]  0.003995326 0.002511296  0.00212774  0.007434365
#> Sigma[4,2] -0.021670226 0.017752534 -0.04540010 -0.008534517
#> Sigma[4,3]  0.214288648 0.061254893  0.13799979  0.266029083
#> Sigma[4,4]  0.201257221 0.060391185  0.12923052  0.255311476
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  1.0109949 0.03198100   0.9683807    1.0373126
#> lag1_var2  0.2094882 0.06395787   0.1533793    0.2946513
#> lag1_var3  0.2733957 0.08125510   0.2051162    0.3820717
#> lag1_var4 -0.2732187 0.07066643  -0.3683180   -0.2136816
#> const     -0.2632037 0.12069262  -0.4009778   -0.1212961
#> 
#> $ARE$A$equation2
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.09534516 0.3573257  -0.2882936    0.5057666
#> lag1_var2  0.91865563 1.5403010  -0.9722336    2.5651201
#> lag1_var3  0.42296909 2.0453447  -2.1702303    2.4951786
#> lag1_var4 -0.44477563 1.9861739  -2.3794280    2.1012326
#> const      0.18984697 2.5055268  -2.6682653    3.0696017
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.6505100 0.5743413  0.10837972    1.3510716
#> lag1_var2  0.4826553 1.5412286 -0.77199147    2.5651157
#> lag1_var3  1.7290678 2.1105778  0.04597728    4.5764449
#> lag1_var4 -0.9315129 1.9707220 -3.55974818    0.6945609
#> const     -1.3138167 5.7457979 -6.06088594    6.2451316
#> 
#> $ARE$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.7327304 0.6004244   0.2553250    1.4352105
#> lag1_var2  1.2189548 0.8925593   0.1148619    2.1096532
#> lag1_var3  2.1086905 1.0968112   0.8042102    3.3023806
#> lag1_var4 -1.3047755 0.9640770  -2.3285070   -0.1606127
#> const     -3.1474753 4.4416832  -6.1201961    2.9867145
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.007508429 0.005547755 0.003305591   0.01497673
#> 
#> $ARG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.07471941 0.02145024  -0.1016945  -0.05236607
#> Sigma[2,2]  3.44619142 0.17393849   3.3087390   3.68159437
#> 
#> $ARG$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.07223356 0.02726324  0.03982912   0.09828576
#> Sigma[3,2] -2.40858673 0.68087495 -3.25328402  -1.74170475
#> Sigma[3,3]  2.53492439 0.94977867  1.69502059   3.79057211
#> 
#> $ARG$Sigma$equation4
#>                   mean         sd  5% quantile 95% quantile
#> Sigma[4,1]  0.03101936 0.02990843 -0.001695782   0.06196541
#> Sigma[4,2] -0.35722093 0.65845499 -1.143969469   0.33690216
#> Sigma[4,3]  1.20158734 0.62276467  0.655357192   2.03066332
#> Sigma[4,4]  1.10242935 0.36640444  0.715613710   1.52408684
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.8430766 0.07676517   0.7514899    0.9254649
#> lag1_var2  0.5861928 0.26750983   0.3596091    0.9217226
#> lag1_var3  0.9575984 0.44691794   0.5831922    1.5218040
#> lag1_var4 -0.8789774 0.41310414  -1.4008080   -0.5274709
#> const     -0.5797275 0.15562809  -0.7326610   -0.4047502
#> 
#> $ARG$A$equation2
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.207086  1.349247   -2.005971    0.9641412
#> lag1_var2 -2.535176  4.233696   -7.730334    1.8705089
#> lag1_var3 -5.277089  6.805089  -13.624789    1.8394403
#> lag1_var4  5.230639  6.396629   -1.322366   13.1144002
#> const     11.831606 13.173266   -2.054627   27.5743132
#> 
#> $ARG$A$equation3
#>                  mean       sd 5% quantile 95% quantile
#> lag1_var1 -0.07647889 1.044039   -1.366146    0.9157017
#> lag1_var2  5.15188354 2.853238    1.930138    8.0971684
#> lag1_var3  8.92400900 4.645862    3.611867   13.7173353
#> lag1_var4 -7.80639357 4.185072  -12.030113   -3.0014071
#> const     -8.63881608 4.539792  -12.842527   -2.6842871
#> 
#> $ARG$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.2949593 0.9980856   -1.462028    0.8641756
#> lag1_var2  3.7631208 2.3027756    2.000088    6.8910887
#> lag1_var3  5.9373247 3.8368878    2.853554   11.1076603
#> lag1_var4 -4.7741851 3.3973742   -9.365090   -2.1852401
#> const     -3.6262547 5.0366390   -8.982379    2.1412502
#> 
#> 
#> 
```
