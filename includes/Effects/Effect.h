#ifndef EFFECT_H
#define EFFECT_H

#include <iostream>

class City; // Déclaration anticipée de la classe City

class Effect{
    public:
        Effect(std::string nom): name(std::move(nom)) {};
        virtual ~Effect() = default;
        std::string getName() const {return name;};
        void apply(City* city) const;
        virtual void effect(City* city) const = 0;
    private:
        std::string name;
};


#endif
