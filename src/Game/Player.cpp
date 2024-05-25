#include "Player.h"
#include "City.h"
#include "Game.h"
#include "Card.h"
#include "Wonder.h"
#include "Building.h"
#include <utility>
#include <iostream>

Player::Player(int treasury) : city(*new City(treasury)), isAI(false), aiLevel(AiLevel::NONE), name("Player"){
    std::cout << "Player created" << std::endl;
}

Player::~Player(){
    delete &city;
    std::cout << "Player destroyed" << std::endl;
}

int Player::getShields() const{
    return city.getShields();
};

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
void Player::addWonderToCity(Wonder* wonder) {
    city.addWonder(wonder);
}


void Player::chooseWonder(std::vector<Wonder*>& availableWonders) {
    if (!availableWonders.empty()) {
        // Check if the player is AI
        if (isAIPlayer()) {
            // Randomly pick a wonder from the available wonders
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, availableWonders.size() - 1);
            int index = dis(gen);

            // Take the randomly chosen wonder
            Wonder* chosenWonder = availableWonders[index];
            availableWonders.erase(availableWonders.begin() + index);

            std::cout << getName() << " (AI) chose " << chosenWonder->getName() << std::endl;

            // Add the chosen wonder to the player's wonders
            addWonderToCity(chosenWonder);
        } else {
            // Human player
            std::cout << getName() << ", choose a wonder from the following options:" << std::endl;
            for (int i = 0; i < availableWonders.size(); ++i) {
                std::cout << i + 1 << ". " << availableWonders[i]->getName() << std::endl;
            }

            // Ask the player to choose a wonder
            int choice;
            do {
                std::cout << "Enter the number corresponding to your choice: ";
                choice = getIntInput();
            } while (choice < 1 || choice > availableWonders.size());

            // Take the chosen wonder
            Wonder* chosenWonder = availableWonders[choice - 1];
            availableWonders.erase(availableWonders.begin() + choice - 1);

            std::cout << getName() << " chose " << chosenWonder->getName() << std::endl;

            // Add the chosen wonder to the player's wonders
            addWonderToCity(chosenWonder);

        }
    }
}
