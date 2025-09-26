
# Create ILO dataset from provided files
library(dplyr)

# this file contains a dynamic panel dynamic dataset
all_cv    <- read.csv("inst/varia/ilo_dynamic_panel_missing.csv")
colnames(all_cv) = c("year", "iso3code", "country", "GDP", "UR", "EPR", "LFPR", colnames(all_cv)[8:11])

# all variables all countries
data_cv <- all_cv %>% 
  filter(year <= 2024) %>% 
  mutate(gdp = log(GDP)) %>% 
  select(year, iso3code, gdp, UR, EPR, LFPR)

# Create a list with the country data
countries = unique(data_cv$iso3code)
countries = countries[order(countries)]

ilo_dynamic_panel_missing       = list()
ilo_exogenous_variables_missing = list()

for (i in 1:length(countries)) {
   data_c <- data_cv %>% 
    filter(iso3code == countries[i]) %>% 
    select(gdp, UR, EPR, LFPR) %>% 
    ts(start = 1991, frequency = 1)
  
  times       = zoo::index(data_c)
  labour_miss = apply(data_c, 1, \(x)(all(is.na(x[2:3]))))
  
  if (all(labour_miss)) {
    first_in = 30
  } else {
    first_in    = which(!labour_miss)[1]
  }
  
  if ( first_in == 1 ) {
    ilo_dynamic_panel_missing[[i]] <- ilo_dynamic_panel[[i]]
    ilo_exogenous_variables_missing[[i]] <- ilo_exogenous_variables[[i]]
  } else {
    ilo_dynamic_panel_missing[[i]] <- 
      data_c[-seq_len(first_in - 1),] |> 
      ts(start = times[first_in], frequency = 1)
    
    ilo_exogenous_variables_missing[[i]] <- 
      ilo_exogenous_variables[[i]][-seq_len(first_in - 1), ] |> 
      ts(start = times[first_in], frequency = 1)
  }
  names(ilo_dynamic_panel_missing)[i] <- countries[i]
}

save(ilo_dynamic_panel_missing, file = "data/ilo_dynamic_panel_missing.rda")
save(ilo_exogenous_variables_missing, file = "data/ilo_exogenous_variables_missing.rda")
