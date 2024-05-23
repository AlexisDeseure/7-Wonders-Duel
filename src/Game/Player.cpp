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

const DeckElement* Player::selectCard(Game& game, MarketDeck& marketDeck){ //permet au joueur de sélectionner une carte à jouer
    const DeckElement** building_list = marketDeck.getFirstBuildings();
    for(size_t i = 0; i<(sizeof(DeckElement)/sizeof(building_list));i++){
        if (building_list[i]->isVisible()){
            std::cout<<"Building "<<"n°"<<i<<"\n";
        }
    }
    std::cout<<"Select a card: ";
    int select = getIntInput();
    return building_list[select];
}

bool Player::buyCard(Game& game, Card& card,MarketDeck& marketDeck){
    if (city.canAfford(card.getCost(&city))){
        city.applyEachTurnEffects(game, card);
        card.applyEffects(game);
        if (dynamic_cast<Wonder*>(&card)){ //card is a wonder, il faut choisir un building à défausser pour construire le wonder
            const DeckElement* discarded_card = Player::selectCard(game,marketDeck); //on choisit une des cartes parmi les premières du deck
            //MarketDeck::iterator it = begin() //tentative avec un itérateur mais ne marche pas :/
            //marketDeck.getBuilding(marketDeck);
            if(discarded_card->isVisible()){
                discarded_card->DeckElement::deleteDeckFromMarket(); //suppression "manuelle" pour le moment, il faut remplacer le premier élément dans le deck
            }
        }


        city.addCard(card);
        return true;
    }
    return false;
}
