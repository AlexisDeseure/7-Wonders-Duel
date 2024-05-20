#include "EarnXVictoryPointPerMostWonderAtEndGame.h"

#include "Game.h"
#include "Player.h"
#include "City.h"

#include <algorithm>


void EarnXVictoryPointPerMostWonderAtEndGame::effect(Game& game) {
    game.getTurnPlayer().getCity().addEndGameEffects(this);
}

void EarnXVictoryPointPerMostWonderAtEndGame::endEffect(Game& game) {
    City& current = game.getTurnPlayer().getCity();
    City& other = game.getOtherPlayer().getCity();
    int max = std::max(current.getWonders().size(), other.getWonders().size());
    current.addVictoryPoints(max*number);
}

void EarnXVictoryPointPerMostWonderAtEndGame::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    number = int_parameters[0];
}
