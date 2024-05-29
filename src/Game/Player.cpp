#include "Player.h"
#include "City.h"
#include "Game.h"
#include "Card.h"
#include "Wonder.h"
#include "Building.h"
#include <utility>
#include <iostream>
#include "Board.h"

using namespace std ;
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

int Player::getScore(Game& game) const{
    city.applyEndEffects(game); //appliquer les effets de fin de partie (ex: les points de victoire des cartes guildes
    int score = city.getTreasury()/3; // 1 pts pour 3 pièces
    score += city.getVictoryPoints();
    return score;
};

int Player::getPlayerChoice(int max){
    int choice;
    bool first_try = true;
    if (isAI){
        choice = selectRandomInteger(1, max);
    }
    else{
        do {
            if (first_try) first_try = false;
            else std::cout << "Choix invalide, réessayer." << std::endl;
            std::cout << name << ", entrez un nombre entre 1 et " << max << " :";
            choice = getIntInput();
        } while (choice < 1 || choice > max);
    }

    return choice;
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
    std::cout << "Le joueur " << name << " joue ! Le joueur "<<game.getOtherPlayer().getName()<<" est en attente..."<<std::endl;

    std::cout << "Veuillez selectionner une carte parmis les suivantes : " << std::endl;
    std::vector<DeckElement*> firstbuildings = game.getBoard().getMarketDeck().getFirstBuildings();
    int i = 1 ;
    for (DeckElement* element : firstbuildings) {
        cout<< i << " ";
        element->getBuilding()->print();
        i++;
    }

    int choix = getPlayerChoice(static_cast<int>(firstbuildings.size()));
    std::cout << "Veuillez choisir une action parmis : " << std::endl;
    std::cout << "\t1 : Construct Building "<< std::endl;
    std::cout << "\t2 : Discard Building "<< std::endl;
    int action = getPlayerChoice(2);

    if(action == 1) {
        getCity().constructBuilding(firstbuildings[choix-1]->getBuilding(),game);
        cout<< "Building construit" ;
    }
    else {
        getCity().discardBuilding(firstbuildings[choix-1]->getBuilding(),game);
        cout << "building détruit";
    }

    // Choisir une action
    //Construct builing
    //DISCARD BUILDING

    //TODO utiliser buyCard pour le choix de construction de wonders et de card + implémenter le discard card

}

// const DeckElement* Player::selectCard(Game& game, MarketDeck& marketDeck){ //permet au joueur de sélectionner une carte à jouer
//     const DeckElement** building_list = marketDeck.getFirstBuildings();
//     for(size_t i = 0; i<(sizeof(DeckElement)/sizeof(building_list));i++){
//         if (building_list[i]->isVisible()){
//             std::cout<<"Building "<<"n°"<<i<<"\n";
//         }
//     }
//     std::cout<<"Select a card: ";
//     int select = getIntInput();
//     return building_list[select];
// }

// bool Player::buyCard(Game& game, Card& card,MarketDeck& marketDeck){
//     if (city.canAfford(card.getCost(&city))){
//         city.applyEachTurnEffects(game, card);
//         card.applyEffects(game);
//         if (dynamic_cast<Wonder*>(&card)){ //card is a wonder, il faut choisir un building à défausser pour construire le wonder
//             const DeckElement* discarded_card = Player::selectCard(game,marketDeck); //on choisit une des cartes parmi les premières du deck
//             //MarketDeck::iterator it = begin() //tentative avec un itérateur mais ne marche pas :/
//             //marketDeck.getBuilding(marketDeck);
//             if(discarded_card->isVisible()){
//                 discarded_card->DeckElement::deleteDeckFromMarket(); //suppression "manuelle" pour le moment, il faut remplacer le premier élément dans le deck
//             }
//         }


//         city.addCard(card);
//         return true;
//     }
//     return false;
// }
void Player::addWonderToCity(Wonder* wonder) {
    city.addWonder(wonder);

}



void Player::chooseWonder(std::vector<Wonder*>& availableWonders) {
    if (!availableWonders.empty()) {
        
        // Human player
        std::cout << getName() << ", choisir une merveille parmi les suivantes :" << std::endl;
        for (size_t i = 0; i < availableWonders.size(); ++i) {
            std::cout <<"\t"<< i + 1 << " : " << availableWonders[i]->getName() << std::endl;
        }

        // Ask the player to choose a wonder
        int choice = getPlayerChoice(static_cast<int>(availableWonders.size()));

        // Take the chosen wonder
        Wonder* chosenWonder = availableWonders[choice - 1];
        availableWonders.erase(availableWonders.begin() + choice - 1);

        std::cout << getName() << " a choisi " << chosenWonder->getName() << std::endl;

        // Add the chosen wonder to the player's wonders
        addWonderToCity(chosenWonder);

    }
}
