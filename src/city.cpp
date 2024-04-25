#pragma once
#include "city.h"

//Constructeur
city::City(int victory, int  treasury, int shields, bool turn = false) : victory_points(victory), treasury(treasury), number_of_shields(shields), player_turn(turn), wonder(new Wonder* [4]),
progress_token(new ProgressToken* [10]), ressources(new Ressource* [30]), scientific_symbol(new ScientificSymbol* [7]),taille_scientific_symbol(0),taille_ressources(0) {
}

void city:: constructBuilding(){}
    //Faire appel au consructeur de la classe Building
void city:: constructWonder();{}
    //Faire appel au consructeur de la classe Wonder
void city:: discardCard(){}

bool city:: checkMilitaryVictory(){
    int military_position = 9;
    if (number_of_shields >= military_position) {
        std::cout << "Victoire militaire obtenue !" << std::endl;
        return true;
    } else {
        std::cout << "Victoire militaire non atteinte." << std::endl;
        return false;
    }
}

bool city:: checkScientificVictory(){
    //Ici il faut une fonction pour calculer
    int unique_scientific_symbols = 6; //  Doit être calculé en fonction de la collection de symboles scientifiques.
    if (taille_scientific_symbols >= unique_scientific_symbols) {
        std::cout << "Victoire scientifique obtenue !" << std::endl;
        return true;
    } else {
        std::cout << "Victoire scientifique non atteinte." << std::endl;
        return false;
    }
}







