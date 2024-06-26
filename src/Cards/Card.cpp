#include "Card.h"
#include "Ressource.h"
#include "RessourceCost.h"
#include "Effect.h"
#include "City.h"
#include "Game.h"
#include <list>
#include <iostream>
#include "Building.h"
#include "Instanciator.h"
using namespace std;

// en fait cette fonction ne sert pas l'idée c'est de faire tout dans getCost : en fait la fonction doit renvoyer le
// cout de la carte en fonction de la ville qui la construit donc il faut parcourir chaque cout (de type resource) et
// vérifier si la ville a assez de ressources de ce type si non calculer le nombre de ressource manquante multiplié
// par le prix de la ressource. Vérifier également si la carte ne dispose pas de chainage qui permettrait de l'avoir
// gratuitement si c'est le cas alors le cout est de 0 (cf getCost)


Card::~Card() {
    // for (auto &c: cost) {
    //     delete c;
    // }
    // for (auto &e: effects) {
    //     delete e;
    // }
}

Card::Card(std::string name, const std::vector<RessourceCost>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, QString image)
    : name(std::move(name)), effects(effects), cost(cost), money_cost(direct_cost), image(image){
      };


unsigned int Card::getMoneyCost() const{
    return money_cost;
}

std::list<RessourceType> Card::getLackingRessources(City* city) const{
    unsigned int ressource_necessaire;
    unsigned int ressource_possede;
    std::list<RessourceType> lack_ressources;
    RessourceType type_intermediaire;

    // Calculer les ressources manquantes après avoir vérifier les ressources de bases de la ville
    for (auto& ressource : cost) {

        ressource_necessaire = ressource.getAmount();
        ressource_possede = city->getRessource(ressource.getType()).getAmount();
        if (ressource_necessaire > ressource_possede) {
            //ajouter autant de ressources que nécessaire dans la liste des ressources manquantes
            type_intermediaire = ressource.getType();

            for (unsigned int i = 0; i < ressource_necessaire - ressource_possede; i++)
                lack_ressources.push_back(type_intermediaire);
        }
    }

    city->updateRemainingRessources(lack_ressources);
    return lack_ressources;
}

unsigned int Card::getCost(City* city) const {
    unsigned int money_cost = getMoneyCost();

    std::list<RessourceType> lack_ressources = getLackingRessources(city);

    if (isChainInInCity(city)) {
        return 0;
    }

    // Calculer le prix des ressources manquantes
    for (auto& ressource : lack_ressources) {
        money_cost += city->getRessource(ressource).getPrice();
    }

    return money_cost;
}


void Card::applyEffects(Game& game) {
    for (auto& effect : effects) {
        effect->apply(game);
    }
}

void Card::addRessources(RessourceCost R) {
    cost.push_back(R);
}

void Card::print() const {
    cout << "\tNom : " << name << endl;
    cout << "\tCoût : ";
    if (cost.empty() && money_cost == 0) {
        cout << "Aucun" << endl;
    }
    else{
        cout << endl;
        for (auto& ressource : cost) {
            cout << "\t\t- " << ressource.getAmount() << " " << ressourceTypeToString(ressource.getType()) << endl;
        }
        if (money_cost > 0){
            cout << "\t\t- Pièces : " << money_cost << endl;
        }
    }
    if(!effects.empty()) {
        cout << "\tEffets : " << endl;
        for (auto &effect: effects) {
            effect->display();
        }
    }
}

