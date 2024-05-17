#ifndef ADDRESSOURCE_H
#define ADDRESSOURCE_H

#include "EffectFactory.h"

class City; // Déclaration anticipée de City
enum class RessourceType;

class AddRessource : public Effect {
    public:
        AddRessource();
        void effect(City* city) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

    private:
        RessourceType ressource;
        int quantity;

};

REGISTER_CLASS(AddRessource);

#endif
