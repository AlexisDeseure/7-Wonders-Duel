#include "StartMenu.h"

StartMenu::StartMenu(QWidget *parent) : QWidget(parent){

    QSize size = parent->size();
    QRect ALL_size = QRect(parent->pos(),size);

//LAYOUT GLOBAL
    ALL = new QVBoxLayout(this);
    ALL->setGeometry(ALL_size);

//UPPER TAB

    upper_window = new QHBoxLayout();
        start_menu = new QLabel("Start Menu");
        seven_wonder_duel = new QLabel("7 Wonders Duel");
        QUIT = new QPushButton("Quit");
        QUIT->setDefault(0);
        //connect(QUIT, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(QUIT, SIGNAL(clicked()), this, SLOT(quitButton()));

    upper_window->addWidget(start_menu);
    upper_window->addWidget(seven_wonder_duel);
    upper_window->addWidget(QUIT);

    ALL->addLayout(upper_window);

//BANDE JOUEURS:
    player_settings_tab = new QHBoxLayout();
    //JOUEUR 1
        player1_settings = new QVBoxLayout();

            PLAYER1 = new QLabel("PLAYER 1");
            PLAYER1->setFixedHeight(20);
            QLabel* p1_type = new QLabel("Choose Player 1 Type");
            p1_type->setFixedHeight(20);
            upper_band_p1 = new QHBoxLayout();

            QButtonGroup* p1_type_group = new QButtonGroup;
            p1_HUMAIN = new QCheckBox("HUMAIN");
            p1_IA = new QCheckBox("IA");

            p1_type_group->addButton(p1_HUMAIN);
            p1_type_group->addButton(p1_IA);

            upper_band_p1->addWidget(p1_HUMAIN);
            upper_band_p1->addWidget(p1_IA);


            input_p1_name = new QInputDialog;
            input_p1_name->setOption(QInputDialog::NoButtons);
            //textValue() pour récupérer l'input.
            input_p1_name->setLabelText("PLAYER 1 NAME");

            player1_settings->addWidget(PLAYER1);
            player1_settings->addWidget(p1_type);
            player1_settings->addLayout(upper_band_p1);
            player1_settings->addWidget(input_p1_name);

    //JOUEUR 2
        player2_settings = new QVBoxLayout();

            QLabel* p2_type = new QLabel("Choose Player 2 Type");
            PLAYER2 = new QLabel("PLAYER 2");
            PLAYER2->setFixedHeight(20);
            p2_type->setFixedHeight(20);
            upper_band_p2 = new QHBoxLayout();
            QButtonGroup* p2_type_group = new QButtonGroup;
            p2_HUMAIN = new QCheckBox("HUMAIN");
            p2_IA = new QCheckBox("IA");

            p2_type_group->addButton(p2_HUMAIN);
            p2_type_group->addButton(p2_IA);

            upper_band_p2->addWidget(p2_HUMAIN);
            upper_band_p2->addWidget(p2_IA);

            input_p2_name = new QInputDialog;
            input_p2_name->setOption(QInputDialog::NoButtons);
            //textValue() pour récupérer l'input.
            input_p2_name->setLabelText("PLAYER 2 NAME");

            player2_settings->addWidget(PLAYER2);
            player2_settings->addWidget(p2_type);
            player2_settings->addLayout(upper_band_p2);
            player2_settings->addWidget(input_p2_name);

        player_settings_tab->addLayout(player1_settings);
        player_settings_tab->addLayout(player2_settings);

    ALL->addLayout(player_settings_tab);

    //BANDE INFERIEURE

    QButtonGroup* starter_group = new QButtonGroup;

    QLabel* choose_starting_player = new QLabel("Choose Starter");
    choose_starting_player->setAlignment(Qt::AlignCenter);
    lower_games_settings = new QHBoxLayout();

    p1_starter = new QCheckBox("Joueur 1");
    p2_starter = new QCheckBox("Joueur 2");
    random_starter = new QCheckBox("Aléatoire");
    terminal = new QCheckBox("Terminal");
    starter_group->addButton(p1_starter);
    starter_group->addButton(p2_starter);
    starter_group->addButton(random_starter);




    START = new QPushButton("START");
    START->setDefault(1);
    connect(START, SIGNAL(clicked()), this, SLOT(startButton()));
    lower_games_settings->addWidget(p1_starter);
    lower_games_settings->addWidget(p2_starter);
    lower_games_settings->addWidget(random_starter);
    lower_games_settings->addWidget(terminal);
    lower_games_settings->addWidget(START);

    ALL->addWidget(choose_starting_player);
    ALL->addLayout(lower_games_settings);
}

void StartMenu::startButton(){
    setGameParameters();
    displayGameParameters();
    emit StartPressed();
}

void StartMenu::quitButton(){
    emit quitPressed();
}

void StartMenu::setGameParameters(){
    setp1typeIA(p1_IA->isChecked());
    setp1TypeHuman(p1_HUMAIN->isChecked());
    setp2TypeIA(p2_IA->isChecked());
    setp2TypeHuman(p2_HUMAIN->isChecked());
    setp1name(input_p1_name->textValue());
    setp2name(input_p2_name->textValue());
    setp1starts(p1_starter->isChecked());
    setp2starts(p2_starter->isChecked());
    setrandomstart(random_starter->isChecked());
    setterminal(terminal->isChecked());
    qDebug() << "Starting Parameters set!";
}

void StartMenu::displayGameParameters(){
    qDebug() << "P1IA: " <<getp1typeIA() << " | P1H: "<< getp1typeHuman() << " | P2IA: "<< getp2typeIA() << " | P2H:"
              << getp2typeHuman() << " | P1Name: " <<getp1name().toStdString() <<" | P2Name: " << getp2name().toStdString()
             <<" | P1Start: "<< getp1starts() <<" | P2Start: "<< getp2starts() << " | RandStart: "<< getrandomstart()
             << " | Terminal: "<<getterminal();
}
