#include "EarnVictoryPointsPerProgressTokenAtEndGame.h"

#include "Game.h"
#include "Player.h"
#include "City.h"

#include <algorithm>

void EarnVictoryPointsPerProgressTokenAtEndGame::effect(Game& game) {
    game.getTurnPlayer().getCity().addEndGameEffects(this);
}

void EarnVictoryPointsPerProgressTokenAtEndGame::endEffect(Game& game) {
    City& current = game.getTurnPlayer().getCity();
    City& other = game.getOtherPlayer().getCity();
    int max = std::max(current.getProgressTokens().size(), other.getProgressTokens().size());
    current.addVictoryPoints(max*number);
}

void EarnVictoryPointsPerProgressTokenAtEndGame::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    number = int_parameters[0];
}
