#ifndef CHOOSEWONDERSUI_H
#define CHOOSEWONDERSUI_H

#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCore>
#include <QWidget>
#include <vector>
#include "Wonder.h"

class ChooseWonderStart: public QWidget{
Q_OBJECT
private:

    QPushButton* ready;
    QLabel* p1;
    QLabel* p2;
    QPushButton* QUIT;
    // Layout de cartes
    QVBoxLayout* columns;

public:
    ChooseWonderStart(QWidget *parent,std::vector<Wonder*> wonders_vect);
    QHBoxLayout* displayCurrentCards(std::vector<Wonder*> wonders_vect);
signals:
    void selectionDone();
};

#endif // CHOOSEWONDERSUI_H