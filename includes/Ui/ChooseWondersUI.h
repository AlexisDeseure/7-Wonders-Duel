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
signals:
    void selectionDone(Wonder* selectedWonder); // Signal emitted when a wonder is selected

//private slots:
  //  void handleSelection(Wonder* selectedWonder); // Slot to handle the selection

public:
    ChooseWonderStart(QWidget *parent,std::vector<Wonder*> wonders_vect);
    QVBoxLayout* displayCurrentCards(std::vector<Wonder*> wond_vect);
signals:
    void selectionDone();
};

#endif // CHOOSEWONDERSUI_H
