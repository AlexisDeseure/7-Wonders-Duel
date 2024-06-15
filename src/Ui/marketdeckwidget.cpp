#include "marketdeckwidget.h"
#include "cardwidget.h"
#include "BuildingsLayout.h"
#include "Card.h"
#include "Instanciator.h"
#include "PlayerWidget.h"
#include <vector>
#include <QGridLayout>

/* To DO
- initialisation test
- catch the deckElement at playerWidget.cpp and marketdeckwidget.cpp (should be OK)
- Add signal and slots to build a wonder
- finish PlayerWidget::switchTurn() (see comments)
*/

MarketDeckWidget::MarketDeckWidget(MarketDeck* market,PlayerWidget* p1,PlayerWidget* p2,std::vector<Building*>& a1Cards,std::vector<Building*>& a2Cards,std::vector<Building*>& a3Cards,QWidget* parent) : p1(p1), p2(p2), QWidget(parent),market(market),age(1), a1Cards(a1Cards), a2Cards(a2Cards), a3Cards(a3Cards){
    cardFinder = new std::map<DeckElement*,CardWidget*>;
    clickables = market->getFirstBuildings();
    generateAge(1);

    //Connections: AI actions towards MDW
    connect(p1,&PlayerWidget::aiCard,this,&MarketDeckWidget::getCardFromAI);
    connect(p2,&PlayerWidget::aiCard,this,&MarketDeckWidget::getCardFromAI);


}

