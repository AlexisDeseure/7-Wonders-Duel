#ifndef ADDMONEY_H
#define ADDMONEY_H

#include "EffectFactory.h"

class AddMoney : public Effect {
    public:
        AddMoney() : quantity(0) {};

        void print() override{ std::cout << "Obtenir " << quantity << " pièces" << std::endl;};
        void effect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

    private:
        int quantity;
};

// Enregistrement de la classe AddMoney dans la factory pour pouvoir l'instancier à partir de son nom
REGISTER_CLASS(AddMoney);


#endif
