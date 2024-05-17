#ifndef ADDRESSOURCECHOICE_H
#define ADDRESSOURCECHOICE_H

#include "EffectFactory.h"

class City; // Déclaration anticipée de City
enum class RessourceType;

class AddRessourceChoice : public Effect {
    public:
        AddRessourceChoice();
        void effect(City* city) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

    private:
        RessourceType ressource;
        int quantity;

};

#endif
