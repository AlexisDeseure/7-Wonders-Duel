#ifndef EARNMONEYPERWONDERATCONSTRUCT_H
#define EARNMONEYPERWONDERATCONSTRUCT_H

#include "EffectFactory.h"

class EarnMoneyPerWonderAtConstruct : public Effect {
    public:
        EarnMoneyPerWonderAtConstruct() : money(0) {};

        void effect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
        void print() override {std::cout << "Gagner " << money << " pièces par merveille construite" << std::endl;};
    private:
        int money;

};


REGISTER_CLASS(EarnMoneyPerWonderAtConstruct);

#endif
