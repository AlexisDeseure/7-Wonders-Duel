#ifndef ENDGAMEPOPUP_H
#define ENDGAMEPOPUP_H

#include "Player.h"
#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCore>
#include <QWidget>


class EndGamePopUp : public QWidget{
Q_OBJECT
private:
    QLabel* WINNER;
    QLabel* time;
    int i=9;
public:
    EndGamePopUp(QWidget* parent,Player* winner);
signals:
    void endGame();
public slots:
    void quitting();

};

#endif // ENDGAMEPOPUP_H
