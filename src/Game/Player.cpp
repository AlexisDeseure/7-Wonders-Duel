#include "Player.h"
#include "City.h"
#include "Game.h"

#include <utility>
#include <iostream>

Player::Player(bool ai, AiLevel level, std::string name) : city(*new City()), isAI(ai), aiLevel(level), name(std::move(name)){
    std::cout << "Player created" << std::endl;
}

Player::~Player(){
    delete &city;
    std::cout << "Player destroyed" << std::endl;
}

std::string AiLeveltoString(AiLevel level){
    std::string str;
    switch (level) {
        case AiLevel::EASY:
            str = "EASY";
            break;
        case AiLevel::MEDIUM:
            str =  "MEDIUM";
            break;
        case AiLevel::HARD:
            str = "HARD";
            break;
        default:
            str = "NONE";
            break;
    };
    return str;
}

void Player::play(Game& game){
    std::cout << "joueur " << name << " joue ! Le joueur "<<game.getOtherPlayer().getName()<<" est en attente..."<<std::endl;
}
