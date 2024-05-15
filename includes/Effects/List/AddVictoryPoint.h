#ifndef ADDVICTORYPOINT_H
#define ADDVICTORYPOINT_H

#include "../Effect.h"

class City; // Déclaration anticipée de City

class AddVictoryPoint : public Effect {
    public:
        AddVictoryPoint(int quantity) : Effect(), quantity(quantity) {};
        void effect(City* city) override;


    private:
        int quantity;

};

#endif
