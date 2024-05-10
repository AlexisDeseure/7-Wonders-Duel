#ifndef GAME_H
#define GAME_H

#include <iostream>

class Board;
class Player;

class Game{
    private:
        int age;
        Board& board;
        Player* players[2];

    public:

        void advanceAge(){ age++; };
        void startGame();
        void startMenu();
        void endGame();
        void invertTurnPlayer();
        Player& getTurnPlayer() const { return *players[0]; };
        Player& getOtherPlayer() const { return *players[1]; };

        Game();
        ~Game();
};

#endif
