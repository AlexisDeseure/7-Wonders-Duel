#include "ConflictPawn.h"
#include "Player.h"

ConflictPawn::ConflictPawn(int victory_position) : position(0), victory_position(victory_position) {}

void ConflictPawn::move(int shields) {
    position = shields;
    if (position >= victory_position) {
        position = victory_position;
    } else if (position <= -victory_position) {
        position = -victory_position;
    }
}

int ConflictPawn::getPosition() const {
    return position;
}

bool ConflictPawn::isMilitaryVictory() const {
    return position == victory_position || position == -victory_position;
}














