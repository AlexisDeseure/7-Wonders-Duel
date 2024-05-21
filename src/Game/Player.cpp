#include "Player.h"
#include "City.h"
#include "Game.h"
#include "Card.h"
#include "Wonder.h"
#include "Building.h"
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
    //TODO utiliser buyCard pour le choix de construction de wonders et de card + implémenter le discard card
}

bool Player::buyCard(Game& game, Card& card){
    if (city.canAfford(card.getCost(&city))){
        city.applyEachTurnEffects(game, card);
        card.applyEffects(game);
        city.addCard(card);
        return true;
    }
    return false;
}
