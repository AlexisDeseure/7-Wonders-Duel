#ifndef MARKETDECKWIDGET_H
#define MARKETDECKWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

class MarketDeckWidget : public QWidget
{
public:
    MarketDeckWidget(QWidget* parent = nullptr);
    ~MarketDeckWidget() = default;

private:
    MarketDeckWidget(const MarketDeckWidget& widget) = delete;
    //const MarketDeck* market_deck; //à rajouter dans le constructeur
};

#endif // MARKETDECKWIDGET_H
