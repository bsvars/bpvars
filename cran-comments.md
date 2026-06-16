## R CMD check results

0 errors | 0 warnings | 0 notes

- Passess all the checks on GitHub action R-CMD-check
- Passess `devtools::check()` run locally 
- Passes `devtools::check(remote = TRUE, manual = TRUE)` run locally
- Passes `devtools::check_win_devel()`. Well, it gives:
```
* checking CRAN incoming feasibility ... [14s] NOTE
Maintainer: 'Tomasz Woźniak <wozniak.tom@pm.me>'

Possibly misspelled words in DESCRIPTION:
  Hassan (29:31)
  Liu (29:18)
```
but it's all as intnded.