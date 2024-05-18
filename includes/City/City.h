#ifndef CITY_H
#define CITY_H

#define PROGRESS_TOKEN_LENGTH 10
#define WONDER_LENGTH 4

#include <string>
#include <vector>
#include <list>


class Building;
class Wonder;
class ProgressToken;
class Ressource;
class ScientificSymbol;
class Card;
enum class RessourceType;
enum class SymboleType;

class City {
    private:
        int victory_points;
        int treasury;
        int number_of_shields;

        std::vector<Wonder*> wonders;
        std::vector<ProgressToken*> progress_tokens;
        std::vector<Ressource*> ressources;
        std::vector<ScientificSymbol*> scientific_symbols;
        std::vector<Building*> buildings;
        std::vector<std::string> chain_symbols;

    public:
        City(int victory = 0, int treasury = 0, int shields = 0);
        ~City();
        Ressource& getRessource(RessourceType name);
        std::vector<Ressource*>& getRessources();
        unsigned int getPriceForRemainingRessources(std::list<RessourceType>& remaining_ressources); //permet de calculer le
        // prix pour les ressources manquantes (ie : celles qui ne sont pas représentées par les ressources "classiques"
        // de la ville) à partir des ressource à choix
        int getDistinctScientificSymbols() const;
        bool canAfford(int price) const;
        bool constructBuilding(Building* building);
        bool constructWonder(Wonder* wonder);
        void discardCard(Card* card);
        bool checkScientificVictory();
        void addMoney(int money);
        void addRessource(std::vector<RessourceType> types);
        void addVictoryPoints(int points);
        void addShields(int shields);
        void addChainSymbol(const std::string& symbol); //permet d'ajouter le nom d'un symbole de chainage à la ville
        bool hasChainSymbol(const std::string& symbol) const; //permet de vérifier si un symbole de chainage est présent dans la ville
};

template <typename T>
void removeFirstElement(std::list<T>& vec, const T& element);

#endif // CITY_H
