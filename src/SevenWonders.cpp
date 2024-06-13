#include "Game.h"
#include "Building.h"
#include "ProgressToken.h"
#include "City.h"
#include "Card.h"
#include "Instanciator.h"
#include "EffectFactory.h"
#include "Ressource.h"
#include "Building.h"
#include "Effect.h"
#include "AddMoney.h"
#include "DeckElement.h"
#include "AddRessource.h"
#include "GameParameters.h"
#include "IncludeEffects.h"
#include "MarketDeck.h"
#include "DeckPile.h"
#include "Player.h"  // Ensure Player.h is included
#include "SevenWonderUI.h"
#include "StartMenu.h"


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
    QApplication app(argc, argv);
    Game();
    return app.exec();
}
