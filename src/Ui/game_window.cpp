#include "game_window.h"
#include "PlayerWidget.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Building.h"
#include "DeckElement.h"
#include "cardwidget.h"


GameWindow::GameWindow(Game* game, QWidget *parent)
    : QMainWindow(parent), game(game)
{

    setWindowTitle("7 Wonders");
    setStyleSheet("GameWindow{"
                  "border-image: url(../../../data/image/backgrounds/gameplayingbackground.jpg) 0 0 0 0 stretch stretch;"
                  "background-repeat: no-repeat;"
                  "background-position: center;"
                  "}");
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    grid = new QGridLayout(centralWidget);

    player1 = new PlayerWidget(game, &game->getTurnPlayer(),centralWidget);
    player2 = new PlayerWidget(game, &game->getOtherPlayer(),centralWidget);
    market = new MarketDeckWidget(game, centralWidget);


    // connect(player1,&PlayerWidget::endTurn,player2,&PlayerWidget::switchTurn);
    // connect(player2,&PlayerWidget::endTurn,player1,&PlayerWidget::switchTurn);


    // military_deck = new MilitaryDeck(centralWidget);


    // //grid setup: maybe add a static value for grids and cols, so you can do fractions ?
    // //4 rows, 5 columns
    // grid->addWidget(military_deck,0,0,1,1);//row 0, column 0
    // grid->addWidget(market,0,1,1,3); //row 0, column 1-3
    // grid->addWidget(player1,0,4,1,1); //row 0, column 0
    // //grid->addWidget(player2,0,4,1,1); //row 0, column 4
    //grid setup: maybe add a static value for grids and cols, so you can do fractions ?
    //4 rows, 5 columns
    grid->addWidget(player1,0,0,4,1); //row 0-4, column 0
    grid->addWidget(player2,0,6,4,1); //row 0-4, column 4
    grid->addWidget(market,0,1,4,5); //row 0-2, column 1-3
    //grid->addWidget(military_deck,4,1,1,4);//row 3, column 1-3

    //Colors for testing at the moment

    // player1->setStyleSheet("background-color: rgba(50, 50, 50, 0.5); "
    //                        "color: white; "
    //                        "border-radius: 10px; "
    //                        "padding: 10px;");

    // player2->setStyleSheet("background-color: rgba(50, 50, 50, 0.5); "
    //                        "color: white; "
    //                        "border-radius: 10px; "
    //                        "padding: 10px;");

    // market->setStyleSheet("background-color: rgba(50, 50, 50, 0.5); "
    //                       "color: white; "
    //                       "border-radius: 10px; "
    //                       "padding: 10px;");
    //military_deck->setStyleSheet("background-color: pink; color: white;");

    //button testing
    // b1 = new QPushButton("player1",player1);
    // b2 = new QPushButton("player2",player2);
    // b4 = new QPushButton("market",market);

}

void GameWindow::refreshEverything(){
    player1->updatePlayerInfo();
    player2->updatePlayerInfo();

    std::vector<DeckElement*> buildings = game->getBoard().getMarketDeck().getFirstBuildings();

    for (auto& line : market->printed_cards){
        for (auto& card : line){
            auto it = std::find(buildings.begin(), buildings.end(), card->getCard());
            if (it != buildings.end()){
                card->makeClickable();
            }
        }
    }
};

GameWindow::~GameWindow()
{
    delete(player1);
    delete(player2);
    delete(military_deck);
    delete(market);
    delete(grid);
}
