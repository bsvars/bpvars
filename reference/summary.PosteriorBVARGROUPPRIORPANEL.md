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
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.01242298 0.002668657 0.009857156    0.0158417
#> 
#> $AFG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.01342407 0.01210091 -0.02465884  0.002525759
#> Sigma[2,2]  0.25725289 0.09269851  0.16191165  0.373310187
#> 
#> $AFG$Sigma$equation3
#>                   mean         sd  5% quantile 95% quantile
#> Sigma[3,1]  0.03094849 0.02172948  0.001648522   0.04912121
#> Sigma[3,2] -0.21415683 0.05623169 -0.256645490  -0.13800667
#> Sigma[3,3]  0.39505813 0.10328033  0.280888328   0.52033738
#> 
#> $AFG$Sigma$equation4
#>                   mean         sd   5% quantile 95% quantile
#> Sigma[4,1]  0.02525836 0.01916399 -0.0006192983   0.04024628
#> Sigma[4,2] -0.12550984 0.04180186 -0.1707616291  -0.07412548
#> Sigma[4,3]  0.34547865 0.09433262  0.2490580032   0.46556022
#> Sigma[4,4]  0.33162726 0.08527127  0.2463720621   0.43986546
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9542998 0.02328362   0.9394308    0.9863953
#> lag1_var2 -0.4796111 0.09913423  -0.6131130   -0.3986286
#> lag1_var3 -1.0579294 0.28766596  -1.4530896   -0.8468156
#> lag1_var4  0.9354087 0.27547553   0.7354580    1.3139549
#> const      6.7096663 0.60665402   6.0969493    7.4396358
#> 
#> $AFG$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4298163 0.1210134   0.3107061    0.5849837
#> lag1_var2 -0.3990382 0.7844722  -0.9587289    0.6652186
#> lag1_var3 -3.1150423 1.6592233  -4.2561340   -0.8300883
#> lag1_var4  2.7830303 1.4560442   0.7729709    3.7639355
#> const      5.3211850 8.5256450  -5.6261625   12.9969140
#> 
#> $AFG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.2617076 0.1006970 -0.34481574   -0.1447963
#> lag1_var2  1.1692970 0.7866611  0.09956203    1.5833273
#> lag1_var3  4.3437733 2.0818714  1.51274120    5.5286482
#> lag1_var4 -3.1025682 1.9517932 -4.23667938   -0.4425685
#> const     -2.2050594 6.1262233 -7.88216664    5.7885356
#> 
#> $AFG$A$equation4
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.08029708 0.1269726  -0.1831202  0.083507756
#> lag1_var2  1.10981666 0.5821795   0.3468093  1.624301027
#> lag1_var3  3.30079517 1.6294658   1.1481685  4.657263130
#> lag1_var4 -2.06158238 1.5516988  -3.3259696  0.004102731
#> const     -5.90093882 5.5177009 -11.8744074 -0.998322924
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                 mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.0242305 0.004155224  0.01980954   0.02893454
#> 
#> $AGO$Sigma$equation2
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.01527432 0.006317614  -0.0231068 -0.009646743
#> Sigma[2,2]  0.13391523 0.025320818   0.1105624  0.164603979
#> 
#> $AGO$Sigma$equation3
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.005771597 0.01752475 -0.01136905   0.02575807
#> Sigma[3,2] -0.112524219 0.02526671 -0.14206680  -0.08464611
#> Sigma[3,3]  0.358762986 0.08453589  0.29045026   0.47231317
#> 
#> $AGO$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.00134997 0.02125786 -0.01974130   0.02493865
#> Sigma[4,2] -0.01353741 0.03377577 -0.05758086   0.01478992
#> Sigma[4,3]  0.32209368 0.09035530  0.23977205   0.43954419
#> Sigma[4,4]  0.37089646 0.09982634  0.25786779   0.48679185
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.7493265 0.03635312   0.7066694    0.7852191
#> lag1_var2  0.5720316 0.15616214   0.4150701    0.7378086
#> lag1_var3  0.8275687 0.17075426   0.6496846    1.0127702
#> lag1_var4 -0.7643866 0.14833814  -0.9340847   -0.6196952
#> const      2.4068011 2.21250048  -0.3355538    4.6482365
#> 
#> $AGO$A$equation2
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.00562742 0.09960642  -0.1271870   0.09297618
#> lag1_var2  0.90882779 0.39117057   0.6396434   1.44025035
#> lag1_var3 -0.10965666 0.58340797  -0.5755687   0.67242186
#> lag1_var4  0.18856987 0.48712305  -0.4701408   0.56327977
#> const     -6.23005079 4.21030570 -11.1879415  -1.73639955
#> 
#> $AGO$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.09171873 0.2622434  -0.3652905    0.1801090
#> lag1_var2  1.38738309 0.9578198   0.5340154    2.5201431
#> lag1_var3  2.62980219 1.4734235   1.1163826    4.2317609
#> lag1_var4 -1.64173734 1.3025496  -3.0737760   -0.3288758
#> const      1.09626059 4.1220029  -3.5321670    5.9729513
#> 
#> $AGO$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.2374033 0.2307627  -0.4898283  -0.01563462
#> lag1_var2  2.0758580 0.9200068   1.1625165   3.14567825
#> lag1_var3  2.5451135 1.3516886   1.1331196   3.98403896
#> lag1_var4 -1.4230251 1.2232628  -2.7491620  -0.17059029
#> const     -5.4744249 4.4295151 -10.0957566  -0.07888916
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[1,1] 0.003131004 0.00061734 0.002568914  0.003837266
#> 
#> $ALB$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.04721395 0.02825826 -0.06952755  -0.01244926
#> Sigma[2,2]  7.56723669 1.36476884  6.11557901   9.24671165
#> 
#> $ALB$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.04229047 0.02596433  0.02637282   0.07765358
#> Sigma[3,2] -4.86655945 1.20400852 -6.44156877  -3.81649309
#> Sigma[3,3]  6.63265960 3.89627706  4.12025615  11.91952646
#> 
#> $ALB$Sigma$equation4
#>                  mean         sd 5% quantile 95% quantile
#> Sigma[4,1] 0.01217123 0.02912424 -0.01916658   0.04511311
#> Sigma[4,2] 0.17625153 0.64396135 -0.53413656   0.85712077
#> Sigma[4,3] 4.12001679 3.90893633  1.85753238   9.47030726
#> Sigma[4,4] 5.15169369 4.42294637  2.45902436  11.25689897
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                   mean         sd 5% quantile 95% quantile
#> lag1_var1  0.938861231 0.01925670  0.91974905   0.96067878
#> lag1_var2 -0.001304593 0.04799655 -0.05825529   0.04504218
#> lag1_var3 -0.006411595 0.07230860 -0.09299101   0.06304420
#> lag1_var4  0.001122738 0.06109119 -0.05484896   0.07487558
#> const      1.706763431 0.40825542  1.25027057   2.18740870
#> 
#> $ALB$A$equation2
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1 -2.709671  0.8996204  -3.3268595   -1.4681876
#> lag1_var2  3.156273  1.8242429   0.9263651    5.1394565
#> lag1_var3  4.215364  2.7203496   0.9044946    7.2062070
#> lag1_var4 -3.363594  2.3978859  -5.9317964   -0.4099856
#> const     17.093560 33.7653752 -19.0416050   54.0458205
#> 
#> $ALB$A$equation3
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1   1.9143809  1.710098   0.4141801    4.1954576
#> lag1_var2  -0.4827946  1.067621  -1.7935544    0.6672694
#> lag1_var3  -0.2950963  1.643157  -2.4251938    1.2137875
#> lag1_var4   0.8395474  1.563126  -0.6445915    2.8652454
#> const     -21.4732731 34.593013 -67.4168940    6.9256891
#> 
#> $ALB$A$equation4
#>                   mean        sd 5% quantile 95% quantile
#> lag1_var1  -0.08677189  1.846753  -2.1013658     2.161388
#> lag1_var2   1.60371948  2.195886  -0.5249704     4.094900
#> lag1_var3   2.55482270  3.445224  -0.8880967     6.616635
#> lag1_var4  -1.31382611  3.059442  -4.8417834     1.764092
#> const     -13.74931037 23.855948 -45.7213168     4.563868
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                  mean           sd  5% quantile 95% quantile
#> Sigma[1,1] 0.00124467 0.0004176849 0.0008715999  0.001781774
#> 
#> $ARE$Sigma$equation2
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[2,1] -0.006659592 0.002836255 -0.009397656 -0.003580317
#> Sigma[2,2]  0.211494887 0.045264489  0.160913595  0.263511677
#> 
#> $ARE$Sigma$equation3
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.008690113 0.003396055  0.005472659   0.01311357
#> Sigma[3,2] -0.175779675 0.061001185 -0.241696760  -0.11614636
#> Sigma[3,3]  0.301529922 0.081005978  0.215582164   0.38240402
#> 
#> $ARE$Sigma$equation4
#>                    mean          sd   5% quantile 95% quantile
#> Sigma[4,1]  0.003564639 0.002280415  0.0009315594  0.006187703
#> Sigma[4,2] -0.010807842 0.038883292 -0.0503529050  0.038547831
#> Sigma[4,3]  0.168318176 0.056911465  0.1261446529  0.245965635
#> Sigma[4,4]  0.164101347 0.050935601  0.1323462956  0.234567726
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.95012625 0.02854601   0.9200926    0.9823604
#> lag1_var2  0.04701504 0.12236620  -0.1163613    0.1477712
#> lag1_var3  0.01522933 0.15871877  -0.1943517    0.1555396
#> lag1_var4 -0.01913458 0.15066868  -0.1480275    0.1802524
#> const      1.56391708 0.27647277   1.3301217    1.9364903
#> 
#> $ARE$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4832247 0.3227841   0.1701128    0.8787561
#> lag1_var2  0.3804781 1.0351264  -0.7894571    1.2371930
#> lag1_var3  0.1264445 1.2949927  -1.2692548    1.4220842
#> lag1_var4 -0.2165763 1.2406474  -1.4373514    1.1067896
#> const     -4.0332536 4.3721745  -8.9626330    0.6599587
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.4238757 0.2741232   0.1041566   0.70108628
#> lag1_var2  2.2995566 1.5292083   0.1995300   3.37163216
#> lag1_var3  3.6306242 1.9541123   0.9666395   5.12751355
#> lag1_var4 -2.7712411 1.9905142  -4.2397665  -0.04847755
#> const     -0.9543465 3.4787547  -3.7192818   3.70499164
#> 
#> $ARE$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.7899872 0.3113345   0.3744624    1.0545318
#> lag1_var2  2.5032936 1.5295210   0.7270328    3.9686053
#> lag1_var3  3.6275381 2.0862632   1.0790507    5.5922603
#> lag1_var4 -2.8171518 2.1351478  -4.8253143   -0.1873632
#> const     -5.4408369 3.3847580  -8.7507951   -1.1178771
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                   mean           sd 5% quantile 95% quantile
#> Sigma[1,1] 0.003402559 0.0006888627 0.002707866  0.004223636
#> 
#> $ARG$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.07689277 0.01031946 -0.08883423  -0.06481973
#> Sigma[2,2]  3.72991086 0.43896041  3.25073918   4.16611011
#> 
#> $ARG$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.07476856 0.02080099  0.05523016    0.1018169
#> Sigma[3,2] -2.61982386 0.85146268 -3.67292996   -1.7416114
#> Sigma[3,3]  3.04481964 0.94786859  2.10067434    4.2404290
#> 
#> $ARG$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1]  0.03219567 0.01747446  0.01693129   0.05533004
#> Sigma[4,2] -0.40015392 0.68597534 -1.26812234   0.29284773
#> Sigma[4,3]  1.63187372 0.61835992  0.87141792   2.26182992
#> Sigma[4,4]  1.55905175 0.59407216  0.86968528   2.25093510
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9144452 0.06723827  0.83082278    0.9788575
#> lag1_var2  0.1170561 0.18527420 -0.08194026    0.3151886
#> lag1_var3  0.1898433 0.30499652 -0.13606917    0.5195838
#> lag1_var4 -0.1809262 0.27507310 -0.47758703    0.1115499
#> const      1.7668216 0.51234289  1.25131662    2.3710736
#> 
#> $ARG$A$equation2
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.9905033  0.2853848  -1.2857365   -0.6513421
#> lag1_var2  1.7596052  2.1923721  -0.4892847    4.4948780
#> lag1_var3  1.7195828  3.4643521  -1.8248596    6.0222590
#> lag1_var4 -1.4006720  3.2863511  -5.4727945    1.9243771
#> const     10.1605232 11.1203066  -1.4179198   23.0513535
#> 
#> $ARG$A$equation3
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.3729911  0.9721938  -0.7471935    1.3433990
#> lag1_var2  3.4750777  3.2020696  -0.1021877    6.3552254
#> lag1_var3  6.2726436  5.1740057   0.4548048   10.8081114
#> lag1_var4 -5.4412174  4.6682646  -9.5605839   -0.2451172
#> const     -2.4546375 18.5658628 -21.6043705   18.0162022
#> 
#> $ARG$A$equation4
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.2996591  0.8973225   -1.327175    0.6027403
#> lag1_var2  4.7165583  2.6638489    1.681465    7.6975916
#> lag1_var3  7.5787401  4.3203314    2.644925   12.3328962
#> lag1_var4 -6.5041379  3.8785523  -10.843325   -2.0519227
#> const      2.4956744 15.1253921  -16.365801   17.2833777
#> 
#> 
#> 
```
