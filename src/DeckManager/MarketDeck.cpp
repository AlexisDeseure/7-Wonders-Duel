#include "MarketDeck.h"

#include <utility>
#include "DeckElement.h"
#include "Building.h"
#include "BuildingsLayout.h"
#include "Instanciator.h"
#include "DeckElement.h"

void MarketDeck::advanceAge(int age, std::vector<Building*>& buildings) {
    elements = Instanciator::getInstanciator()->getBuildingsLayout().getAgeWithBuildings(age, buildings);
    selectable_elements = elements[0];
}


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
//void MarketDeck::addFirstBuilding(const DeckElement* building) {
//     const DeckElement** new_first_buildings = new const DeckElement*[nb_first_buildings + 1];
//    for (int i = 0; i < nb_first_buildings; i++) {
//        new_first_buildings[i] = first_buildings[i];
//    }
//    new_first_buildings[nb_first_buildings] = building;
//    first_buildings = new_first_buildings;
//    nb_first_buildings++;
//}
void MarketDeck::addFirstBuilding(DeckElement* building, unsigned int index) {
    if (index < selectable_elements.size()) {
        selectable_elements.insert(selectable_elements.begin() + index, building);
    } else {
        selectable_elements.push_back(building);
    }
}

void MarketDeck::getBuilding(unsigned int i) {
    DeckElement* currentElement = selectable_elements[i];
    currentElement->deleteDeckFromMarket();
    if (i < selectable_elements.size()) { // Suppression de l'élément sélectionné
        selectable_elements.erase(selectable_elements.begin() + i);
    }
    // Ajout des fils de l'élément supprimé si ils n'ont pas de père
    if (currentElement->getLeftSon()!=nullptr){
        if (currentElement->getLeftSon()->getLeftFather() == nullptr) {
            addFirstBuilding(currentElement->getLeftSon(), i);
            i++;
        }
    }
    if(currentElement->getRightSon()==nullptr){
        if (currentElement->getRightSon()->getRightFather() == nullptr)
            addFirstBuilding(currentElement->getRightSon(), i);
    }
    // supprimer l'élément de l'architecture donc de sa ligne
    for (auto& line : elements) {
        for (auto it = line.begin(); it != line.end(); ++it) {
            if (*it == currentElement) {
                line.erase(it);
                break;
            }
        }
    }
}

void MarketDeck::print() {
    std::vector<std::vector<DeckElement*>> all = getAllBuildings();
    for (auto it = all.end() - 1; it != all.begin() - 1; --it) {
        for (auto& element : *it) {
            std::cout << *element << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Elements sélectionables : " << std::endl;
    int i = 1;
    for (auto& element : getFirstBuildings()) {
        std::cout << i << " : " << std::endl;
        element->getBuilding()->print();
        i++;
    }
}

std::ostream &operator<<(std::ostream& os, MarketDeck& m){
    m.print();
    return os;
}

