#include "ChangeMarketRule.h"
#include "City.h"
#include "Ressource.h"

ChangeMarketRule::ChangeMarketRule() : ressource(RessourceType::LENGTH) {}

void ChangeMarketRule::effect(City* city) {
    city->getRessource(ressource).changeMarketRule();
}

void ChangeMarketRule::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    ressource = StringToRessourceType(string_parameters[0]);
}
