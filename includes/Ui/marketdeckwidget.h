#ifndef MARKETDECKWIDGET_H
#define MARKETDECKWIDGET_H
#include "BuildingsLayout.h"

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Instanciator.h"
#include "MarketDeck.h"
#include "DeckElement.h"
#include "cardwidget.h"
#include "PlayerWidget.h"
#include <map>

class MarketDeckWidget : public QWidget
{

//friend class BuildingsLayout;
public:
    MarketDeckWidget(MarketDeck* market,PlayerWidget* p1,PlayerWidget* p2,std::vector<Building*>& a1Cards,std::vector<Building*>& a2Cards,std::vector<Building*>& a3Cards,QWidget* parent = nullptr);
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
    std::map<DeckElement*,CardWidget*>* cardFinder;
    std::vector<DeckElement*> clickables;
    std::vector<Building*>& a1Cards; //toutes les cartes de l'âge 1
    std::vector<Building*>& a2Cards; //toutes les cartes de l'âge 2
    std::vector<Building*>& a3Cards; //toutes les cartes de l'âge 3
    int age;

public slots:
    void updateMarketDeck(DeckElement* card);
    void getCardFromAI(DeckElement* card);

};

#endif // MARKETDECKWIDGET_H
