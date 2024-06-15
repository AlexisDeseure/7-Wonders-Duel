#include "Player.h"
#include "City.h"
#include "Game.h"
#include "Card.h"
#include "Wonder.h"
#include "Building.h"
#include "DeckElement.h"
#include "MarketDeck.h"
#include "DeckPile.h"
#include "Building.h"
#include "ScientificSymbol.h"
#include "ChooseWondersUI.h"
#include "game_window.h"

#include <QtCore>
#include <QObject>
#include <utility>
#include <iostream>
#include <algorithm>
#include "Board.h"

using namespace std ;
Player::Player(int treasury) : city(*new City(treasury)), isAI(false), aiLevel(AiLevel::NONE), name("Player"){
    // std::cout << "Player created" << std::endl;
}

Player::~Player(){
    delete &city;
    // std::cout << "Player destroyed" << std::endl;
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
    if (max <1){
        return 0;
    }
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
    MarketDeck& marketDeck = game.getBoard().getMarketDeck();
    City& city = getCity();
    std::cout << "Le joueur " << name << " joue ! Le joueur "<<game.getOtherPlayer().getName()<<" est en attente..."<<std::endl;
    std::cout << "Récapitulatif des possessions du joueur : "<<std::endl;
    std::cout << "Money : "<<city.getTreasury()<<std::endl;
    std::cout << "Ressources : "<<std::endl;
    for (auto& r : city.getRessources()){
        r->print();
    }
    std::cout << "Jetons de progrès : "<<std::endl;
    for (auto& r : city.getScientificSymbols()){
        r->print();
    }
    std::cout << "Veuillez selectionner une carte parmi les suivantes : " << std::endl;
    std::vector<DeckElement*>& firstbuildings = marketDeck.getFirstBuildings();

    marketDeck.print();

    int choice = getPlayerChoice(static_cast<int>(firstbuildings.size()));
    Building* building = firstbuildings[choice-1]->getBuilding();

    std::cout << "Vous avez choisi le bâtiment : " << building->getName() << std::endl;

    bool check_choice = false;
    while (!check_choice){
        std::cout << "Veuillez choisir une action parmi : " << std::endl;
        std::cout << "\t1 : Construire le bâtiment "<< std::endl;
        std::cout << "\t2 : Echanger le bâtiment contre des pièces "<< std::endl;
        std::cout << "\t3 : Construire une merveille en utilisant ce bâtiment"<< std::endl;
        int action = getPlayerChoice(3);

        if(action == 1) {
            check_choice = city.constructBuilding(building,game);
            if (check_choice){
                city.applyEachTurnEffects(game, *building);
                marketDeck.getBuilding(choice - 1);
                cout<< "Bâtiment construit" << endl;
            }
        }
        else if(action == 2) {
            city.discardBuilding(building,game);
            marketDeck.getBuilding(choice - 1) ;
            cout << "Bâtiment détruit" << endl;
            check_choice = true;
        }
        else{
            std::cout << "Choisissez une merveille à construire : " << std::endl;
            std::vector<Wonder*>& Wonders = getCity().getWonders();
            int i = 1;
            for (auto& wonder : Wonders){
                std::cout << i << " : " << std::endl;
                wonder->print();
                i++;
            }
            int wonder_choice = getPlayerChoice(static_cast<int>(Wonders.size()));
            std::cout << "Vous avez sélectionné : "<<Wonders[wonder_choice-1]->getName()<<std::endl;
            check_choice = city.constructWonder(Wonders[wonder_choice-1],game);
            if (check_choice){
                city.applyEachTurnEffects(game, *Wonders[wonder_choice-1]);
                marketDeck.getBuilding(choice - 1);
                game.getDeck().addDiscardedBuilding(building);
                cout<< "Merveille construite" << endl;
            }
        }
    }
}

