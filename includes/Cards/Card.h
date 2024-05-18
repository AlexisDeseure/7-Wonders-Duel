#ifndef CARD_H
#define CARD_H

#include <string>

#include <utility>
#include <vector>

#include <QString>

#include "Ressource.h"

class Effect;
class City;

enum class CardType {
    Yellow,
    Brown,
    Grey,
    Purple,
    Green,
    Red,
    Blue,
    LENGTH
};

class Card {
    private:
        std::string name;
        std::vector<Ressource*> cost;
        std::vector<Effect*> effects;
        const unsigned int money_cost; // coût de base de la carte en or (irréductible sauf en cas de chaînage ou l'acquisition est forcément gratuite)
        CardType type;

    public :
        Card(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, CardType t)
            : name(std::move(name)), cost(cost), effects(effects), money_cost(direct_cost), type(t){};

        virtual ~Card();

        void ajouteRessources(Ressource* R);
        std::string getName() const {
            return name;
        };
        CardType getType() const {return type;}
        unsigned int getMoneyCost() const; //permet simplment d'accéder au potentiel coût imposé en or
        unsigned int getCost(City* city) const; //permet d'obtenir le coût minimal réel que devra payer une ville pour se procurer la carte (à utiliser avant chaque achat)
        void applyEffects(City* city);
        virtual bool isChainInInCity(const City* city) const = 0;


};

#endif
