#ifndef DECKELEMENT_H
#define DECKELEMENT_H

namespace DeckElement {

    class DeckElement {
    private:
        bool is_root;
        const DeckElement* right_son;
        const DeckElement* left_son;
        const Building* building;
        const MarketDeck* m_deck;
    public:
        bool root_status() const{return is_root;}

        DeckElement(): is_root(false), right_son(nullptr), left_son(nullptr){};
        DeckElement(const bool& root): is_root(root), right_son(nullptr),left_son(nullptr){};
        DeckElement(const DeckElement& r_son): is_root(false), right_son(&r_son), left_son(nullptr){};
        DeckElement(const DeckElement& r_son, const DeckElement& l_son): is_root(false), right_son(&r_son), left_son(&l_son){};
        DeckElement(const bool& root, const DeckElement& r_son, const DeckElement& l_son): is_root(root), right_son(&r_son), left_son(&l_son){};
    };

} // DeckElement

#endif //PROJET_DECKELEMENT_H
