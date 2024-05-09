#include "../../../includes/Effects/List/AddVictoryPoint.h"
#include "../../../includes/City/City.h"

void AddVictoryPoint::effect(City* city) {
    city->addVictoryPoints(quantity);
}