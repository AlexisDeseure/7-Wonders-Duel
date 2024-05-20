#include "EarnXVictoryPointPerLotOfMoneyMostAtEndGame.h"

#include "Game.h"
#include "Player.h"
#include "City.h"

#include <algorithm>


void EarnXVictoryPointPerLotOfMoneyMostAtEndGame::effect(Game& game) {
    game.getTurnPlayer().getCity().addEndGameEffects(this);
}

void EarnXVictoryPointPerLotOfMoneyMostAtEndGame::endEffect(Game& game) {
    City& current = game.getTurnPlayer().getCity();
    City& other = game.getOtherPlayer().getCity();
    int max = std::max(current.getTreasury(), other.getTreasury());
    current.addVictoryPoints((max/batch_size)*number);
}

void EarnXVictoryPointPerLotOfMoneyMostAtEndGame::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    number = int_parameters[0];
    batch_size = int_parameters[1];
}
