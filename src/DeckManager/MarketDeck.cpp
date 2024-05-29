#include "MarketDeck.h"

#include <utility>
#include "DeckElement.h"
#include "Building.h"
#include "BuildingsLayout.h"
#include "Instanciator.h"
#include "DeckElement.h"

void MarketDeck::advanceAge(int age, std::vector<Building*>& buildings) {
    elements = Instanciator::getInstanciator()->getBuildingsLayout().getAgeWithBuildings(age, buildings);
    elements_selectionables = elements[0];
}

std::ostream &operator<<(std::ostream& os, const MarketDeck& m){
    std::vector<std::vector<DeckElement*>> all =  m.getAllBuildings();
    for(auto it = all.end()-1; it != all.begin()-1; --it){
        for(auto& element : *it){
            os << *element << " | ";
        }
        os << std::endl;
    }
    os << std::endl << "Elements sélectionables : " << std::endl;
    for (auto& element : m.getFirstBuildings()){
        os << *element << " | ";
    }
    return os;
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
    if (index < elements_selectionables.size()) {
        elements_selectionables.insert(elements_selectionables.begin() + index, building);
    } else {
        elements_selectionables.push_back(building);
    }
}

DeckElement& MarketDeck::getBuilding(unsigned int i) {
    DeckElement* currentElement = elements_selectionables[i];
    if (currentElement->getLeftFather() == nullptr && currentElement->getRightFather() == nullptr) { // No father, origin node

        // Add sons to the list of possible buildings, making them visible if they exist
        currentElement->deleteDeckFromMarket();

        // Remove the building from first_building
        if (i < elements_selectionables.size()) {
            elements_selectionables.erase(elements_selectionables.begin() + i);
        }

        // Place sons at the same index
        if (currentElement->getRightSon()) {
            addFirstBuilding(currentElement->getRightSon(), i);
        }
        if (currentElement->getLeftSon()) {
            addFirstBuilding(currentElement->getLeftSon(), i);
        }
    }
    return *currentElement;
}



