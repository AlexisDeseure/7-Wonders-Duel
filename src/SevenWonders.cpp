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
    // QMainWindow fenetre;
    // fenetre.setFixedSize(400,225);
    // StartMenu start_menu = StartMenu(&fenetre);
    // fenetre.setWindowTitle("Seven Wonders Duel");
    // start_menu.setGeometry(fenetre.geometry());
    // QPushButton *bouton = new QPushButton("Cliquez-moi", &fenetre);
    // bouton->setGeometry(150, 80, 100, 30);
    // QObject::connect(bouton, &QPushButton::clicked, &fenetre, &QMainWindow::close);

    //Test de l'affichage de jeu

    // MarketDeck* market = new MarketDeck();
    // GameWindow* fenetre = new GameWindow(market);
    // fenetre->show();

    // QApplication app(argc, argv);
    //QMainWindow* fenetre = new QMainWindow();
    //fenetre->setFixedSize(400,225);
    //ChooseWonderStart* test = new ChooseWonderStart(fenetre);
    //test->show();
    Game();
    return app.exec();
}
