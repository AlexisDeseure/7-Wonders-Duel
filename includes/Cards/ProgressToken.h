#ifndef PROGRESSTOKEN_H
#define PROGRESSTOKEN_H

#include "Card.h"

class City; // Déclaration anticipée de City

class ProgressToken : public Card{

    private:
        bool on_the_board;

    public:
        ProgressToken(std::string name, const std::vector<RessourceCost>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)
        : Card(std::move(name), cost, effects, direct_cost), on_the_board(false) {};
        bool onTheBoard() const{ return on_the_board;};
        void status_switch(){if (!on_the_board) on_the_board = true;};
        bool isChainInInCity([[maybe_unused]] const City* city) const override {return false;};
        void print() const override {Card::print();};
};


#endif //PROGRESSTOKEN_H
