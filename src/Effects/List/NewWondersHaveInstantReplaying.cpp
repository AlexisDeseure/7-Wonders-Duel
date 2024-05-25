#include "NewWondersHaveInstantReplaying.h"
#include "Game.h"
#include "Player.h"
#include "City.h"
#include "Card.h"

void NewWondersHaveInstantReplaying::effect(Game& game) {
    game.getTurnPlayer().getCity().addEachTurnEffects(this);
}

void NewWondersHaveInstantReplaying::eachTurnEffect(Game& game, [[maybe_unused]] Card& card){
    game.replay();
}
