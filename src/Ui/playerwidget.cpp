#include "PlayerWidget.h"
#include "Player.h"
#include "City.h"
#include "Game.h"
#include <QVBoxLayout>
#include <QString>

PlayerWidget::PlayerWidget(Game* g, Player* p, QWidget* parent) : QWidget(parent), player(p) {

    playerName = new QLabel(QString::fromStdString(player->getName()), this);

    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(getplayer()->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    setStyleSheet("background-color: rgba(50, 50, 50, 0.5); "
                  "color: white; "
                  "border-radius: 10px; "
                  "padding: 10px;");
    // playerName->setStyleSheet("background: transparent;");
    // playerCityTreasury->setStyleSheet("background: transparent;");
    // playerCityShields->setStyleSheet("background: transparent;");
    // playerCityVictoryPoints->setStyleSheet("background: transparent;");



    refreshButton = new QPushButton("Refresh", this);
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);

    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(playerName);
    layout->addWidget(playerCityTreasury);
    layout->addWidget(playerCityShields);
    layout->addWidget(playerCityVictoryPoints);
    layout->addWidget(refreshButton);
}

void PlayerWidget::updatePlayerInfo() {
    playerName->setText(QString::fromStdString(player->getName()));
    playerCityTreasury->setText(QString("Treasury: ") + QString::number(player->getCity().getTreasury()));
    playerCityShields->setText(QString("Shields: ") + QString::number(player->getCity().getShields()));
    playerCityVictoryPoints->setText(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()));
}

void PlayerWidget::onRefreshButtonClicked() {
    updatePlayerInfo();
}
