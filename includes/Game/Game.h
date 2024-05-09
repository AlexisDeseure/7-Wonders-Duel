#ifndef GAME_H
#define GAME_H

class Board;
class City;

class Game{
    private:
        int age;
        Board* board;
        City* player_1;
        City* player_2;

    public:
        Game();
        void advanceAge(){ age++; };
        void startGame();
};

#endif
