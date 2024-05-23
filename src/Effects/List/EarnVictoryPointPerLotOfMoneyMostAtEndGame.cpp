#include "EarnVictoryPointPerLotOfMoneyMostAtEndGame.h"

#include "Game.h"
#include "Player.h"
#include "City.h"

#include <algorithm>


void EarnVictoryPointPerLotOfMoneyMostAtEndGame::effect(Game& game) {
    game.getTurnPlayer().getCity().addEndGameEffects(this);
}

void EarnVictoryPointPerLotOfMoneyMostAtEndGame::endEffect(Game& game) {
    City& current = game.getTurnPlayer().getCity();
    City& other = game.getOtherPlayer().getCity();
    int max = std::max(current.getTreasury(), other.getTreasury());
    current.addVictoryPoints((max/batch_size)*number);
}

void EarnVictoryPointPerLotOfMoneyMostAtEndGame::setParameters(std::vector<int> int_parameters, [[maybe_unused]] std::vector<std::string> string_parameters) {
    number = int_parameters[0];
    batch_size = int_parameters[1];
}
