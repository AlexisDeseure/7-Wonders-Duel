#include "../../includes/Game/Game.h"
#include "../../includes/BoardManager/Board.h"
#include "../../includes/Game/Player.h"


Game::Game() : age(0), board(*new Board()){
    age = 0;
    players[0] = new Player();
    players[1] = new Player();

    startMenu();
    std::cout << "Game created" << std::endl;
    startGame();
}

Game::~Game() {
    delete &board;
    delete players[0];
    delete players[1];
    std::cout << "Game finished" << std::endl;
}

void Game::startMenu(){
    std::cout << "Menu started" << std::endl;
}

void Game::startGame(){
    std::cout << "Game started" << std::endl;
}

void Game::invertTurnPlayer(){
    Player &player = getTurnPlayer();
    players[0] = &getOtherPlayer();
    players[1] = &player;
    std::cout << "Turn inverted" << std::endl;
}