#include "Board.h"
#include "ConflictPawn.h"
#include "MarketDeck.h"
#include "ProgressToken.h"

#include <iostream>

Board::Board(int victory_position) : constructed_wonders(0), conflict_pawn(*new ConflictPawn(victory_position)), market_deck(*new MarketDeck()){
    std::cout << "Board created" << std::endl;
}

bool Board::deckIsEmpty() const{
    return market_deck.isEmpty();
}
