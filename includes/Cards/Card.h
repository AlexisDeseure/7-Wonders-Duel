#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>

class Effect;
class Ressource;
class City;

class Card {
    std::string name;

    std::vector<Ressource*> cost;
    std::vector<Effect*> effects;

    public :
        Card(std::string name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects)
        : name(std::move(name)), cost(cost), effects(effects){};

        ~Card();

    //     //   for (int i = 0; i++; i < taille_ressources) {
    //     //       delete ressources[i];
    //     //   }
    //        delete[] cost;
    //
        void ajouteRessources(Ressource* R);
        std::string getName() const {
            return name;
        };
        // void getPriceRessources() const; en fait c'est inutile

        unsigned int getCost(const City* city) const;
        void applyEffects(City* city) const;
        virtual bool isChainInInCity(const City* city) const = 0;


};

#endif