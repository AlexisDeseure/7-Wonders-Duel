#ifndef BOARD_H
#define BOARD_H

#define MAX_WONDERS 7

class ConflictPawn;
class MarketDeck;

class Board{
    private:
        int constructed_wonders;
        ConflictPawn& conflict_pawn;
        MarketDeck& market_deck;

    public:
        Board();
        ~Board()=default;
        bool canConstructWonder() const { return constructed_wonders < MAX_WONDERS; };
        void constructWonder() { constructed_wonders++; };
        void advanceConflictPawn(int step);
        bool deckIsEmpty() const;

};

#endif
