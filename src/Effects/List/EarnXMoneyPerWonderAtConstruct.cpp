#include "EarnXMoneyPerWonderAtConstruct.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

void EarnXMoneyPerWonderAtConstruct::effect(Game& game) {
    City& city = game.getTurnPlayer().getCity();
    int total = money * city.getWonders().size();
    city.addMoney(total);
}

void EarnXMoneyPerWonderAtConstruct::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    money = int_parameters[0];
}
