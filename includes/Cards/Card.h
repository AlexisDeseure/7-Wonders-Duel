#ifndef CARD_H
#define CARD_H

#include <string>

#include <utility>
#include <vector>
#include <list>
#include <QString>
#include "RessourceCost.h"

class Effect;
class City;
class Game;
class Ressource;
enum class RessourceType;

class Card {
    private:
        std::string name;
        std::vector<Effect*> effects;
        std::vector<RessourceCost> cost;
        unsigned int money_cost; // coût de base de la carte en or (irréductible sauf en cas de chaînage ou l'acquisition est forcément gratuite)
    protected:
        QString image;

    public :
        Card(std::string name, const std::vector<RessourceCost>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, QString image)
            : name(std::move(name)), effects(effects), cost(cost), money_cost(direct_cost), image(image){};

        virtual ~Card();

        void addRessources(RessourceCost R);
        std::string getName() const {
            return name;
        };

        unsigned int getMoneyCost() const; //permet simplement d'accéder au potentiel coût imposé en or
        std::list<RessourceType> getLackingRessources(City* city) const;
        unsigned int getCost(City* city) const; //permet d'obtenir le coût minimal réel que devra payer une ville pour se procurer la carte (à utiliser avant chaque achat)
        void applyEffects(Game& game);
        virtual bool isChainInInCity(const City* city) const = 0;
        std::vector<Effect*> getEffects() const {return effects;};
        virtual void print() const;

};

#endif
