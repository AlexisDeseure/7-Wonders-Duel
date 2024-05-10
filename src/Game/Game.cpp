#include "../../includes/Game/Game.h"
#include "../../includes/BoardManager/Board.h"
#include "../../includes/City/City.h"


Game::Game(){
    age = 0;
    std::cout << "Game created" << std::endl;
}

void Game::startGame(){
    board = new Board();
    player_1 = new City();
    player_2 = new City();
    std::cout << "Game started" << std::endl;
}