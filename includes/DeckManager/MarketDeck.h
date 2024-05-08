#ifndef MARKETDECK_H
#define MARKETDECK_H

class DeckElement;
class Building;

namespace Deck {

    class MarketDeck {

    private:
        const int age;
        DeckElement** first_buildings;
        const int nb_first_buildings;

    public:
        MarketDeck() :age(0), first_buildings(nullptr), nb_first_buildings(0){};
        MarketDeck(const MarketDeck& m) = delete;
        ~MarketDeck();
        MarketDeck& operator=(const MarketDeck& m) = delete;

        void advanceAge();

        class iterator {
        private:
            DeckElement** building;
            unsigned int nb_buildings;
            friend class MarketDeck;
            iterator(DeckElement** building, const unsigned int& nb_buildings): building(building), nb_buildings(nb_buildings){};

        public:
            iterator():building(nullptr), nb_buildings(0){};
            iterator& operator++() { building++; nb_buildings--; return *this; };
            bool operator!=(const iterator& i) const { return building != i.building; };
            iterator begin() { return iterator(building, nb_buildings); };
            iterator end() { return iterator(building + nb_buildings, 0); };
            DeckElement& operator*() { return **building; };
            // méthode pour accéder au building et le supprimer de l'architecture (rajoute les building fils dans la liste des choix possibles)
            Building& getBuilding();
        };

    };

}

#endif