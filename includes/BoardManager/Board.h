#ifndef BOARD_H
#define BOARD_H


#include <vector>

class ConflictPawn;
class MarketDeck;
class ProgressToken;
class Player;
class Game;
class Building;

class Board{
    private:
        int constructed_wonders;
        ConflictPawn& conflict_pawn;
        MarketDeck& market_deck;

    public:
        Board(int victory_position);
        ~Board()=default;
        bool canConstructWonder() const;
        void constructWonder() { constructed_wonders++; };
        bool deckIsEmpty() const;
        void advanceAge(int age, std::vector<Building*>& buildings);
        ProgressToken* getProgressToken(Game& game, Player& player, bool within_discarded = false, int number_choice = 0) const;
        ConflictPawn& getConflictPawn(){return conflict_pawn;};

};

#endif




