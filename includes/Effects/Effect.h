#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <vector>

class Game;
class Card;

class Effect{
    public:
        Effect() = default;
        virtual ~Effect() = default;

        // implementation of the template method design pattern
        void apply(Game& game);
        virtual void effect(Game& game) = 0;

        virtual void inverseEffect([[maybe_unused]] Game& game) {};
        virtual void endEffect([[maybe_unused]] Game& game) {};
        virtual void eachTurnEffect([[maybe_unused]] Game& game, [[maybe_unused]] Card& card) {};
        virtual void setParameters([[maybe_unused]] std::vector<int> int_parameters, [[maybe_unused]] std::vector<std::string> string_parameters) {};
};





#endif
