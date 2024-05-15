#include "../../../includes/Effects/List/AddRessource.h"
#include "../../../includes/City/City.h"
#include"../../../includes/City/Ressource.h"

AddRessource::AddRessource() : ressource(RessourceType::RessourceTypeCount), quantity(0) {}

void AddRessource::effect(City* city) {
    city->getRessource(ressource)+=quantity;
}

void AddRessource::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
    //TODO : implémenter la conversion de string en RessourceType
}