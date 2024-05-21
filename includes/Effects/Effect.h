#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <vector>
#include <iostream>

class Game;
class Card;

class Effect{
    public:
        Effect() = default;
        virtual ~Effect() = default;

        // implementation of the template method design pattern
        void apply(Game& game);
        virtual void effect(Game& game) = 0;
        virtual void endEffect(Game& game) {};
        virtual void eachTurnEffect(Game& game, Card& card) {};
        virtual void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) = 0;
};



#endif
