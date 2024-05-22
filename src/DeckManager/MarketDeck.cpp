#include "MarketDeck.h"
#include "DeckElement.h"


MarketDeck::~MarketDeck() {
    for (int i = 0; i < nb_first_buildings; i++) {
        delete first_buildings[i];
    }

};

/*
void MarketDeck::removeBuilding(DeckElement* building) {
    int index = -1;
    for (int i = 0; i < nb_first_buildings; i++) {
        if (first_buildings[i] == building) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < nb_first_buildings - 1; i++) {
            first_buildings[i] = first_buildings[i + 1];
        }
        nb_first_buildings--;
    }
}
*/
void MarketDeck::addFirstBuilding(const DeckElement* building) {
     const DeckElement** new_first_buildings = new const DeckElement*[nb_first_buildings + 1];
    for (int i = 0; i < nb_first_buildings; i++) {
        new_first_buildings[i] = first_buildings[i];
    }
    new_first_buildings[nb_first_buildings] = building;
    delete[] first_buildings;
    first_buildings = new_first_buildings;
    nb_first_buildings++;
}

DeckElement& MarketDeck::iterator::getBuilding(MarketDeck& M) {
    DeckElement& currentElement = **building;

    if (currentElement.getLeftFather() == nullptr && currentElement.getRightFather() == nullptr) { //pas de père, noed origine

        // Ajout des fis a la liste des buildings possibles, en les mettant a visible s'ils  existent
        currentElement.deleteDeckFromMarket();

        //Il faut enlever le building des first_building
        //MarketDeck
        int index = -1;
        for (int i = 0; i < M.nb_first_buildings; i++) {
            if (M.first_buildings[i] == *building) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < M.nb_first_buildings - 1; i++) {
                M.first_buildings[i] = M.first_buildings[i + 1];
            }
            M.nb_first_buildings--;
        }

        if(currentElement.getRightSon()) {

            M.addFirstBuilding(currentElement.getRightSon()) ;


        }
        if(currentElement.getLeftSon()) {

            M.addFirstBuilding(currentElement.getLeftSon()) ;

        }
    }

    return currentElement;
}



