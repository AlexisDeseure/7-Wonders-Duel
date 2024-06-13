#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QString>

PlayerWidget::PlayerWidget(Player* player, QWidget *parent) : QWidget(parent), m_player(player) {
    playerName = new QLabel(QString::fromStdString(m_player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(m_player->getAiLevel())), this);
    //playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(m_player->getCity().getTreasury()), this);
    //playerCityShields = new QLabel(QString("Shields: ") + QString::number(m_player->getCity().getShields()), this);
    //playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(m_player->getCity().getVictoryPoints()), this);
    
    refreshButton = new QPushButton("Refresh", this);
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(playerName);
    layout->addWidget(playerAIStatus);
    layout->addWidget(playerCityTreasury);
    layout->addWidget(playerCityShields);
    layout->addWidget(playerCityVictoryPoints);
    layout->addWidget(refreshButton);
}

void PlayerWidget::updatePlayerInfo() {
    playerName->setText(QString::fromStdString(m_player->getName()));
    playerAIStatus->setText(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(m_player->getAiLevel())));
    //playerCityTreasury->setText(QString("Treasury: ") + QString::number(m_player->getCity().getTreasury()));
    //playerCityShields->setText(QString("Shields: ") + QString::number(m_player->getCity().getShields()));
    //playerCityVictoryPoints->setText(QString("Victory Points: ") + QString::number(m_player->getCity().getVictoryPoints()));
}

void PlayerWidget::onRefreshButtonClicked() {
    updatePlayerInfo();
}


/*
Make fake widgets to show when selecting a card from another player ?
Also considering switching player widgets between each turn


class PlayerWidget : public QWidget{
public:
    PlayerWidget(QWidget *parent = nullptr);
    ~PlayerWidget() = default;

    //Player& getplayer const(){return player;};
private:
    PlayerWidget(const PlayerWidget& widget) = delete;
    //Player player;
    //vector<BuildingWidgets*> buildings;
    //std::vector<ProgressTokenWidgets*> progress_Tokens;
    //std::vector<RessourceWidgets> ressources;
    //MoneyWidget *money;

};

#endif // PLAYERWIDGET_H
*/
