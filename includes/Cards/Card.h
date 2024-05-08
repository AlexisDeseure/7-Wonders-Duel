#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Effect;
class Ressource;
class City;

class Card {
    std::string name;
    Ressource** ressources;
    Effect** effects;
    //City* owner;
    //pas besoin de la class city car city contient deja
    //la liste des cartes
    int taille_ressources;
    //cet attribut contient le nombre

public :
    Card(std::string name) : name(std::move(name)), ressources(new Ressource* [0]), taille_ressources(0), effects(new Effect* [0]) {};
    ~Card() {
        for (int i = 0; i++; i < taille_ressources) {
            delete ressources[i];
        }
        delete[] ressources;

    }
    std::string getName() const {
        return name;
    };
    Ressource* getPriceRessources() const;
    int getCost(const City* city) const{return 0;};

};


#endif