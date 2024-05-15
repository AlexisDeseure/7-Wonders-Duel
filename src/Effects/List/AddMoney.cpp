#include "../../../includes/Effects/List/AddMoney.h"
#include "../../../includes/City/City.h"

void AddMoney::effect(City* city) {
    city->addMoney(quantity);
}

void AddMoney::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
}



