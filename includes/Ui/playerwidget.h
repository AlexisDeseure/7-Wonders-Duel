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

class PlayerWidget : public QWidget {
    Q_OBJECT

public:
    explicit PlayerWidget(Player* player, QWidget* parent = nullptr);

private slots:
    void showResources();
    void showWonders();
    void showProgressTokens();
    void onRefreshButtonClicked();

private:
    void setupUi();
    void connectSignals();
    void updatePlayerInfo();
    QDialog* createDialog(const QString& title, const QString& content);

    QLabel* playerName;
    QLabel* playerAIStatus;
    QLabel* playerCityTreasury;
    QLabel* playerCityShields;
    QLabel* playerCityVictoryPoints;
    QPushButton* refreshButton;

    QPushButton* resourcesButton;
    QPushButton* wondersButton;
    QPushButton* progressTokensButton;

    Player* player;
};

#endif // PLAYERWIDGET_H
