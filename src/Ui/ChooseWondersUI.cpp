#include "ChooseWondersUI.h"

ChooseWonderStart::ChooseWonderStart(QWidget *parent,std::vector<Wonder*> wonders_vect) : QWidget(parent){

    QSize size = parent->size();
    QRect ALL_size = QRect(parent->pos(),size);

    //LAYOUT GLOBAL
    columns = new QVBoxLayout(this);
    columns->setGeometry(ALL_size);
    //player == 0 : joueur 2
    //player == 1 : joueur 1
    p1 = new QLabel("Joueur 1, à toi de choisir!");
    p2 = new QLabel("Joueur 2, à toi de choisir!");
    qDebug() << "INSIDE FIRST";
    QHBoxLayout* cards = displayCurrentCards(wonders_vect);
    qDebug() << "OUTSIDE FIRST";
    columns->addLayout(cards);
    columns->addWidget(p1);
    columns->addWidget(p2);
}

QHBoxLayout* ChooseWonderStart::displayCurrentCards(std::vector<Wonder*> wond_vect){
    //Layout cartes
    QHBoxLayout* row = new QHBoxLayout;
    for (Wonder* wonder: wond_vect) {
        QVBoxLayout* card = new QVBoxLayout;
        QLabel* name = new QLabel("Nom: " + QString::fromStdString(wonder->getName()));
        QLabel* MoneyCost = new QLabel("MoneyCost: " + QString::number(wonder->getMoneyCost()));
        card->addWidget(name);
        card->addWidget(MoneyCost);
        row->addLayout(card);
    }
    return row;
}

//void ChooseWonderStart::changeChooser(){

//}
