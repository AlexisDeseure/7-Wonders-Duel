#include "militarydeck.h"
#include <QWidget>

MilitaryDeck::MilitaryDeck(QWidget* Parent,int p) : QWidget(Parent), pawn_pos(p) {
    pawn_grid = new QGridLayout(this);
    pawn = new QLabel(this);
    deck = new QLabel(this);
    QPixmap deck_image(":/images/data/image/board.png");
    deck_image = deck_image.scaled(228, 780, Qt::KeepAspectRatio); //original size 268 * 949
    deck->setPixmap(deck_image);
    pawn_grid->addWidget(deck,0,0,19,3);
    for(int i = 0; i<19;i++){
        if(i!=9) pawn_grid->addWidget(new QWidget,i,1,1,1);
    }
    //Colors for
    pawn_grid->addWidget(pawn,9,1,1,1);
    pawn->setStyleSheet("background-color: blue; color: white;");


    QPushButton* b = new QPushButton("Military",pawn);
}
