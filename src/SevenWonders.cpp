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
    QApplication app(argc, argv);
    Game();
    return app.exec();
}
