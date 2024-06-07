#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Instanciator.h"
#include "DeckPile.h"
#include "ConflictPawn.h"
#include "GameParameters.h"
#include "City.h"
#include "Effect.h"
#include "AddVictoryPoint.h"
#include <random>
#include <iostream>
#include <algorithm>

Game::Game() : age(0), turn(0), isReplaying(false), winner(nullptr) {
    Instanciator* inst = Instanciator::getInstanciator();
    int length = inst->getGameParameters().getLengthConflictPawnBoard();
    board = new Board(length);
    int nb_b = inst->getGameParameters().getNumberBuildingPerAge();
    int nb_pt = inst->getGameParameters().getNumberProgressTokenBoard();
    int nb_w = inst->getGameParameters().getNumberSelectedWonders();
    deck = new DeckPile(nb_b,nb_pt,nb_w);
    players[0] = new Player(Instanciator::getInstanciator()->getGameParameters().getCoinsStart());
    players[1] = new Player(Instanciator::getInstanciator()->getGameParameters().getCoinsStart());
    startGame();
}

Game::~Game() {
    delete board;
    delete players[0];
    delete players[1];
    delete deck;
    std::cout << R"(
  __  __               _       _ _                  _          _                    _
 |  \/  |             (_)     | ( )                (_)        (_)              /   | |
 | \  / | ___ _ __ ___ _    __| |/  __ ___   _____  _ _ __     _  ___  _   _  ___  | |
 | |\/| |/ _ \ '__/ __| |  / _` |  / _` \ \ / / _ \| | '__|   | |/ _ \| | | |/ _ \ | |
 | |  | |  __/ | | (__| | | (_| | | (_| |\ V / (_) | | |      | | (_) | |_| |  __/ |_|
 |_|  |_|\___|_|  \___|_|  \__,_|  \__,_| \_/ \___/|_|_|      | |\___/ \__,_|\___| (_)
                                                             _/ |
                                                            |__/
)" << std::endl;
}

void Game::startMenu(){
    AiLevel level;
    int choice;

    std::cout <<std::endl << "*********************** Choix des joueurs *********************** " << std::endl<<std::endl;


    for (int i = 0; i < 2; i++) {
        displayplayerChoice(i+1);
        choice = players[i]->getPlayerChoice(2);
        switch (choice) {
            case 1:
                std::cout << "Entrez le nom du joueur : "<< std::endl;
                players[i]->setName(getStrInput());
                break;

            case 2:
                // level = aiOptions(*players[i]);
                // players[i]->setAiLevel(level);
                players[i]->setAI(true);
                players[i]->setAiLevel(AiLevel::EASY);
                players[i]->setName("BOT");// + AiLeveltoString(level));
                break;

        }
    }

    if (players[0]->getName() == players[1]->getName()){
        players[0]->setName(players[0]->getName() + " (1)");
        players[1]->setName(players[1]->getName() + " (2)");
    }
}

AiLevel Game::aiOptions(Player& player) {
    displayAiLevelChoice();
    int choice = player.getPlayerChoice(3);
    player.setAI(true);
    switch (choice) {
        case 1:
            return AiLevel::EASY;

        case 2:
            return AiLevel::MEDIUM;

        default:
            return AiLevel::HARD;
    }
}

void Game::displayAiLevelChoice(){
    std::cout << "Choisissez le niveau de l'IA : "<< std::endl;
    std::cout << "\t1. Facile" << std::endl;
    std::cout << "\t2. Moyen" << std::endl;
    std::cout << "\t3. Difficile" << std::endl;
}

void Game::displayplayerChoice(int nb_joueur){
    std::cout << "Choisissez le type du joueur " << nb_joueur << std::endl;
    std::cout << "\t1. Humain" << std::endl;
    std::cout << "\t2. IA" << std::endl;
}




void Game::startGame(){

    std::cout << R"(
_________   __      __                  .___                    ________                .__
\______  \ /  \    /  \____   ____    __| _/___________  ______ \______ \  __ __   ____ |  |
    /    / \   \/\/   /  _ \ /    \  / __ |/ __ \_  __ \/  ___/  |    |  \|  |  \_/ __ \|  |
   /    /   \        (  <_> )   |  \/ /_/ \  ___/|  | \/\___ \   |    `   \  |  /\  ___/|  |__
  /____/     \__/\  / \____/|___|  /\____ |\___  >__|  /____  > /_______  /____/  \___  >____/
                  \/             \/      \/    \/           \/          \/            \/
    )" << std::endl;

    startMenu();
    std::cout << "Nom des joueurs : " << players[0]->getName() << " et " << players[1]->getName() << std::endl;
    selectWondersPhase();
    while (age < Instanciator::getInstanciator()->getGameParameters().getNumberAge()){
        if (playAge()){
            break;
        }
    }
    endGame();

}

void Game::chooseWhoStartsAge(Player& player){
    std::cout << player.getName() << ", choisissez qui commence l'âge : " << std::endl;
    std::cout << "\t1 : " << players[0]->getName() << std::endl;
    std::cout << "\t2 : " << players[1]->getName() << std::endl;
    std::cout << "\t3 : Aléatoire" << std::endl;
    int choice = player.getPlayerChoice(3);
    switch (choice) {
        case 1:
            if (&getTurnPlayer() == players[0]) invertTurnPlayer();
            std::cout << getOtherPlayer().getName() <<" commencera !" << std::endl;
            break;

        case 2:
            if (&getTurnPlayer() == players[1]) invertTurnPlayer();
            std::cout << getOtherPlayer().getName() <<" commencera !" << std::endl;
            break;

        default:
            randomPlayerStart();
            break;
    }
}

bool Game::playAge(){
    advanceAge();
    std::cout << "Age " << age << " en cours" << std::endl;
    // vérifier quel est le joueur mené militairement pour lui laisser qui commence l'age entre
    // les deux joueurs (lui, l'adversaire, ou aléatoirement en utilisant la méthode randomPlayerStart)
    if (board->getConflictPawn().getPosition()<0){
        chooseWhoStartsAge(getTurnPlayer());
    }
    else if (board->getConflictPawn().getPosition()>0){
        chooseWhoStartsAge(getOtherPlayer());
    }
    else{
        randomPlayerStart();
    }
    while (!board->deckIsEmpty()){
        playTurn();

        if(endTurn())
            return true;
    }
    return false;
}

void Game::replay(){
    if (!isReplaying) isReplaying=true;
}

void Game::playTurn(){
    turn++;
    if (!isReplaying) invertTurnPlayer();
    isReplaying=false;
    std::cout <<std::endl << "*********************** Tour numéro  "<<turn<<" - Joueur "<< getTurnPlayer().getName() <<" *********************** " << std::endl<<std::endl;
    getTurnPlayer().play(*this);
}

void Game::selectWondersPhase() {
    // permet de sélectionner les merveilles pour chaque joueur parmis 8 merveilles sélectionnées aléatoirement
    std::cout <<std::endl << "*********************** Sélection des Merveilles ***********************" <<std::endl<<std::endl;
    randomPlayerStart();
    invertTurnPlayer(); //nécessaire car c'est ce qui est fait ensuite automatiquement à chaque tour de jeu classique
    std::vector<Wonder*> allWonders = deck->getAllWonders();
    std::shuffle(allWonders.begin(), allWonders.end(), std::mt19937(std::random_device()()));

    auto selectionPhase = [&](Player* firstPlayer, Player* secondPlayer) {
        // fonction pour la phase de sélection des wonders
        std::vector<Wonder*> wondersToSelect;
        wondersToSelect.reserve(4); // Réservation de la mémoire pour les 4 wonders pour éviter les réallocations

        for (int i = 0; i < 4; i++) {
            wondersToSelect.push_back(allWonders.back());
            allWonders.pop_back();
        }

        std::cout << "Merveilles disponibles : "<<std::endl;
        for (const auto& wonder : wondersToSelect) {
            std::cout <<"\t- "<< wonder->getName() << std::endl;
        }
        std::cout << std::endl;

        // ordre de sélection des wonders :
        firstPlayer->chooseWonder(wondersToSelect);
        secondPlayer->chooseWonder(wondersToSelect);
        secondPlayer->chooseWonder(wondersToSelect);
        firstPlayer->chooseWonder(wondersToSelect);
    };

    selectionPhase(&getTurnPlayer(), &getOtherPlayer());
    selectionPhase(&getOtherPlayer(), &getTurnPlayer());

    std::cout << "Phase de sélection des Merveilles terminée" << std::endl;
}

bool Game::endTurn() {
    //fin du tour, vérifier si le joueur a gagné
    if(updateConflictPawn()){
        std::cout << "Victoire militaire !" << std::endl;
        if (board->getConflictPawn().getPosition() >= 0){
            winner = &getTurnPlayer();
        }
        else{
            winner = &getOtherPlayer();
        }
        return true;
    }
    if (checkScientificVictory()){
        std::cout << "Victoire scientifique !" << std::endl;
        winner = &getTurnPlayer();
        return true;
    }
    return false;
}


bool Game::updateConflictPawn() {
    //mettre à jour la position du pion de conflit et appliquer les effets des cases si nécessaire
    ConflictPawn& conflict = board->getConflictPawn();
    int totalShields = getTurnPlayer().getShields() - getOtherPlayer().getShields();
    conflict.move(totalShields);
    if (checkMilitaryVictory()){
        return true; // victoire militaire détectée
    }
    for (auto& step : Instanciator::getInstanciator()->getGameParameters().getConflictPawnBoard()){
        if (conflict.getPosition() >= step.number && step.effect != nullptr){
            step.effect->apply(*this); //on applique l'effet de la case (il s'appliquera sur le joueur en train de jouer)
            step.effect = nullptr; //on reset l'effet pour ne pas l'appliquer plusieurs fois
        }
    }
    return false; // pas de victoire militaire détectée
}

bool Game::checkMilitaryVictory() const {
    //vérifier si le joueur a gagné militairement
    return board->getConflictPawn().isMilitaryVictory();
}

bool Game::checkScientificVictory() const {
    //vérifier si le joueur a gagné scientifiquement
    return getTurnPlayer().getCity().checkScientificVictory();
}

void Game::advanceAge(){
    //avancer à l'âge suivant
    age++;
    std::cout <<std::endl << "*********************** Age "<<age<<" *********************** " << std::endl<<std::endl;

    deck->advanceAge(age);
    board->advanceAge(age, deck->getBuildings());
}

void Game::endGame(){
    //fin du jeu, calcul du gagnant
    std::cout <<std::endl << "*********************** Fin du jeu *********************** " << std::endl<<std::endl;

    if (winner == nullptr){
        calculateWinner();
    }
    std::cout << "Calcul du gagnant" << std::endl;
    if (winner == nullptr){
        std::cout << "Egalité !" << std::endl;
    }
    else {
        std::cout << "Bravo à " << winner->getName() << " qui remporte la victoire !" << std::endl;
    }
    //TODO : détruire les objets dynamiques, pointeurs, etc
}

void Game::calculateWinner(){
    //calculer le score de chaque joueur et déterminer le gagnant
    int position = board->getConflictPawn().getPosition();
    int victory_points_conflict = 0;
    for (auto& element :Instanciator::getInstanciator()->getGameParameters().getConflictPawnBoard()){
        if (std::abs(position)>=element.number){
            victory_points_conflict = element.victory_points;
        }
    }
    if (position > 0){
        getTurnPlayer().getCity().addVictoryPoints(victory_points_conflict);
    }
    else{
        getOtherPlayer().getCity().addVictoryPoints(victory_points_conflict);
    }
    int score1 = getTurnPlayer().getScore(*this);
    invertTurnPlayer();
    int score2 = getTurnPlayer().getScore(*this);
    if (score1 > score2){
        winner = &getOtherPlayer();
    }
    else if (score1 < score2){
        winner = &getTurnPlayer();
    }
    else{
        processEquality();
    }
}

void Game::processEquality(){
    //attribuer la victoire à celui qui a le plus de points de victoire sur ses cartes bleues sinon à personne
    int score1 = getNumberOfVictoryPointsBlue(getTurnPlayer());
    int score2 = getNumberOfVictoryPointsBlue(getOtherPlayer());
    if (score1 > score2){
        winner = &getTurnPlayer();
    }
    else if (score1 < score2){
        winner = &getOtherPlayer();
    }
    else{
        winner = nullptr;
    }
}

int Game::getNumberOfVictoryPointsBlue(Player& player){
    //retourne le nombre de points de victoire sur les cartes bleues
    int number_victory_points_blue = 0;
    for (auto& building : player.getCity().getBuildings()){
        if (building->getType() == BuildingType::Blue){
            for (auto& effect : building->getEffects()){
                if (dynamic_cast<AddVictoryPoint*>(effect) != nullptr){
                    number_victory_points_blue += dynamic_cast<AddVictoryPoint*>(effect)->getQuantity();
                }
            }
        }
    }
    return number_victory_points_blue;
}


void Game::invertTurnPlayer(){
    //inverser les joueurs à chaque tour
    std::swap(players[0], players[1]);
}

void Game::randomPlayerStart() {
    //choisir aléatoirement le joueur qui commence
    if(selectRandomInteger() == 1){
        invertTurnPlayer();
    }
    std::cout << getOtherPlayer().getName() <<" commencera !" << std::endl;
};

int selectRandomInteger(int min, int max){
    //retourne un entier aléatoire entre min et max
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    int number = dis(gen);
    return number;
}

int getIntInput()
{
    /**
     * @brief Récupère l'entrée de l'utilisateur et empêche les erreurs de saisie
     *
     * @return int
     */

    int choice;
    std::string input;
    std::cin.clear();
    std::getline(std::cin, input);

    if (input.length() > 0 && std::isdigit(input[0])) {
        choice = std::stoi(input);
    } else {
        choice = -1; // Valeur invalide
    }
    std::cout << std::endl;
    return choice;
}

std::string getStrInput()
{
    /**
     * @brief Récupère l'entrée de l'utilisateur et empêche les erreurs de saisie
     *
     * @return std::string
     */

    std::string input;
    std::cin.clear();
    std::getline(std::cin, input);
    std::cout << std::endl;
    return input;
}
