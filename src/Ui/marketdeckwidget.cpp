#include "marketdeckwidget.h"
#include "cardwidget.h"
#include "BuildingsLayout.h"
#include "Card.h"
#include "Instanciator.h"
#include "Board.h"
#include <vector>

std::vector<Building*> buildings; //à rajouter dans le main

MarketDeckWidget::MarketDeckWidget(Game* g,QWidget* parent) :  QWidget(parent), game(g), Cardlines(nullptr){
    cardFinder = new std::map<DeckElement*,CardWidget*>;
    clickables = game->getBoard().getMarketDeck().getFirstBuildings();

    //Connections: AI actions towards MDW
    // connect(p1,&PlayerWidget::aiCard,this,&MarketDeckWidget::getCardFromAI);
    // connect(p2,&PlayerWidget::aiCard,this,&MarketDeckWidget::getCardFromAI);
}




bool MarketDeckWidget::checkCardPos(int age,int i,int j)const{
    switch(age){
    case 1:
        return (((i==0)&&(j==4 || j==6))||((i==1)&&(j==3 || j==5 || j==7))||((i==2)&&(j==2||j==4||j==6||j==8))||((i==3)&&(j==1||j==3||j==5||j==7||j==9))||((i==4)&&(j==0||j==2||j==4||j==6||j==8||j==10)));
    case 2:
        return (((i==0)&&(j==0||j==2||j==4||j==6||j==8||j==10))||((i==1)&&(j==1||j==3||j==5||j==7||j==9))||((i==2)&&(j==2||j==4||j==6||j==8))||((i==3)&&(j==3||j==5||j==7))||((i==4)&&(j==4||j==6)));
    case 3:
        return (((i==0)&&(j==2||j==4))||((i==1)&&(j==1||j==1||j==3||j==5))||((i==2)&&(j==0||j==2||j==4||j==6))||((i==3)&&(j==1||j==5))||((i==4)&&(j==0||j==2||j==4||j==6))||((i==5)&&(j==1||j==3||j==5))||((i==6)&&(j==2||j==4)));
    }
}

void MarketDeckWidget::generateAge(int age){

    if (Cardlines != nullptr){
        delete this->Cardlines;
    }

    Cardlines = new QVBoxLayout(this);
    int width = 115;
    int height = 170;

    int compteur;
    // std::vector<std::vector<DeckElement*>>& layout = Instanciator::getInstanciator()->getBuildingsLayout().getAgeWithBuildings(age, buildings); //buildings à rajouter comme var statique
    // DeckElement* building;
    std::vector<std::vector<DeckElement*>>& layout = game->getBoard().getMarketDeck().getAllBuildings(); //buildings à rajouter comme var statique
    printed_cards = std::vector<std::vector<CardWidget*>>();

    switch(age){
    case 1:
        for(int i = 0; i < 5; i++){
            QGridLayout* line = new QGridLayout(this);
            compteur = 0;
            std::vector<CardWidget*> line_cards;
            for(int j = 0; j < 11; j++){
                if (checkCardPos(age,i,j)){
                    CardWidget* carteWidget = new CardWidget(layout[4-i][compteur], this);
                    qDebug() << "carte "<<carteWidget->getCard()->getBuilding()->getName();
                    carteWidget->setFixedSize(width,height);
                    line_cards.push_back(carteWidget);
                    // building = layout[i][j];
                    // CardWidget* carteWidget = new CardWidget(building,this);
                    // carteWidget->setFixedSize(100,100);
                    line->addWidget(carteWidget,i,j,1,1);
                    compteur++;
                }
            }
            printed_cards.push_back(line_cards);
            Cardlines->addLayout(line);
        }
        return;
    case 2:
        for(int i = 0; i < 5; i++){
            QGridLayout* line = new QGridLayout(this);
            compteur = 0;
            std::vector<CardWidget*> line_cards;
            for(int j = 0; j < 11; j++){
                if (checkCardPos(age,i,j)){
                    CardWidget* carteWidget = new CardWidget(layout[i][compteur], this);
                    carteWidget->setFixedSize(width,height);
                    line_cards.push_back(carteWidget);
                    // building = layout[i][j];
                    // CardWidget* carteWidget = new CardWidget(building,this);
                    // carteWidget->setFixedSize(100,100);
                    line->addWidget(carteWidget,i,j,1,1);
                    compteur++;
                }
            }
            printed_cards.push_back(line_cards);
            Cardlines->addLayout(line);
        }
        return;
    case 3:
        for(int i = 0; i < 7; i++){
            QGridLayout* line = new QGridLayout(this);
            compteur = 0;
            std::vector<CardWidget*> line_cards;
            for(int j = 0; j < 7; j++){
                if (checkCardPos(age,i,j)){
                    qDebug() << "game : " << layout[i].size();
                    CardWidget* carteWidget = new CardWidget(layout[i][compteur], this);
                    carteWidget->setFixedSize(width,height);
                    line_cards.push_back(carteWidget);
                    // building = layout[i][j];
                    // CardWidget* carteWidget = new CardWidget(building,this);
                    // carteWidget->setFixedSize(100,100);
                    line->addWidget(carteWidget,i,j,1,1);
                }
            }
            printed_cards.push_back(line_cards);
            Cardlines->addLayout(line);
        }
        return;

    }

    // switch(age){
    // case 1: //10 cases de long, 5 lignes
    //     for(int i = 0; i < 5; i++){
    //         QGridLayout* line = new QGridLayout(this);
    //         for(int j = 0; j < 11; j++){
    //             if (checkCardPos(age,i,j)){

    //                 CardWidget* carteWidget = new CardWidget(this);
    //                 carteWidget->setFixedSize(width,height);
    //                 // building = layout[i][j];
    //                 // CardWidget* carteWidget = new CardWidget(building,this);
    //                 // carteWidget->setFixedSize(100,100);
    //                 line->addWidget(carteWidget,i,j,1,1);
    //             }
    //         }
    //         Cardlines->addLayout(line);
    //     }
    //     return;
    // case 2: //idem que 1 mais à l'envers
    //     for(int i = 0; i < 5; i++){
    //         QGridLayout* line = new QGridLayout(this);
    //         for(int j = 0; j < 11; j++){
    //             if (checkCardPos(age,i,j)){
    //                 CardWidget* carteWidget = new CardWidget(this);
    //                 carteWidget->setFixedSize(width,height);
    //                 // building = layout[i][j];
    //                 // CardWidget* carteWidget = new CardWidget(building,this);
    //                 // carteWidget->setFixedSize(100,100);
    //                 line->addWidget(carteWidget,i,j,1,1);
    //             }
    //         }
    //         Cardlines->addLayout(line);
    //     }
    //     return;
    // case 3: //7*7
    //     for(int i = 0; i < 7; i++){
    //         QGridLayout* line = new QGridLayout(this);
    //         for(int j = 0; j < 7; j++){
    //             if (checkCardPos(age,i,j)){
    //                 CardWidget* carteWidget = new CardWidget(this);
    //                 carteWidget->setFixedSize(width,height);
    //                 // building = layout[i][j];
    //                 // CardWidget* carteWidget = new CardWidget(building,this);
    //                 // carteWidget->setFixedSize(100,100);
    //                 line->addWidget(carteWidget,i,j,1,1);
    //             }
    //         }
    //         Cardlines->addLayout(line);
    //     }
    //     return;
    // }
}
