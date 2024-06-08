#ifndef CITY_H
#define CITY_H

#include <string>
#include <vector>
#include <list>
#include <algorithm>

class Building;
class Wonder;
class ProgressToken;
class Ressource;
class ScientificSymbol;
class Card;
class Game;
class Effect;
enum class RessourceType;
enum class SymboleType;
enum class BuildingType;

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

        std::list<Effect*> eachTurnEffects;
        std::list<Effect*> endGameEffects;

    public:
        City(int treasury = 0);
        ~City();
        Ressource& getRessource(RessourceType name);
        ScientificSymbol& getScientificSymbol(SymboleType name);
        std::vector<ScientificSymbol*>& getScientificSymbols();
        std::vector<Ressource*>& getRessources();
        std::vector<Wonder*>& getWonders();
        std::vector<ProgressToken*>& getProgressTokens();
        std::vector<Building*>& getBuildings();

        int getDistinctScientificSymbols() const;
        int getTreasury() const;
        int getNumberOfBuildingType(BuildingType type) const; //obtenir le nombre du building possédés d'une même couleur
        int getShields() const {return number_of_shields;}
        int getVictoryPoints() const{ return victory_points;};

        bool canAfford(int price) const;
        bool constructBuilding(Building* building, Game& game);
        bool constructWonder(Wonder* wonder, Game& game);
        void discardBuilding(Building* building, Game& game);
        bool checkScientificVictory(); //sera surtout gérer dans game ou player mais garder pour les opérations dans city (simplifier la relecture: elle sera appelée par une autre méthode et ainsi de suite)
        bool hasChainSymbol(const std::string& symbol) const; //permet de vérifier si un symbole de chainage est présent dans la ville

        void addMoney(int money);
        void addRessource(std::vector<RessourceType> types);
        void addVictoryPoints(int points);
        void addShields(int shields);
        void addChainSymbol(const std::string& symbol); //permet d'ajouter le nom d'un symbole de chainage à la ville
        void addEachTurnEffects(Effect* effect);
        void addEndGameEffects(Effect* effect);
        void addCard(Card& card); //permet d'ajouter une carte à la ville (fonctionne pour tous les types)
        void addWonder(Wonder* wonder);
        void addScientificSymbol(SymboleType name, int quantity, Game& game);
        void addProgressToken(ProgressToken* PT, Game& game);

        void removeBuilding(Building* building);
        void applyEndEffects(Game& game);
        void applyEachTurnEffects(Game& game, Card& card);
        void updateRemainingRessources(std::list<RessourceType>& remaining_ressources); //permet de modifier la liste des ressources manquantes (ie : celles qui ne sont pas représentées par les ressources "classiques"
        // de la ville) à partir des ressource à choix
};

template <typename T>
void removeFirstElement(std::list<T>& vec, const T& element) {
    auto it = std::find(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        vec.erase(it);
    }
}

#endif // CITY_H
