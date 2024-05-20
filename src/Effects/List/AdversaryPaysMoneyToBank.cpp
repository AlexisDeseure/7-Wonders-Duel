#include "AdversaryPaysMoneyToBank.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

void AdversaryPaysMoneyToBank::effect(Game& game) {
    game.getOtherPlayer().getCity().addMoney(-1*quantity);
}

void AdversaryPaysMoneyToBank::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
}
