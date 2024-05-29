#include "EarnVictoryPointPerThingMostAtEndGame.h"
#include "Building.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

#include <algorithm>

void EarnVictoryPointPerThingMostAtEndGame::effect(Game& game) {
    game.getTurnPlayer().getCity().addEndGameEffects(this);
}

void EarnVictoryPointPerThingMostAtEndGame::endEffect(Game& game) {
    City& current = game.getTurnPlayer().getCity();
    City& other = game.getOtherPlayer().getCity();
    int max = std::max(processTotalNumberForCity(current), processTotalNumberForCity(other));
    current.addVictoryPoints(max*number);
}

int EarnVictoryPointPerThingMostAtEndGame::processTotalNumberForCity(City& city){
    int total = 0;
    for (auto& type : types){
        total += city.getNumberOfBuildingType(type);
    }
    return total;
}

void EarnVictoryPointPerThingMostAtEndGame::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    number = int_parameters[0];
    for (auto& type : string_parameters){
        types.push_back(StringToBuildingType(type));
    }
}

void EarnVictoryPointPerThingMostAtEndGame::print() {
    std::cout << "Gagner " << number << " points de victoire par building de couleur ";
    for(auto& type : types){
        if (type != types[0]){
            std::cout << " ou ";
        }
        std::cout << buildingTypeToString(type);
    }
    std::cout<<" construit(s)" << std::endl;
}