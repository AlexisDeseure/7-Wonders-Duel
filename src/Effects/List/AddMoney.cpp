#include "../../../includes/Effects/List/AddMoney.h"
#include "../../../includes/City/City.h"

void AddMoney::effect(City* city) {
    city->addMoney(quantity);
}