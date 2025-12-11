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
#>               mean         sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01488 0.00916183 0.006896132   0.02501312
#> 
#> $AFG$Sigma$equation2
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.003859703 0.01403241 -0.01847807   0.01303752
#> Sigma[2,2]  0.290955549 0.13786614  0.15807948   0.45780207
#> 
#> $AFG$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1] -0.01106913 0.03891678 -0.05542867   0.02688173
#> Sigma[3,2] -0.27832743 0.13245865 -0.44749317  -0.16373782
#> Sigma[3,3]  0.50227438 0.22250355  0.34950213   0.80326503
#> 
#> $AFG$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.01653609 0.03969195 -0.06531798   0.02024806
#> Sigma[4,2] -0.17716113 0.10706492 -0.32502871  -0.10776904
#> Sigma[4,3]  0.44368045 0.20867955  0.31121193   0.73249673
#> Sigma[4,4]  0.43009420 0.20022848  0.29687598   0.70269755
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                   mean         sd 5% quantile 95% quantile
#> lag1_var1  0.974624200 0.03813875   0.9244094    1.0065762
#> lag1_var2  0.047556710 0.15225988  -0.1592706    0.1225774
#> lag1_var3  0.028122911 0.42076186  -0.5410933    0.2699885
#> lag1_var4  0.008100966 0.39772157  -0.2290290    0.5447136
#> const     -1.347780357 0.80983270  -2.1115916   -0.3838221
#> 
#> $AFG$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.6384611 0.4370512   0.2854690     1.128832
#> lag1_var2 -0.5659507 1.0538704  -1.7598585     0.242837
#> lag1_var3 -3.0222129 1.9262788  -5.2389949    -1.530313
#> lag1_var4  2.6058886 1.6536368   1.3351819     4.505726
#> const      6.3140348 4.6669881   0.8979085    11.301413
#> 
#> $AFG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.6638091 0.4673528  -1.2827297   -0.2834805
#> lag1_var2  1.7636732 1.0393694   0.6847948    3.0301259
#> lag1_var3  5.2931189 1.9084520   3.1646563    7.4386269
#> lag1_var4 -3.8932589 1.6539758  -5.6660169   -2.0594775
#> const     -1.8211001 6.3704498  -9.8753779    4.7743588
#> 
#> $AFG$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.4379019 0.3620403  -0.9110518   -0.1089546
#> lag1_var2  1.6136681 0.9047833   0.7102718    2.6844313
#> lag1_var3  4.2267083 1.8602416   2.4353089    6.4285307
#> lag1_var4 -2.8713650 1.6786871  -4.9667134   -1.3276442
#> const     -3.8845779 5.7136840 -11.1444934    1.9005556
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01283738 0.003062652  0.00953549   0.01594083
#> 
#> $AGO$Sigma$equation2
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[2,1] -0.005561989 0.002631461 -0.008621555 -0.002931132
#> Sigma[2,2]  0.153049731 0.028602528  0.130310577  0.191765342
#> 
#> $AGO$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1] -0.02616213 0.02459927 -0.05988074  -0.00807016
#> Sigma[3,2] -0.21170060 0.05881977 -0.28126947  -0.14888092
#> Sigma[3,3]  0.78023080 0.08056897  0.67684914   0.85816475
#> 
#> $AGO$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.03349943 0.02826002 -0.07163871  -0.01137052
#> Sigma[4,2] -0.11041394 0.05131456 -0.15752057  -0.04664575
#> Sigma[4,3]  0.71805238 0.10973469  0.58572601   0.83256765
#> Sigma[4,4]  0.73625431 0.15849575  0.55921139   0.89714006
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.92246474 0.05466262   0.8666489    0.9917415
#> lag1_var2 -0.07007255 0.24952770  -0.3659907    0.2130458
#> lag1_var3  0.06607620 0.30848248  -0.2780759    0.4358014
#> lag1_var4  0.01105663 0.29957248  -0.3475169    0.3482958
#> const     -1.99086666 1.06407437  -3.2317147   -1.1727849
#> 
#> $AGO$A$equation2
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.03420296 0.1549905 -0.16714658  0.168746498
#> lag1_var2  0.32267531 0.3427624 -0.05365887  0.677043676
#> lag1_var3 -0.52173015 0.4289364 -0.86030182  0.008116376
#> lag1_var4  0.62990567 0.4318463  0.11873769  0.986970307
#> const     -4.71008164 3.9484961 -9.70733207 -0.779701663
#> 
#> $AGO$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.3525235 0.5033202  -0.8659852    0.2396469
#> lag1_var2  3.9493306 1.3458469   2.4499830    5.0547213
#> lag1_var3  5.0181374 2.1363528   2.5840288    7.1440960
#> lag1_var4 -4.2644982 2.0117222  -6.2302396   -1.9772424
#> const     13.4187951 8.1562578   4.1833752   23.0604913
#> 
#> $AGO$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.4129343 0.4472999  -0.8955515   0.08963794
#> lag1_var2  4.2233648 1.5828058   2.3582018   5.51862348
#> lag1_var3  4.5517124 2.3162276   2.0594238   6.78683811
#> lag1_var4 -3.6908924 2.2160599  -5.8344347  -1.27721006
#> const      8.8091901 8.2128199   1.1221565  18.93497678
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01918072 0.005428085  0.01281355   0.02500999
#> 
#> $ALB$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.03083682 0.08682336  -0.1185611     0.072775
#> Sigma[2,2]  7.55460283 1.28123722   5.8661783     8.690272
#> 
#> $ALB$Sigma$equation3
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[3,1] -0.1455233 0.08951571  -0.2640707  -0.06502145
#> Sigma[3,2] -4.2704926 0.61569870  -4.9825763  -3.55538913
#> Sigma[3,3]  5.5917521 1.06734577   4.5569977   6.92514329
#> 
#> $ALB$Sigma$equation4
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.2162495 0.06540166  -0.2935937   -0.1414226
#> Sigma[4,2]  0.8224750 1.22428006  -0.5233596    2.0583351
#> Sigma[4,3]  3.4956046 1.32881935   2.5689493    5.3280832
#> Sigma[4,4]  5.0646361 1.18511064   3.8099727    6.5254235
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  1.1747535 0.04568703   1.1305290    1.2268892
#> lag1_var2 -0.2762312 0.03032147  -0.3084831   -0.2389857
#> lag1_var3 -0.4431843 0.04759866  -0.4880717   -0.3892057
#> lag1_var4  0.3907079 0.03919655   0.3440958    0.4320481
#> const     -0.6541032 0.93551782  -1.6198167    0.4425597
#> 
#> $ALB$A$equation2
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1 -3.607296  0.7858928   -4.675149    -3.060882
#> lag1_var2  5.034636  1.4101231    3.759508     6.831084
#> lag1_var3  7.290812  2.2975819    5.247076    10.258306
#> lag1_var4 -5.971325  1.9435922   -8.454509    -4.168543
#> const      8.821264 14.5052067  -10.186282    22.284052
#> 
#> $ALB$A$equation3
#>                   mean         sd 5% quantile 95% quantile
#> lag1_var1   1.58611690  0.4138233    1.262491    2.1500647
#> lag1_var2  -0.23464142  1.1828766   -1.737138    0.9351174
#> lag1_var3   0.05347578  1.8279987   -2.233696    1.9425498
#> lag1_var4   0.44712247  1.5795036   -1.176410    2.4059935
#> const     -11.84219863 13.5564479  -25.458902    5.0776224
#> 
#> $ALB$A$equation4
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  -1.140436  0.2001024   -1.337522   -0.8890763
#> lag1_var2   3.485711  0.7191067    2.834583    4.3238468
#> lag1_var3   5.551155  1.0775790    4.457133    6.7716825
#> lag1_var4  -3.970482  0.8936467   -5.068887   -3.1746940
#> const     -11.380396 18.1789231  -33.178206    9.1029476
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.001819062 0.0006805489 0.001161966  0.002623798
#> 
#> $ARE$Sigma$equation2
#>                    mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.008021365 0.002868942 -0.01076292 -0.004479199
#> Sigma[2,2]  0.181549174 0.054037788  0.14546325  0.256046969
#> 
#> $ARE$Sigma$equation3
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.008040876 0.003782957  0.003432138   0.01156726
#> Sigma[3,2] -0.184703059 0.066566024 -0.267414734  -0.11559554
#> Sigma[3,3]  0.443116948 0.129758365  0.279624267   0.56211445
#> 
#> $ARE$Sigma$equation4
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[4,1]  0.001818749 0.004939991 -0.004357504  0.006512945
#> Sigma[4,2] -0.044463432 0.036864837 -0.075965247  0.003929617
#> Sigma[4,3]  0.305696734 0.096246622  0.193756564  0.415913032
#> Sigma[4,4]  0.276793891 0.078217842  0.201042297  0.378152041
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                 mean          sd 5% quantile 95% quantile
#> lag1_var1  1.0259203 0.007557712   1.0175982    1.0344643
#> lag1_var2  0.3159494 0.080580356   0.2166414    0.3958683
#> lag1_var3  0.3851506 0.095062971   0.2706336    0.4848581
#> lag1_var4 -0.3809404 0.093937958  -0.4771220   -0.2692672
#> const     -1.0150164 0.617160800  -1.7949826   -0.3954598
#> 
#> $ARE$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.1039863 0.4331302  -0.2834051    0.6515223
#> lag1_var2  1.9322327 2.5868692  -0.5122861    5.1050042
#> lag1_var3  1.9439569 3.0844530  -1.0158592    5.6890604
#> lag1_var4 -1.9194394 2.9552593  -5.5391070    0.8991515
#> const     -3.2756555 3.0338615  -6.1934844    0.2310439
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.5730185 0.6340188 -0.02358505     1.398289
#> lag1_var2 -0.9664132 3.0043113 -4.84109524     1.795322
#> lag1_var3 -0.5221333 3.6535892 -5.11972790     3.052587
#> lag1_var4  1.2535667 3.4603116 -2.08342050     5.611179
#> const      5.2163772 4.0909874  1.05399341    10.078000
#> 
#> $ARE$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.6488198 0.4556854   0.1899860     1.215492
#> lag1_var2  0.5056220 1.0836455  -0.9363472     1.445496
#> lag1_var3  0.9671625 1.3543746  -0.7604580     2.328364
#> lag1_var4 -0.1943552 1.2445612  -1.4195682     1.394745
#> const      1.1025802 4.8394745  -3.2765425     7.397902
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.005259872 0.002311217 0.003844561  0.008421145
#> 
#> $ARG$Sigma$equation2
#>                 mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.090760 0.05675993  -0.1693423  -0.05512539
#> Sigma[2,2]  3.884278 1.16977029   2.7405024   5.38409126
#> 
#> $ARG$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.08319032 0.03160461   0.0593024     0.125760
#> Sigma[3,2] -3.02992897 0.70672392  -3.8814841    -2.379229
#> Sigma[3,3]  3.27386031 0.50748248   2.8571827     3.939200
#> 
#> $ARG$Sigma$equation4
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[4,1]  0.03262356 0.007569526   0.0251823   0.04228219
#> Sigma[4,2] -0.75489236 0.377756947  -1.2653584  -0.45593101
#> Sigma[4,3]  1.60984079 0.281932091   1.3273282   1.96646097
#> Sigma[4,4]  1.29382022 0.147099241   1.1065412   1.44292457
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.8958846 0.07283664   0.8056742    0.9688507
#> lag1_var2  0.4668280 0.09566629   0.3872992    0.5942508
#> lag1_var3  0.7652905 0.16028099   0.6275595    0.9782413
#> lag1_var4 -0.7012126 0.13686285  -0.8825112   -0.5900607
#> const     -1.0847886 0.52638835  -1.6159269   -0.4494196
#> 
#> $ARG$A$equation2
#>                 mean       sd 5% quantile 95% quantile
#> lag1_var1  0.1204689 2.044307   -2.099395     2.618482
#> lag1_var2 -2.0226200 3.946934   -6.847228     2.016354
#> lag1_var3 -4.5602851 6.641509  -12.686554     2.209195
#> lag1_var4  4.6461358 5.855477   -1.228423    11.783284
#> const     -5.7972124 6.789213  -13.945395     1.477778
#> 
#> $ARG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.7176313 0.9427176   -1.813363    0.3717169
#> lag1_var2  5.8438366 1.2757195    4.333812    7.2573808
#> lag1_var3 10.2642264 2.1631472    7.706237   12.6842262
#> lag1_var4 -9.1458507 1.7485794  -11.065234   -7.0920566
#> const     10.0474571 2.9232917    6.578330   13.2865984
#> 
#> $ARG$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.7450806 0.3618674   -1.033556   -0.2979631
#> lag1_var2  4.8727225 1.4562773    3.246457    6.5405176
#> lag1_var3  7.8989258 2.3865566    5.200822   10.5944292
#> lag1_var4 -6.6507008 2.3027179   -9.272092   -4.0516899
#> const      4.4213219 4.7361045   -1.913838    8.2325191
#> 
#> 
#> 
```
