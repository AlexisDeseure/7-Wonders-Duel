#ifndef STARTMENU_H
#define STARTMENU_H

#include "Connector.h"
#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>


class StartMenu: public QWidget{
    Q_OBJECT
private:
    bool p1TypeIA;
    bool p1TypeHuman;
    bool p2TypeIA;
    bool p2TypeHuman;
    QString p1Name;
    QString p2Name;
    bool p1Starts;
    bool p2Starts;
    bool randomStarter;
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

    void setGameParameters();

    void setp1typeIA(bool p1TypeI){p1TypeIA = p1TypeI;}
    void setp1TypeHuman(bool p1TypeH){p1TypeHuman = p1TypeH;}
    void setp2TypeIA(bool p2TypeI){p2TypeIA = p2TypeI;}
    void setp2TypeHuman(bool p2TypeH){p2TypeHuman = p2TypeH;}
    void setp1name(QString name){p1Name = name;}
    void setp2name(QString name){p2Name = name;}
    void setp1starts(bool start){p1Starts = start;}
    void setp2starts(bool start){p2Starts = start;}
    void setrandomstart(bool start){randomStarter = start;}

    bool getp1typeIA(){return p1TypeIA;}
    bool getp1typeHuman(){return p1TypeHuman;}
    bool getp2typeIA(){return p2TypeIA;}
    bool getp2typeHuman(){return p2TypeHuman;}
    QString getp1name(){return p1Name;}
    QString getp2name(){return p2Name;}
    bool getp1starts(){return p1Starts;}
    bool getp2starts(){return p2Starts;}
    bool setrandomstart(){return randomStarter;}

    void displayGameParameters();

public slots:
    void startButton();
signals:
    void StartPressed();
};

#endif // STARTMENU_H
