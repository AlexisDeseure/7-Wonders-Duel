#ifndef PROJET_WONDER_H
#define PROJET_WONDER_H

#include"includes/City/City.h"
#include "Card.h"

class Wonder : public Card{
    private:
        bool active; //Montre si la merveille est sur le plateau
        const City::City* city;
    public:
        Wonder(); //Constructeur
        void select(); //Selecteur à voir
    };
// Wonder

#endif //PROJET_WONDER_H
