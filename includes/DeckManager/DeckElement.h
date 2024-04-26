#ifndef DECKELEMENT_H
#define DECKELEMENT_H

namespace Deck {

    class DeckElement {
        private:
            const DeckElement* const right_son;
            const DeckElement* const left_son;
            const Building& building;
            bool visible;

        public:
            DeckElement(const Building& building, const DeckElement* right_son = nullptr, const DeckElement* left_son = nullptr, const bool& visible = true): right_son(right_son), left_son(left_son), building(building), visible(visible){};
            ~DeckElement() = default;
            DeckElement& operator=(const DeckElement& d) = delete;

            const DeckElement* getRightSon() const { return right_son; };
            const DeckElement* getLeftSon() const { return left_son; };
            const Building& getBuilding() const { return building; };
            bool isVisible() const { return visible; };
            void setVisible() { if (!visible) visible = true; };
            DeckElement operator++(int) const { return *right_son; };
            DeckElement operator++() const { return *left_son; };

        };

} // DeckElement

#endif
