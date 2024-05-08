#ifndef ADDVICTORYPOINT_H
#define ADDVICTORYPOINT_H

#include "../Effect.h"

class City; // Déclaration anticipée de City

class AddVictoryPoint : public Effect {
public:
    AddVictoryPoint(std::string nom, int quantity) : Effect(std::move(nom)), quantity(quantity) {};
    void effect(City* city);


private:
    int quantity;

};

#endif
