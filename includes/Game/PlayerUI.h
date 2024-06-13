#ifndef PLAYERUI_H
#define PLAYERUI_H

#include <string>
#include <utility>
#include "MarketDeck.h"
#include "Wonder.h"
#include "DeckElement.h"
class City;
class GameUI;
class Card;

enum class AiLevel{
    NONE,
    EASY,
    MEDIUM,
    HARD
};
std::string AiLeveltoString(AiLevel level);

class PlayerUI{
    private:
        City& city;
        bool isAI;
        AiLevel aiLevel;
        std::string name;

    public:
        PlayerUI(int treasury = 0);
        ~PlayerUI();

        bool isAIPlayer() const {return isAI;};
        City& getCity() const {return city;};
        std::string getName() const {return name;};
        AiLevel getAiLevel() const {return aiLevel;};

        void setAI(bool ai){isAI = ai;};
        void setAiLevel(AiLevel level){aiLevel = level;};
        void setName(std::string n){this->name = std::move(n);};

        int getShields() const;
        int getScore(GameUI& game) const; // get the score of the player (number of victory points)
        const DeckElement* selectCard(Game& game, MarketDeck& marketDeck); //permet au joueur de sélectionner une carte à jouer
        bool buyCard(GameUI& game, Card& card,MarketDeck& marketDeck); //acheter carte ou wonder après avoir appliquer les effets de chaque tours
        void play(GameUI& game); //permet de permettre au joueur de jouer son tour
        void chooseWonder(std::vector<Wonder*>& availableWonders);
        void addWonderToCity(Wonder* wonder);

        int getPlayerChoice(int max); //permet de récupérer l'entrée utilisateur
};
#endif
