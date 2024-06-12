#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <vector>
#include "Player.h"

/*
Make fake widgets to show when selecting a card from another player ?
Also considering switching player widgets between each turn
*/

class PlayerWidget : public QWidget{
public:
    PlayerWidget(Player* p, QWidget *parent = nullptr);
    ~PlayerWidget() = default;

    Player* getplayer() const{return player;};

signals:
    void onRefreshButtonClicked();
private:
    PlayerWidget(const PlayerWidget& widget) = delete;
    Player* player;

    QLabel* playerName;
    QLabel* playerAIStatus;
    QLabel* playerCityTreasury;
    QLabel* playerCityShields;
    QLabel* playerCityVictoryPoints;

    QVBoxLayout* layout;
    QPushButton* refreshButton;

};

#endif // PLAYERWIDGET_H
