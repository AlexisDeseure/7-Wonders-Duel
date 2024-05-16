#include "Card.h"
#include "Ressource.h"
#include "Effect.h"
#include "City.h"


using namespace std;

// en fait cette fonction ne sert pas l'idée c'est de faire tout dans getCost : en fait la fonction doit renvoyer le
// cout de la carte en fonction de la ville qui la construit donc il faut parcourir chaque cout (de type resource) et
// vérifier si la ville a assez de ressources de ce type si non calculer le nombre de ressource manquante multiplié
// par le prix de la ressource. Vérifier également si la carte ne dispose pas de chainage qui permettrait de l'avoir
// gratuitement si c'est le cas alors le cout est de 0 (cf getCost)


//void Card::getPriceRessources() const {
//    for (int i = 0; i < taille_ressources; i++) {
//        if (cost[i] != nullptr) { // Check if the pointer is not null
//            std::cout << *cost[i]; // Dereference the pointer to access the object
//        }
//
//    }
//    //return ressources
//}
Card::~Card() {
    for (auto &c: cost) {
        delete c;
    }
    for (auto &e: effects) {
        delete e;
    }
}

unsigned int Card::getCost(const City* city) const {
    unsigned int money_cost = 0;
    unsigned int ressource_necessaire;
    unsigned int ressource_possede;

    if (isChainInInCity(city)) {
        return 0;
    }

    for (auto& ressource : cost) {
        ressource_necessaire = ressource->getAmount();
        ressource_possede = city->getRessource(ressource->getType()).getAmount();

        if (ressource_necessaire > ressource_possede) {
            money_cost += (ressource_necessaire - ressource_possede) * ressource->getPrice();
        }
    }

    return money_cost;
}

void Card::applyEffects(City* city) const {
    for (auto& effect : effects) {
        effect->apply(city);
    }
}

void Card::ajouteRessources(Ressource* R) {
    cost.push_back(R);
}
