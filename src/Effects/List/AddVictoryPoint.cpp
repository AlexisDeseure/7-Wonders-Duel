#include "../../../includes/Effects/List/AddVictoryPoint.h"
#include "../../../includes/City/City.h"

void AddVictoryPoint::effect(City* city) {
    city->addVictoryPoints(quantity);
}

void AddVictoryPoint::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
}