#include "MoveConflictPawn.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

void MoveConflictPawn::effect(Game& game) {
    game.getTurnPlayer().getCity().addShields(amount);
}

void MoveConflictPawn::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    amount = int_parameters[0];
}

