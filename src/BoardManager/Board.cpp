#include "Board.h"
#include "ConflictPawn.h"
#include "MarketDeck.h"
#include "ProgressToken.h"
#include "Instanciator.h"
#include "GameParameters.h"
#include "Player.h"
#include "City.h"
#include "Game.h"
#include "DeckPile.h"
#include "Building.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

Board::Board(int victory_position) : constructed_wonders(0), conflict_pawn(*new ConflictPawn(victory_position)),
    market_deck(*new MarketDeck()){
    // std::cout << "Board created" << std::endl;
}

bool Board::deckIsEmpty() const{
    return market_deck.isEmpty();
}

void Board::advanceAge(int age, std::vector<Building*>& buildings){
    market_deck.advanceAge(age, buildings);
}

ProgressToken* Board::getProgressToken(Game& game, Player& player, bool within_discarded, int number_choice) const{
    DeckPile& deck = game.getDeck();
    std::vector<ProgressToken *>& progress_tokens_list = deck.getProgressTokens();
    if (within_discarded) {
        progress_tokens_list = deck.getOtherProgressTokens();
        std::shuffle(progress_tokens_list.begin(), progress_tokens_list.end(), std::mt19937(std::random_device()()));
    }
    int nb_choice = (within_discarded)?(std::min(number_choice, static_cast<int>(progress_tokens_list.size()))):progress_tokens_list.size();
    if (!progress_tokens_list.empty()){
        std::cout << player.getName() <<", choisissez un jeton de progrès parmi la liste :" << std::endl;
        // Affichage des jetons de progrès (tous ceux du plateau ou number_choice parmi ceux défaussés)
        for (int i = 1; i <= nb_choice; i++){
            std::cout << i << " : " << std::endl;
            progress_tokens_list[i-1]->print();
        }
        int choice = player.getPlayerChoice(static_cast<int>(nb_choice));
        ProgressToken* selected = progress_tokens_list[choice-1];
        progress_tokens_list.erase(progress_tokens_list.begin() + choice-1);

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
