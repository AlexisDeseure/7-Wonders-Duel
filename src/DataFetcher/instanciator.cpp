#include "../../includes/DataFetcher/Instanciator.h"

void Instanciator::constructBuilding(){
    for (std::pair<QString,QString>& noms : this->getNames()) {
        if (noms.first == "Building"){
            RessourceType ressource;
            Building currBuild = new Building(noms.second.toStdString(),json.getCost(noms.second), json.getBuildingEffects(noms.second), json.getDirectCost(noms.second), json.getColor(noms.second), json.getAge(noms.second), json.getChaining(noms.second).first, json.getChaining(noms.second).second);
            this->addBuildingToInstanciator(currBuild);
        }
    }

}
// Constructeur de Building:
// Building(const std::string& name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, BuildingType t, int a, const std::vector<std::string>& chainIn = {}, const std::vector<std::string>& chainOut = {})

void Instanciator::addBuildingToInstanciator(Building building){
    this->getBuildings().insert(getBuildings().end(),1,building);
}

//Classes abstraites ?
void Instanciator::addPTtoInstanciator(ProgressToken PT){
    this->getPTInstanciator().insert(getPTInstanciator().end(),1,PT);
}
void Instanciator::addWonderToInstanciator(Wonder wonder){
    this->getWonders().insert(getWonders().end(),1,wonder);
}
