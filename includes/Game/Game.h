#ifndef GAME_H
#define GAME_H

#define COIN_START 7
#define AGE_MAX 3
#define WONDERS_MAX 7

#define NB_BUILDING_PER_AGE 20
#define NB_PROGRESS_TOKEN_BOARD 5
#define NB_WONDERS 8
#define NB_CARD_GUILDS 3

#define FILE_PATH "../../../data/data.json"

#include <string>
#include <vector>


class DeckPile;
class Board;
class Player;
enum class AiLevel;
class Building;

class Game{
    private:
        int age;
        Board& board;
        Player* players[2];
        bool isReplaying;
        DeckPile& deck;

    public:

        void advanceAge();
        void startGame();
        void replay();
        void selectWondersPhase();
        void endGame();
        void invertTurnPlayer();
        void randomPlayerStart();
        Player& getTurnPlayer() const { return *players[0]; };
        Player& getOtherPlayer() const { return *players[1]; };
        void playAge();
        void playTurn();
        void startMenu();
        void displayplayerChoice(int nb_joueur);
        void displayAiLevelChoice();
        AiLevel aiOptions();
        Game();
        ~Game();
};

int selectRandomInteger(int min = 0, int max = 1);
int getIntInput();
std::string getStrInput();
#endif
