#include "DeckElement.h"



 void DeckElement::deleteDeckFromMarket() const{

    if (right_son) {
        right_son->setVisible() ;
        right_son->left_father = nullptr ;

    }

    if (left_son) {
        left_son->setVisible() ;
        left_son->right_father = nullptr ;
    }

}










