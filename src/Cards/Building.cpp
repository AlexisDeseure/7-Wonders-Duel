#include "Building.h"
#include "City.h"

void Building::addChainOutToCity(City* city) const {
    for (const auto& chain : chainOut) {
        city->addChainSymbol(chain);
    }
}

bool Building::isChainInInCity(const City* city) const {
    for (const auto& chain : chainIn) {
        if (city->hasChainSymbol(chain)) {
            return true;
        }
    }
    return false;
}

std::string buildingTypeToString(BuildingType type){
    if (type == BuildingType::LENGTH){
        throw std::invalid_argument("BuildingType out of range");
    }
    return building_type_name[static_cast<std::size_t>(type)];
}

BuildingType StringToBuildingType(std::string nom){
    for (std::size_t i = 0; i < static_cast<int>(BuildingType::LENGTH); i++){
        if (nom == building_type_name[i]){
            return static_cast<BuildingType>(i);
        }
    }
    throw std::invalid_argument("BuildingType not found");
}
