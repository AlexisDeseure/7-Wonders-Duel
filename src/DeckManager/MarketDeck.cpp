#include "MarketDeck.h"
#include "DeckElement.h"

MarketDeck::~MarketDeck() {
    for (int i = 0; i < nb_first_buildings; i++) {
        delete first_buildings[i];
    }

};


