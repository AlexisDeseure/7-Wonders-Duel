#include "City/City.h"

//Constructeur
City::City(int victory, int  treasury, int shields, bool turn) : victory_points(victory), treasury(treasury), number_of_shields(shields), player_turn(turn), wonder(new Wonder* [4]),
                                                                 progress_tokens(new ProgressToken* [10]), ressources(new Ressource* [30]), scientific_symbols(new ScientificSymbol* [7]),taille_scientific_symbols(0),taille_ressources(0) {
}

void City::constructBuilding(Building* building) {
    // Vérifie si le joueur a les ressources nécessaires
    if (canAfford(building->getCost())) {
        // Déduit les coûts des ressources
        treasury -= building->getCost();
        // Ajoute le bâtiment à la liste des bâtiments de la cité
        // A VOIR COMMENT
        std::cout << "Bâtiment construit : " << building->getName() << std::endl;
    } else {
        std::cout << "Ressources insuffisantes pour construire ce bâtiment." << std::endl;
    }
}

void City::constructWonder(Wonder* wonder) {
    if (canAfford(wonder->getCost()) && !wonder->isBuilt()) {
        treasury -= wonder->getCost();
        wonder->setBuilt(true);
        std::cout << "Merveille construite : " << wonder->getName() << std::endl;
        // Active l'effet de la merveille si nécessaire
        // A FAIRE
    } else {
        std::cout << "Conditions non remplies pour construire cette merveille." << std::endl;
    }
}

void City::discardCard(Card* card) {
    int coinsReceived = 2; // Base de pièces reçues pour défausser une carte
    // Ajoute des pièces supplémentaires si des bâtiments commerciaux spécifiques sont présents
    coinsReceived += calculer coins from commercialBuildings();
    treasury += coinsReceived;
    std::cout << "Carte défaussée pour " << coinsReceived << " pièces." << std::endl;
    // La carte est ensuite retirée du jeu ou placée dans une pile de défausse
    // A VOIR COMMENT
}

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