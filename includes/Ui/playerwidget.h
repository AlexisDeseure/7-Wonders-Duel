#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include "Player.h"

class PlayerWidget : public QWidget {
    Q_OBJECT

public:
    explicit PlayerWidget(Player* player, QWidget *parent = nullptr);
    void updatePlayerInfo();

private:
    Player* m_player;
    QLabel* playerName;
    QLabel* playerAIStatus;
    QLabel* playerCityTreasury;
    QLabel* playerCityShields;
    QLabel* playerCityVictoryPoints;
    QPushButton* refreshButton;

private slots:
    void onRefreshButtonClicked();
};

#endif // PLAYERWIDGET_H
