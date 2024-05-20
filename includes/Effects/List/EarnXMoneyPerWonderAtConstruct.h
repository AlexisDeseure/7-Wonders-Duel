#ifndef EARNXMONEYPERWONDERATCONSTRUCT_H
#define EARNXMONEYPERWONDERATCONSTRUCT_H

#include "EffectFactory.h"

class EarnXMoneyPerWonderAtConstruct : public Effect {
    public:
        EarnXMoneyPerWonderAtConstruct() : money(0) {};

        void effect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

    private:
        int money;

};


REGISTER_CLASS(EarnXMoneyPerWonderAtConstruct);

#endif
