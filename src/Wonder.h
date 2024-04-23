//
// Created by mateo on 09/04/2024.
//

#ifndef PROJET_WONDER_H
#define PROJET_WONDER_H

class Card;
namespace Wonder {

    class Wonder : public Card{
    private:
        bool active; //Montre si la merveille est sur le plateau
        const City* city;
    public:
        Wonder(); //Constructeur
        void select(); //Selecteur? à voir
    };

} // Wonder

#endif //PROJET_WONDER_H
