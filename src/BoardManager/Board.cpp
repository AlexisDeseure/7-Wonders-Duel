#include "Board.h"
#include "ConflictPawn.h"
#include "MarketDeck.h"

Board::Board() : constructed_wonders(0), conflict_pawn(*new ConflictPawn()), market_deck(*new MarketDeck()){
    std::cout << "Board created" << std::endl;

}

bool Board::deckIsEmpty() const{
    return market_deck.isEmpty();
}
