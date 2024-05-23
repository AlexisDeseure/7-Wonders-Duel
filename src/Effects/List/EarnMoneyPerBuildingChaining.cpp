#include "EarnMoneyPerBuildingChaining.h"
#include "Game.h"
#include "Player.h"
#include "City.h"
#include "Card.h"

void EarnMoneyPerBuildingChaining::effect(Game& game) {
    game.getTurnPlayer().getCity().addEachTurnEffects(this);
}

void EarnMoneyPerBuildingChaining::setParameters(std::vector<int> int_parameters, [[maybe_unused]] std::vector<std::string> string_parameters) {
    money = int_parameters[0];
}

void EarnMoneyPerBuildingChaining::eachTurnEffect(Game& game, Card& card){
    City& city = game.getTurnPlayer().getCity();
    if (card.isChainInInCity(&city)){
       city.addMoney(money);
    }
}