void MarketDeckWidget::updateMarketDeck(DeckElement* card){ //maybe DeckElement isn't necessary
    clickables = market->getFirstBuildings();
    if(clickables.empty()){
        generateAge(++age);
        updateMarketDeck(nullptr);
    }
    else{
        for(auto DE : clickables){
            CardWidget* widget;
            auto it = cardFinder->find(DE);
            if (it != cardFinder->end()) {
                widget = it->second;
                widget->makeClickable();
                update();
            }
        }
    }
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
    market->advanceAge(age,a1Cards);
    std::vector<std::vector<DeckElement*>> layout;//buildings en position i,j
    int cardIndex; //index of the card in the market deck line
    DeckElement* building;
    CardWidget* carteWidget;
    // for(int i = 0; i < 5; i++){

    //     for(int j = 0; j < 11; j++){
    //         if (checkCardPos(age,i,j)){

    //             CardWidget* carteWidget = new CardWidget(this);
    //             carteWidget->setFixedSize(width,height);

    //             //Connections : MD and Card
    //             connect(carteWidget, &CardWidget::sendDefausse, this, &MarketDeckWidget::updateMarketDeck);
    //             connect(carteWidget, &CardWidget::sendAchat, this, &MarketDeckWidget::updateMarketDeck);

    //             //Connections : players and cards
    //             connect(carteWidget, &CardWidget::sendDefausse,p1,&PlayerWidget::recieveDefausse);
    //             connect(carteWidget, &CardWidget::sendAchat,p1,&PlayerWidget::recieveAchat);
    //             connect(carteWidget, &CardWidget::sendDefausse,p2,&PlayerWidget::recieveDefausse);
    //             connect(carteWidget, &CardWidget::sendAchat,p2,&PlayerWidget::recieveAchat);
    //             //add wonder building connection


    //             // building = layout[i][j];
    //             //CardWidget* carteWidget = new CardWidget(building,this);
    //             cardFinder->insert({building,carteWidget});
    //             // carteWidget->setFixedSize(100,100);
    //             line->addWidget(carteWidget,i,j,1,1);
    //         }
    //     }
    // }
    switch(age){
    case 1: //10 cases de long, 5 lignes
        market->advanceAge(age,a1Cards);
        layout = market->getAllBuildings();
        for(int i = 0; i < 5; i++){
            cardIndex = 0;
            QGridLayout* line = new QGridLayout(this);
            for(int j = 0; j < 11; j++){
                if (checkCardPos(age,i,j)){
                    building = layout[i][cardIndex++];
                    carteWidget = new CardWidget(building,this);
                    carteWidget->setFixedSize(100,100);

                    //Connections : MD and Card
                    connect(carteWidget, &CardWidget::sendDefausse, this, &MarketDeckWidget::updateMarketDeck);
                    connect(carteWidget, &CardWidget::sendAchat, this, &MarketDeckWidget::updateMarketDeck);

                    //Connections : players and cards
                    connect(carteWidget, &CardWidget::sendDefausse,p1,&PlayerWidget::recieveDefausse);
                    connect(carteWidget, &CardWidget::sendAchat,p1,&PlayerWidget::recieveAchat);
                    connect(carteWidget, &CardWidget::sendDefausse,p2,&PlayerWidget::recieveDefausse);
                    connect(carteWidget, &CardWidget::sendAchat,p2,&PlayerWidget::recieveAchat);
                    //add wonder building connection

                    cardFinder->insert({building,carteWidget});
                    line->addWidget(carteWidget,i,j,1,1);
                }
            }
        }
        return;
    case 2: //idem que 1 mais à l'envers
        market->advanceAge(age,a2Cards);
        layout = market->getAllBuildings();
        for(int i = 0; i < 5; i++){
            cardIndex = 0;
            QGridLayout* line = new QGridLayout(this);
            for(int j = 0; j < 11; j++){
                if (checkCardPos(age,i,j)){
                    building = layout[i][cardIndex++];
                    carteWidget = new CardWidget(building,this);
                    carteWidget->setFixedSize(100,100);

                    //Connections : MD and Card
                    connect(carteWidget, &CardWidget::sendDefausse, this, &MarketDeckWidget::updateMarketDeck);
                    connect(carteWidget, &CardWidget::sendAchat, this, &MarketDeckWidget::updateMarketDeck);

                    //Connections : players and cards
                    connect(carteWidget, &CardWidget::sendDefausse,p1,&PlayerWidget::recieveDefausse);
                    connect(carteWidget, &CardWidget::sendAchat,p1,&PlayerWidget::recieveAchat);
                    connect(carteWidget, &CardWidget::sendDefausse,p2,&PlayerWidget::recieveDefausse);
                    connect(carteWidget, &CardWidget::sendAchat,p2,&PlayerWidget::recieveAchat);
                    //add wonder building connection

                    cardFinder->insert({building,carteWidget});
                    line->addWidget(carteWidget,i,j,1,1);
                }
            }
        }
        return;
    case 3: //7*7
        market->advanceAge(age,a3Cards);
        layout = market->getAllBuildings();
        for(int i = 0; i < 7; i++){
            cardIndex = 0;
            QGridLayout* line = new QGridLayout(this);
            for(int j = 0; j < 7; j++){
                if (checkCardPos(age,i,j)){
                    building = layout[i][cardIndex++];
                    carteWidget = new CardWidget(building,this);
                    carteWidget->setFixedSize(100,100);

                    //Connections : MD and Card
                    connect(carteWidget, &CardWidget::sendDefausse, this, &MarketDeckWidget::updateMarketDeck);
                    connect(carteWidget, &CardWidget::sendAchat, this, &MarketDeckWidget::updateMarketDeck);

                    //Connections : players and cards
                    connect(carteWidget, &CardWidget::sendDefausse,p1,&PlayerWidget::recieveDefausse);
                    connect(carteWidget, &CardWidget::sendAchat,p1,&PlayerWidget::recieveAchat);
                    connect(carteWidget, &CardWidget::sendDefausse,p2,&PlayerWidget::recieveDefausse);
                    connect(carteWidget, &CardWidget::sendAchat,p2,&PlayerWidget::recieveAchat);
                    //add wonder building connection

                    cardFinder->insert({building,carteWidget});
                    line->addWidget(carteWidget,i,j,1,1);
                }
            }
        }
    }
    updateMarketDeck(nullptr);
    return;
}

void MarketDeckWidget::getCardFromAI(DeckElement* card){//deletes a cardwidget from a deckelement recieved by the AI
    CardWidget* widget;
    auto it = cardFinder->find(card);
    if (it != cardFinder->end()) {
        widget = it->second;
        widget->close();
        delete widget;
        updateMarketDeck(nullptr);
    }
    //else throw an error ?

}


