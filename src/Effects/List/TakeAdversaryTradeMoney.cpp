#include "TakeAdversaryTradeMoney.h"
#include "Game.h"
#include "Player.h"
#include "City.h"
#include "Card.h"

#include <algorithm>

void TakeAdversaryTradeMoney::effect(Game& game) {
    //cet effet et ajouté chez l'adversaire
    game.getOtherPlayer().getCity().addEachTurnEffects(this);
}

void TakeAdversaryTradeMoney::eachTurnEffect(Game& game, Card& card){
    // cet effet est appliqué quand l'adversiare achete une carte et si il a du acheter des ressources, l'argent dépensée est ajouté
    // chez le joueur qui avait eu cet effet
    int money_to_give = std::max(static_cast<unsigned int>(0), card.getCost(&game.getTurnPlayer().getCity()) - card.getMoneyCost());
    game.getOtherPlayer().getCity().addMoney(money_to_give);
}
