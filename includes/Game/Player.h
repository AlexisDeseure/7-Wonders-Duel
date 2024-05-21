#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <utility>

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

    public:
        Player(bool ai=false, AiLevel level=AiLevel::NONE, std::string name="Player");
        ~Player();

        bool isAIPlayer() const {return isAI;};
        City& getCity() const {return city;};
        std::string getName() const {return name;};
        AiLevel getAiLevel() const {return aiLevel;};

        void setAI(bool ai){isAI = ai;};
        void setAiLevel(AiLevel level){aiLevel = level;};
        void setName(std::string n){this->name = std::move(n);};

        bool buyCard(Game& game, Card& card); //acheter carte ou wonder après avoir appliquer les effets de chaque tours
        void play(Game& game); //permet de permettre au joueur de jouer son tour
};
#endif
