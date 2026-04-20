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
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[1,1] 0.007159709 0.00252703 0.005171378   0.01057744
#> 
#> $AFG$Sigma$equation2
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.01628862 0.006991992 -0.02407605 -0.008681227
#> Sigma[2,2]  0.24224563 0.052331543  0.19420126  0.310330758
#> 
#> $AFG$Sigma$equation3
#>                   mean          sd  5% quantile 95% quantile
#> Sigma[3,1]  0.01971907 0.009102487  0.009476488   0.03051798
#> Sigma[3,2] -0.24045348 0.062767917 -0.319810113  -0.17812545
#> Sigma[3,3]  0.43668383 0.098032896  0.338632151   0.55060607
#> 
#> $AFG$Sigma$equation4
#>                  mean          sd  5% quantile 95% quantile
#> Sigma[4,1]  0.0115214 0.007190718  0.003627288   0.02029237
#> Sigma[4,2] -0.1467393 0.052685448 -0.203312989  -0.08172377
#> Sigma[4,3]  0.3628407 0.080599689  0.276950332   0.44804226
#> Sigma[4,4]  0.3442311 0.070364320  0.264500964   0.41599051
#> 
#> 
#> $AFG$A
#> $AFG$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9665174 0.03480860   0.9352943   1.01088386
#> lag1_var2 -0.0784417 0.04762354  -0.1436192  -0.04722431
#> lag1_var3 -0.1739979 0.04711720  -0.2365836  -0.13108223
#> lag1_var4  0.1650775 0.03369552   0.1261401   0.20312827
#> const      1.2351907 0.49170655   0.7911000   1.86511199
#> 
#> $AFG$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.2416291 0.1593570  0.07399833   0.44134063
#> lag1_var2  1.1219416 0.2212331  0.81951238   1.28189642
#> lag1_var3  0.4500340 0.4148050 -0.04500991   0.84367457
#> lag1_var4 -0.4675981 0.3744921 -0.83224404  -0.05436005
#> const     -3.8195331 2.1470526 -5.42270244  -0.88999293
#> 
#> $AFG$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.1540682 0.1808986 -0.31698253   0.06336444
#> lag1_var2 -0.2823299 0.4168162 -0.69566607   0.24605553
#> lag1_var3  0.8084423 0.6901014  0.09921814   1.61486242
#> lag1_var4  0.1804390 0.5830821 -0.46573142   0.77749024
#> const      5.4460316 7.1605995 -1.73384144  14.61386312
#> 
#> $AFG$A$equation4
#>                  mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.07081808 0.1603962  -0.2390759    0.1001651
#> lag1_var2  0.21806905 0.3314993  -0.1263301    0.5804860
#> lag1_var3  1.12310901 0.5200631   0.5458083    1.6822419
#> lag1_var4 -0.03146641 0.4506172  -0.4964871    0.4435948
#> const     -0.25027227 6.0718627  -5.2986629    7.7747630
#> 
#> 
#> 
#> $AGO
#> $AGO$Sigma
#> $AGO$Sigma$equation1
#>                  mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.02662845 0.008560165  0.01598715   0.03573773
#> 
#> $AGO$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.04812386 0.01085117 -0.06178211  -0.03702125
#> Sigma[2,2]  0.23394387 0.07700550  0.16440185   0.33277818
#> 
#> $AGO$Sigma$equation3
#>                    mean         sd 5% quantile 95% quantile
#> Sigma[3,1] -0.003152957 0.02937706 -0.02987086   0.03569673
#> Sigma[3,2] -0.113312898 0.06743862 -0.20623445  -0.06709843
#> Sigma[3,3]  0.400461709 0.08459467  0.28760832   0.46488088
#> 
#> $AGO$Sigma$equation4
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[4,1] -0.05321248 0.03594340 -0.08560189 -0.005712599
#> Sigma[4,2]  0.09133000 0.04802129  0.05235069  0.156396768
#> Sigma[4,3]  0.37790878 0.08329041  0.27321689  0.456153377
#> Sigma[4,4]  0.55441469 0.12507090  0.42409258  0.709290007
#> 
#> 
#> $AGO$A
#> $AGO$A$equation1
#>                mean         sd 5% quantile 95% quantile
#> lag1_var1  1.164577 0.05576897   1.0888244    1.2050247
#> lag1_var2 -1.140894 0.35649598  -1.3263186   -0.6591919
#> lag1_var3 -1.505528 0.36987608  -1.7054048   -0.9978336
#> lag1_var4  1.432497 0.38535282   0.9086739    1.6223768
#> const      1.305331 1.87485573  -0.7817406    3.5105875
#> 
#> $AGO$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.2613684 0.1776360   -0.443427  -0.05598494
#> lag1_var2  2.1611669 0.2416140    1.862132   2.41934451
#> lag1_var3  1.6847663 0.6802766    1.165014   2.60959073
#> lag1_var4 -1.5479550 0.5078201   -2.225782  -1.09998697
#> const     -1.8962752 7.3991935  -10.772250   6.24831488
#> 
#> $AGO$A$equation3
#>                 mean       sd 5% quantile 95% quantile
#> lag1_var1 -0.4065202 0.266472  -0.6877075   -0.1055531
#> lag1_var2  2.0312055 1.200954   0.3777509    2.6669312
#> lag1_var3  3.4175275 1.833706   0.9079093    4.4788271
#> lag1_var4 -2.4684799 1.699072  -3.4410520   -0.1404559
#> const     10.9974205 8.054584   1.5118912   19.8122445
#> 
#> $AGO$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -0.8065384 0.1959533   -1.042899   -0.5947657
#> lag1_var2  3.9379965 1.3278336    2.126752    4.7988398
#> lag1_var3  5.0664072 1.6227607    2.863996    6.1325631
#> lag1_var4 -3.9459422 1.6370247   -4.968678   -1.7302703
#> const      9.7672039 7.3664183    1.791623   17.7290237
#> 
#> 
#> 
#> $ALB
#> $ALB$Sigma
#> $ALB$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.002698907 0.001327661 0.001667889  0.004405098
#> 
#> $ALB$Sigma$equation2
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[2,1] -0.06146569 0.06318308  -0.1483146  -0.02307712
#> Sigma[2,2]  8.05742364 3.09753659   5.6196333  12.27010772
#> 
#> $ALB$Sigma$equation3
#>                   mean         sd 5% quantile 95% quantile
#> Sigma[3,1]  0.05984937 0.05013225  0.01602341    0.1237728
#> Sigma[3,2] -5.11558901 2.40109224 -8.40583824   -3.5797442
#> Sigma[3,3]  8.09243928 3.97598884  3.95588186   12.5841054
#> 
#> $ALB$Sigma$equation4
#>                 mean         sd 5% quantile 95% quantile
#> Sigma[4,1] 0.0217647 0.03899908 -0.01213536    0.0729713
#> Sigma[4,2] 0.2672365 0.80693251 -0.64788810    0.9785417
#> Sigma[4,3] 5.4828112 4.35716160  1.86515461   11.2773831
#> Sigma[4,4] 6.6407867 4.80375612  2.68507505   13.0395484
#> 
#> 
#> $ALB$A
#> $ALB$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.95146050 0.02982589  0.91575597  0.978067743
#> lag1_var2 -0.03255270 0.04271347 -0.09110082 -0.002343382
#> lag1_var3 -0.05420731 0.06937922 -0.14913370 -0.006480767
#> lag1_var4  0.04159511 0.05786506 -0.00153888  0.120125857
#> const      1.90612681 0.71137434  1.11786313  2.565736071
#> 
#> $ALB$A$equation2
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 -3.960446  1.299883   -5.363343    -2.492949
#> lag1_var2  4.881929  2.164132    2.229467     7.112217
#> lag1_var3  6.977308  3.488768    2.771966    10.724003
#> lag1_var4 -5.682953  2.871743   -8.727825    -2.196592
#> const     18.287340 32.709605  -23.013709    50.193256
#> 
#> $ALB$A$equation3
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1  1.627915  1.704038  -0.6460713     3.014330
#> lag1_var2 -2.713969  2.144062  -5.6478621    -1.192071
#> lag1_var3 -3.801956  3.555582  -8.6299899    -1.022425
#> lag1_var4  3.682106  3.065655   1.3078321     7.830174
#> const     27.083198 50.810644 -27.7647212    89.161822
#> 
#> $ALB$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1 -1.3672940  1.620670   -3.262367    0.2992444
#> lag1_var2  0.1804611  2.587765   -2.713014    2.7510500
#> lag1_var3  0.3606516  4.188892   -4.315079    4.7964681
#> lag1_var4  0.4175331  3.718445   -3.400927    4.5003881
#> const     45.3338704 35.487924    3.997630   86.2215725
#> 
#> 
#> 
#> $ARE
#> $ARE$Sigma
#> $ARE$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.002111523 0.001006606 0.001303464  0.003459728
#> 
#> $ARE$Sigma$equation2
#>                    mean          sd 5% quantile 95% quantile
#> Sigma[2,1] -0.008827507 0.004105971 -0.01412681 -0.004802949
#> Sigma[2,2]  0.179937285 0.054112507  0.11169299  0.234706948
#> 
#> $ARE$Sigma$equation3
#>                   mean         sd  5% quantile 95% quantile
#> Sigma[3,1]  0.01001302 0.01147611 -0.001336897   0.02451233
#> Sigma[3,2] -0.15043263 0.04844596 -0.207821524  -0.09537863
#> Sigma[3,3]  0.36239408 0.18241824  0.195005519   0.58962633
#> 
#> $ARE$Sigma$equation4
#>                    mean          sd  5% quantile 95% quantile
#> Sigma[4,1]  0.003560478 0.009185712 -0.006779669   0.01432156
#> Sigma[4,2] -0.009646546 0.041222554 -0.048808691   0.04360805
#> Sigma[4,3]  0.244583237 0.149497021  0.103149473   0.43483469
#> Sigma[4,4]  0.238927197 0.126644454  0.126535663   0.40563585
#> 
#> 
#> $ARE$A
#> $ARE$A$equation1
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  0.9453009 0.00951536   0.9359960    0.9566583
#> lag1_var2  0.1397012 0.01873698   0.1202836    0.1634450
#> lag1_var3  0.1452742 0.01255506   0.1343872    0.1616318
#> lag1_var4 -0.1507411 0.01652751  -0.1732030   -0.1382758
#> const      1.8232073 0.55605329   1.2036893    2.4352764
#> 
#> $ARE$A$equation2
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.1958001 0.4184904 -0.18648505   0.73913428
#> lag1_var2  0.1618129 0.7989157 -0.93826809   0.64178495
#> lag1_var3 -0.4188973 0.7865608 -1.49112733   0.01917449
#> lag1_var4  0.4101683 0.6784216  0.03860658   1.34025833
#> const     -3.2380183 4.5045819 -9.27016764   0.71560700
#> 
#> $ARE$A$equation3
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.7486441 0.3100512   0.3458080    1.0165134
#> lag1_var2 -0.8703888 0.8781258  -1.5163568    0.3240634
#> lag1_var3 -0.2710143 1.0307174  -1.0804632    1.1058151
#> lag1_var4  1.0114936 0.9745929  -0.2626716    1.9051491
#> const      0.1151673 5.3811282  -4.3023762    7.3791279
#> 
#> $ARE$A$equation4
#>                 mean        sd 5% quantile 95% quantile
#> lag1_var1  0.8665542 0.2944680   0.4854781   1.14797607
#> lag1_var2 -0.7836689 0.2895487  -1.0848115  -0.41797664
#> lag1_var3 -0.6232554 0.4583387  -1.1084053  -0.05556774
#> lag1_var4  1.3856311 0.5189956   0.8140540   2.01793404
#> const     -3.6704202 2.3795506  -5.6315500  -0.95146774
#> 
#> 
#> 
#> $ARG
#> $ARG$Sigma
#> $ARG$Sigma$equation1
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[1,1] 0.002976511 0.001081393 0.001888419  0.004260333
#> 
#> $ARG$Sigma$equation2
#>                   mean        sd 5% quantile 95% quantile
#> Sigma[2,1] -0.06180162 0.0134247  -0.0752566  -0.04671146
#> Sigma[2,2]  3.14772451 0.7161835   2.2515789   3.90543359
#> 
#> $ARG$Sigma$equation3
#>                   mean        sd 5% quantile 95% quantile
#> Sigma[3,1]  0.05585691 0.0118344  0.04425527   0.06872301
#> Sigma[3,2] -2.18331806 0.3121008 -2.42572478  -1.76096646
#> Sigma[3,3]  2.35321152 0.2748006  1.97856185   2.52013700
#> 
#> $ARG$Sigma$equation4
#>                   mean          sd 5% quantile 95% quantile
#> Sigma[4,1]  0.02165127 0.006380994  0.01423437   0.02890178
#> Sigma[4,2] -0.29885475 0.229566621 -0.58403650  -0.05572257
#> Sigma[4,3]  1.15519478 0.143850278  0.98448740   1.31904663
#> Sigma[4,4]  1.10474741 0.254057017  0.81153052   1.34664867
#> 
#> 
#> $ARG$A
#> $ARG$A$equation1
#>                  mean         sd 5% quantile 95% quantile
#> lag1_var1  0.89748291 0.04114495  0.85023606    0.9416844
#> lag1_var2  0.09713667 0.03213441  0.05439405    0.1243720
#> lag1_var3  0.16541690 0.05246330  0.09478894    0.2072436
#> lag1_var4 -0.15383903 0.04707778 -0.19210906   -0.0905496
#> const      2.11239978 0.72426630  1.24971776    2.8682142
#> 
#> $ARG$A$equation2
#>                mean        sd 5% quantile 95% quantile
#> lag1_var1 -2.088885  1.334394   -3.684440    -0.704136
#> lag1_var2  3.101616  1.391182    1.993567     4.984909
#> lag1_var3  3.812230  2.279845    1.992575     6.901446
#> lag1_var4 -2.947618  2.001539   -5.670086    -1.347829
#> const      5.725605 16.327426   -9.337984    26.255244
#> 
#> $ARG$A$equation3
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1  1.2829084  0.6679444   0.5422533    1.9357644
#> lag1_var2 -0.5485373  1.2922520  -1.8511323    0.9859829
#> lag1_var3 -0.2199578  2.1612921  -2.3604450    2.3425863
#> lag1_var4  0.5020818  1.9857798  -1.8320162    2.4623863
#> const      7.3396557 12.1221737  -8.2782282   19.3076139
#> 
#> $ARG$A$equation4
#>                 mean         sd 5% quantile 95% quantile
#> lag1_var1 -0.1035044  0.5366331 -0.65095048    0.5066637
#> lag1_var2  1.4274770  1.1614272  0.07245842    2.5897366
#> lag1_var3  2.2364884  1.9589407 -0.04154365    4.2113405
#> lag1_var4 -1.3589784  1.7436515 -3.10452805    0.6911105
#> const      9.6734245 11.2971674 -4.62774667   21.0051457
#> 
#> 
#> 
```
