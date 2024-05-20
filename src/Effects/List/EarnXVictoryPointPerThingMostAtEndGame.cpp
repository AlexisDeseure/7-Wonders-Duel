#include "EarnXVictoryPointPerThingMostAtEndGame.h"
#include "Building.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

#include <algorithm>

void EarnXVictoryPointPerThingMostAtEndGame::effect(Game& game) {
    game.getTurnPlayer().getCity().addEndGameEffects(this);
}

void EarnXVictoryPointPerThingMostAtEndGame::endEffect(Game& game) {
    City& current = game.getTurnPlayer().getCity();
    City& other = game.getOtherPlayer().getCity();
    int max = std::max(processTotalNumberForCity(current), processTotalNumberForCity(other));
    current.addVictoryPoints(max*number);
}

int EarnXVictoryPointPerThingMostAtEndGame::processTotalNumberForCity(City& city){
    int total = 0;
    for (auto& type : types){
        total += city.getNumberOfBuildingType(type);
    }
    return total;
}

void EarnXVictoryPointPerThingMostAtEndGame::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    number = int_parameters[0];
    for (auto& type : string_parameters){
        types.push_back(StringToBuildingType(type));
    }
}
