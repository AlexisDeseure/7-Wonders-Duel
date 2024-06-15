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
    QLabel* currentPlayerLabel;
    QPushButton* QUIT;
    // Layout de cartes
    QVBoxLayout* columns;
    std::map<Wonder*, QPushButton*> dictionary;

signals:
    void selectionDone(Wonder* selectedWonder);
    void exitBoucleSelection();

//private slots:
  //  void handleSelection(Wonder* selectedWonder); // Slot to handle the selection

public:
    ChooseWonderStart(QWidget *parent,std::vector<Wonder*> wonders_vect);
    QVBoxLayout* displayCurrentCards(std::vector<Wonder*> wond_vect);
    void setCurrentPlayerLabel(QString new_label){
        currentPlayerLabel->setText(new_label);
    };
    void deleteLabel(){delete currentPlayerLabel;};
    void handleAiChoice(Wonder* wonder);

private slots:
    void destroyButton(QPushButton* button);

};

#endif // CHOOSEWONDERSUI_H
