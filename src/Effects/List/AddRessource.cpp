#include "../../../includes/Effects/List/AddRessource.h"
#include "../../../includes/City/City.h"
#include"../../../includes/City/Ressource.h"

void AddRessource::effect(City* city) {
    city->getRessource(ressource)+=quantity;
}