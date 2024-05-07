//Crée par Mateo
#ifndef PROGRESSTOKEN_H
#define PROGRESSTOKEN_H

#include "Card.h"
#include "../City/City.h"

class ProgressToken : public Card{
    

private:
    bool on_the_board;
    const City::City* city;
    const Board* board;

public:
    ProgressToken(): on_the_board(false) {};
    bool onTheBoard() const{ return on_the_board;};
    void status_switch(){if (!on_the_board) on_the_board = true;};
};


#endif //PROGRESSTOKEN_H
