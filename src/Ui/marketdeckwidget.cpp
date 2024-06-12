#include "marketdeckwidget.h"
#include "cardwidget.h"
#include "Card.h"
MarketDeckWidget::MarketDeckWidget(QWidget* parent) : QWidget(parent) {
    Cardlines = new QVBoxLayout(this);
    generateAge(3);
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
    Cardlines = new QVBoxLayout(this);
    int width = 115;
    int height = 170;
    switch(age){
    case 1: //10 cases de long, 5 lignes
        for(int i = 0; i < 5; i++){
            QGridLayout* line = new QGridLayout(this);
            for(int j = 0; j < 11; j++){
                if (checkCardPos(age,i,j)){
                    CardWidget* carteWidget = new CardWidget(this);
                    carteWidget->setFixedSize(width,height);
                    line->addWidget(carteWidget,i,j,1,1);
                }
            }
            Cardlines->addLayout(line);
        }
        return;
    case 2: //idem que 1 mais à l'envers
        for(int i = 0; i < 5; i++){
            QGridLayout* line = new QGridLayout(this);
            for(int j = 0; j < 11; j++){
                if (checkCardPos(age,i,j)){
                    CardWidget* carteWidget = new CardWidget(this);
                    carteWidget->setFixedSize(width,height);
                    line->addWidget(carteWidget,i,j,1,1);
                }
            }
            Cardlines->addLayout(line);
        }
        return;
    case 3: //7*7
        for(int i = 0; i < 7; i++){
            QGridLayout* line = new QGridLayout(this);
            for(int j = 0; j < 7; j++){
                if (checkCardPos(age,i,j)){
                    CardWidget* carteWidget = new CardWidget(this);
                    carteWidget->setFixedSize(width,height);
                    line->addWidget(carteWidget,i,j,1,1);
                }
            }
            Cardlines->addLayout(line);
        }
        return;
    }
}
