#ifndef DECKELEMENT_H
#define DECKELEMENT_H

#include"Building.h"


class DeckElement: public Building {
    private:
        DeckElement* right_son;
        DeckElement* left_son;
        DeckElement* right_father;
        DeckElement* left_father;
        bool visible;

    public:
        DeckElement(const std::string& name, const std::vector<RessourceCost>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, BuildingType t,
                    int a, const std::vector<std::string>& chainIn = {}, const std::vector<std::string>& chainOut = {},
                    DeckElement* right_son = nullptr, DeckElement* left_son = nullptr, DeckElement* right_father = nullptr, DeckElement* left_father = nullptr,
                    const bool& visible = true)
            : Building(name, cost, effects, direct_cost, t, a, chainIn, chainOut),
            right_son(right_son), left_son(left_son), right_father(right_father), left_father(left_father), visible(visible) {}
        ~DeckElement() = default ;
        DeckElement& operator=(const DeckElement& d) = delete;
        const DeckElement* getRightSon() const { return right_son; };
        void deleteDeckFromMarket() const ;
        const DeckElement* getLeftSon() const { return left_son; };
        const DeckElement* getRightFather() const { return right_father; };
        const DeckElement* getLeftFather() const { return left_father; };
        //getBuilding ne sert plus a rien apres l'heritage
       //const Building* getBuilding() const { return this; };
        bool isVisible() const { return visible; };
        void setVisible() { if (!visible) visible = true; };
        const DeckElement* operator++(int) const { return right_son; };
        const DeckElement* operator++() const { return left_son; };
        const DeckElement* operator--(int) const { return right_father; };
        const DeckElement* operator--() const { return left_father; }

    };

#endif
