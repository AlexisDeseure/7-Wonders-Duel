#ifndef WONDER_H
#define WONDER_H

#include "Card.h"
#include <iostream>
#include <QString>

class Wonder : public Card{
    private:
        bool active;

    public:
        Wonder(std::string name, const QString img,const std::vector<RessourceCost>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost)
        : Card(std::move(name), cost, effects, direct_cost,img), active(false) {}; //Constructeur

        void activate(){if(!active) active=true;}; //Selecteur de status
        bool isBuilt() const {return active;};
        void setBuilt(bool b){active = b;};
        bool isChainInInCity([[maybe_unused]] const City* city) const override {return false;};
        void print() const override {
            Card::print();
            std::cout << ((active)?"Déjà construite":"Pas encore construite")<<std::endl;
        };
        QString getImage() const {return image;};
};
// Wonder

#endif
