//Crée par Mateo
#ifndef PROGRESSTOKEN_H
#define PROGRESSTOKEN_H

#include "Card.h"

class City; // Déclaration anticipée de City

class ProgressToken : public Card{

    private:
        bool on_the_board;
        //const Board* board;

    public:
        ProgressToken(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects)
        : Card(std::move(name), cost, effects), on_the_board(false) {};
        bool onTheBoard() const{ return on_the_board;};
        void status_switch(){if (!on_the_board) on_the_board = true;};
};


#endif //PROGRESSTOKEN_H
