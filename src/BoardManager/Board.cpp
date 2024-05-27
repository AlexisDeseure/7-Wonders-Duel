#include "Board.h"
#include "ConflictPawn.h"
#include "MarketDeck.h"
#include "ProgressToken.h"
#include "Instanciator.h"
#include "GameParameters.h"
#include "Player.h"
#include "City.h"
#include <vector>
#include <iostream>

Board::Board(int victory_position) : constructed_wonders(0), conflict_pawn(*new ConflictPawn(victory_position)),
    market_deck(*new MarketDeck()){
    Instanciator* instanciator = Instanciator::getInstanciator();
    progressToken = instanciator->extractXRandomProgressTokensFrom(instanciator->getPTInstanciator(), instanciator->getGameParameters().getNumberProgressTokenBoard());
    std::cout << "Board created" << std::endl;
}

bool Board::deckIsEmpty() const{
    return market_deck.isEmpty();
}

ProgressToken* Board::getProgressToken(Player& player) const{
    if (progressToken.first.size() > 0){
        std::cout << player.getName() <<", choisi un jeton de progrès parmi la liste (valeur par défaut = 1):" << std::endl;
        int i = 1;
        for (auto progress_token : progressToken.first){
            std::cout << i << " : " << progress_token->getName() << std::endl;
        }
        int choice = getIntInput();
        if (choice < 1 || static_cast<size_t>(choice) > progressToken.first.size()){
            std::cout << "Choix invalide, choix par défaut" << std::endl;
            choice = 1;
        }
        
        ProgressToken* selected = progressToken.first[choice-1];
        const_cast<std::vector<ProgressToken*> &>(progressToken.first).erase(progressToken.first.begin() + choice-1);
        return selected;
    }
    else{
        std::cout << "Il n'y a plus de jeton de progrès à distribuer" << std::endl;
        return nullptr;
    }
}


bool Board::canConstructWonder() const {
    return constructed_wonders < Instanciator::getInstanciator()->getGameParameters().getWondersMax();
}
