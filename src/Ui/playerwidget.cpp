#include "PlayerWidget.h"
#include "Player.h"
#include "City.h"
#include "Game.h"
#include <QVBoxLayout>
#include <QString>
#include "Ressource.h"
#include "Building.h"

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
    detailsButton = new QPushButton("Show Details", this); // New details button
    connect(detailsButton, &QPushButton::clicked, this, &PlayerWidget::onDetailsButtonClicked);

    detailsButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");
    buildingsButton = new QPushButton("Show Buildings", this); // New buildings button
    connect(buildingsButton, &QPushButton::clicked, this, &PlayerWidget::onBuildingsButtonClicked);

    buildingsButton->setStyleSheet("QPushButton { background-color: gray; }"
                                   "QPushButton:hover { background-color: lightgray; }");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(playerName);
    layout->addWidget(playerCityTreasury);
    layout->addWidget(playerCityShields);
    layout->addWidget(playerCityVictoryPoints);
    layout->addWidget(refreshButton);
    layout->addWidget(detailsButton); // bouton des details
    layout->addWidget(buildingsButton); // Button to show buildings


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

void PlayerWidget::onDetailsButtonClicked() {
    // Création d'un layout pour organiser les éléments
    QVBoxLayout *layout = new QVBoxLayout;

    QString details = "Resources:\n";
    auto& resources = player->getCity().getRessources();
    for (auto& resource : resources) {
        details += QString::fromStdString(ressourceTypeToString(resource->getType())) + ": ";
        details += QString::number(resource->getAmount()) + "\n";
    }
    details += "\n";

    QLabel *resourcesLabel = new QLabel(details);
    layout->addWidget(resourcesLabel);

    /*
    details = "Buildings:\n";
    auto& buildings = player->getCity().getBuildings();
    for (auto& building : buildings) {
        details += QString::fromStdString(buildingTypeToString(building->getType())) + "\n";
    }
    details += "\n";
*/

//    QLabel *buildingsLabel = new QLabel(details);
  //  layout->addWidget(buildingsLabel);

    details = "Wonders:\n";
    auto& wonders = player->getCity().getWonders();
    QGridLayout* wondersLayout = new QGridLayout;
    wondersLayout->setSpacing(10); // Adjust spacing between widgets

    for (int i = 0; i < 4; ++i) {
        int row = i / 2; // Two items per row
        int col = i % 2;

        QPixmap pixmap(wonders[i]->getImage());
        QLabel* imageLabel = new QLabel;
        imageLabel->setPixmap(pixmap.scaledToWidth(250)); // Scale image to fit width 250 pixels
        imageLabel->setAlignment(Qt::AlignCenter); // Center align image

        // Create a container widget to hold the image and the text label
        QWidget* container = new QWidget;
        QVBoxLayout* containerLayout = new QVBoxLayout(container);
        containerLayout->setContentsMargins(0, 0, 0, 0);
        containerLayout->setSpacing(0);

        // Add the image label to the container
        containerLayout->addWidget(imageLabel);

        // Create a label for the status text
        QLabel* statusLabel = new QLabel(container);
        statusLabel->setAlignment(Qt::AlignRight | Qt::AlignTop);
        statusLabel->setStyleSheet("QLabel { background-color: rgba(0, 0, 0, 128); color: white; padding: 2px; }");

        if (wonders[i]->isBuilt()) {
            statusLabel->setText("Built");
        } else {
            statusLabel->setText("Not Built");
        }

        // Add the status label to the container
        containerLayout->addWidget(statusLabel);
        containerLayout->setAlignment(statusLabel, Qt::AlignRight | Qt::AlignTop);

        wondersLayout->addWidget(container, row, col);
    }
    // Add the nested layout to the main layout of PlayerWidget
    layout->addLayout(wondersLayout);


    // Créer une boîte de message avec un layout personnalisé
    QDialog dialog(this);
    dialog.setWindowTitle("Player Details");
    dialog.setLayout(layout);
    dialog.exec();
}
void PlayerWidget::onBuildingsButtonClicked() {
    QString details = "Buildings:\n";
    auto& buildings = player->getCity().getBuildings();
    for (auto& building : buildings) {
        details += QString::fromStdString(buildingTypeToString(building->getType())) + "\n";
    }

    QMessageBox::information(this, "Buildings", details);
}

