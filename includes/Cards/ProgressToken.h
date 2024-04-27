//Crée par Mateo
#ifndef PROGRESSTOKEN_H
#define PROGRESSTOKEN_H

#include "Card.h"

class ProgressToken : public Card{
private:
    bool on_the_board;
public:
    ProgressToken() {
        on_the_board = false;
    };
    bool otb() const{ return on_the_board;};

    void status_switch(){on_the_board= not(on_the_board);};
};


#endif //PROGRESSTOKEN_H
