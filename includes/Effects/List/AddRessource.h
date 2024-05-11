#ifndef ADDRESSOURCE_H
#define ADDRESSOURCE_H

#include "../Effect.h"

class City; // Déclaration anticipée de City
enum class RessourceType;

class AddRessource : public Effect {
public:
    AddRessource(std::string nom, RessourceType ressource, int quantity = 1) : Effect(std::move(nom)), ressource(ressource),
                                                                     quantity(quantity) {};
    void effect(City* city);


private:
    RessourceType ressource;
    int quantity;

};
#endif
