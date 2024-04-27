#include "includes/City/City.h"

namespace City {

    //Constructeur
    City::City(int victory, int  treasury, bool turn) : victory_points(victory), treasury(treasury), player_turn(turn), wonder(new Wonder* [4]),
        progress_tokens(new ProgressToken* [10]), ressources(new Ressource* [30]), scientific_symbols(new ScientificSymbol* [7]), taille_scientific_symbols(0), taille_ressources(0),military_position(0) {
    }

    void City::constructBuilding() {};
    //Faire appel au consructeur de la classe Building
    void City::constructWonder() {};
    //Faire appel au consructeur de la classe Wonder
    void City::discardCard() {}
    //Appel au destructeur de card

    bool City::checkMilitaryVictory() {
        if (military_position >= 9 ) {
            std::cout << "Victoire militaire obtenue !" << std::endl;
            return true;
        }
        else {
            std::cout << "Victoire militaire non atteinte." << std::endl;
            return false;
        }
    }

    bool City::checkScientificVictory() {
        //Ici il faut une fonction pour calculer
        int unique_scientific_symbols = 6; //  Doit être calculé en fonction de la collection de symboles scientifiques.
        if (taille_scientific_symbols >= unique_scientific_symbols) {
            std::cout << "Victoire scientifique obtenue !" << std::endl;
            return true;
        }
        else {
            std::cout << "Victoire scientifique non atteinte." << std::endl;
            return false;
        }


    }
}


