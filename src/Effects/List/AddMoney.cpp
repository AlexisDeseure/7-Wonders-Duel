#include "AddMoney.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

void AddMoney::effect(Game& game) {
    game.getTurnPlayer().getCity().addMoney(quantity);
}

void AddMoney::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
}



