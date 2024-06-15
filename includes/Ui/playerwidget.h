#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <vector>
#include "Player.h"
#include "Game.h"

/*
Make fake widgets to show when selecting a card from another player ?
Also considering switching player widgets between each turn
*/

class PlayerWidget : public QWidget{
    Q_OBJECT
public:
    PlayerWidget(Game* g, Player* p, QWidget *parent = nullptr);
    ~PlayerWidget() = default;

    Player* getplayer() const{return player;};

    void updatePlayerInfo();

signals:
    void endTurn();
    void aiCard(DeckElement* card);

public slots:
    // void recieveAchat(DeckElement* card);
    // void recieveDefausse(DeckElement* card);
    // void switchTurn();
    void onRefreshButtonClicked();
    void onDetailsButtonClicked();
    void onBuildingsButtonClicked();  // New slot for buildings button



private:
    PlayerWidget(const PlayerWidget& widget) = delete;
    Player* player;
    bool playing;
    Game* g;
    MarketDeck* md;

    QLabel* playerName;
    QLabel* playerCityTreasury;
    QLabel* playerCityShields;
    QLabel* playerCityVictoryPoints;

    QVBoxLayout* layout;
    QPushButton* refreshButton;
    QPushButton* detailsButton; // bouton qui montre les details
    QPushButton* buildingsButton; // bouton qui montre les details

};

#endif // PLAYERWIDGET_H
