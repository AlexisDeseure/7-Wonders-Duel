#include "marketdeckwidget.h"
#include "cardwidget.h"
#include "BuildingsLayout.h"
#include "Card.h"
#include "Instanciator.h"
#include "PlayerWidget.h"
#include <vector>
#include <QGridLayout>

/* To DO
- vector to check clickables
- refresh clickables vector at each turn
- initialisation test
- catch the deckElement at playerWidget.cpp and marketdeckwidget.cpp (should be OK)
- Add signal and slots to build a wonder
- finish adding all connections, connect p1 and p2 completely
- finish PlayerWidget::switchTurn() (see comments)
- HASHMAP CARDWIDGETS AND DECKELEMENTS TO FIND CARDS FROM A DE
*/

MarketDeckWidget::MarketDeckWidget(MarketDeck* market,PlayerWidget* p1,PlayerWidget* p2,QWidget* parent) : p1(p1), p2(p2), QWidget(parent),market(market) {
    Cardlines = new QVBoxLayout(this);
    generateAge(3);


}

void MarketDeckWidget::updateMarketDeck(){
    this->update();
    //récupérer le DE
    //envoyer signal vers le gamewindow
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
    delete this->Cardlines;

    int width = 115;
    int height = 170;
    QGridLayout* line = new QGridLayout(this);
    // std::vector<std::vector<DeckElement*>>& layout = Instanciator::getInstanciator()->getBuildingsLayout().getAgeWithBuildings(age, buildings); //buildings à rajouter comme var statique
    // DeckElement* building;

    std::vector<std::vector<DeckElement*>>& layout = market->getAllBuildings(); //buildings à rajouter comme var statique
    int cardIndex; //index of the card in the market deck line
    DeckElement* building;
    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 11; j++){
            if (checkCardPos(age,i,j)){

                CardWidget* carteWidget = new CardWidget(this);
                carteWidget->setFixedSize(width,height);

                //Connections : MD and Card
                connect(carteWidget, &CardWidget::sendDefausse, this, &MarketDeckWidget::updateMarketDeck);
                connect(carteWidget, &CardWidget::sendAchat, this, &MarketDeckWidget::updateMarketDeck);

                //Connections : players and cards
                connect(carteWidget, &CardWidget::sendDefausse,p1,&PlayerWidget::recieveDefausse);
                connect(carteWidget, &CardWidget::sendAchat,p1,&PlayerWidget::recieveAchat);
                connect(carteWidget, &CardWidget::sendDefausse,p2,&PlayerWidget::recieveDefausse);
                connect(carteWidget, &CardWidget::sendAchat,p2,&PlayerWidget::recieveAchat);
                //add wonder building connection


                // building = layout[i][j];
                // CardWidget* carteWidget = new CardWidget(building,this);
                // carteWidget->setFixedSize(100,100);
                line->addWidget(carteWidget,i,j,1,1);
            }
        }
    }
    // switch(age){
    // case 1: //10 cases de long, 5 lignes
    //     for(int i = 0; i < 5; i++){
    //         cardIndex = 0;
    //         QGridLayout* line = new QGridLayout(this);
    //         for(int j = 0; j < 11; j++){
    //             if (checkCardPos(age,i,j)){
    //                 building = layout[i][cardIndex++];
    //                 CardWidget* carteWidget = new CardWidget(building,this);
    //                 carteWidget->setFixedSize(100,100);
    //                 line->addWidget(carteWidget,i,j,1,1);
    //             }
    //         }
    //         Cardlines->addLayout(line);
    //     }
    //     return;
    // case 2: //idem que 1 mais à l'envers
    //     for(int i = 0; i < 5; i++){
    //         cardIndex = 0;
    //         QGridLayout* line = new QGridLayout(this);
    //         for(int j = 0; j < 11; j++){
    //             if (checkCardPos(age,i,j)){
    //                 building = layout[i][cardIndex++];
    //                 CardWidget* carteWidget = new CardWidget(building,this);
    //                 carteWidget->setFixedSize(100,100);
    //                 line->addWidget(carteWidget,i,10-j,1,1);
    //             }
    //         }
    //         Cardlines->addLayout(line);
    //     }
    //     return;
    // case 3: //7*7
    //     for(int i = 0; i < 7; i++){
    //         cardIndex = 0;            
    //         QGridLayout* line = new QGridLayout(this);
    //         for(int j = 0; j < 7; j++){
    //             if (checkCardPos(age,i,j)){
    //                 building = layout[i][cardIndex++];
    //                 CardWidget* carteWidget = new CardWidget(building,this);
    //                 carteWidget->setFixedSize(100,100);
    //                 line->addWidget(carteWidget,i,j,1,1);
    //             }
    //         }
    //         Cardlines->addLayout(line);
    //     }
    //     return;
    // }
}


