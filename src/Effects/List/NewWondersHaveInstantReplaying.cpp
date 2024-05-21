#include "NewWondersHaveInstantReplaying.h"
#include "Game.h"
#include "Player.h"
#include "City.h"
#include "Card.h"

void NewWondersHaveInstantReplaying::effect(Game& game) {
    game.getTurnPlayer().getCity().addEachTurnEffects(this);
}

void NewWondersHaveInstantReplaying::eachTurnEffect(Game& game, Card& card){
    game.replay();
}
