#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "playerwidget.h"
#include "marketdeckwidget.h"
#include "militarydeck.h"
#include "Instanciator.h"
#include "Game.h"



class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(Game* game, MarketDeck* marketDeck,std::vector<Building*>& age1,std::vector<Building*>& age2, std::vector<Building*>& age3,QWidget *parent = nullptr);
    ~GameWindow();

    PlayerWidget& getplayer1()const{return *player1;};
    PlayerWidget& getplayer2()const{return *player2;};

private:
    //Grid
    QGridLayout* grid;

    //Widgets
    PlayerWidget *player1;
    PlayerWidget *player2;
    MilitaryDeck* military_deck;
    MarketDeckWidget* market;

    //buttons for testing
    QPushButton* b1;
    QPushButton* b2;
    QPushButton* b3;
    QPushButton* b4;
    QPushButton* b5;
    QPushButton* b6;
};
#endif // GAME_WINDOW_H
