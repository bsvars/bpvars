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

[`estimate.BVARGROUPPRIORPANEL`](http://bsvars.org/bpvars/dev/reference/estimate.BVARGROUPPRIORPANEL.md),
[`specify_bvarGroupPriorPANEL`](http://bsvars.org/bpvars/dev/reference/specify_bvarGroupPriorPANEL.md)

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
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.007454368 0.001426155 0.006105925  0.009204719
#> 
#> $AFG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.01022106 0.00259833 -0.01376824 -0.008224466
#> Sigma[2,2]  0.21163715 0.05529465  0.16374305  0.278768270
#> 
#> $AFG$Sigma$equation3
#>                   mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.01244932 0.007079025  0.006092086    0.0218261
#> Sigma[3,2] -0.20603393 0.078045222 -0.289905525   -0.1293726
#> Sigma[3,3]  0.41863695 0.114287538  0.332054632    0.5668306
#> 
#> $AFG$Sigma$equation4
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[4,1]  0.007825848 0.005964626  0.001496477   0.01511589
#> Sigma[4,2] -0.129666531 0.069568452 -0.201869738  -0.05473294
#> Sigma[4,3]  0.369461416 0.101403277  0.287161042   0.50517121
#> Sigma[4,4]  0.352351765 0.093550064  0.265271452   0.47588616
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.97892220 0.02445873  0.94968869   1.00300098
#> lag1_var2  0.02938789 0.01270680  0.01478824   0.04360794
#> lag1_var3  0.08008722 0.03980549  0.03119600   0.11370115
#> lag1_var4 -0.06431424 0.04319386 -0.10057831  -0.00717874
#> const     -0.12840961 0.82915910 -0.85397607   0.95752098
#> 
#> $AFG$A$equation2
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.09881178 0.2804277  -0.2461910    0.3970144
#> lag1_var2  0.75792390 0.1213031   0.6372994    0.8862801
#> lag1_var3 -0.73269430 0.1738029  -0.8888847   -0.5200910
#> lag1_var4  0.68136719 0.1834984   0.4775801    0.8293649
#> const     -0.62706140 5.3232329  -5.6162096    5.2277592
#> 
#> $AFG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.1159764 0.2068337 -0.04480184   0.39596842
#> lag1_var2 -1.0104283 0.1314540 -1.18087356  -0.88255117
#> lag1_var3 -0.2716960 0.2058795 -0.53100328  -0.05999222
#> lag1_var4  0.9399721 0.2079050  0.71191409   1.16171249
#> const     16.0594501 6.1036532 10.34791937  23.01692214
#> 
#> $AFG$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.1927602 0.1365336  0.04564715    0.3590141
#> lag1_var2 -0.7557524 0.1035502 -0.89273050   -0.6615832
#> lag1_var3 -0.7271256 0.1768273 -0.92827381   -0.5213316
#> lag1_var4  1.4773493 0.1634032  1.27522765    1.6237190
#> const     10.4783860 5.5703840  4.00288310   15.9684955
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.008433624 0.002811637 0.005316218    0.0118512
#> 
#> $AGO$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.02243616 0.01207340 -0.03634304 -0.008580528
#> Sigma[2,2]  0.20422234 0.05998647  0.14258310  0.278022596
#> 
#> $AGO$Sigma$equation3
#>                     mean         sd 5% quantile 95% quantile
#> Sigma[3,1] -0.0002205045 0.02615211 -0.03166523   0.02912411
#> Sigma[3,2] -0.0259208391 0.09285547 -0.10642645   0.09722271
#> Sigma[3,3]  0.4594709806 0.20633694  0.28426496   0.72311472
#> 
#> $AGO$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.01928757 0.03598031 -0.06558173   0.01675752
#> Sigma[4,2]  0.14437802 0.13077933  0.01099171   0.29857592
#> Sigma[4,3]  0.51213618 0.25437914  0.31615022   0.79091358
#> Sigma[4,4]  0.72016104 0.33871039  0.40800980   1.13905526
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9575632 0.06160602   0.8840744    1.0245960
#> lag1_var2  0.4398126 0.08972669   0.3556661    0.5512501
#> lag1_var3  0.5682485 0.14996981   0.4049521    0.7507505
#> lag1_var4 -0.4749697 0.13991761  -0.6536548   -0.3408483
#> const     -6.1330221 2.50346312  -8.8436568   -3.5790102
#> 
#> $AGO$A$equation2
#>                 mean         sd  5% quantile 95% quantile
#> lag1_var1  0.3072066  0.2550746  0.008586153    0.5265210
#> lag1_var2 -1.4489475  1.1844422 -2.162379852    0.1687459
#> lag1_var3 -3.0274867  1.5757296 -4.067351264   -0.8934700
#> lag1_var4  2.7357832  1.4191553  0.819326828    3.6745150
#> const     16.7248231 10.7211236  5.015863749   29.6303859
#> 
#> $AGO$A$equation3
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.1214019  0.1618744 -0.08921822    0.2494021
#> lag1_var2 -1.3510838  0.7593174 -2.30580544   -0.6843298
#> lag1_var3 -1.0195417  0.7073769 -1.90010885   -0.2958180
#> lag1_var4  1.4815911  0.8670694  0.74678273    2.5984827
#> const     35.0993255 17.7700559 18.29423535   57.7168867
#> 
#> $AGO$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.3569964  0.242485   0.0944034    0.6250953
#> lag1_var2 -2.9040467  1.552870  -4.4234467   -0.9735081
#> lag1_var3 -3.9272955  1.569256  -5.3747752   -1.9437194
#> lag1_var4  4.1972437  1.810474   1.9342257    5.9371313
#> const     45.3793660 18.628088  23.0604468   64.2212556
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.002257363 0.0004743044 0.001674167  0.002692464
#> 
#> $ALB$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.07985898 0.05688228   -0.146069   -0.0203747
#> Sigma[2,2] 11.52330559 5.27903568    7.450513   17.5271720
#> 
#> $ALB$Sigma$equation3
#>                   mean         sd  5% quantile 95% quantile
#> Sigma[3,1]  0.02983168 0.02651549   0.00109979   0.05772976
#> Sigma[3,2] -7.11430188 2.80776370 -10.86054036  -4.81889708
#> Sigma[3,3]  6.26035752 1.88320196   4.67687678   8.79121011
#> 
#> $ALB$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.02455091 0.01588611 -0.04415776 -0.008016256
#> Sigma[4,2]  0.46852256 1.51447245 -0.59829652  2.554799874
#> Sigma[4,3]  1.86282118 1.00886176  0.63555228  2.973613513
#> Sigma[4,4]  2.53496043 0.47654732  1.93314187  3.024519355
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                  mean         sd  5% quantile 95% quantile
#> lag1_var1  1.03348342 0.04682309  0.979533399  1.081261945
#> lag1_var2  0.07964860 0.04696275  0.015335221  0.115200193
#> lag1_var3  0.10965675 0.07326779  0.009012535  0.163666021
#> lag1_var4 -0.09101255 0.06352597 -0.137908784 -0.003766172
#> const     -2.05476505 0.82110598 -2.919983522 -1.027700373
#> 
#> $ALB$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -2.8285335  2.151097   -4.130868   0.08697182
#> lag1_var2 -0.1139914  1.834888   -1.801257   2.19215799
#> lag1_var3 -0.7286773  2.865585   -3.496553   2.85855907
#> lag1_var4  0.8234703  2.264013   -2.028631   3.01906502
#> const     69.4301653 66.096931  -15.483197 131.66198137
#> 
#> $ALB$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1   1.8073630  0.976713   0.5642732     2.622713
#> lag1_var2  -0.7775955  1.336493  -2.5644923     0.384864
#> lag1_var3  -0.7327559  2.065453  -3.4688835     1.110818
#> lag1_var4   1.2164125  1.641520  -0.2902496     3.366248
#> const     -14.4378427 35.385402 -51.5369714    20.888380
#> 
#> $ALB$A$equation4
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.0284533  0.8382547  -1.0226885    0.9280674
#> lag1_var2 -1.1376772  0.6394585  -1.7616844   -0.3233140
#> lag1_var3 -1.5999032  0.9898757  -2.5853071   -0.3432118
#> lag1_var4  2.2398211  0.8359305   1.1533310    3.0389440
#> const     25.0038153 18.8352941   0.2409387   41.8259440
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.001779186 0.0008661955 0.001093383  0.002899706
#> 
#> $ARE$Sigma$equation2
#>                    mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.004734525 0.008439087  -0.0158350  0.002666422
#> Sigma[2,2]  0.206547904 0.057103725   0.1480546  0.278456237
#> 
#> $ARE$Sigma$equation3
#>                    mean          sd   5% quantile 95% quantile
#> Sigma[3,1]  0.003575098 0.003803357 -0.0009255305  0.007936449
#> Sigma[3,2] -0.218368431 0.064839683 -0.3036161806 -0.159537503
#> Sigma[3,3]  0.433811272 0.162138220  0.2755176636  0.633548167
#> 
#> $ARE$Sigma$equation4
#>                     mean          sd  5% quantile 95% quantile
#> Sigma[4,1]  9.418085e-05 0.003363603 -0.004440389   0.00255177
#> Sigma[4,2] -5.774316e-02 0.036852867 -0.096799279  -0.01193449
#> Sigma[4,3]  2.677470e-01 0.119355585  0.136881729   0.40700881
#> Sigma[4,4]  2.268161e-01 0.093643415  0.130384119   0.33848700
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9946212 0.04382908  0.93677744    1.0348618
#> lag1_var2  0.2291772 0.17032542  0.09472559    0.4600977
#> lag1_var3  0.3006713 0.23250631  0.13037499    0.6163662
#> lag1_var4 -0.2941231 0.21394385 -0.58282458   -0.1302538
#> const     -0.3168389 0.50797887 -0.95668463    0.1976092
#> 
#> $ARE$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.2155753 0.3838309   -0.718813    0.1430143
#> lag1_var2  2.1633427 0.5822192    1.562494    2.8379036
#> lag1_var3  1.9815040 0.7712416    1.238416    2.9158545
#> lag1_var4 -1.8412711 0.7074194   -2.632282   -1.0919522
#> const     -4.1778536 2.6417629   -7.732954   -1.9231835
#> 
#> $ARE$A$equation3
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1  1.589921 0.5510919    1.104091     2.324381
#> lag1_var2 -5.327060 0.5930657   -5.966607    -4.695372
#> lag1_var3 -5.833581 0.4796763   -6.361405    -5.321334
#> lag1_var4  6.145032 0.4604693    5.666807     6.709009
#> const     11.318727 3.5613858    7.431311    15.695873
#> 
#> $ARE$A$equation4
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1  1.438725 0.3514716    1.027714     1.808814
#> lag1_var2 -3.843121 0.6617870   -4.653588    -3.123824
#> lag1_var3 -4.524012 0.7018404   -5.417360    -3.824068
#> lag1_var4  4.960232 0.7963875    4.205120     5.989508
#> const      6.461070 1.7394303    4.225547     8.165870
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.003403513 0.001258263  0.00228281  0.004853698
#> 
#> $ARG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.02883709 0.05097664 -0.06774149   0.03994607
#> Sigma[2,2]  4.38933708 2.45550306  2.32751922   7.70343517
#> 
#> $ARG$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.03729764 0.03848956 -0.01118977    0.0771342
#> Sigma[3,2] -3.23076185 1.66063114 -5.45121026   -1.7938439
#> Sigma[3,3]  3.09670262 1.18202467  1.95257311    4.6244152
#> 
#> $ARG$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.02282938 0.01378612  0.01538929   0.04171003
#> Sigma[4,2] -0.62048260 0.30932317 -0.95872582  -0.28969764
#> Sigma[4,3]  1.26581917 0.28922063  0.95905228   1.60215185
#> Sigma[4,4]  0.99977557 0.17992921  0.79827946   1.21052620
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.9107901 0.0715396   0.8150236    0.9734029
#> lag1_var2  0.4020574 0.1932416   0.2725650    0.6687473
#> lag1_var3  0.6609095 0.3286386   0.4387262    1.1142993
#> lag1_var4 -0.6056586 0.2959314  -1.0139351   -0.4072981
#> const     -0.9339706 0.9159203  -1.8676693    0.1626342
#> 
#> $ARG$A$equation2
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 -3.443722  1.958094   -5.881333    -1.527436
#> lag1_var2  6.624417  2.930464    3.149169     9.678394
#> lag1_var3  9.839171  5.058127    3.900668    15.248744
#> lag1_var4 -8.270692  4.481438  -12.883086    -2.870593
#> const      1.366005 33.201407  -43.692587    27.447632
#> 
#> $ARG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.7670652  1.482199  -0.8531187     2.433737
#> lag1_var2  0.6896827  1.922446  -1.7135904     2.650840
#> lag1_var3  1.6427076  3.272261  -2.4234767     5.031830
#> lag1_var4 -1.4764050  3.004568  -4.5522790     2.297911
#> const     26.7734947 26.715431   6.3678581    62.939017
#> 
#> $ARG$A$equation4
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 -1.507164 0.4202878   -2.013871    -1.052936
#> lag1_var2  5.146076 1.6584490    3.060432     6.821530
#> lag1_var3  8.307997 2.7264582    4.864999    11.029464
#> lag1_var4 -7.083609 2.5831326   -9.667097    -3.821075
#> const     25.989555 7.8398395   16.886171    34.983744
#> 
#> 
#> 
```
