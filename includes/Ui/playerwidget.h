#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <vector>
#include "Player.h"
#include "Game.h"



class PlayerWidget : public QWidget{
public:
    PlayerWidget(Game* g,MarketDeck* md,Player* p, QWidget *parent = nullptr);
    ~PlayerWidget() = default;

    Player* getplayer() const{return player;};

    void updatePlayerInfo();

signals:
    void onRefreshButtonClicked();
    void endTurn();

public slots:
    void recieveAchat(DeckElement* card);
    void recieveDefausse(DeckElement* card);
    void switchTurn();

private:
    PlayerWidget(const PlayerWidget& widget) = delete;
    Player* player;
    bool playing;
    Game* g;
    MarketDeck* md;

    QLabel* playerName;
    QLabel* playerAIStatus;
    QLabel* playerCityTreasury;
    QLabel* playerCityShields;
    QLabel* playerCityVictoryPoints;

    QVBoxLayout* layout;
    QPushButton* refreshButton;

};

#endif // PLAYERWIDGET_H
