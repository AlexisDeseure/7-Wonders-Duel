#ifndef EFFECT_H
#define EFFECT_H

#include <iostream>
#include <map>
#include <vector>

class City; // Déclaration anticipée de la classe City

class Effect{
    public:
        Effect() = default;
        virtual ~Effect() = default;

        // implementation of the template method design pattern
        void apply(City* city);
        virtual void effect(City* city) = 0;
        virtual void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) = 0;
};



#endif
