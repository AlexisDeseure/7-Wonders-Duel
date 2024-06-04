#include <QApplication>
#include <QWidget>
#include "game_window.h"
//#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow* w = new GameWindow();
    w->resize(1200,800);
    w->show();
    return a.exec();
}
