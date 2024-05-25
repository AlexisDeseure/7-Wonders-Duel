#ifndef CONFLICTPAWN_H
#define CONFLICTPAWN_H

class ConflictPawn {
public:
    ConflictPawn();

    void move(int shields);
    int getPosition() const;
    bool isMilitaryVictory() const;

private:
    int position;
    static const int VICTORY_POSITION = 9; // Position to win the game
};

#endif // CONFLICTPAWN_H
