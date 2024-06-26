#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <utility>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCore>
#include <QWidget>
#include "MarketDeck.h"
#include "Wonder.h"
#include "DeckElement.h"
#include "ChooseWondersUI.h"
class City;
class Game;
class Card;
class GameWindow;

enum class AiLevel{
    NONE,
    EASY,
    MEDIUM,
    HARD
};
std::string AiLeveltoString(AiLevel level);

class Player: public QObject{
    Q_OBJECT
    private:
        City& city;
        bool isAI;
        AiLevel aiLevel;
        std::string name;

        Wonder* intermediateWonder; //sert à stocker une wonder intermédiaire pour l'ui pour le callback

    signals:
        void destroyWondersAi(Wonder* w);

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
        void playUi(Game& game, GameWindow* fenetre);
        void chooseWonder(std::vector<Wonder*>& availableWonders);
        void addWonderToCity(Wonder* wonder);
        void chooseWonderUi(std::vector<Wonder*>& availableWonders, ChooseWonderStart* fenetre);

        int getPlayerChoice(int max); //permet de récupérer l'entrée utilisateur
    private slots:
        void handleSelectionWonderDone(Wonder* wonder);

};
#endif
