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
#> Sigma[1,1] 0.005281184 0.0006413759 0.004491172  0.005838355
#> 
#> $AFG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.01049094 0.01232830 -0.02186927  0.004907158
#> Sigma[2,2]  0.25697325 0.09611812  0.16633132  0.372273783
#> 
#> $AFG$Sigma$equation3
#>                   mean         sd  5% quantile 95% quantile
#> Sigma[3,1]  0.02011856 0.01186782  0.007368415    0.0347440
#> Sigma[3,2] -0.20648178 0.17488467 -0.444859776   -0.0731645
#> Sigma[3,3]  0.54911045 0.25533080  0.316396523    0.8738559
#> 
#> $AFG$Sigma$equation4
#>                   mean         sd  5% quantile 95% quantile
#> Sigma[4,1]  0.01696039 0.01064216  0.007275544   0.03050124
#> Sigma[4,2] -0.10732436 0.16416961 -0.330741422   0.01361157
#> Sigma[4,3]  0.53353045 0.22949413  0.298490702   0.81277909
#> Sigma[4,4]  0.56961430 0.21802733  0.322926775   0.79754764
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.97801962 0.02466272   0.9477484    1.0047058
#> lag1_var2 -0.03520303 0.10189967  -0.1077722    0.1048893
#> lag1_var3 -0.03208098 0.24106675  -0.2133949    0.2971936
#> lag1_var4  0.02035801 0.21554763  -0.2738036    0.1847559
#> const      1.26575046 0.89134814   0.2867388    2.0314652
#> 
#> $AFG$A$equation2
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.41344398 0.1045331   0.3065337    0.5238383
#> lag1_var2  0.03164536 0.7979022  -1.0603433    0.5027890
#> lag1_var3 -1.89802508 2.0728286  -4.7387173   -0.6434906
#> lag1_var4  1.59995204 1.9064767   0.4326406    4.2242053
#> const      5.28687220 8.4117793  -1.4027629   16.5757227
#> 
#> $AFG$A$equation3
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.1598682  0.4292633  -0.2346935    0.7262956
#> lag1_var2  1.4166331  1.6254173   0.4813356    3.6520036
#> lag1_var3  5.6030483  3.7818249   3.0805099   10.8285478
#> lag1_var4 -4.3810976  3.4172313  -9.0934105   -2.0682306
#> const     -8.2238267 12.8336387 -25.2906450    3.1450023
#> 
#> $AFG$A$equation4
#>                  mean         sd  5% quantile 95% quantile
#> lag1_var1   0.4067203  0.5115888  -0.09511099     1.070956
#> lag1_var2   1.5883148  1.4829648   0.70272275     3.618385
#> lag1_var3   5.2954097  3.3645873   2.87094617     9.917498
#> lag1_var4  -4.0618320  3.0429777  -8.21502622    -1.840783
#> const     -13.1238583 10.8725434 -27.11766360    -2.796259
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[1,1] 0.09453674 0.04760778  0.04158669    0.1502249
#> 
#> $AGO$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.03798849 0.02658215 -0.06747715 -0.008341855
#> Sigma[2,2]  0.12097041 0.03348817  0.08615904  0.159735626
#> 
#> $AGO$Sigma$equation3
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[3,1] -0.007745106 0.03361256 -0.04306117   0.03362827
#> Sigma[3,2] -0.073140891 0.03476953 -0.11805555  -0.03991274
#> Sigma[3,3]  0.344789953 0.10047942  0.24308850   0.46613191
#> 
#> $AGO$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.03938253 0.05785482 -0.08797999   0.03074818
#> Sigma[4,2]  0.02165431 0.03987340 -0.01567840   0.06583003
#> Sigma[4,3]  0.34068329 0.10200145  0.21959041   0.44238442
#> Sigma[4,4]  0.42114827 0.12331796  0.25971027   0.52769593
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4599753 0.2151433   0.2643176    0.6937520
#> lag1_var2  1.4979660 0.3921736   1.2049748    2.0325732
#> lag1_var3  1.9968716 0.4370378   1.5926494    2.5385163
#> lag1_var4 -1.8120045 0.3896636  -2.3268494   -1.4976092
#> const     -0.2712299 1.0978604  -1.7281173    0.6672768
#> 
#> $AGO$A$equation2
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.18873053 0.1014470  0.05961866    0.2849338
#> lag1_var2  0.06208463 0.1899430 -0.19433829    0.2180325
#> lag1_var3 -1.18035645 0.1722255 -1.36966384   -0.9995472
#> lag1_var4  1.14554563 0.1679485  0.96675355    1.3432973
#> const     -1.54876679 1.3960221 -3.08981238   -0.1367850
#> 
#> $AGO$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.07699915 0.5321378  -0.7162233    0.4134098
#> lag1_var2  0.92648437 1.8937926  -1.0468369    3.0601217
#> lag1_var3  2.07546259 2.7141345  -0.7241019    5.1152826
#> lag1_var4 -1.15278323 2.4343837  -3.8496353    1.4182646
#> const      6.21016486 6.2705187  -1.1154821   13.0085197
#> 
#> $AGO$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 0.01107922 0.6933744  -0.8435567    0.6233634
#> lag1_var2 0.79628112 2.2531853  -1.5042007    3.3803318
#> lag1_var3 0.92696418 3.2081112  -2.3810438    4.5828635
#> lag1_var4 0.03596743 2.8715869  -3.2035695    3.0553371
#> const     1.14215021 6.2045926  -6.1220644    7.7360597
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.002438879 0.0008210386 0.001385756  0.003174186
#> 
#> $ALB$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.04031667 0.02527634 -0.07382463  -0.01874187
#> Sigma[2,2]  6.39663684 1.47760542  4.38659032   7.55893006
#> 
#> $ALB$Sigma$equation3
#>                   mean         sd  5% quantile 95% quantile
#> Sigma[3,1]  0.04110969 0.02843724  0.008341458   0.07340989
#> Sigma[3,2] -4.09446191 1.25823804 -5.652713228  -2.74837991
#> Sigma[3,3]  5.76275496 2.54314374  3.943537786   9.25456668
#> 
#> $ALB$Sigma$equation4
#>                  mean         sd  5% quantile 95% quantile
#> Sigma[4,1] 0.01933085 0.03025498 -0.007736991   0.05934594
#> Sigma[4,2] 0.17768005 0.83686873 -0.891576929   0.97976087
#> Sigma[4,3] 3.78054455 2.23858455  2.183177693   6.86309364
#> Sigma[4,4] 4.86584958 2.19703078  3.139333210   7.86211580
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                  mean         sd  5% quantile 95% quantile
#> lag1_var1  0.96698257 0.02163014  0.942424473   0.98654947
#> lag1_var2  0.01584736 0.02312237 -0.015300781   0.03365183
#> lag1_var3  0.01401469 0.03605410 -0.034364804   0.04240494
#> lag1_var4 -0.01712488 0.02844906 -0.038330967   0.02132800
#> const      0.85404611 0.67043021 -0.004406519   1.44469523
#> 
#> $ALB$A$equation2
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 -3.890142 0.6480885   -4.485826    -3.065294
#> lag1_var2  4.565841 0.9542976    3.402453     5.561107
#> lag1_var3  6.687293 1.5252394    4.873587     8.293698
#> lag1_var4 -5.426300 1.2393243   -6.722736    -3.939444
#> const     20.705066 9.5257473   11.300052    32.375591
#> 
#> $ALB$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1   2.3158125  0.529147   1.8416676    3.0041077
#> lag1_var2  -0.7486505  1.014379  -1.9342052    0.2527150
#> lag1_var3  -0.9886801  1.614009  -2.7391334    0.7323964
#> lag1_var4   1.2994974  1.404445  -0.1410792    2.8578481
#> const     -18.7664368 21.875904 -41.0859946    4.2863640
#> 
#> $ALB$A$equation4
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  -0.4401755  0.952816   -1.354120    0.7229499
#> lag1_var2   2.5536141  0.847079    1.733075    3.4722147
#> lag1_var3   3.8903561  1.340350    2.531287    5.3698165
#> lag1_var4  -2.5776898  1.140204   -3.836911   -1.4176690
#> const     -12.0038290 26.088909  -36.753508   18.7554559
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.001557477 0.0004001261 0.001199473  0.002089792
#> 
#> $ARE$Sigma$equation2
#>                   mean          sd  5% quantile 95% quantile
#> Sigma[2,1] -0.00622999 0.001269037 -0.007347833 -0.004539878
#> Sigma[2,2]  0.17800014 0.047526318  0.121731138  0.231573955
#> 
#> $ARE$Sigma$equation3
#>                   mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.01044744 0.003223748  0.007062002   0.01405697
#> Sigma[3,2] -0.17568715 0.058265378 -0.245585617  -0.12614492
#> Sigma[3,3]  0.42840111 0.065245019  0.365584522   0.50810634
#> 
#> $ARE$Sigma$equation4
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[4,1]  0.005356216 0.003900874  0.001290713  0.009722819
#> Sigma[4,2] -0.036757640 0.035356194 -0.069368553  0.008654926
#> Sigma[4,3]  0.292170498 0.068990003  0.251636405  0.385439160
#> Sigma[4,4]  0.265153462 0.079240371  0.201706836  0.372021623
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                  mean          sd 5% quantile 95% quantile
#> lag1_var1  0.98386714 0.012335318  0.96852686   0.99527213
#> lag1_var2  0.05541432 0.015047526  0.03819495   0.07316796
#> lag1_var3  0.04838819 0.006128529  0.04147417   0.05503590
#> lag1_var4 -0.06038517 0.009919905 -0.06969946  -0.04732812
#> const      1.33047760 0.302348958  1.05449074   1.72629826
#> 
#> $ARE$A$equation2
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.09872496 0.20245355  -0.3042806    0.1571707
#> lag1_var2  0.94582737 0.18415712   0.7328322    1.1276941
#> lag1_var3  0.44245047 0.09485327   0.3402318    0.5552267
#> lag1_var4 -0.35462275 0.12112293  -0.4989136   -0.2386034
#> const     -3.13793985 4.48440638  -8.8215524    0.7209399
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.7678564 0.5928842 -0.03889843  1.159697851
#> lag1_var2 -0.8556918 0.3874842 -1.36857644 -0.506658783
#> lag1_var3 -0.2777442 0.3079059 -0.68746212  0.001137655
#> lag1_var4  0.9966356 0.3564634  0.68364805  1.432750745
#> const      1.1254028 6.6115698 -5.51686960  9.611297739
#> 
#> $ARE$A$equation4
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1  0.74473773 0.4598352   0.1103272   1.03287419
#> lag1_var2 -0.15553648 0.4179606  -0.7340362   0.09358683
#> lag1_var3  0.05501412 0.3521501  -0.4143004   0.34489483
#> lag1_var4  0.75613470 0.3682689   0.3937879   1.22798425
#> const     -4.51709287 3.1335335  -7.5394539  -0.43949848
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.002087357 0.000218091 0.001851407  0.002348693
#> 
#> $ARG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.04592023 0.01278976  -0.0635242  -0.03725159
#> Sigma[2,2]  3.15774638 0.58301001   2.3744204   3.62754905
#> 
#> $ARG$Sigma$equation3
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[3,1]  0.04118765 0.008952575  0.03284204   0.05256344
#> Sigma[3,2] -2.15506906 0.364075441 -2.47431856  -1.67307933
#> Sigma[3,3]  2.18898261 0.345916170  1.84043117   2.63279365
#> 
#> $ARG$Sigma$equation4
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[4,1]  0.01521789 0.003135826  0.01198852   0.01900741
#> Sigma[4,2] -0.24276799 0.234773336 -0.52641176   0.01238722
#> Sigma[4,3]  0.96637813 0.207402250  0.81895492   1.24970721
#> Sigma[4,4]  0.91347284 0.116881070  0.80119758   1.05953625
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                  mean          sd 5% quantile 95% quantile
#> lag1_var1  0.94160076 0.006648275  0.93543415   0.95000840
#> lag1_var2  0.04908020 0.028410311  0.01736786   0.08278732
#> lag1_var3  0.07589813 0.046984536  0.02279131   0.13079350
#> lag1_var4 -0.07801682 0.046437944 -0.13252765  -0.02525171
#> const      1.68988252 0.313686451  1.26228964   1.86052260
#> 
#> $ARG$A$equation2
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1 -2.083734  0.6154863   -2.797820    -1.364186
#> lag1_var2  3.909398  1.6906071    2.173389     5.660806
#> lag1_var3  5.361236  2.7344957    2.539001     8.162235
#> lag1_var4 -4.328177  2.4264322   -6.973501    -1.941850
#> const     -2.993161 21.1957365  -24.596893    22.788353
#> 
#> $ARG$A$equation3
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1  1.723726  0.4020803   1.2514966    2.1764845
#> lag1_var2 -1.724763  1.1773437  -2.9351492   -0.4491760
#> lag1_var3 -2.389880  1.9719235  -4.3946073   -0.1847813
#> lag1_var4  2.326097  1.8241397   0.3684222    4.2020216
#> const     14.738985 14.5516130  -1.4255659   32.2014090
#> 
#> $ARG$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4294930 0.4073226   0.1397970    0.9857597
#> lag1_var2  0.6832072 1.0295318  -0.6472356    1.7040800
#> lag1_var3  0.8982218 1.7578416  -1.3506693    2.6815587
#> lag1_var4 -0.2748355 1.5794758  -1.9263464    1.7142460
#> const      9.9378812 8.0879104  -1.1382156   15.7528775
#> 
#> 
#> 
```
