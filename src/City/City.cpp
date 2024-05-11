#include "includes/City/City.h"

City::City(int victory, int treasury, int shields, bool turn)
    :victory_points(victory), treasury(treasury), number_of_shields(shields), player_turn(turn),
    wonder(new Wonder *[WONDER_LENGTH]), progress_tokens(new ProgressToken *[PROGRESS_TOKEN_LENGTH]),
    ressources(new Ressource*[static_cast<unsigned long long int>(RessourceType::RessourceTypeCount)]),
    scientific_symbols(new ScientificSymbol*[static_cast<unsigned long long int>(SymboleType::SymbolTypeCount)])
{}


void City::constructBuilding(Building* building) {
    // Vérifie si le joueur a les ressources nécessaires
    int cost = building->getCost(this);
    if (canAfford(cost)) {
        // Déduit les coûts des ressources
        treasury -= cost;
        // Ajoute le bâtiment à la liste des bâtiments de la cité
        // A VOIR COMMENT
        std::cout << "Bâtiment construit : " << building->getName() << std::endl;
    } else {
        std::cout << "Ressources insuffisantes pour construire ce bâtiment." << std::endl;
    }
}

void City:: constructBuilding(){};
//Faire appel au consructeur de la classe Building
void City:: constructWonder(){};
//Faire appel au consructeur de la classe Wonder
void City:: discardCard(){}

void City::discardCard(Card* card) {
    int coinsReceived = 2; // Base de pièces reçues pour défausser une carte
    // Ajoute des pièces supplémentaires si des bâtiments commerciaux spécifiques sont présents
    coinsReceived += 0;//calculer coins from commercialBuildings();
    treasury += coinsReceived;
    std::cout << "Carte défaussée pour " << coinsReceived << " pièces." << std::endl;
    // La carte est ensuite retirée du jeu ou placée dans une pile de défausse
    // A VOIR COMMENT
}


/* je pense qu'il faudrait plutôt faire ça au niveau de la classe board qui gère le jeu : par exemple à chaque tour, elle interroge l'instance
 * de la classe ConflictPawn pour savoir si un des 2 joueurs a gagné la victoire militaire
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
*/

bool City::checkScientificVictory() {
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

















