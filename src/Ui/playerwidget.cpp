#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
        //ss << r->ressourceTypeToString() << "\n";
      //  ss << r->print(); << "\n";
   // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
        //ss << symbol->getName() << "\n";
      //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
























































































































#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
#include "PlayerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "Player.h"
#include "City.h"
#include <QString>


PlayerWidget::PlayerWidget(Player* p, QWidget* parent) : QWidget(parent), player(p) {
    setupUi();
    connectSignals();
    updatePlayerInfo();
}

void PlayerWidget::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(player->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");

    refreshButton = new QPushButton("Refresh", this);
    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    mainLayout->addWidget(playerName);
    mainLayout->addWidget(playerAIStatus);
    mainLayout->addWidget(playerCityTreasury);
    mainLayout->addWidget(playerCityShields);
    mainLayout->addWidget(playerCityVictoryPoints);
    mainLayout->addWidget(refreshButton);

    //  buttons for resources, wonders, and progress tokens
    resourcesButton = new QPushButton(tr("Afficher les ressources"), this);
    wondersButton = new QPushButton(tr("Afficher les merveilles"), this);
    progressTokensButton = new QPushButton(tr("Afficher les jetons de progrès"), this);

    mainLayout->addWidget(resourcesButton);
    mainLayout->addWidget(wondersButton);
    mainLayout->addWidget(progressTokensButton);

    setLayout(mainLayout);
}

void PlayerWidget::connectSignals() {
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);
    connect(resourcesButton, &QPushButton::clicked, this, &PlayerWidget::showResources);
    connect(wondersButton, &QPushButton::clicked, this, &PlayerWidget::showWonders);
    connect(progressTokensButton, &QPushButton::clicked, this, &PlayerWidget::showProgressTokens);
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

void PlayerWidget::showResources() {
    std::stringstream ss;
    ss << "Ressources :\n";
    //for (auto& r : player->getCity().getRessources()) {
    //ss << r->ressourceTypeToString() << "\n";
    //  ss << r->print(); << "\n";
    // }
    QDialog* dialog = createDialog("Ressources", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showWonders() {
    std::stringstream ss;
    ss << "Merveilles :\n";
    for (auto& wonder : player->getCity().getWonders()) {
        ss << wonder->getName() << "\n";
    }
    QDialog* dialog = createDialog("Merveilles", QString::fromStdString(ss.str()));
    dialog->exec();
}

void PlayerWidget::showProgressTokens() {
    std::stringstream ss;
    ss << "Jetons de progrès :\n";
    //for (auto& symbol : player->getCity().getScientificSymbols()) {
    //ss << symbol->getName() << "\n";
    //  ss << symbol->print() << "\n";
    //}
    QDialog* dialog = createDialog("Jetons de progrès", QString::fromStdString(ss.str()));
    dialog->exec();
}

QDialog* PlayerWidget::createDialog(const QString& title, const QString& content) {
    QDialog* dialog = new QDialog;
    dialog->setWindowTitle(title);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    QPushButton* closeButton = new QPushButton(tr("Fermer"), dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    return dialog;
}
