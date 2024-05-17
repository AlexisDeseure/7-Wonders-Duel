#include "AddRessourceChoice.h"
#include "City.h"
#include"Ressource.h"

void AddRessourceChoice::effect(City* city) {
    city->addRessource(ressources);
}


void AddRessourceChoice::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    for (const std::string& ressource : string_parameters) {
        ressources.push_back(StringToRessourceType(ressource));
    }
}
