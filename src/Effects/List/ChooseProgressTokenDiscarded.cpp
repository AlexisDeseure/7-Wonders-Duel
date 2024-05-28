#include "ChooseProgressTokenDiscarded.h"
#include "Game.h"
#include "Player.h"
#include "City.h"
#include "ProgressToken.h"
#include "Board.h"

void ChooseProgressTokenDiscarded::effect(Game& game) {
    Player& player = game.getTurnPlayer();
    City& city = player.getCity();
    ProgressToken* progress_token = game.getBoard().getProgressToken(game,player, true, 3);
    city.addProgressToken(progress_token, game);
}

