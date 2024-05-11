#include "../../includes/DeckManager/MarketDeck.h"
#include "../../includes/DeckManager/DeckElement.h"

MarketDeck::~MarketDeck() {
    for (int i = 0; i < nb_first_buildings; i++) {
        delete first_buildings[i];
    }

};


