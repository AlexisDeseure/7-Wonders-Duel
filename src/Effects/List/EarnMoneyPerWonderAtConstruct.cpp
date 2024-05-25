#include "EarnMoneyPerWonderAtConstruct.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

void EarnMoneyPerWonderAtConstruct::effect(Game& game) {
    City& city = game.getTurnPlayer().getCity();
    int total = money * city.getWonders().size();
    city.addMoney(total);
}

void EarnMoneyPerWonderAtConstruct::setParameters(std::vector<int> int_parameters, [[maybe_unused]] std::vector<std::string> string_parameters) {
    money = int_parameters[0];
}
