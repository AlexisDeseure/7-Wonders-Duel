#ifndef PROJET_WONDER_H
#define PROJET_WONDER_H

#include"includes/City/City.h"
#include "Card.h"

class Wonder : public Card{
    private:
        bool active; //Montre si la merveille est sur le plateau
    public:
        Wonder(): active(false){}; //Constructeur
        void activate(){if(!active) active=true;}; //Selecteur de status
        bool getStatus(){return active;};
    };
// Wonder

#endif //PROJET_WONDER_H
