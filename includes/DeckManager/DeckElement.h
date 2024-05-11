#ifndef DECKELEMENT_H
#define DECKELEMENT_H

class Building;

class DeckElement {
    private:
        const DeckElement* const right_son;
        const DeckElement* const left_son;
        const DeckElement* const right_father;
        const DeckElement* const left_father;
        const Building* building;
        bool visible;

    public:
        DeckElement(const Building* b, const bool& visible = true, const DeckElement* right_son = nullptr, const DeckElement* left_son = nullptr,  const DeckElement* right_father = nullptr,  const DeckElement* left_father = nullptr ): right_son(right_son), left_son(left_son), right_father(right_father), left_father(left_father), building(b), visible(visible){};
        ~DeckElement() = default;
        DeckElement& operator=(const DeckElement& d) = delete;

        const DeckElement* getRightSon() const { return right_son; };
        const DeckElement* getLeftSon() const { return left_son; };
        const DeckElement* getRightFather() const { return right_father; };
        const DeckElement* getLeftFather() const { return left_father; };
        const Building* getBuilding() const { return building; };
        bool isVisible() const { return visible; };
        void setVisible() { if (!visible) visible = true; };
        const DeckElement* operator++(int) const { return right_son; };
        const DeckElement* operator++() const { return left_son; };
        const DeckElement* operator--(int) const { return right_father; };
        const DeckElement* operator--() const { return left_father; };

    };


#endif
