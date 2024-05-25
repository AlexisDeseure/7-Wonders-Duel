#ifndef CONFLICTPAWN_H
#define CONFLICTPAWN_H

class Player;

class ConflictPawn {
public:
    ConflictPawn(int victory_position);

    void move(int shields);
    int getPosition() const;
    bool isMilitaryVictory() const;

private:
    int position;
    const int victory_position = 9; // Position to win the game
};

#endif // CONFLICTPAWN_H
