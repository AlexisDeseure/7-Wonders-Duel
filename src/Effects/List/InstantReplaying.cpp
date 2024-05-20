#include "InstantReplaying.h"
#include "Game.h"

void InstantReplaying::effect(Game& game) {
    game.replay();
}
