#ifndef ADDRESSOURCE_H
#define ADDRESSOURCE_H

#include "../Effect.h"

class City; // Déclaration anticipée de City

class AddRessource : public Effect {
public:
    AddRessource(std::string nom, int ressource, int quantity = 1) : Effect(nom), ressource(ressource),
                                                                     quantity(quantity) {};
    void effect(City* city);


private:
    int ressource;
    int quantity;

};
#endif
