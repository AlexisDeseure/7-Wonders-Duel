#ifndef DECKELEMENT_H
#define DECKELEMENT_H

#include"Building.h"
#include<ostream>

class DeckElement {
    private:
        DeckElement* right_son;
        DeckElement* left_son;
        DeckElement* right_father;
        DeckElement* left_father;
        Building* building;
        bool visible;

    public:
        DeckElement(DeckElement* right_son = nullptr, DeckElement* left_son = nullptr,
                    DeckElement* right_father = nullptr, DeckElement* left_father = nullptr,
                    const bool& visible = true)
            : right_son(right_son), left_son(left_son), right_father(right_father),
            left_father(left_father), building(nullptr), visible(visible) {}
        ~DeckElement() = default ;
        DeckElement& operator=(const DeckElement& d) = delete;

        void deleteDeckFromMarket() const;

        DeckElement* getRightSon() const { return right_son; };
        DeckElement* getLeftSon() const { return left_son; };
        DeckElement* getRightFather() const { return right_father; };
        DeckElement* getLeftFather() const { return left_father; };
        Building* getBuilding() const { return building; };

        void setRightSon(DeckElement* new_el) { right_son = new_el; };
        void setLeftSon(DeckElement* new_el) { left_son = new_el; };
        void setRightFather(DeckElement* new_el) { right_father = new_el; };
        void setLeftFather(DeckElement* new_el) { left_father = new_el; };
        void setBuilding(Building* new_building) { building = new_building; };

        DeckElement& operator++(int) const { return *right_son; };
        DeckElement& operator++() const { return *left_son; };
        DeckElement& operator--(int) const { return *right_father; };
        DeckElement& operator--() const { return *left_father; }

        //getBuilding ne sert plus a rien apres l'heritage
       //const Building* getBuilding() const { return this; };
        bool isVisible() const { return visible; };
        void setVisible(bool v=true) { visible = v; };


    };

std::ostream &operator<<(std::ostream& os, const DeckElement& d);

#endif
