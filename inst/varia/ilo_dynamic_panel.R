
# Create ILO dataset from provided files
library(dplyr)

# this file contains a dynamic panel dynamic dataset
all_cv    <- read.csv("inst/varia/ilo_dynamic_panel.csv")
colnames(all_cv) = c("iso3code", "year", "GDP", "UR", "EPR", "LFPR", colnames(all_cv)[7:10])

# all variables all countries
data_cv <- all_cv %>% 
  filter(year <= 2024) %>% 
  mutate(gdp = log(GDP)) %>% 
  select(year, iso3code, gdp, UR, EPR, LFPR)

# Create a list with the country data
countries = unique(data_cv$iso3code)
countries = countries[order(countries)]
ilo_dynamic_panel = list()
for (i in 1:length(countries)) {
  ilo_dynamic_panel[[i]] <- data_cv %>% 
    filter(iso3code == countries[i]) %>% 
    select(gdp, UR, EPR, LFPR) %>% 
    ts(start = 1991, frequency = 1)
  names(ilo_dynamic_panel)[i] <- countries[i]
}

save(ilo_dynamic_panel, file = "data/ilo_dynamic_panel.rda")



all_cv    <- read.csv("inst/varia/ilo_dynamic_panel.csv")
colnames(all_cv) = c("iso3code", "year", "GDP", "UR", "EPR", "LFPR", colnames(all_cv)[7:10])

# all variables all countries
data_cv <- all_cv %>% 
  filter(year > 2024) %>% 
  mutate(gdp = log(GDP)) %>% 
  select(year, iso3code, gdp, UR, EPR, LFPR)

data_cv$UR = data_cv$EPR = data_cv$LFPR = NA

countries = unique(data_cv$iso3code)
countries = countries[order(countries)]
ilo_conditional_forecasts = list()
for (i in 1:length(countries)) {
  ilo_conditional_forecasts[[i]] <- data_cv %>% 
    filter(iso3code == countries[i]) %>% 
    select(gdp, UR, EPR, LFPR) %>% 
    ts(start = 2025, frequency = 1)
  names(ilo_conditional_forecasts)[i] <- countries[i]
}

save(ilo_conditional_forecasts, file = "data/ilo_conditional_forecasts.rda")
