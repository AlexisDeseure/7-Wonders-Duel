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
    void generateAge(int i);
    bool checkCardPos(int age, int i, int j)const;

private:
    MarketDeckWidget(const MarketDeckWidget& widget) = delete;
    //const MarketDeck* market_deck; //à rajouter dans le constructeur
    QVBoxLayout* Cardlines;
};

#endif // MARKETDECKWIDGET_H
