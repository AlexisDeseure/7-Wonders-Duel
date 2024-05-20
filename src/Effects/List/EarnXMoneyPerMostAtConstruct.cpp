#include "EarnXMoneyPerMostAtConstruct.h"
#include "Building.h"
#include "Game.h"
#include "Player.h"
#include "City.h"


EarnXMoneyPerMostAtConstruct::EarnXMoneyPerMostAtConstruct() : money(0),  type(BuildingType::LENGTH){};

void EarnXMoneyPerMostAtConstruct::effect(Game& game) {
    City& city = game.getTurnPlayer().getCity();
    int number = city.getNumberOfBuildingType(type);
    city.addMoney(number*money);
}

void EarnXMoneyPerMostAtConstruct::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    money = int_parameters[0];
    type = StringToBuildingType(string_parameters[0]);
}