void Player::playUi(Game& game, GameWindow* fenetre){
    fenetre->refreshAll();
    MarketDeck& marketDeck = game.getBoard().getMarketDeck();
    City& city = getCity();
    std::vector<DeckElement*>& firstbuildings = marketDeck.getFirstBuildings();
    std::cout << "Le joueur " << name << " joue ! Le joueur "<<game.getOtherPlayer().getName()<<" est en attente..."<<std::endl;
    std::cout << "Money : "<<city.getTreasury()<<std::endl;

    //int choice = getPlayerChoice(static_cast<int>(firstbuildings.size()));

    QEventLoop loopWonder;

    // CardWidget::connect(fenetre, SIGNAL(acheterPressed()), &loopWonder, SLOT(quit()));

    loopWonder.exec();
    // Building* building = firstbuildings[choice-1]->getBuilding();
    qDebug()<<"fdssd";
    // std::cout << "Vous avez choisi le bâtiment : " << building->getName() << std::endl;

    // bool check_choice = false;
    // while (!check_choice){
    //     std::cout << "Veuillez choisir une action parmi : " << std::endl;
    //     std::cout << "\t1 : Construire le bâtiment "<< std::endl;
    //     std::cout << "\t2 : Echanger le bâtiment contre des pièces "<< std::endl;
    //     std::cout << "\t3 : Construire une merveille en utilisant ce bâtiment"<< std::endl;
    //     int action = getPlayerChoice(3);

    //     if(action == 1) {
    //         check_choice = city.constructBuilding(building,game);
    //         if (check_choice){
    //             city.applyEachTurnEffects(game, *building);
    //             marketDeck.getBuilding(choice - 1);
    //             cout<< "Bâtiment construit" << endl;
    //         }
    //     }
    //     else if(action == 2) {
    //         city.discardBuilding(building,game);
    //         marketDeck.getBuilding(choice - 1) ;
    //         cout << "Bâtiment détruit" << endl;
    //         check_choice = true;
    //     }
    //     else{
    //         std::cout << "Choisissez une merveille à construire : " << std::endl;
    //         std::vector<Wonder*>& Wonders = getCity().getWonders();
    //         int i = 1;
    //         for (auto& wonder : Wonders){
    //             std::cout << i << " : " << std::endl;
    //             wonder->print();
    //             i++;
    //         }
    //         int wonder_choice = getPlayerChoice(static_cast<int>(Wonders.size()));
    //         std::cout << "Vous avez sélectionné : "<<Wonders[wonder_choice-1]->getName()<<std::endl;
    //         check_choice = city.constructWonder(Wonders[wonder_choice-1],game);
    //         if (check_choice){
    //             city.applyEachTurnEffects(game, *Wonders[wonder_choice-1]);
    //             marketDeck.getBuilding(choice - 1);
    //             game.getDeck().addDiscardedBuilding(building);
    //             cout<< "Merveille construite" << endl;
    //         }
    //     }
    // }
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
        int choice;
        if (availableWonders.size()!=1){
            std::cout << getName() << ", choisir une merveille parmi les suivantes :" << std::endl;
            for (size_t i = 0; i < availableWonders.size(); ++i) {
                std::cout <<"\t"<< i + 1 << " : " << availableWonders[i]->getName() << std::endl;
            }

            choice = getPlayerChoice(static_cast<int>(availableWonders.size()));
        }
        else choice = 1;
        Wonder* chosenWonder = availableWonders[choice - 1];
        availableWonders.erase(availableWonders.begin() + choice - 1);

        std::cout << getName() << " a choisi " << chosenWonder->getName() << std::endl;

        addWonderToCity(chosenWonder);

    }
}
void Player::handleSelectionWonderDone(Wonder* wonder){
    intermediateWonder = wonder;
}
void Player::chooseWonderUi(std::vector<Wonder*>& availableWonders, ChooseWonderStart* fenetre) {
    if (!availableWonders.empty()) {
        int* choice = new int(1);
        fenetre->setCurrentPlayerLabel(QString::fromStdString(getName())+" choisis une merveille");
        if (isAI){
            *choice = selectRandomInteger(1,static_cast<int>(availableWonders.size()));
            Wonder* wonder = availableWonders[*choice - 1];
            emit destroyWondersAi(wonder);
        }
        else {
            QEventLoop loopWonder;
            ChooseWonderStart::connect(fenetre, SIGNAL(selectionDone(Wonder*)), this, SLOT(handleSelectionWonderDone(Wonder*)));
            ChooseWonderStart::connect(fenetre, SIGNAL(selectionDone(Wonder*)), &loopWonder, SLOT(quit()));
            loopWonder.exec();
            auto it = std::find(availableWonders.begin(), availableWonders.end(), intermediateWonder);
            if (it != availableWonders.end()) {
                // Calculer l'indice
                *choice = std::distance(availableWonders.begin(), it)+1;
                std::cout << "Indice de la wonder: " << *choice << std::endl;
            } else {
                std::cout << "Le pointeur de availableWonders n'a pas été trouvé dans le vecteur." << std::endl;
            }
        }
        Wonder* chosenWonder = availableWonders[*choice - 1];
        availableWonders.erase(availableWonders.begin() + *choice - 1);

        delete choice;


        addWonderToCity(chosenWonder);

    }
}
