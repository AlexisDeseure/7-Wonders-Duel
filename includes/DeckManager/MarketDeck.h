#ifndef MARKETDECK_H
#define MARKETDECK_H
#include"Card.h"
#include"Building.h"
#include"DeckElement.h"

class MarketDeck {

    private:
        const int age;
        const DeckElement** first_buildings;
        int nb_first_buildings;
        friend class iterator ;


    public:
        MarketDeck() :age(0), first_buildings(nullptr), nb_first_buildings(0){};
        MarketDeck(const MarketDeck& m) = delete;
       // void removeBuilding(DeckElement* building) ;
        ~MarketDeck();
        MarketDeck& operator=(const MarketDeck& m) = delete;
        void advanceAge();
        bool isEmpty() const { return nb_first_buildings == 0; };
        void addFirstBuilding(const DeckElement* building) ;
        class iterator {
        private:
            DeckElement** building;
            unsigned int nb_buildings;
            friend class MarketDeck;
            iterator(DeckElement** building, const unsigned int& nb_buildings): building(building), nb_buildings(nb_buildings){};

        public:
            iterator():building(nullptr), nb_buildings(0){};
            iterator& operator++() { building++; nb_buildings--; return *this; };
          //  void removeBuilding(DeckElement* building) ;
            bool operator!=(const iterator& i) const { return building != i.building; };
            iterator begin() { return iterator(building, nb_buildings); };
            iterator end() { return iterator(building + nb_buildings, 0); };
            DeckElement& operator*() { return **building; };
            //Méthode pour accéder au building et le supprimer de l'architecture (rajoute les building fils dans la liste des choix possibles)
            DeckElement& getBuilding(MarketDeck& M);

        };


    };

#endif
