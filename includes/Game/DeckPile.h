#ifndef DECKPILE_H
#define DECKPILE_H

#include <vector>
#include <utility>

class Building;
class Wonder;
class ProgressToken;

class DeckPile{
private:
    std::pair<std::vector<Building*>, std::vector<Building*>> buildings;
    std::vector<Wonder*> wonders;
    std::pair<std::vector<ProgressToken*>,std::vector<ProgressToken*>> progress_tokens;

    int nb_buildings;

public:
    DeckPile(int nb_buildings, int nb_token, int nb_wonder);

    void addDiscardedBuilding(Building* build);

    Wonder* selectNextWonder();
    Building* selectNextBuilding();
    ProgressToken* selectNextProgressToken();

    std::vector<Building*> getDiscardedBuildings() {return buildings.second;};
    std::vector<ProgressToken*> getOtherProgressTokens() {return progress_tokens.second;};

    void advanceAge(int age);
};

#endif // DECKPILE_H
