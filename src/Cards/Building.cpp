#include "../../includes/Cards/Building.h"
#include "../../includes/City/City.h"

void Building::addChainOutToCity(City* city) const {
    for (const auto& chain : chainOut) {
        city->addChainSymbol(chain);
    }
}

bool Building::isChainInInCity(const City* city) const {
    for (const auto& chain : chainIn) {
        if (!city->hasChainSymbol(chain)) {
            return false;
        }
    }
    return true;
}