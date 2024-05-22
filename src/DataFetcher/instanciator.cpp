#include "../../includes/DataFetcher/Instanciator.h"
#include "Building.h"
#include "Wonder.h"
#include"Card.h"
#include "ProgressToken.h"

const std::vector<Ressource*> Instanciator::jsonToRessource(std::vector<std::pair<QString,int>> jsonRes){
    std::vector<Ressource*> cost;
    for (std::pair<QString,int> res: jsonRes){
        std::vector<RessourceType> RT;
        unsigned int amount;

        Ressource resCurr= Ressource(RT,amount);

    }

    return cost;
}

//Constructeur de Ressource.
//explicit Ressource(std::vector<RessourceType> t, unsigned int a=0, unsigned int p=2);

void Instanciator::constructBuilding(){
    for (std::pair<QString,QString>& noms : this->getNames()) {
        if (noms.first == "Building"){
            Building currBuild = new Building(noms.second.toStdString(),json.getCost(noms.second), json.getBuildingEffects(noms.second), json.getDirectCost(noms.second), StringToBuildingType(json.getColor(noms.second)), json.getAge(noms.second), json.getChaining(noms.second).first, json.getChaining(noms.second).second);
            this->addBuildingToInstanciator(currBuild);
        }
    }
}

//LA FONCTION CI-DESSUS EST INCOMPLETE, LE CONSTRUCTEUR EST MAL APPELE, JE SUIS AU COURANT, IL FAUT DISCUTER DES COMPATIBILITES DE TYPES;

// Constructeur de Building:
// Building(const std::string& name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, BuildingType t, int a, const std::vector<std::string>& chainIn = {}, const std::vector<std::string>& chainOut = {})

void Instanciator::constructWonder(){
    for (std::pair<QString,QString>& noms : this->getNames()) {
        if (noms.first == "Wonder"){
            Wonder currWonder = new Wonder(noms.second.toStdString(),json.getCost(noms.second),json.getWonderEffects(noms.second),json.getDirectCost(noms.second));
            this->addWonderToInstanciator(currWonder);
        }
    }
}

//Constructeur de Wonder:
//Wonder(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)

void Instanciator::constructPT(){
    for (std::pair<QString,QString>& noms : this->getNames()) {
        if (noms.first == "Progress Token"){
            ProgressToken currPT = new ProgressToken(noms.second.toStdString(),json.getCost(noms.second),json.getProgressTokenEffects(noms.second),json.getDirectCost(noms.second));
            this->addPTtoInstanciator(currPT);
        }
    }
}
//Constructeur de ProgressToken:
//ProgressToken(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)

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

std::vector<Building> Instanciator::getCardFromXAge(int age){
    std::vector<Building> Bage;
    for (Building buildings : getBuildings()){
        if (buildings.getAge() == age){
            Bage.insert(Bage.end(),1,buildings);
        }
    }
    if (age < 1 || age > 3){
        qDebug() << "Renvoie d'un vecteur vide, il n'y a pas d'âge" << age << "!";
    }
    return Bage;
}
