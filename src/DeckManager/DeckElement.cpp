#include "DeckElement.h"



 void DeckElement::deleteDeckFromMarket() {

    if (right_son) {
        right_son->setVisible() ;
        right_son->left_son = nullptr ;

    }

    if (left_son) {
        left_son->setVisible() ;
        left_son->right_son = nullptr ;
    }

}









