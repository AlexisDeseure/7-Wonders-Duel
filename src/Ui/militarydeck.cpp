#include "militarydeck.h"


MilitaryDeck::MilitaryDeck(QWidget* Parent,int p) : QWidget(Parent), pawn_pos(p) {
    pawn_grid = new QGridLayout(this);
    pawn = new QLabel(this);
    deck = new QLabel(this);
    pawn_grid->addWidget(deck,0,0,19,3);
    for(int i = 0; i<19;i++){
        if(i!=9) pawn_grid->addWidget(new QWidget,1,i,1,1);
    }
    //Colors for
    pawn_grid->addWidget(pawn,9,1,1,1);
    pawn->setStyleSheet("background-color: blue; color: white;");


    QPushButton* b = new QPushButton("Military",pawn);
}
