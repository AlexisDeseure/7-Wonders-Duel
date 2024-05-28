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

Game::Game() : age(0), isReplaying(false), winner(nullptr) {
    Instanciator* inst = Instanciator::getInstanciator();
    int length = inst->getGameParameters().getLengthConflictPawnBoard();
    board = new Board(length);
    int nb_b = inst->getGameParameters().getNumberBuildingPerAge();
    int nb_pt = inst->getGameParameters().getNumberProgressTokenBoard();
    int nb_w = inst->getGameParameters().getNumberSelectedWonders();
    deck = new DeckPile(nb_b,nb_pt,nb_w);
    players[0] = new Player(Instanciator::getInstanciator()->getGameParameters().getCoinsStart());
    players[1] = new Player(Instanciator::getInstanciator()->getGameParameters().getCoinsStart());
    std::cout << "Game created" << std::endl;
    startGame();
}

Game::~Game() {
    delete board;
    delete players[0];
    delete players[1];
    delete deck;
    std::cout << "Game finished" << std::endl;
}

void Game::startMenu(){
    AiLevel level;
    int choice;

    for (int i = 0; i < 2; i++) {
        do{
            displayplayerChoice(i+1);
            switch (choice = getIntInput()) {
                case 1:
                    players[i]->setAI(false);
                    std::cout << "Entrez le nom du joueur : "<< std::endl;
                    players[i]->setName(getStrInput());
                    break;

                case 2:
                    players[i]->setAI(true);
                    level = aiOptions();
                    players[i]->setAiLevel(level);
                    players[i]->setName("BOT " + AiLeveltoString(level));
                    break;

                default:
                    std::cout << "Choix invalide" << std::endl;
                    break;
            }
        }while(choice < 1 || choice > 2);
    }
}

AiLevel Game::aiOptions() {
    AiLevel level;
    int choice = 0;
    do {
        displayAiLevelChoice();
        switch (choice = getIntInput()) {
            case 1:
                level = AiLevel::EASY;
                break;

            case 2:
                level = AiLevel::MEDIUM;
                break;

            case 3:
                level = AiLevel::HARD;
                break;

            default:
                std::cout << "Choix invalide" << std::endl;
                break;
        }
    }while (choice < 1 || choice > 3);

    return level;
}

void Game::displayAiLevelChoice(){
    std::cout << "Choisissez le niveau de l'IA : "<< std::endl;
    std::cout << "\t1. Facile" << std::endl;
    std::cout << "\t2. Moyen" << std::endl;
    std::cout << "\t3. Difficile" << std::endl;
    std::cout << "Selection: ";
}

void Game::displayplayerChoice(int nb_joueur){
    std::cout << "Choisissez le type du joueur " << nb_joueur << std::endl;
    std::cout << "\t1. Humain" << std::endl;
    std::cout << "\t2. IA" << std::endl;
    std::cout << "Selection: ";
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


void Game::startGame(){

    std::cout << "Game started" << std::endl;
    startMenu();
    std::cout << "nom des joueurs : " << players[0]->getName() << " et " << players[1]->getName() << std::endl;
    selectWondersPhase();
    while (age < Instanciator::getInstanciator()->getGameParameters().getNumberAge()){
        if (playAge()){
            break;
        }
    }
    endGame();

}

bool Game::playAge(){
    advanceAge();
    std::cout << "Age " << age << " en cours" << std::endl;
    // vérifier quel est le joueur mené militairement pour lui laisser qui commence l'age entre
    // les deux joueurs (lui, l'adversaire, ou aléatoirement en utilisant la méthode randomPlayerStart)
    // à faire
//    while (!board.deckIsEmpty()){
//        playTurn();
//        if(endTurn()){return true;}
//    }
    return false;
}

void Game::replay(){
    if (!isReplaying) isReplaying=true;
}

void Game::playTurn(){
    if (!isReplaying) invertTurnPlayer();
    isReplaying=false;
    getTurnPlayer().play(*this);
}

void Game::selectWondersPhase() {
    // permet de sélectionner les merveilles pour chaque joueur parmis 8 merveilles sélectionnées aléatoirement

    randomPlayerStart();
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

        std::cout << "Merveilles disponibles : ";
        for (const auto& wonder : wondersToSelect) {
            std::cout << wonder->getName() << " ";
        }
        std::cout << std::endl;

        // ordre de sélection des wonders :
        firstPlayer->chooseWonder(wondersToSelect);
        secondPlayer->chooseWonder(wondersToSelect);
        secondPlayer->chooseWonder(wondersToSelect);
        firstPlayer->chooseWonder(wondersToSelect);
    };

    selectionPhase(players[0], players[1]);
    selectionPhase(players[1], players[0]);

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
    std::cout << "Age avance" << std::endl;
    age++;
    deck->advanceAge(age);
    board->advanceAge(age, deck->getBuildings());
}

void Game::endGame(){
    //fin du jeu, calcul du gagnant
    if (winner == nullptr){
        calculateWinner();
    }
    std::cout << "Calcul du gagnant" << std::endl;
    if (winner == nullptr){
        std::cout << "Egalité !" << std::endl;
    }
    else {
        std::cout << "Bravo à " << winner->getName() << "qui remporte la victoire !" << std::endl;
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
    std::cout << getTurnPlayer().getName() <<" commencera !" << std::endl;
};

int selectRandomInteger(int min, int max){
    //retourne un entier aléatoire entre min et max
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    int number = dis(gen);
    return number;
}
