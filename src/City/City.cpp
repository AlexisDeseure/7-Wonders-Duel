#include "../../includes/City/City.h"
#include"../../includes/Cards/Wonder.h"
#include"../../includes/Cards/Building.h"
#include"../../includes/Cards/ProgressToken.h"
#include"../../includes/City/Ressource.h"
#include"../../includes/City/ScientificSymbol.h"

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

void City::constructWonder(Wonder* wonder) {
    int cost = wonder->getCost(this);
    if (canAfford(cost) && !wonder->isBuilt()) {
        treasury -= cost;
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
    int unique_scientific_symbols = SCIENTIFIC_SYMBOL_LENGTH-1; //  Doit être calculé en fonction de la collection de symboles scientifiques.
    if (getDistinctScientificSymbols() >= unique_scientific_symbols) {
        std::cout << "Victoire scientifique obtenue !" << std::endl;
        return true;
    }
    else {
        std::cout << "Victoire scientifique non atteinte." << std::endl;
        return false;
    }


}


