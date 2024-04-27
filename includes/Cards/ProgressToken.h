//Crée par Mateo
#ifndef PROGRESSTOKEN_H
#define PROGRESSTOKEN_H

#include "Card.h"

class ProgressToken : public Card{
private:
    bool on_the_board;
public:
    ProgressToken(): on_the_board(false) {};
    bool onTheBoard() const{ return on_the_board;};
    void status_switch(){if (!on_the_board) on_the_board = true;};
};


#endif //PROGRESSTOKEN_H
