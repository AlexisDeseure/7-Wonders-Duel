#ifndef GAME_H
#define GAME_H


#define GAME_PARAMETERS_PATH "../../data/game_parameters.json"

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
        Board* board;
        Player* players[2];
        bool isReplaying;
        DeckPile* deck;
        Player* winner;

    public:
        bool endTurn();
        bool checkMilitaryVictory() const;
        bool checkScientificVictory() const;
        bool updateConflictPawn();
        void processEquality();
        void advanceAge();
        void startGame();
        void replay();
        void selectWondersPhase();
        void endGame();
        void calculateWinner();
        void invertTurnPlayer();
        void randomPlayerStart();
        Player& getTurnPlayer() const { return *players[0]; };
        Player& getOtherPlayer() const { return *players[1]; };
        Board& getBoard() {return *board;}
        DeckPile& getDeck() {return *deck;}
        bool playAge();
        void playTurn();
        void startMenu();
        void displayplayerChoice(int nb_joueur);
        void displayAiLevelChoice();
        AiLevel aiOptions();
        int getNumberOfVictoryPointsBlue(Player& player);
        Game();
        ~Game();
};

int selectRandomInteger(int min = 0, int max = 1);
int getIntInput();
std::string getStrInput();
#endif
