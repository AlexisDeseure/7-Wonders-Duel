#include "EarnMoneyPerMostAtConstruct.h"
#include "Building.h"
#include "Game.h"
#include "Player.h"
#include "City.h"


EarnMoneyPerMostAtConstruct::EarnMoneyPerMostAtConstruct() : money(0),  type(BuildingType::LENGTH){};

void EarnMoneyPerMostAtConstruct::effect(Game& game) {
    City& city = game.getTurnPlayer().getCity();
    int number = city.getNumberOfBuildingType(type);
    city.addMoney(number*money);
}

void EarnMoneyPerMostAtConstruct::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    money = int_parameters[0];
    type = StringToBuildingType(string_parameters[0]);
}
