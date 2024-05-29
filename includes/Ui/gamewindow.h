#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "playerwidget.h"
#include "cardwidget.h"
#include "Game.h" //  game header

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    PlayerWidget *player1Widget;
    PlayerWidget *player2Widget;
    //MarketWidget *marketWidget;
    //MilitaryWidget *militaryWidget;

    // void setupUi();
    // void setupConnections();
    Game game; // game instance

// public slots:
//     void onCardClicked();
};

#endif // GAMEWINDOW_H
