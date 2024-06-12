#include "Game.h"
#include "Building.h"
#include "ProgressToken.h"
#include "City.h"
#include "Card.h"
#include "Instanciator.h"
#include "EffectFactory.h"
#include "Ressource.h"
#include "Building.h"
#include "Effect.h"
#include "AddMoney.h"
#include "DeckElement.h"
#include "AddRessource.h"
#include "GameParameters.h"
#include "IncludeEffects.h"
#include "MarketDeck.h"
#include "DeckPile.h"
#include "Player.h"  // Ensure Player.h is included
#include "SevenWonderUI.h"
#include "StartMenu.h"
#include "game_window.h"

#include <QTextStream>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <vector>

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

    /*Instanciator::getInstanciator();
    int nb_b = Instanciator::getInstanciator()->getGameParameters().getNumberBuildingPerAge();
    int nb_pt = Instanciator::getInstanciator()->getGameParameters().getNumberProgressTokenBoard();
    int nb_w = Instanciator::getInstanciator()->getGameParameters().getNumberSelectedWonders();
    DeckPile deck(nb_b, nb_pt, nb_w);
    MarketDeck market;

    for (int age = 1; age <= 3; age++) {
        deck.advanceAge(age);
        market.advanceAge(age, deck.getBuildings());
        cout << market;
        cout << endl << endl << "###################################" << endl << endl;
    }

    // Create a Game instance
    Game game;

    // Create Player instances
    Player player1(10); // Assuming the player starts with a treasury of 10
    Player player2(10); // Another player

    // Set player names
    player1.setName("Player 1");
    player2.setName("Player 2");

    // Set AI levels if needed
    player1.setAI(false); // Assuming player1 is not AI
    player2.setAI(true);  // Assuming player2 is AI
    player2.setAiLevel(AiLevel::EASY);  Set AI level to EASY for player2*/

    // std::vector<RessourceCost> ressourceVector;
    // RessourceCost R1(5, RessourceType::Wood);
    // RessourceCost R2(5, RessourceType::Wood);
    // RessourceCost R3(3, RessourceType::Wood);
    // ressourceVector.push_back(R1);
    // ressourceVector.push_back(R2);
    // ressourceVector.push_back(R3);
    // AddMoney addMoney;
    // AddRessource addRessource ;
    // std::vector<Effect*> Effets;
    // Effets.push_back(&addMoney);
    // Effets.push_back(&addRessource);

    // DeckElement D( "Deck1", ressourceVector, Effets, 2,BuildingType::Yellow,10) ;

    // QApplication app(argc, argv);
    // // QTextStream qin(stdin);
    // // QString line = qin.readLine();
    // // std::cout << "Vous avez entré : " << line.toStdString() << std::endl;
    // cout << "Liste des classes enregistrées" <<endl;
    // for (auto& testtest : EffectFactory::instance().creators){
    //     cout << testtest.first << endl;
    // }
    // cout << "FIN" <<endl;
    // City c;
    // std::vector<RessourceType> vect_ress = {RessourceType::Glass,RessourceType::Paper,RessourceType::Wood};

    // c.addRessource(vect_ress);
    // c.getRessource(RessourceType::Paper)+=2;
    // for (auto& r : c.getRessources()){
    //     cout << "Liste ressource : ";
    //     for (auto& t : r->getTypes()) cout<< ressourceTypeToString(t)<<" ";
    //     cout << endl;
    //     cout << "Tradable : " << r->getTradable()<<endl<<endl;
    // }
    // //c.addChainSymbol("test");
    // RessourceType vere = RessourceType::Glass;
    // RessourceType pap = RessourceType::Paper;
    // RessourceCost re(3,vere);
    // c.getRessource(RessourceType::Glass).updatePrice(-1);
    // RessourceCost re2(4,pap);
    // std::vector<RessourceCost> vecre = {re, re2};
    // Effect* effect = EffectFactory::instance().create("AddMoney");
    // cout << "re : " << c.getRessource(RessourceType::Glass).getPrice()<<endl;
    // Building b("test", vecre, {effect}, 2, BuildingType::Blue,3);
    // cout << "cost : " << b.getCost(&c)<<endl;
    // for (auto& t : b.getLackingRessources(&c)){
    //     cout << ressourceTypeToString(t);
    // }
    // cout<<endl;
    // Effect* currEffect = EffectFactory::instance().create("ChooseProgressTokenDiscarded");
    // currEffect->setParameters({},{});
    // Instanciator::getInstanciator();
    // int nb_b = Instanciator::getInstanciator()->getGameParameters().getNumberBuildingPerAge();
    // int nb_pt = Instanciator::getInstanciator()->getGameParameters().getNumberProgressTokenBoard();
    // int nb_w = Instanciator::getInstanciator()->getGameParameters().getNumberSelectedWonders();
    // DeckPile deck(nb_b,nb_pt,nb_w);
    // MarketDeck market;

    // for (int age = 1; age <=3; age++){
    //     deck.advanceAge(age);
    //     market.advanceAge(age, deck.getBuildings());
    //     cout << market;
    //     cout <<endl<<endl<<"###################################"<<endl<<endl;
    // }
    //Game();

    // //cout<<Instanciator::getInstanciator()->getGameParameters();
    // system("pause");

    string s;
    cout << "Choississez entre version console ou non :" << endl;
    cin >> s;

    if (s=="1"){
        Game();
        return 0;
    }
    else{
        // Test QT
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
        GameWindow* fenetre = new GameWindow();


        // //Affichage de la fenêtre
        fenetre->show();

        //SevenWonderUI ui;
        //ui.show();

        // Exécution de la boucle d'événements
        return app.exec();

    }

    // Execute play method for player1
    // player1.play(game);

    //system("pause");
}
