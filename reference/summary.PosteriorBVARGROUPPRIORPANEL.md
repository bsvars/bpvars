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
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.006925418 0.002718711 0.004842733   0.01058817
#> 
#> $AFG$Sigma$equation2
#>                    mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.007786259 0.002684843 -0.01093893 -0.005157631
#> Sigma[2,2]  0.175685476 0.049410119  0.11659385  0.218304427
#> 
#> $AFG$Sigma$equation3
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.009441254 0.005505767  0.004934248   0.01688993
#> Sigma[3,2] -0.118997507 0.044430527 -0.172179268  -0.06991697
#> Sigma[3,3]  0.226500459 0.058117604  0.171346726   0.30269194
#> 
#> $AFG$Sigma$equation4
#>                    mean          sd   5% quantile 95% quantile
#> Sigma[4,1]  0.005563449 0.005547857  0.0006710802   0.01299019
#> Sigma[4,2] -0.051795574 0.036141837 -0.0998559479  -0.01996955
#> Sigma[4,3]  0.201574069 0.049581781  0.1473536076   0.26146032
#> Sigma[4,4]  0.206622402 0.046262909  0.1484587691   0.25476517
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9706971 0.02585756   0.9352755    0.9880962
#> lag1_var2 -0.2260799 0.01793938  -0.2495283   -0.2123863
#> lag1_var3 -0.4891528 0.04104760  -0.5350532   -0.4427250
#> lag1_var4  0.4355850 0.03782109   0.3958010    0.4810010
#> const      3.2135203 0.63353233   2.5677289    3.9568988
#> 
#> $AFG$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.3708779 0.1773704   0.1403619   0.52558834
#> lag1_var2 -0.1474264 0.1756823  -0.3775839   0.01226588
#> lag1_var3 -2.6071033 0.2498193  -2.9192852  -2.34594743
#> lag1_var4  2.3241738 0.1973909   2.1021077   2.55932923
#> const      4.2429341 2.2171106   2.5779153   7.12276764
#> 
#> $AFG$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  -0.1726222 0.2163104   -0.425513   0.07268276
#> lag1_var2   3.0757245 0.3258526    2.657520   3.39664923
#> lag1_var3   8.5761069 0.5140214    7.903144   9.04947814
#> lag1_var4  -6.7869350 0.3931770   -7.141243  -6.27123194
#> const     -29.3068907 4.0470361  -34.738595 -25.96076491
#> 
#> $AFG$A$equation4
#>                    mean        sd 5% quantile 95% quantile
#> lag1_var1  -0.001051857 0.2344930  -0.2502739     0.289935
#> lag1_var2   3.482110869 0.3054630   3.0713231     3.731208
#> lag1_var3   8.506584816 0.4581353   7.8952128     8.877288
#> lag1_var4  -6.588574813 0.3405467  -6.8770089    -6.138129
#> const     -38.998436145 4.0080816 -44.3769179   -36.146900
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[1,1] 0.08736371 0.03070208  0.04864956    0.1195209
#> 
#> $AGO$Sigma$equation2
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.006814596 0.01656901 -0.02190914   0.01478751
#> Sigma[2,2]  0.143426007 0.03065481  0.11648900   0.18359206
#> 
#> $AGO$Sigma$equation3
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.1682859 0.08540852  0.06781486   0.26419375
#> Sigma[3,2] -0.1273577 0.04836510 -0.18690369  -0.08067226
#> Sigma[3,3]  0.7278536 0.24008915  0.46891014   0.97851973
#> 
#> $AGO$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.17318502 0.10697846  0.05103138  0.298219841
#> Sigma[4,2] -0.02359913 0.03946691 -0.07603915  0.008290024
#> Sigma[4,3]  0.71501296 0.26812215  0.44120288  1.013941884
#> Sigma[4,4]  0.79066272 0.28818678  0.50558526  1.127488416
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.7092595 0.1090423  0.61718234   0.85059217
#> lag1_var2  0.6938660 0.6195002 -0.02785903   1.27608344
#> lag1_var3  0.6717115 0.7938367 -0.25758597   1.43828591
#> lag1_var4 -0.8247623 0.7231313 -1.52173255   0.03349342
#> const     16.0292565 3.6721961 13.01754507  20.97205161
#> 
#> $AGO$A$equation2
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.04744145 0.05381405 -0.02092273   0.09744655
#> lag1_var2  0.73384677 0.35847698  0.26767881   1.05908236
#> lag1_var3 -0.32816326 0.36451234 -0.78736613   0.03063939
#> lag1_var4  0.41555684 0.36244324  0.06042669   0.87553650
#> const     -7.72097410 1.38071789 -9.54412713  -6.54697814
#> 
#> $AGO$A$equation3
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 -1.021034  0.343123   -1.386512   -0.6677376
#> lag1_var2  4.196678  1.714706    2.427244    6.0794880
#> lag1_var3  5.797371  2.292801    3.468827    8.3929951
#> lag1_var4 -5.025176  2.028827   -7.324675   -2.9415957
#> const     34.233205 11.955627   22.133962   47.1375724
#> 
#> $AGO$A$equation4
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1 -1.104900  0.4001301   -1.534357   -0.6790672
#> lag1_var2  4.679130  2.1212284    2.437709    7.0536364
#> lag1_var3  5.385757  2.7892601    2.578593    8.6087085
#> lag1_var4 -4.514840  2.4846547   -7.394589   -2.0171121
#> const     28.152308 14.0380770   13.167801   42.8199022
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01419754 0.006465428 0.005954502   0.02073161
#> 
#> $ALB$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.02055992 0.04395241 -0.08096964  0.005167495
#> Sigma[2,2]  7.74712636 3.35262430  5.05250117 12.225243006
#> 
#> $ALB$Sigma$equation3
#>                  mean        sd 5% quantile 95% quantile
#> Sigma[3,1] -0.1284869 0.1079243  -0.2218442   0.01657516
#> Sigma[3,2] -5.4847731 2.3775377  -8.6075274  -3.37562397
#> Sigma[3,3]  7.7157529 1.4999742   6.2582362   9.60723716
#> 
#> $ALB$Sigma$equation4
#>                  mean        sd 5% quantile 95% quantile
#> Sigma[4,1] -0.1782513 0.1041698  -0.2783855  -0.04384297
#> Sigma[4,2] -0.4213556 0.4164935  -0.8947931   0.03734016
#> Sigma[4,3]  4.9631948 1.5515896   3.2802254   6.68099669
#> Sigma[4,4]  5.7327242 1.9223084   3.6447838   7.71977398
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  1.0434681 0.09970618   0.9099971    1.1306796
#> lag1_var2 -0.3105830 0.12512690  -0.4012542   -0.1396622
#> lag1_var3 -0.4862524 0.20021118  -0.6317096   -0.2122540
#> lag1_var4  0.4170436 0.17596599   0.1748628    0.5368534
#> const      3.4681448 1.71699421   1.5211553    5.2285508
#> 
#> $ALB$A$equation2
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1 -2.638267  0.7850451   -3.447041    -1.649318
#> lag1_var2  3.260933  0.6031541    2.524223     3.925517
#> lag1_var3  4.696054  0.7402304    3.765002     5.448334
#> lag1_var4 -3.633479  0.6259147   -4.290531    -2.859055
#> const      6.030420 25.0509226  -26.142999    29.774657
#> 
#> $ALB$A$equation3
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1   0.9519275  0.8747375   0.4770232     2.134916
#> lag1_var2   1.8801217  2.4936324  -1.4135303     4.121810
#> lag1_var3   3.2325455  3.8297605  -1.8719367     6.515475
#> lag1_var4  -2.3079709  3.2996134  -5.1011567     2.116686
#> const     -26.0966025 23.5613797 -51.9475925     1.869640
#> 
#> $ALB$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  -1.062215  1.742875   -2.276718    1.2889276
#> lag1_var2   4.603461  2.694237    1.125548    7.1991850
#> lag1_var3   7.274922  4.290173    1.676061   11.2894328
#> lag1_var4  -5.388192  3.704120   -8.767327   -0.5096200
#> const     -32.466630 24.411993  -50.975975    0.8349899
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                  mean           sd  5% quantile 95% quantile
#> Sigma[1,1] 0.00148022 0.0005948712 0.0009255281  0.002264108
#> 
#> $ARE$Sigma$equation2
#>                    mean           sd  5% quantile 95% quantile
#> Sigma[2,1] -0.005490476 0.0008476526 -0.006477667  -0.00483409
#> Sigma[2,2]  0.140182796 0.0185423115  0.126697869   0.16541097
#> 
#> $ARE$Sigma$equation3
#>                   mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.01001669 0.002734198  0.006679674   0.01300756
#> Sigma[3,2] -0.12873194 0.013020810 -0.143507986  -0.11501627
#> Sigma[3,3]  0.38002171 0.070740735  0.313935445   0.47129841
#> 
#> $ARE$Sigma$equation4
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[4,1]  0.005856501 0.002880464  0.002727478  0.009392689
#> Sigma[4,2] -0.019066273 0.024821412 -0.042481976  0.013355487
#> Sigma[4,3]  0.283091651 0.069756087  0.226778588  0.376855142
#> Sigma[4,4]  0.272353197 0.067487893  0.223116348  0.365040751
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9741909 0.01795782   0.9525758    0.9917462
#> lag1_var2 -0.2595159 0.04074120  -0.2960966   -0.2052946
#> lag1_var3 -0.3560820 0.05560461  -0.4164527   -0.2884803
#> lag1_var4  0.3400675 0.05041392   0.2779836    0.3943087
#> const      1.9070868 0.30080703   1.5879470    2.2439556
#> 
#> $ARE$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.1470974 0.4119909  -0.2949879    0.6499181
#> lag1_var2  1.1576262 0.6710099   0.3706309    1.7558690
#> lag1_var3  0.7173450 0.8159219  -0.2540923    1.4420669
#> lag1_var4 -0.6457517 0.8525659  -1.3764895    0.3187132
#> const     -8.3585740 4.3442190 -14.0176990   -4.3696990
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.3301664 0.2328355  0.06311022    0.5421757
#> lag1_var2 -1.7221361 1.2838467 -3.25597810   -0.7858363
#> lag1_var3 -1.4470115 1.3626033 -3.00505562   -0.3065679
#> lag1_var4  2.2164111 1.3477505  1.10754681    3.7594491
#> const      8.6592381 5.5809801  1.96771530   14.8488145
#> 
#> $ARE$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4577138 0.2846502   0.1437310    0.6737575
#> lag1_var2 -0.8811168 0.9658197  -1.9770694    0.1603194
#> lag1_var3 -0.9403099 0.9621577  -1.9640973    0.1277378
#> lag1_var4  1.7847972 0.9695683   0.6776409    2.7921275
#> const      0.3506067 4.7663973  -3.5052494    6.7428756
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.00390871 0.001186765  0.00318809  0.005544569
#> 
#> $ARG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.06420729 0.02166954 -0.09076259   -0.0409056
#> Sigma[2,2]  3.13290953 0.46454656  2.65584667    3.6523896
#> 
#> $ARG$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.05207512 0.01518603  0.03426027   0.06951664
#> Sigma[3,2] -2.14418176 0.14283030 -2.29057874  -1.96268004
#> Sigma[3,3]  2.28142041 0.38983518  1.96951672   2.80695548
#> 
#> $ARG$Sigma$equation4
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[4,1]  0.01487088 0.003950941   0.0108446   0.01958461
#> Sigma[4,2] -0.25709995 0.267376189  -0.5235148   0.06613976
#> Sigma[4,3]  1.09246822 0.452391280   0.6723441   1.67599923
#> Sigma[4,4]  1.05438132 0.362188036   0.7146982   1.52441416
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.93633868 0.04247624  0.89218652   0.98338938
#> lag1_var2 -0.06699849 0.08272102 -0.15829342   0.02467818
#> lag1_var3 -0.10543253 0.13763945 -0.25948225   0.04089244
#> lag1_var4  0.09681981 0.11808100 -0.03343712   0.22830005
#> const      2.28697184 0.74102663  1.38173416   3.10096900
#> 
#> $ARG$A$equation2
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  -0.8144692  0.9305447   -1.581457    0.3115785
#> lag1_var2   2.5264989  3.4143587   -1.800925    6.0345644
#> lag1_var3   2.8922084  5.6775831   -4.292566    8.7433483
#> lag1_var4  -2.2790145  4.9617358   -7.277099    4.0513800
#> const     -12.8734828 28.4697786  -48.349876   15.3469820
#> 
#> $ARG$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.02781015 0.9394614   -1.304430    0.7249756
#> lag1_var2  4.89097297 3.0844447    2.445450    9.0157994
#> lag1_var3  8.67299867 5.0892666    4.705732   15.5018671
#> lag1_var4 -7.61918063 4.6242522  -13.795750   -3.9095503
#> const     -4.67512610 7.9332312  -11.127995    6.0252235
#> 
#> $ARG$A$equation4
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  -0.5848697  0.5661819   -1.358657   -0.1891772
#> lag1_var2   6.9511064  1.8530114    4.757964    8.7213378
#> lag1_var3  11.2718316  3.0848809    7.584397   14.2273794
#> lag1_var4  -9.7259725  2.8263692  -12.497131   -6.3751857
#> const     -18.1807019 14.6835553  -34.182263   -3.2007762
#> 
#> 
#> 
```
