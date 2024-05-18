#ifndef CARD_H
#define CARD_H

#include <string>

#include <utility>
#include <vector>

#include <QString>

#include "Ressource.h"

class Effect;
class City;

class Card {
    private:
        std::string name;

        std::vector<Ressource*> cost;
        std::vector<Effect*> effects;

    public :
        Card(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects)
        : name(std::move(name)), cost(cost), effects(effects){};

        virtual ~Card();

        void ajouteRessources(Ressource* R);
        std::string getName() const {
            return name;
        };

        unsigned int getCost(City* city) const;
        void applyEffects(City* city);
        virtual bool isChainInInCity(const City* city) const = 0;


};

#endif
