#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include"C:\Users\ismat\Documents\UTC - GI02\LO21\git\7_Wonders_Duel\includes\City\Ressource.h"
#include"C:\Users\ismat\Documents\UTC - GI02\LO21\git\7_Wonders_Duel\includes\City\City.h"
class Effect; 
class Card {
    std::string name;
    Ressource** ressources;
    Effect** effects;
    //City* owner;
    //pas besoin de la class city car city contient deja
    //la liste des cartes
    int taille_ressources;
    //cet attribut contient le nombre de ressources

public :
    Card(std::string name) : name(std::move(name)), ressources(new Ressource* [0]), taille_ressources(0), effects(new Effect* [0]) {};
    ~Card() {
     //   for (int i = 0; i++; i < taille_ressources) {
     //       delete ressources[i];
     //   }
        delete[] ressources;

    }
    Ressource* ajouteRessources( Ressource& R);
    std::string getName() const {
        return name;
    };
    void getPriceRessources() const;
    int getCost(const City* city) const{return 0;}


};

#endif