#ifndef WONDER_H
#define WONDER_H

#include "Card.h"

class Wonder : public Card{
    private:
        bool active; //Montre si la merveille est sur le plateau
    public:
        Wonder(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)
        : Card(std::move(name), cost, effects, direct_cost), active(false) {}; //Constructeur

        void activate(){if(!active) active=true;}; //Selecteur de status
        bool isBuilt() const {return active;};
        void setBuilt(bool b){active = b;};
        bool isChainInInCity(const City* city) const override {return false;};
};
// Wonder

#endif
