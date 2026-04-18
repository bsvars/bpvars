# based on the original file sent by Miguel 
# /2024-09 data/Final baseline April 2024 gdp.xlsx

data_tmp      = read.csv("inst/varia/ilo_dynamic_panel.csv")
unique_index  =  which(data_tmp[,2] == 2024)
country_tmp   = data_tmp[unique_index,c(1,7:10)]
countries     = unique(country_tmp$iso3code)
country_tmp   = country_tmp[order(countries),]

country_grouping_region             = match(country_tmp[,2], unique(country_tmp[,2]))
country_grouping_subregionbroad     = match(country_tmp[,3], unique(country_tmp[,3]))
country_grouping_subregiondetailed  = match(country_tmp[,4], unique(country_tmp[,4]))
country_grouping_incomegroup        = match(country_tmp[,5], unique(country_tmp[,5]))

save(country_grouping_region, file = "data/country_grouping_region.rda")
save(country_grouping_subregionbroad, file = "data/country_grouping_subregionbroad.rda")
save(country_grouping_subregiondetailed, file = "data/country_grouping_subregiondetailed.rda")
save(country_grouping_incomegroup, file = "data/country_grouping_incomegroup.rda")
