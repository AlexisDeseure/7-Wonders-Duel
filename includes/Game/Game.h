#ifndef GAME_H
#define GAME_H


#define GAME_PARAMETERS_PATH "../../../data/game_parameters.json"
#include "qtmetamacros.h"
#include <QtCore>
#include <QObject>
#include <string>
#include <vector>
#include <exception>
#include"Wonder.h"

class DeckPile;
class Board;
class Player;
enum class AiLevel;
class Building;

class GameException : public std::exception{
private:
    std::string message;

public:
    GameException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class Game:  public QObject{
Q_OBJECT
    private:
        int age;
        unsigned int turn;
        Board* board;
        Player* players[2];
        bool isReplaying;
        DeckPile* deck;
        Player* winner;
        bool isTerminal;
        bool exit;
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
        AiLevel aiOptions(Player& player);
        int getNumberOfVictoryPointsBlue(Player& player);
        void chooseWhoStartsAge(Player& player);

        void handleWonderSelection(Wonder* selectedWonder, Player* firstPlayer, Player* secondPlayer, std::vector<Wonder*>& wondersToSelect, QEventLoop& loopWonder);
        Game();
        ~Game();

        // UI SPECIFIC
        void selectWonderPhaseUI(QWidget* fenetre);
        void startGameUI(QWidget* fenetre);
        bool playAgeUI();
        void endGameUI(QWidget* fenetre);
        void advanceAgeUI();
        void playTurnUI();
        bool endTurnUI();
    public slots:
        void quitting(){exit = true;}
        void quitGame() {
            qApp->quit();
        }
        void handleWonderSelection() {return;};
};

int selectRandomInteger(int min = 0, int max = 1);
int getIntInput();
std::string getStrInput();
#endif
