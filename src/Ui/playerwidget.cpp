#include "PlayerWidget.h"
#include "Player.h"
#include
#include <QVBoxLayout>
#include <QString>

PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(getplayer()->getCity()->getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    refreshButton = new QPushButton("Refresh", this);
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);

    QVBoxLayout layout = new QVBoxLayout(this);
    layout->addWidget(playerName);
    layout->addWidget(playerAIStatus);
    layout->addWidget(playerCityTreasury);
    layout->addWidget(playerCityShields);
    layout->addWidget(playerCityVictoryPoints);
    layout->addWidget(refreshButton);
}

void PlayerWidget::updatePlayerInfo() {
    playerName->setText(QString::fromStdString(player->getName()));
    playerAIStatus->setText(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())));
    playerCityTreasury->setText(QString("Treasury: ") + QString::number(player->getCity().getTreasury()));
    playerCityShields->setText(QString("Shields: ") + QString::number(player->getCity().getShields()));
    playerCityVictoryPoints->setText(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()));
}

void PlayerWidget::onRefreshButtonClicked() {
    updatePlayerInfo();
}
