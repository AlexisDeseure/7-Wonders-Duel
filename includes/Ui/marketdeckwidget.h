#ifndef MARKETDECKWIDGET_H
#define MARKETDECKWIDGET_H
#include "BuildingsLayout.h"

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Instanciator.h"
#include "MarketDeck.h"
#include "PlayerWidget.h"

class MarketDeckWidget : public QWidget
{

//friend class BuildingsLayout;
public:
    MarketDeckWidget(MarketDeck* market,PlayerWidget* p1,PlayerWidget* p2,QWidget* parent = nullptr);
    ~MarketDeckWidget() = default;
    void generateAge(int i);
    bool checkCardPos(int age, int i, int j)const;

private:
    MarketDeckWidget(const MarketDeckWidget& widget) = delete;
    //const MarketDeck* market_deck; //à rajouter dans le constructeur
    QVBoxLayout* Cardlines;
    MarketDeck* market;
    PlayerWidget* p1; //having both players in the marketwidget allows for streamlined communication between all objects, marketwidget is a station for all classes
    PlayerWidget* p2;

public slots:
    void updateMarketDeck();

};

#endif // MARKETDECKWIDGET_H
