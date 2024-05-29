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
                    QToolBox* choose_player1;
                    QToolBox* choose_IA_difficulty_p1;
                QInputDialog* input_p1_name;

            //Joueur 2
            QVBoxLayout* player2_settings;
                QHBoxLayout* upper_band_p2;
                    QToolBox* choose_player2;
                    QToolBox* choose_IA_difficulty_p2;
                QInputDialog* input_p2_name;

        //Bande du bas
        QHBoxLayout* lower_games_settings;
            QPushButton* START;
            QToolBox* choose_starting_player;
            QToolBox* choose_DLC;

public:
    StartMenu(QWidget *parent);
    ~StartMenu() = default;
};

#endif // STARTMENU_H
