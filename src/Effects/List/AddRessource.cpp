#include "AddRessource.h"
#include "City.h"
#include"Ressource.h"

AddRessource::AddRessource() : ressource(RessourceType::LENGTH), quantity(0) {}

void AddRessource::effect(City* city) {
    city->getRessource(ressource)+=quantity;
}

void AddRessource::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
    ressource = StringToRessourceType(string_parameters[0]);
}
