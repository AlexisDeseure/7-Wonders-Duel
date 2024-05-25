#include "ConflictPawn.h"

ConflictPawn::ConflictPawn() : position(0) {}

void ConflictPawn::move(int shields) {
    position += shields;
    if (position > VICTORY_POSITION) {
        position = VICTORY_POSITION;
    } else if (position < -VICTORY_POSITION) {
        position = -VICTORY_POSITION;
    }
}

int ConflictPawn::getPosition() const {
    return position;
}

bool ConflictPawn::isMilitaryVictory() const {
    return position == VICTORY_POSITION || position == -VICTORY_POSITION;
}















