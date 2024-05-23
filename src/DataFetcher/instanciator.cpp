#include "Instanciator.h"

Instanciator *Instanciator::instance = nullptr;

std::vector<Effect*> Instanciator::effTransToEffect(std::vector<File::EffectTransfer> vecTransfer){
    std::vector<Effect*> effets;
    for (File::EffectTransfer transfer:vecTransfer){
        Effect* currEffect = EffectFactory::instance().create(transfer.getEffect().toStdString());
        currEffect->setParameters(transfer.getAmount(),transfer.getResType());
        effets.insert(effets.end(),1,currEffect);
    }
    return effets;
}

// virtual void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) = 0;

// Exemple d'instanciation d'une classe à partir de son nom :
// Effect* effect = EffectFactory::instance().create("AddMoney");


void Instanciator::constructBuilding(){
    for (std::pair<QString,QString>& noms : getNames()) {
        if (noms.first == "Building"){
            Building currBuild = Building(noms.second.toStdString(),json.getCost(noms.second), effTransToEffect(json.getBuildingEffects(noms.second)), json.getDirectCost(noms.second), StringToBuildingType(json.getColor(noms.second).toStdString()), json.getAge(noms.second), {json.getChaining(noms.second).first.toStdString()}, {json.getChaining(noms.second).second.toStdString()});
            addBuildingToInstanciator(currBuild);
        }
    }
}


// Constructeur de Building:
// Building(const std::string& name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, BuildingType t, int a, const std::vector<std::string>& chainIn = {}, const std::vector<std::string>& chainOut = {})

void Instanciator::constructWonder(){
    for (std::pair<QString,QString>& noms : getNames()) {
        if (noms.first == "Wonder"){
            Wonder currWonder = Wonder(noms.second.toStdString(),json.getCost(noms.second),effTransToEffect(json.getWonderEffects(noms.second)),json.getDirectCost(noms.second));
            addWonderToInstanciator(currWonder);
        }
    }
}

//Constructeur de Wonder:
//Wonder(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)

void Instanciator::constructPT(){
    for (std::pair<QString,QString>& noms : getNames()) {
        if (noms.first == "Progress Token"){
            ProgressToken currPT = ProgressToken(noms.second.toStdString(),json.getCost(noms.second),effTransToEffect(json.getProgressTokenEffects(noms.second)),json.getDirectCost(noms.second));
            addPTtoInstanciator(currPT);
        }
    }
}
//Constructeur de ProgressToken:
//ProgressToken(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)

void Instanciator::addBuildingToInstanciator(Building building){
    getBuildings().insert(getBuildings().end(),1,building);
}

void Instanciator::addPTtoInstanciator(ProgressToken PT){
    getPTInstanciator().insert(getPTInstanciator().end(),1,PT);
}
void Instanciator::addWonderToInstanciator(Wonder wonder){
    getWonders().insert(getWonders().end(),1,wonder);
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

std::vector<Building> Instanciator::extractXRandomBuildingsFrom(std::vector<Building> cartes,unsigned int X){
    std::vector<Building> randRes;
    srand((unsigned int)time(0));
    std::vector<unsigned int> val;
    for (unsigned int i = 0; i<cartes.size()-X; i++){
        unsigned int currVal = rand()%cartes.size()+1;
        if (find(val.begin(),val.end(),currVal) != val.end()) {
            val.push_back(currVal);
        }
        else i--;
    }
    for (unsigned int i = 0; i<cartes.size();i++){
        if (find(val.begin(),val.end(),i)!=val.end()){
            randRes.push_back(cartes[i]);
        }
    }
    return randRes;
}

std::vector<ProgressToken> Instanciator::extractXRandomProgressTokensFrom(std::vector<ProgressToken> cartes,unsigned int X){
    std::vector<ProgressToken> randRes;
    srand((unsigned int)time(0));
    std::vector<unsigned int> val;
    for (unsigned int i = 0; i<cartes.size()-X; i++){
        unsigned int currVal = rand()%cartes.size()+1;
        if (find(val.begin(),val.end(),currVal) !=val.end()) {
            val.push_back(currVal);
        }
        else i--;
    }
    for (unsigned int i = 0; i<cartes.size();i++){
        if (find(val.begin(),val.end(),i)!=val.end()){
            randRes.push_back(cartes[i]);
        }
    }
    return randRes;
}

std::vector<Wonder> Instanciator::extractXRandomWondersFrom(std::vector<Wonder> cartes,unsigned int X){
    std::vector<Wonder> randRes;
    srand((unsigned int)time(0));
    std::vector<unsigned int> val;
    for (unsigned int i = 0; i<cartes.size()-X; i++){
        unsigned int currVal = rand()%cartes.size()+1;
        if (find(val.begin(),val.end(),currVal) !=val.end()) {
            val.push_back(currVal);
        }
        else i--;
    }
    for (unsigned int i = 0; i<cartes.size();i++){
        if (find(val.begin(),val.end(),i)!=val.end()){
            randRes.push_back(cartes[i]);
        }
    }
    return randRes;
}
