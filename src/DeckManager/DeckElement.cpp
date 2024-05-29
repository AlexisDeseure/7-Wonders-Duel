#include "DeckElement.h"
#include "Building.h"


 void DeckElement::deleteDeckFromMarket() const{


    if (right_son) {
        right_son->left_father = nullptr ;
        if (right_son->right_father)
            right_son->setVisible();
    }

    if (left_son) {
        left_son->right_father = nullptr ;
        if (left_son->left_father)
            left_son->setVisible();
    }

}

std::ostream &operator<<(std::ostream& os, const DeckElement& d){
    if (d.isVisible())
        os << d.getBuilding()->getName();
    else
        os << "Hidden";
    return os;
}










