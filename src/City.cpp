#include "includes/City.h"

//Constructeur
City::City(int victory, int  treasury, int shields, bool turn) : victory_points(victory), treasury(treasury), number_of_shields(shields), player_turn(turn), wonder(new Wonder* [4]),
                                                                         progress_tokens(new ProgressToken* [10]), ressources(new Ressource* [30]), scientific_symbols(new ScientificSymbol* [7]),taille_scientific_symbols(0),taille_ressources(0) {
}

void City:: constructBuilding(){};
//Faire appel au consructeur de la classe Building
void City:: constructWonder(){};
//Faire appel au consructeur de la classe Wonder
void City:: discardCard(){}

bool City:: checkMilitaryVictory(){
    int military_position = 9;
    if (number_of_shields >= military_position) {
        std::cout << "Victoire militaire obtenue !" << std::endl;
        return true;
    } else {
        std::cout << "Victoire militaire non atteinte." << std::endl;
        return false;
    }
}

bool City::checkScientificVictory(){
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











