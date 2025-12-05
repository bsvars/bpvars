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
#> Sigma[1,1] 0.007627532 0.0008213695 0.006575333  0.008397889
#> 
#> $AFG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.01235917 0.01080069 -0.02303179  0.001529326
#> Sigma[2,2]  0.21389393 0.03810738  0.17166743  0.257347105
#> 
#> $AFG$Sigma$equation3
#>                   mean         sd   5% quantile 95% quantile
#> Sigma[3,1]  0.01815777 0.01368882  0.0002807008   0.03073048
#> Sigma[3,2] -0.21011955 0.05999125 -0.2790226552  -0.13970665
#> Sigma[3,3]  0.43634773 0.08693276  0.3240864254   0.51626704
#> 
#> $AFG$Sigma$equation4
#>                   mean         sd   5% quantile 95% quantile
#> Sigma[4,1]  0.01402614 0.01121451 -0.0006157591   0.02409723
#> Sigma[4,2] -0.14412683 0.05540220 -0.2036250587  -0.07725317
#> Sigma[4,3]  0.39849640 0.08880027  0.2820844287   0.47536996
#> Sigma[4,4]  0.38883452 0.09407559  0.2652455281   0.47693647
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9951266 0.02227971   0.9670484    1.0184491
#> lag1_var2 -0.2306647 0.07246837  -0.3085457   -0.1422662
#> lag1_var3 -0.4145206 0.14779847  -0.5961156   -0.2531867
#> lag1_var4  0.3459569 0.12743688   0.2138449    0.5062183
#> const      3.6846623 0.93494504   2.5960566    4.7555378
#> 
#> $AFG$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.3640187 0.2419375  0.09367528    0.6545226
#> lag1_var2 -0.2173595 0.5619912 -0.89971543    0.2563327
#> lag1_var3 -2.6916705 0.9786887 -3.77817445   -1.6461751
#> lag1_var4  2.3760723 0.8148170  1.43573523    3.2189026
#> const      6.2371716 6.0180981 -1.17999352   12.4300476
#> 
#> $AFG$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.06598741 0.3912716  -0.5391235    0.3207637
#> lag1_var2  1.20537663 0.9321467   0.1270455    2.1806494
#> lag1_var3  4.59651768 1.6833915   2.6542686    6.2925330
#> lag1_var4 -3.36407513 1.4143436  -4.7813095   -1.7332448
#> const     -5.69372771 7.3735860 -11.7249795    3.9597253
#> 
#> $AFG$A$equation4
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.08286471 0.3331556  -0.3166317    0.4115098
#> lag1_var2  1.21197353 0.8247160   0.2428190    2.0327322
#> lag1_var3  3.69196375 1.5365071   1.9005459    5.2200469
#> lag1_var4 -2.45691990 1.3106669  -3.7759005   -0.9280339
#> const     -8.87153604 6.4514920 -14.4033335   -0.6702584
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01215445 0.001204212  0.01097825   0.01370659
#> 
#> $AGO$Sigma$equation2
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.04100386 0.007435712 -0.04695421  -0.03093713
#> Sigma[2,2]  0.26967579 0.019663752  0.24285412   0.28359243
#> 
#> $AGO$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.06060684 0.01462650  0.04768953   0.07988096
#> Sigma[3,2] -0.30657203 0.07849525 -0.39683338  -0.21602326
#> Sigma[3,3]  0.67215355 0.18680262  0.44934899   0.87937209
#> 
#> $AGO$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.02902752 0.01478212  0.01691746   0.04905146
#> Sigma[4,2] -0.09854709 0.08077054 -0.20297206  -0.02071416
#> Sigma[4,3]  0.48593551 0.15255575  0.29872035   0.65138902
#> Sigma[4,4]  0.47191921 0.11955581  0.31475741   0.57156438
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  1.1281003 0.04213245   1.0824376    1.1799355
#> lag1_var2 -0.7799815 0.07401686  -0.8697331   -0.6991907
#> lag1_var3 -1.1254059 0.09886800  -1.2291751   -1.0030257
#> lag1_var4  1.0124054 0.08511956   0.9111565    1.1081627
#> const      4.1743059 1.57347473   2.1773770    5.6981626
#> 
#> $AGO$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.5405277 0.2102881  -0.7709605   -0.2837337
#> lag1_var2  2.7363772 0.3417515   2.4461658    3.1935160
#> lag1_var3  2.8262253 0.3542624   2.5103938    3.2869190
#> lag1_var4 -2.4717396 0.3469423  -2.9169396   -2.1349125
#> const     -6.8119137 5.5303288 -10.9769146    0.7507629
#> 
#> $AGO$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4073657 0.2751185  0.06336644    0.6833553
#> lag1_var2 -0.7201337 0.3757071 -1.16543646   -0.2958320
#> lag1_var3 -1.0040500 0.5448755 -1.54246260   -0.3422515
#> lag1_var4  1.5750469 0.4130516  1.08865531    2.0283388
#> const      9.4271081 7.5122347  1.78077897   18.9199133
#> 
#> $AGO$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.1392188 0.1602130  -0.3310143    0.0345427
#> lag1_var2  1.4091008 0.3174521   1.0033459    1.7149752
#> lag1_var3  1.2052115 0.5559400   0.4802997    1.7109349
#> lag1_var4 -0.2762818 0.4267887  -0.6676275    0.2825387
#> const      0.8766011 5.0892416  -3.4870580    7.7057224
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.004140899 0.001808119 0.002225693  0.006378346
#> 
#> $ALB$Sigma$equation2
#>                  mean        sd 5% quantile 95% quantile
#> Sigma[2,1] -0.0877453 0.0444828  -0.1312959  -0.03073044
#> Sigma[2,2]  7.0270542 2.2366455   3.9460824   8.60234334
#> 
#> $ALB$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.02738693 0.03284894 -0.01090023   0.06556812
#> Sigma[3,2] -3.60577138 0.95928469 -4.53960089  -2.37399117
#> Sigma[3,3]  4.16450244 0.51323719  3.58608349   4.63827501
#> 
#> $ALB$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.03235271 0.02218456  -0.0598724  -0.01009231
#> Sigma[4,2]  1.20271355 1.24131991   0.0294814   2.68925557
#> Sigma[4,3]  2.10931231 0.79896614   1.3865087   3.17033609
#> Sigma[4,4]  3.44960343 0.62322419   2.8276321   4.14768621
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.90754249 0.01893303  0.88775583   0.93138065
#> lag1_var2  0.02549703 0.05347974 -0.04163101   0.08069194
#> lag1_var3  0.04112416 0.08493795 -0.06358530   0.13201474
#> lag1_var4 -0.03674649 0.07491012 -0.11580075   0.05639963
#> const      1.88549096 0.61046338  1.18655678   2.57628626
#> 
#> $ALB$A$equation2
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -1.2620296  0.9009241  -2.4324761   -0.4159973
#> lag1_var2  2.1628008  1.4653621   0.4594416    3.6458115
#> lag1_var3  2.7087869  2.2825824   0.1193966    5.1016331
#> lag1_var4 -2.0954930  2.0105405  -4.0783245    0.2052769
#> const     -0.9276599 13.1465009 -18.7675293    9.7177882
#> 
#> $ALB$A$equation3
#>                mean       sd 5% quantile 95% quantile
#> lag1_var1  1.428536 1.331369   0.4326927    3.2357938
#> lag1_var2 -1.530331 1.771230  -3.7991959    0.2134580
#> lag1_var3 -1.892708 2.897856  -5.6330969    0.8402726
#> lag1_var4  2.207700 2.405969  -0.1173345    5.3010099
#> const      5.038840 6.644731  -1.5405344   13.5765783
#> 
#> $ALB$A$equation4
#>                 mean        sd  5% quantile 95% quantile
#> lag1_var1  0.5558824  1.295962  -0.47491600    2.0405187
#> lag1_var2 -0.4763303  1.268278  -2.20261050    0.4776451
#> lag1_var3 -0.6023810  2.093000  -3.47510036    0.9044910
#> lag1_var4  1.3838158  1.794771   0.04053706    3.8282852
#> const      1.8695293 16.414849 -20.25105712   15.8516472
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.009746016 0.004175263 0.005275342   0.01439877
#> 
#> $ARE$Sigma$equation2
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[2,1] -0.002041167 0.005388248 -0.009383922  0.001726181
#> Sigma[2,2]  0.152655222 0.015193633  0.137644651  0.171111596
#> 
#> $ARE$Sigma$equation3
#>                     mean         sd  5% quantile 95% quantile
#> Sigma[3,1] -0.0009247672 0.00713337 -0.009018875  0.007567599
#> Sigma[3,2] -0.1561467609 0.04422371 -0.191961314 -0.100581987
#> Sigma[3,3]  0.3333043738 0.06447008  0.267028822  0.414308826
#> 
#> $ARE$Sigma$equation4
#>                   mean          sd  5% quantile 95% quantile
#> Sigma[4,1] -0.00210691 0.004278509 -0.007302843  0.002546514
#> Sigma[4,2] -0.03741508 0.035491695 -0.069591872  0.007749333
#> Sigma[4,3]  0.21734252 0.043865339  0.172621052  0.271718748
#> Sigma[4,4]  0.19420536 0.044771286  0.150985939  0.247512784
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.7977279 0.06362957   0.7293812    0.8755156
#> lag1_var2  0.6232198 0.24871130   0.3007480    0.8614703
#> lag1_var3  0.7653128 0.26217305   0.4193456    1.0008846
#> lag1_var4 -0.7223564 0.25531894  -0.9675533   -0.3909716
#> const      1.9801484 0.39546219   1.6224654    2.5052520
#> 
#> $ARE$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.0624758 0.2301338  -0.3204277   0.17433425
#> lag1_var2  0.8895462 0.2959389   0.5382383   1.22222203
#> lag1_var3  0.5220708 0.3347830   0.1106692   0.88493890
#> lag1_var4 -0.4208969 0.3066945  -0.7371844  -0.03669539
#> const     -4.8647173 1.4480276  -6.6084829  -3.23824100
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.9859943 0.3030091   0.6362883    1.3022629
#> lag1_var2 -1.0982301 0.8032326  -2.1991754   -0.5473033
#> lag1_var3 -0.5316865 1.1581424  -2.1131191    0.1632980
#> lag1_var4  1.1367232 1.1001724   0.3684464    2.6423471
#> const      4.2794597 1.3278297   2.6882256    5.4008236
#> 
#> $ARE$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.9030690 0.1432188   0.7245834    1.0422286
#> lag1_var2 -0.4930967 0.7017889  -1.4189351    0.1345079
#> lag1_var3 -0.2258685 1.0236079  -1.6109297    0.4898118
#> lag1_var4  0.9329010 0.9935701   0.1826522    2.2663114
#> const     -0.3879181 0.9043786  -1.4972840    0.5837445
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.004606352 0.002368888  0.00319309  0.007888042
#> 
#> $ARG$Sigma$equation2
#>                   mean        sd 5% quantile 95% quantile
#> Sigma[2,1] -0.09615459 0.0695162  -0.1886052  -0.03487084
#> Sigma[2,2]  5.18337250 3.4987749   2.7507252   9.98800992
#> 
#> $ARG$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.08780247 0.05231466  0.05259581    0.1591726
#> Sigma[3,2] -3.23679917 2.03047215 -5.99629988   -1.8852245
#> Sigma[3,3]  3.15841472 1.33312685  2.24358443    4.9792893
#> 
#> $ARG$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.03393080 0.01994409  0.01168094   0.05799322
#> Sigma[4,2] -0.09945354 0.33292617 -0.49603264   0.27226554
#> Sigma[4,3]  1.33969234 0.22630509  1.05259752   1.52404980
#> Sigma[4,4]  1.43940499 0.16822991  1.31464240   1.66937813
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.90938921 0.01731469   0.8943765    0.9326562
#> lag1_var2  0.07941247 0.11633943  -0.0741143    0.1749062
#> lag1_var3  0.12739440 0.19215201  -0.1273843    0.2844670
#> lag1_var4 -0.12118326 0.18248229  -0.2690589    0.1211365
#> const      2.06170358 0.62880485   1.5715261    2.9052994
#> 
#> $ARG$A$equation2
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -1.2942012  0.7864183   -1.932435    -0.240503
#> lag1_var2  2.8701448  4.4310078   -1.549247     7.937608
#> lag1_var3  3.6628004  7.2781571   -3.639690    11.605187
#> lag1_var4 -3.0111904  6.7794369  -10.638680     3.626781
#> const     -0.9140532 26.9873270  -38.021094    18.464407
#> 
#> $ARG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.3969394  0.409685  0.04802605    0.9075709
#> lag1_var2  1.8953916  3.074518 -1.67961110    4.9771635
#> lag1_var3  3.6423033  5.021013 -2.40103125    8.6292879
#> lag1_var4 -2.9947814  4.785334 -7.64330709    2.8093610
#> const      7.7907625 15.028681 -8.06795653   26.5350930
#> 
#> $ARG$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.5226294 0.3536067  -0.8921708   -0.1137798
#> lag1_var2  3.8157572 1.3341290   2.3561158    5.3360338
#> lag1_var3  6.1423329 2.1042203   3.8421639    8.5084726
#> lag1_var4 -5.0292092 2.0882870  -7.2382278   -2.5664967
#> const      6.5138614 5.4976148   0.2788180   11.8089248
#> 
#> 
#> 
```
