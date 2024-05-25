#ifndef EARNMONEYPERMOSTATCONSTRUCT_H
#define EARNMONEYPERMOSTATCONSTRUCT_H

#include "EffectFactory.h"

enum class BuildingType;

class EarnMoneyPerMostAtConstruct : public Effect {
    public:
        EarnMoneyPerMostAtConstruct();

        void effect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

    private:
        int money;
        BuildingType type;

};


REGISTER_CLASS(EarnMoneyPerMostAtConstruct);

#endif
