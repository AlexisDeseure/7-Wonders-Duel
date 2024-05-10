#include "../../includes/Game/Player.h"
#include "../../includes/City/City.h"

Player::Player(bool ai) : isAI(ai), city(*new City()){
    std::cout << "Player created" << std::endl;
}

Player::~Player(){
    delete &city;
    std::cout << "Player destroyed" << std::endl;
}
