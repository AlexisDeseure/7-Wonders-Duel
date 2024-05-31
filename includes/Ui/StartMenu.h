#ifndef STARTMENU_H
#define STARTMENU_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>
#include <QToolBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

class StartMenu: public QWidget{
    Q_OBJECT
private:

    //Indentations : du père au fils.

    //Layout global
    QVBoxLayout* ALL;

        // Bande du haut
        QHBoxLayout* upper_window;
            QPushButton* QUIT;
            QLabel* seven_wonder_duel;
            QLabel* start_menu;

        //Bande des deux joueurs
        QHBoxLayout* player_settings_tab;
            //Joueur 1
            QVBoxLayout* player1_settings;
                QHBoxLayout* upper_band_p1;
                    QLabel* PLAYER1;
                    QCheckBox* p1_HUMAIN;
                    QCheckBox* p1_IA;
                QInputDialog* input_p1_name;

            //Joueur 2
            QVBoxLayout* player2_settings;
                QHBoxLayout* upper_band_p2;
                    QLabel* PLAYER2;
                    QCheckBox* p2_HUMAIN;
                    QCheckBox* p2_IA;
                QInputDialog* input_p2_name;

        //Bande du bas
        QHBoxLayout* lower_games_settings;
            QPushButton* START;
            QCheckBox* p1_starter;
            QCheckBox* p2_starter;
            QCheckBox* random_starter;

public:
    StartMenu(QWidget *parent);
    ~StartMenu() = default;
};

#endif // STARTMENU_H
