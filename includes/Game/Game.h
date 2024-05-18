#ifndef GAME_H
#define GAME_H

#define COIN_START 7
#define NB_PLAYERS 2
#define AGE_MAX 3

#include <string>

class Board;
class Player;
enum class AiLevel;

class Game{
    private:
        int age;
        Board& board;
        Player* players[NB_PLAYERS];

    public:

        void advanceAge();
        void startGame();

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
