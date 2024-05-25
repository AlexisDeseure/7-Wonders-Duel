#ifndef BOARD_H
#define BOARD_H

#include "Game.h"
#include <vector>

class ConflictPawn;
class MarketDeck;
class ProgressToken;

class Board{
    private:
        int constructed_wonders;
        ConflictPawn& conflict_pawn;
        MarketDeck& market_deck;
        std::vector<ProgressToken*> progressToken; //jetons sélectionnés en début de partie

    public:
        Board(int victory_position);
        ~Board()=default;
        bool canConstructWonder() const { return constructed_wonders < WONDERS_MAX; };
        void constructWonder() { constructed_wonders++; };
        void advanceConflictPawn(int step);
        bool deckIsEmpty() const;
        ConflictPawn& getConflictPawn(){return conflict_pawn;};

};

#endif
