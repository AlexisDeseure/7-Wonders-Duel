#include "Instanciator.h"
#include "Game.h"
#include "Ressource.h"
#include "RessourceCost.h"
#include "EffectFactory.h"
#include "IncludeEffects.h"
#include "Building.h"
#include "Wonder.h"
#include "Card.h"
#include "ProgressToken.h"

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

Instanciator::~Instanciator(){
    for(auto & it : buildings_instanciator){
        delete it;
    }
    for(auto & it : wonders_instanciator){
        delete it;
    }
    for(auto & it : progress_tokens_instanciator){
        delete it;
    }
    delete cards_file;
    delete buildings_layout;
}
void Instanciator::constructBuilding(){
    for (std::pair<QString,QString>& noms : getNames()) {
        if (noms.first == "Building"){
            QString image = QString::fromStdString(game_parameters.getCardsImagePath())+"/"+cards_file->getImage(noms.second);
            Building* currBuild = new Building(noms.second.toStdString(),image,cards_file->getCost(noms.second), effTransToEffect(cards_file->getBuildingEffects(noms.second)), cards_file->getDirectCost(noms.second), StringToBuildingType(cards_file->getColor(noms.second).toStdString()), cards_file->getAge(noms.second), {cards_file->getChaining(noms.second).second.toStdString()}, {cards_file->getChaining(noms.second).first.toStdString()});
            addBuildingToInstanciator(currBuild);
        }
    }
}


// Constructeur de Building:
// Building(const std::string& name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, BuildingType t, int a, const std::vector<std::string>& chainIn = {}, const std::vector<std::string>& chainOut = {})

void Instanciator::constructWonder(){
    for (std::pair<QString,QString>& noms : getNames()) {
        if (noms.first == "Wonder"){
            QString image = QString::fromStdString(game_parameters.getCardsImagePath())+"/"+cards_file->getImage(noms.second);
            Wonder* currWonder = new Wonder(noms.second.toStdString(),image,cards_file->getCost(noms.second),effTransToEffect(cards_file->getWonderEffects(noms.second)),cards_file->getDirectCost(noms.second));
            addWonderToInstanciator(currWonder);
        }
    }
}

//Constructeur de Wonder:
//Wonder(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)

void Instanciator::constructPT(){
    for (std::pair<QString,QString>& noms : getNames()) {
        if (noms.first == "Progress Token"){
            QString image = QString::fromStdString(game_parameters.getCardsImagePath())+"/"+cards_file->getImage(noms.second);
            ProgressToken* currPT = new ProgressToken(noms.second.toStdString(),image,{},effTransToEffect(cards_file->getProgressTokenEffects(noms.second)),0);
            addPTtoInstanciator(currPT);
        }
    }
}
//Constructeur de ProgressToken:
//ProgressToken(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)

void Instanciator::addBuildingToInstanciator(Building* building){
    buildings_instanciator.push_back(building);
}

void Instanciator::addPTtoInstanciator(ProgressToken* PT){
    progress_tokens_instanciator.push_back(PT);
}
void Instanciator::addWonderToInstanciator(Wonder* wonder){
    wonders_instanciator.push_back(wonder);
}

std::vector<Building*> Instanciator::getCardFromXAge(int age){
    std::vector<Building*> buildings;
    for (Building* building : getBuildings()){
        if (building->getAge() == age){
            buildings.push_back(building);
        }
    }
    if (age < 1 || age > getInstanciator()->getGameParameters().getNumberAge()){
        qDebug() << "Renvoie d'un vecteur vide, il n'y a pas d'âge" << age << "!";
        return {};
    }
    else if (age == getInstanciator()->getGameParameters().getNumberAge()) {
        std::vector<Building*> guilds;
        std::vector<Building*> classic_buildings;
        for (Building* bats: buildings) {
            if (bats->getType() == BuildingType::Purple) {
                guilds.push_back(bats);
            }
            else {
                classic_buildings.push_back(bats);
            }
        }

        buildings = extractXRandomBuildingsFrom(classic_buildings,classic_buildings.size()-getInstanciator()->getGameParameters().getNumberCardGuilds()).first;
        std::vector<Building*> choseGuilds = extractXRandomBuildingsFrom(guilds,getInstanciator()->getGameParameters().getNumberCardGuilds()).first;
        for (Building* guild:choseGuilds){
            buildings.push_back(guild);
        }
    }
    return buildings;
}

std::pair<std::vector<Building*>,std::vector<Building*>> Instanciator::extractXRandomBuildingsFrom(std::vector<Building*> cartes,unsigned int nb){
    std::vector<Building*> rand_token;
    std::vector<Building*> rand_token_remaining;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cartes.begin(), cartes.end(), rng);

    std::vector<unsigned int> val;

    for (unsigned int i = 0; i<cartes.size();i++){
        if (i<nb) rand_token.push_back(cartes[i]);
        else rand_token_remaining.push_back(cartes[i]);
    }

    return {rand_token,rand_token_remaining};
}

std::pair<std::vector<ProgressToken*>,std::vector<ProgressToken*>> Instanciator::extractXRandomProgressTokensFrom(std::vector<ProgressToken*> cartes,unsigned int nb){
    std::vector<ProgressToken*> rand_token;
    std::vector<ProgressToken*> rand_token_remaining;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cartes.begin(), cartes.end(), rng);

    std::vector<unsigned int> val;

    for (unsigned int i = 0; i<cartes.size();i++){
        if (i<nb) rand_token.push_back(cartes[i]);
        else rand_token_remaining.push_back(cartes[i]);
    }

    return {rand_token,rand_token_remaining};
}

std::vector<Wonder*> Instanciator::extractXRandomWondersFrom(std::vector<Wonder*> cartes, unsigned int nb){
    std::vector<Wonder*> rand_wonders;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cartes.begin(), cartes.end(), rng);

    std::vector<unsigned int> val;

    for (unsigned int i = 0; i<nb;i++){
        rand_wonders.push_back(cartes[i]);
    }

    return rand_wonders;
}
