#include "../../includes/DataFetcher/Instanciator.h"

void Instanciator::constructBuilding(){
    std::vector<std::pair<QString,QString>> Lnames=getNames();
    for (std::pair<QString,QString>& noms : Lnames) {
        if (noms.first == "Building"){
            std::vector<Building> Buildings = getBuildings();

        }
    }

}
