#include "../../includes/Cards/Card.h"
#include "../../includes/City/Ressource.h"
#include "../../includes/Effects/Effect.h"
#include "../../includes/City/City.h"
#include <string>
#include <iostream>
using namespace std; 
void Card::getPriceRessources() const {
    for (int i = 0; i < taille_ressources; i++) {
        if (ressources[i] != nullptr) { // Check if the pointer is not null
            std::cout << *ressources[i]; // Dereference the pointer to access the object
        }
    }
    //return ressources
}

Ressource* Card::ajouteRessources(Ressource& R) {
    ressources[taille_ressources] = &R;
    taille_ressources++;
    return &R;
}