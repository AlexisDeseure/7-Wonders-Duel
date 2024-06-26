#ifndef MARKETDECK_H
#define MARKETDECK_H


#include <vector>
#include <ostream>

class DeckElement;
class Building;
class MarketDeck {

    private:
        std::vector<std::vector<DeckElement*>> elements;
        std::vector<DeckElement*> selectable_elements;

    public:
        MarketDeck() = default;
        ~MarketDeck() = default;
        MarketDeck(const MarketDeck& m) = delete;
        MarketDeck& operator=(const MarketDeck& m) = delete;

        void advanceAge(int age, std::vector<Building*>& buildings);
        bool isEmpty() const { return selectable_elements.empty(); };
        std::vector<DeckElement*>& getFirstBuildings() {return selectable_elements;};
        std::vector<std::vector<DeckElement*>>& getAllBuildings() { return elements; };
        void getBuilding(unsigned int i );
        void addFirstBuilding(DeckElement* building, unsigned int index) ;
        void print();


        //        class iterator {
//            private:
//                DeckElement** building;
//                unsigned int nb_buildings;
//                friend class MarketDeck;
//                iterator(DeckElement** building, const unsigned int& nb_buildings): building(building), nb_buildings(nb_buildings){};
//
//            public:
//                iterator():building(nullptr), nb_buildings(0){};
//                iterator& operator++() { building++; nb_buildings--; return *this; };
//              //  void removeBuilding(DeckElement* building) ;
//                bool operator!=(const iterator& i) const { return building != i.building; };
//                iterator begin() { return iterator(building, nb_buildings); };
//                iterator end() { return iterator(building + nb_buildings, 0); };
//                DeckElement& operator*() { return **building; };
//                //Méthode pour accéder au building et le supprimer de l'architecture (rajoute les building fils dans la liste des choix possibles)
//                DeckElement& getBuilding(MarketDeck& M);
//
//        };


};

std::ostream &operator<<(std::ostream& os, const MarketDeck& m);


#endif
