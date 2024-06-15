#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <utility>
#include "MarketDeck.h"
#include "Wonder.h"
#include "DeckElement.h"

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include <City.h>

class City;
class Game;
class Card;

enum class AiLevel{
    NONE,
    EASY,
    MEDIUM,
    HARD
};
std::string AiLeveltoString(AiLevel level);

class Player{
    private:
        City& city;
        bool isAI;
        AiLevel aiLevel;
        std::string name;

        void showResources();
        void showWonders();
        void showProgressTokens();

        QDialog* createDialog(const QString& title, const QString& content);

        //City& city;
        QPushButton* resourcesButton;
        QPushButton* wondersButton;
        QPushButton* progressTokensButton;

    public:
        Player(int treasury = 0);
        ~Player();

        bool isAIPlayer() const {return isAI;};
        City& getCity() const {return city;};
        std::string getName() const {return name;};
        AiLevel getAiLevel() const {return aiLevel;};

        void setAI(bool ai){isAI = ai;};
        void setAiLevel(AiLevel level){aiLevel = level;};
        void setName(std::string n){this->name = std::move(n);};

        int getShields() const;
        int getScore(Game& game) const; // get the score of the player (number of victory points)
        const DeckElement* selectCard(Game& game, MarketDeck& marketDeck); //permet au joueur de sélectionner une carte à jouer
        bool buyCard(Game& game, Card& card,MarketDeck& marketDeck); //acheter carte ou wonder après avoir appliquer les effets de chaque tours
        void play(Game& game); //permet de permettre au joueur de jouer son tour
         void playUI(Game& game); //permet de permettre au joueur de jouer son tour au niveau UI
        void chooseWonder(std::vector<Wonder*>& availableWonders);
        void addWonderToCity(Wonder* wonder);

        int getPlayerChoice(int max); //permet de récupérer l'entrée utilisateur
};
#endif
