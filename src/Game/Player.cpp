#include <utility>

#include "../../includes/Game/Player.h"
#include "../../includes/City/City.h"

Player::Player(bool ai, AiLevel level, std::string name) : isAI(ai), city(*new City()), aiLevel(level), name(std::move(name)){
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