#include "StartMenu.h"

StartMenu::StartMenu(QWidget *parent) : QWidget(parent){

    QSize size = parent->size();
    QRect ALL_size = QRect(parent->pos(),size);

    QRect upper_size = QRect(0,0,size.rwidth(),size.rheight()/8);
    //LAYOUT GLOBAL
    ALL = new QVBoxLayout(this);
    ALL->setGeometry(ALL_size);
    //upper_window

    upper_window = new QHBoxLayout();

    upper_window->setGeometry(upper_size);

    start_menu = new QLabel("Start Menu");
    //start_menu->setGeometry(0,0,size.rwidth()/3,size.rheight()/8);

    seven_wonder_duel = new QLabel("7 Wonders Duel");
    //seven_wonder_duel->setGeometry(size.rwidth()*(2/3),0,size.rwidth()/3,size.rheight()/8);

    QUIT = new QPushButton("Quit");
    //QUIT->setGeometry(size.rwidth(),0,size.rwidth()/3,size.rheight()/8);
    QUIT->setDefault(0);

    upper_window->addWidget(start_menu);
    upper_window->addWidget(seven_wonder_duel);
    upper_window->addWidget(QUIT);

    ALL->addLayout(upper_window);

    //Bandes pour les joueurs:
    //START = new QPushButton;
    //START->setDefault(1);


    // choose_player1 = new QToolBox;

    // choose_player2 = new QToolBox;

    // choose_IA_difficulty_p1 = new QToolBox;

    // choose_IA_difficulty_p2 = new QToolBox;

    // choose_starting_player = new QToolBox;

    // choose_DLC = new QToolBox;

    // input_p1_name = new QInputDialog;

    // input_p2_name = new QInputDialog;
}
