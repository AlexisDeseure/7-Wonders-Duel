#include "Game.h"
#include "Building.h"
#include "ProgressToken.h"
#include "City.h"
#include "Card.h"
#include "Instanciator.h"
#include "EffectFactory.h"
#include "Ressource.h"
#include "Effect.h"
#include "AddMoney.h"
#include "DeckElement.h"
#include "AddRessource.h"
#include "GameParameters.h"
#include "IncludeEffects.h"
#include "MarketDeck.h"
#include "DeckPile.h"
#include "Player.h"  // Ensure Player.h is included

#include <QTextStream>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;



int main(int argc, char* argv[]) {
#ifdef _WIN32
    // Définit la console pour utiliser l'encodage UTF-8 sous Windows
    SetConsoleOutputCP(CP_UTF8);  // UTF-16LE
    SetConsoleCP(CP_UTF8);
#endif

    Instanciator::getInstanciator();
    int nb_b = Instanciator::getInstanciator()->getGameParameters().getNumberBuildingPerAge();
    int nb_pt = Instanciator::getInstanciator()->getGameParameters().getNumberProgressTokenBoard();
    int nb_w = Instanciator::getInstanciator()->getGameParameters().getNumberSelectedWonders();
    DeckPile deck(nb_b, nb_pt, nb_w);
    MarketDeck market;

    for (int age = 1; age <= 3; age++) {
        deck.advanceAge(age);
        market.advanceAge(age, deck.getBuildings());
        cout << market;
        cout << endl << endl << "###################################" << endl << endl;
    }

    // Create a Game instance
    Game game;

    // Create Player instances
    Player player1(10); // Assuming the player starts with a treasury of 10
    Player player2(10); // Another player

    // Set player names
    player1.setName("Player 1");
    player2.setName("Player 2");

    // Set AI levels if needed
    player1.setAI(false); // Assuming player1 is not AI
    player2.setAI(true);  // Assuming player2 is AI
    player2.setAiLevel(AiLevel::EASY); // Set AI level to EASY for player2

    // Execute play method for player1
    player1.play(game);

    system("pause");
    return 0;
}
