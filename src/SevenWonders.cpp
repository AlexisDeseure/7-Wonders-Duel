#include "Game.h"
#include <QTextStream>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <vector>
#include "game_window.h"
#include "EndGamePopUp.h"

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

    //=================Test de l'affichage du market deck ===========================
    // décommenter pour voir
    QApplication app(argc, argv);
    // MarketDeck* market = new MarketDeck();
    // GameWindow* fenetre = new GameWindow(market);
    // fenetre->show();
    //===============================================================================

    //=================Test de l'affichage du EndGamePopUp ==========================
    // QApplication app(argc, argv);
    // QMainWindow* fenetre = new QMainWindow();
    // fenetre->setGeometry(0,0,1280,720);
    // fenetre->show();
    // EndGamePopUp* test = new EndGamePopUp(fenetre,nullptr);
    // test->show();
    // QEventLoop waitingForEndGame;
    // QAbstractButton::connect(test,SIGNAL(endGame()),&waitingForEndGame,SLOT(quit()));
    // waitingForEndGame.exec();
    // fenetre->close();
    //===============================================================================
    Game();
    return app.exec();
}
