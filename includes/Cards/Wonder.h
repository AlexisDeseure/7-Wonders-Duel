#ifndef WONDER_H
#define WONDER_H

#include <iostream>

#include "Card.h"

class Wonder : public Card{
private:
    bool active; //Montre si la merveille est sur le plateau
public:
    Wonder(std::string n) : Card(std::move(n)), active(false) {}; //Constructeur
    void activate(){if(!active) active=true;}; //Selecteur de status
    bool isBuilt() const {return active;};
    void setBuilt(bool b){active = b;};
};
// Wonder

#endif