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
#> Sigma[1,1] 0.006757443 0.0007020677 0.006027212  0.007582175
#> 
#> $AFG$Sigma$equation2
#>                   mean        sd 5% quantile 95% quantile
#> Sigma[2,1] -0.01546618 0.0105268 -0.02615493 -0.002049287
#> Sigma[2,2]  0.28220394 0.1209511  0.19778326  0.448990192
#> 
#> $AFG$Sigma$equation3
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[3,1]  0.0246456 0.005888144   0.0178910   0.03127632
#> Sigma[3,2] -0.3879093 0.275397175  -0.7665411  -0.19488945
#> Sigma[3,3]  0.9878703 0.557002853   0.4719514   1.68579770
#> 
#> $AFG$Sigma$equation4
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[4,1]  0.01825058 0.006008811  0.01078766   0.02451545
#> Sigma[4,2] -0.28930135 0.255296503 -0.63823931  -0.11605177
#> Sigma[4,3]  0.90294445 0.493167330  0.42718586   1.49404054
#> Sigma[4,4]  0.86037140 0.432958889  0.41962815   1.34518870
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                   mean         sd 5% quantile 95% quantile
#> lag1_var1  1.004163072 0.02725863  0.97680057   1.03858251
#> lag1_var2  0.007272838 0.02833953 -0.01813986   0.04336504
#> lag1_var3  0.024452940 0.08380441 -0.06012378   0.12895406
#> lag1_var4 -0.017148189 0.08062985 -0.11567568   0.06425828
#> const     -0.341055536 0.49574961 -0.91836946   0.12914114
#> 
#> $AFG$A$equation2
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.00351338 0.1463137  -0.1906000    0.1349347
#> lag1_var2  1.56330430 0.8492000   0.9284431    2.6895708
#> lag1_var3  1.19251426 1.8607694  -0.2202624    3.6739041
#> lag1_var4 -1.03360822 1.6123935  -3.1896643    0.1952962
#> const     -7.37359360 9.4335609 -18.2351238    1.4767451
#> 
#> $AFG$A$equation3
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.5446973  0.3350263   0.2758461    0.9936467
#> lag1_var2 -2.6902980  1.7526291  -5.0334041   -1.2933393
#> lag1_var3 -3.6966328  3.8043426  -8.8245575   -0.6817093
#> lag1_var4  3.8723324  3.2971492   1.3013629    8.3411688
#> const     29.8350752 17.9324069  13.0330628   49.7546094
#> 
#> $AFG$A$equation4
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.5930887  0.3133245   0.3676925    1.0181245
#> lag1_var2 -2.2538783  1.5618025  -4.3334814   -0.9448906
#> lag1_var3 -3.6187458  3.3826366  -8.1700660   -0.8659119
#> lag1_var4  3.9097715  2.9315880   1.5714881    7.8783488
#> const     23.9461972 15.3958820   8.9090251   40.8336893
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01219041 0.002849528 0.009657193   0.01591905
#> 
#> $AGO$Sigma$equation2
#>                    mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.008388161 0.003632973 -0.01321146 -0.005430804
#> Sigma[2,2]  0.142715550 0.037072111  0.11417259  0.190140272
#> 
#> $AGO$Sigma$equation3
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.004518125 0.003262769  0.001301905  0.008605467
#> Sigma[3,2] -0.107671672 0.036751959 -0.138770912 -0.062944842
#> Sigma[3,3]  0.355918672 0.088316082  0.298647771  0.475588057
#> 
#> $AGO$Sigma$equation4
#>                   mean          sd  5% quantile 95% quantile
#> Sigma[4,1] 0.001289698 0.004519566 -0.002710844  0.007190673
#> Sigma[4,2] 0.002505037 0.038627704 -0.047795643  0.036101389
#> Sigma[4,3] 0.314357253 0.096725335  0.237276104  0.446050626
#> Sigma[4,4] 0.366996602 0.091824524  0.294085194  0.487532752
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.8930478 0.02503784   0.8629721    0.9210974
#> lag1_var2  0.4761474 0.03827145   0.4434967    0.5260496
#> lag1_var3  0.6855346 0.02664251   0.6575069    0.7154257
#> lag1_var4 -0.6066973 0.02236578  -0.6348235   -0.5832975
#> const     -2.5604528 1.23808085  -3.7623071   -1.2027441
#> 
#> $AGO$A$equation2
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.02021762 0.04664527 -0.06309488   0.03435225
#> lag1_var2  0.75519460 0.18484645  0.52652939   0.92191158
#> lag1_var3 -0.15182376 0.18665175 -0.39863019   0.01022252
#> lag1_var4  0.21950367 0.17830703  0.04039267   0.44419251
#> const     -2.69416455 3.21101856 -5.96921287   0.69748303
#> 
#> $AGO$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.2316155 0.1316701   0.0555721    0.3458205
#> lag1_var2 -0.1075550 0.8304600  -1.1608082    0.7482133
#> lag1_var3  0.3806026 0.8839933  -0.7669558    1.2034441
#> lag1_var4  0.3734507 0.8098562  -0.4182472    1.4057181
#> const      7.1472699 7.5138485  -0.2954906   16.7067111
#> 
#> $AGO$A$equation4
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 0.1463667 0.1516157 -0.05860679    0.2660801
#> lag1_var2 0.4484053 0.7889531 -0.57837708    1.1970232
#> lag1_var3 0.2248772 0.8646542 -0.93146336    0.9398171
#> lag1_var4 0.6666342 0.7733180 -0.03121350    1.6792603
#> const     0.1190494 8.7008042 -6.92733302   11.8360209
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.002979768 0.001421185 0.002032302  0.004932301
#> 
#> $ALB$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.06593789 0.02486099 -0.09143136  -0.03476827
#> Sigma[2,2]  7.99322273 2.26842304  5.18287587  10.41166501
#> 
#> $ALB$Sigma$equation3
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[3,1] -0.009739503 0.04584533 -0.07017947   0.03286118
#> Sigma[3,2] -3.503011924 1.62443793 -5.49244984  -1.93895384
#> Sigma[3,3]  5.365451528 1.62841540  3.67165524   7.13320155
#> 
#> $ALB$Sigma$equation4
#>                   mean        sd 5% quantile 95% quantile
#> Sigma[4,1] -0.06250682 0.0693818  -0.1548793 -0.002813835
#> Sigma[4,2]  2.15073084 2.5645913   0.1058352  5.334176729
#> Sigma[4,3]  3.58313545 2.1975839   1.7561223  6.445832617
#> Sigma[4,4]  5.96001211 4.1732302   2.2716121 11.206206438
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  1.01456358 0.02364557  0.98904969   1.04139097
#> lag1_var2  0.02636767 0.04462513 -0.02011892   0.07645985
#> lag1_var3  0.03634705 0.07302777 -0.03984753   0.12013756
#> lag1_var4 -0.02666840 0.06161372 -0.09586595   0.03973386
#> const     -0.94489877 0.21062669 -1.23278258  -0.82508073
#> 
#> $ALB$A$equation2
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1 -2.566313  0.3287248   -2.882886    -2.167985
#> lag1_var2  4.182837  1.3988867    2.961676     6.046287
#> lag1_var3  5.667222  2.4434736    3.480428     8.901947
#> lag1_var4 -4.715624  2.0262977   -7.414236    -2.922010
#> const      5.431490 18.9548848  -19.972674    20.762489
#> 
#> $ALB$A$equation3
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1  2.182365  0.6310158   1.3166051    2.6241249
#> lag1_var2 -2.351361  1.5484491  -4.1754927   -0.6275755
#> lag1_var3 -3.232081  2.2591847  -5.9539741   -0.7377206
#> lag1_var4  3.302038  2.0676408   0.9396414    5.6902378
#> const      2.500330 15.0205798 -14.9166073   19.0995234
#> 
#> $ALB$A$equation4
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1 0.5301638  0.8628195  -0.6531495     1.090596
#> lag1_var2 0.1576162  2.5665006  -2.2189469     3.465971
#> lag1_var3 0.1386794  3.9913627  -3.4236740     5.410415
#> lag1_var4 0.6136872  3.5404044  -4.0168715     3.765794
#> const     1.4243474 18.3197435 -20.6073681    21.310589
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                 mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.0022477 0.0007744571 0.001326048  0.002936652
#> 
#> $ARE$Sigma$equation2
#>                  mean          sd  5% quantile 95% quantile
#> Sigma[2,1] -0.0056859 0.002900219 -0.008782606 -0.002706229
#> Sigma[2,2]  0.1864754 0.039650288  0.135671389  0.222658348
#> 
#> $ARE$Sigma$equation3
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.008371764 0.006706227  0.001425857   0.01653584
#> Sigma[3,2] -0.163418675 0.050740982 -0.224323767  -0.10751183
#> Sigma[3,3]  0.355803995 0.075402698  0.260765327   0.42945169
#> 
#> $ARE$Sigma$equation4
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[4,1]  0.004009127 0.005117003 -0.001960232  0.009973283
#> Sigma[4,2] -0.018750424 0.034623016 -0.064225741  0.009468355
#> Sigma[4,3]  0.232864839 0.080791207  0.136236544  0.322893523
#> Sigma[4,4]  0.222313297 0.081151144  0.139885660  0.325537598
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  1.0193968 0.02872135   0.9860397    1.0526914
#> lag1_var2  0.3717117 0.28348787   0.1218706    0.6782568
#> lag1_var3  0.4746598 0.34405694   0.1768133    0.8518804
#> lag1_var4 -0.4801182 0.33624286  -0.8455668   -0.1887569
#> const     -0.0716292 0.27975315  -0.4166759    0.2290664
#> 
#> $ARE$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.3472369 0.4788974  -0.2378484    0.7625337
#> lag1_var2  1.0266362 0.5352654   0.5624129    1.7139373
#> lag1_var3  0.8315457 0.9000030  -0.1166779    1.8691245
#> lag1_var4 -0.8296995 0.9856472  -1.9242944    0.1980108
#> const     -7.7315395 3.7769709 -11.5856105   -3.0685799
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.7128962 0.3354435   0.3861542    1.1004258
#> lag1_var2  0.0891268 0.9836177  -1.0817252    0.9931477
#> lag1_var3  0.9388669 1.3261063  -0.6251734    1.9846528
#> lag1_var4 -0.2522046 1.3693472  -1.3933530    1.3130615
#> const      5.0284039 3.2994787   2.1013064    9.2193356
#> 
#> $ARE$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  1.0034254 0.1224531   0.8402219   1.10668557
#> lag1_var2  0.8814324 0.6312792   0.2204363   1.56641914
#> lag1_var3  1.5988146 0.7459286   0.8095400   2.35899553
#> lag1_var4 -0.8895788 0.7292515  -1.6085173  -0.08577313
#> const     -3.1265106 3.5708860  -7.0649717   0.21093730
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.002704699 0.0002375916 0.002384647  0.002902772
#> 
#> $ARG$Sigma$equation2
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.05162767 0.007740596  -0.0573809   -0.0410561
#> Sigma[2,2]  2.81122998 0.256412576   2.5387737    3.1289951
#> 
#> $ARG$Sigma$equation3
#>                   mean        sd 5% quantile 95% quantile
#> Sigma[3,1]  0.05395464 0.0109353  0.04156265   0.06436791
#> Sigma[3,2] -2.15351574 0.1654566 -2.33426122  -2.01214301
#> Sigma[3,3]  2.36208617 0.2313283  2.16114058   2.67181393
#> 
#> $ARG$Sigma$equation4
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[4,1]  0.02572233 0.008534804  0.01509564   0.03420286
#> Sigma[4,2] -0.49229512 0.171550052 -0.70810864  -0.31946778
#> Sigma[4,3]  1.17488831 0.187795876  1.02411739   1.42953119
#> Sigma[4,4]  0.98170184 0.171090205  0.81771833   1.17019463
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.91993106 0.01545148   0.9003474    0.9351444
#> lag1_var2  0.23310533 0.03347105   0.1876042    0.2503243
#> lag1_var3  0.38469800 0.05677950   0.3070929    0.4150029
#> lag1_var4 -0.34941974 0.05448453  -0.3846026   -0.2749887
#> const      0.04343507 0.73693496  -0.7175083    0.8904961
#> 
#> $ARG$A$equation2
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.82773921  0.5040823  -1.2055638   -0.1528216
#> lag1_var2  1.12076662  0.7018481   0.2517665    1.8637343
#> lag1_var3  0.59844378  1.2440685  -0.8798247    2.0093846
#> lag1_var4 -0.07962468  1.1887449  -1.3765245    1.3490401
#> const     -6.86609616 15.2682347 -26.7315769    6.0276332
#> 
#> $ARG$A$equation3
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.7581323  0.3357408   0.3554484   1.10009513
#> lag1_var2 -0.8151422  0.8560218  -1.9526915  -0.04715747
#> lag1_var3 -0.6726850  1.5262279  -2.6949862   0.71886416
#> lag1_var4  0.9152508  1.3902695  -0.3846664   2.74437911
#> const     23.7169350 19.8836080   4.6435646  48.90694151
#> 
#> $ARG$A$equation4
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.2014957  0.4259875  -0.3805448    0.5188303
#> lag1_var2 -0.1664840  0.5545186  -0.9243440    0.1549376
#> lag1_var3 -0.3760680  0.9362911  -1.6606254    0.1669684
#> lag1_var4  0.9901640  0.8308464   0.4778885    2.1406473
#> const     17.5112659 18.6882911   5.2094264   43.2447758
#> 
#> 
#> 
```
