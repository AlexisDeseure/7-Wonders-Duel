#include "PlayerWidget.h"
#include "Player.h"
#include "City.h"
#include <QVBoxLayout>
#include <QString>

PlayerWidget::PlayerWidget(Game* g,MarketDeck* md,Player* p, QWidget* parent) : QWidget(parent),g(g), player(p), md(md) {

    playerName = new QLabel(QString::fromStdString(player->getName()), this);
    playing = false;

    playerAIStatus = new QLabel(QString("AI Level: ") + QString::fromStdString(AiLeveltoString(player->getAiLevel())), this);
    playerCityTreasury = new QLabel(QString("Treasury: ") + QString::number(getplayer()->getCity().getTreasury()), this);
    playerCityShields = new QLabel(QString("Shields: ") + QString::number(player->getCity().getShields()), this);
    playerCityVictoryPoints = new QLabel(QString("Victory Points: ") + QString::number(player->getCity().getVictoryPoints()), this);

    playerName->setStyleSheet("background: transparent;");
    playerAIStatus->setStyleSheet("background: transparent;");
    playerCityTreasury->setStyleSheet("background: transparent;");
    playerCityShields->setStyleSheet("background: transparent;");
    playerCityVictoryPoints->setStyleSheet("background: transparent;");



    refreshButton = new QPushButton("Refresh", this);
    connect(refreshButton, &QPushButton::clicked, this, &PlayerWidget::onRefreshButtonClicked);

    refreshButton->setStyleSheet("QPushButton { background-color: gray; }"
                                 "QPushButton:hover { background-color: lightgray; }");

    QVBoxLayout* layout = new QVBoxLayout(this);
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
    show();
}

void PlayerWidget::onRefreshButtonClicked() {
    updatePlayerInfo();
}

//SLOTS
void PlayerWidget::recieveAchat(DeckElement* card){ //signal reçu par playerinput
    if(playing&&!(player->isAIPlayer())){
        //player->Player::buyCard(*g,*card->getBuilding(),*md);//bool buyCard(Game& game, Card& card,MarketDeck& marketDeck);
        if (player->getCity().canAfford(card->getBuilding()->getCost(&player->getCity()))){
            player->getCity().applyEachTurnEffects(*g, *card->getBuilding());
            card->getBuilding()->applyEffects(*g);
            if (dynamic_cast<Wonder*>(card->getBuilding())){ //card is a wonder, il faut choisir un building à défausser pour construire le wonder
                //MarketDeck::iterator it = begin() //tentative avec un itérateur mais ne marche pas :/
                //marketDeck.getBuilding(marketDeck);
                if(card->isVisible()){
                    card->DeckElement::deleteDeckFromMarket(); //suppression "manuelle" pour le moment, il faut remplacer le premier élément dans le deck
                }
            }
        }
        player->getCity().addCard(*card->getBuilding());
        updatePlayerInfo();
        playing=false;
        emit endTurn(); //fin du tour, signal reçu par l'autre joueur
    }
}
void PlayerWidget::recieveDefausse(DeckElement* card){
    if(playing&&!(player->isAIPlayer())){
        player->getCity().discardBuilding(card->getBuilding(),*g);
        updatePlayerInfo();
        playing=false;
        emit endTurn(); //fin du tour, signal reçu par l'autre joueur
    }
}

void PlayerWidget::switchTurn(){ //slot that makes it the player's turn, also plays the game if player is an AI
    playing = true;
    if (player->isAIPlayer()){
        //player->;//method to play the AI's turn ?
        std::vector<DeckElement*>& firstbuildings = md->getFirstBuildings();
        int max = static_cast<int>(firstbuildings.size());
        int choice = selectRandomInteger(1, max);
        DeckElement* card = firstbuildings[choice-1];
        if (player->getCity().canAfford(card->getBuilding()->getCost(&player->getCity()))){
            player->getCity().applyEachTurnEffects(*g, *card->getBuilding());
            card->getBuilding()->applyEffects(*g);
            if (dynamic_cast<Wonder*>(card->getBuilding())){ //card is a wonder, il faut choisir un building à défausser pour construire le wonder
                //MarketDeck::iterator it = begin() //tentative avec un itérateur mais ne marche pas :/
                //marketDeck.getBuilding(marketDeck);
                if(card->isVisible()){
                    card->DeckElement::deleteDeckFromMarket(); //suppression "manuelle" pour le moment, il faut remplacer le premier élément dans le deck
                }
            }
        }
        player->getCity().addCard(*card->getBuilding());
        updatePlayerInfo();
        playing=false;
        emit aiCard(card);
        emit endTurn();
    }
}
