#ifndef CHOOSEWONDERSUI_H
#define CHOOSEWONDERSUI_H

#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>
#include <QtCore>
#include <QWidget>
#include "Game.h"
#include <vector>

class ChooseWonderStart: public QWidget{
Q_OBJECT
private:
    //Tour du joueur de choisir.
    bool player;
    QPushButton* ready;
    QLabel* p1;
    QLabel* p2;
    QPushButton* QUIT;
    // Layout de cartes
    QVBoxLayout* columns;


public:
    ChooseWonderStart(QWidget *parent);
    QHBoxLayout* displayCurrentCards(std::vector<Wonder*> wonders_vect);
public slots:
    void wondersChoosed();
signals:
    void wondersChosen();
    void readyToReceiveWonders();
};

#endif // CHOOSEWONDERSUI_H
