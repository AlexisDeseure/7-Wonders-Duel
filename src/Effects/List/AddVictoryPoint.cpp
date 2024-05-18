#include "AddVictoryPoint.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

void AddVictoryPoint::effect(Game& game) {
    game.getTurnPlayer().getCity().addVictoryPoints(quantity);
}

void AddVictoryPoint::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
}
