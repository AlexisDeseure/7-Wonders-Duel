#include "game_window.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("7 Wonders");
    grid = new QGridLayout(this);

    player1 = new PlayerWidget(this);
    player2 = new PlayerWidget(this);


    market = new MarketDeckWidget(this);
    military_deck = new MilitaryDeck(this);


    //grid setup: maybe add a static value for grids and cols, so you can do fractions ?
    //4 rows, 5 columns
    grid->addWidget(military_deck,0,0,1,1);//row 0, column 0
    grid->addWidget(market,0,1,1,3); //row 0, column 1-3
    grid->addWidget(player1,0,4,1,1); //row 0, column 0
    //grid->addWidget(player2,0,4,1,1); //row 0, column 4

    //Colors for testing at the moment
    player1->setStyleSheet("background-color: blue; color: white;");
    player2->setStyleSheet("background-color: red; color: white;");
    //military_deck->setStyleSheet("background-color: pink; color: white;");
    market->setStyleSheet("background-color : orange; color: white");

    //button testing
    b1 = new QPushButton("player1",player1);
    b2 = new QPushButton("player2",player2);
    b4 = new QPushButton("market",market);
}

GameWindow::~GameWindow()
{
    delete(player1);
    delete(player2);
    delete(military_deck);
    delete(market);
    delete(grid);
}
