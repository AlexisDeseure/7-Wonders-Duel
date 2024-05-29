#include "DeckElement.h"
#include "Building.h"


void DeckElement::deleteDeckFromMarket() const{

    if (left_son) {
        left_son->setRightFather(nullptr) ;
        if (!left_son->getLeftFather())
            left_son->setVisible();
    }

    if (right_son) {
        right_son->setLeftFather(nullptr) ;
        if (!right_son->getRightFather())
            right_son->setVisible();
    }

}

std::ostream &operator<<(std::ostream& os, const DeckElement& d){
    if (d.isVisible())
        os << d.getBuilding()->getName();
    else
        os << "Hidden";
    return os;
}










