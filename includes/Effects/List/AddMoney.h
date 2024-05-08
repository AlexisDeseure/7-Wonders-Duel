#ifndef ADDMONEY_H
#define ADDMONEY_H

#include "../Effect.h"

class City; // Déclaration anticipée de City

class AddMoney : public Effect {
public:
    AddMoney(std::string nom, int quantity) : Effect(std::move(nom)), quantity(quantity) {};
    void effect(City* city);


private:
    int quantity;

};


#endif
