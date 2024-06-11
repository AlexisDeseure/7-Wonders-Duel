#include "ChooseWondersUI.h"

ChooseWonderStart::ChooseWonderStart(QWidget *parent,Connector* connector) : QWidget(parent){

    emit readyToReceiveWonders();
    qDebug()<<"Entered Loop";
    QEventLoop loop;
    connect(connector,SIGNAL(wondersReady()),&loop,SLOT(quit()));
    loop.exec();

    std::vector<Wonder*> shuffled_wonders=connector->getWondersFromGameUI();

    QSize size = parent->size();
    QRect ALL_size = QRect(parent->pos(),size);

    //LAYOUT GLOBAL
    columns = new QVBoxLayout(this);
    columns->setGeometry(ALL_size);
    //player == 0 : joueur 2
    //player == 1 : joueur 1
    p1=new QLabel("Joueur 1, à toi de choisir!");
    p2=new QLabel("Joueur 2, à toi de choisir!");
    if (player){

    }
    else{

    }

    QHBoxLayout* cards = displayCurrentCards(shuffled_wonders);
    columns->addLayout(cards);
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

void ChooseWonderStart::changeChooser(){

}
