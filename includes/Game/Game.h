#ifndef GAME_H
#define GAME_H
#include <iostream>

class Board;
class City;

class Game{
    private:
        int age;
        Board* board;
        City* player_1;
        City* player_2;

    public:
        Game(){
            age = 0;
            std::cout << "Game created" << std::endl;
        };
        void advanceAge(){ age++; };
        void startGame();
};

#endif
