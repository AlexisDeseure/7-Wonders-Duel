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
#include "Board.h"
#include "MarketDeck.h"





class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    //GameWindow( MarketDeck* marketDeck,QWidget *parent = nullptr);
    GameWindow(Game* game, QWidget *parent = nullptr);
    ~GameWindow();

    PlayerWidget& getplayer1()const{return *player1;};
    PlayerWidget& getplayer2()const{return *player2;};
    void updateAge(int age){
        market->generateAge(age);}

    void refreshAll(){
        player1->updatePlayerInfo();
        player2->updatePlayerInfo();
        // qDebug() << "refresh";
        std::vector<DeckElement*> buildings = game->getBoard().getMarketDeck().getFirstBuildings();
        for (auto& line : market->printed_cards){
            for (auto& card : line){
                auto it = std::find(buildings.begin(), buildings.end(), card->getCard());
                if (it != buildings.end()){
                    // qDebug() << "true";
                    card->makeClickable();
                }
            }
        }
    };

private:
    //Grid
    QGridLayout* grid;

    //Widgets
    PlayerWidget *player1;
    PlayerWidget *player2;
    MilitaryDeck* military_deck;
    MarketDeckWidget* market;
    Game* game;


};
#endif // GAME_WINDOW_H
