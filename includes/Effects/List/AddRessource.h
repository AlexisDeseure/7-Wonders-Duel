#ifndef ADDRESSOURCE_H
#define ADDRESSOURCE_H

#include "../Effect.h"

class City; // Déclaration anticipée de City
enum class RessourceType;

class AddRessource : public Effect {
    public:
        AddRessource(RessourceType ressource, int quantity = 1) : Effect(), ressource(ressource), quantity(quantity) {};
        void effect(City* city) override;


    private:
        RessourceType ressource;
        int quantity;

};
#endif
