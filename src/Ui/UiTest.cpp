#include <QApplication>
#include "SevenWonderUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setFixedSize(250, 120);
    fenetre.show();
    return app.exec();
}

