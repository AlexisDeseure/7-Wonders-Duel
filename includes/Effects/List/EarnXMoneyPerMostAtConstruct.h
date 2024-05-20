#ifndef EARNXMONEYPERMOSTATCONSTRUCT_H
#define EARNXMONEYPERMOSTATCONSTRUCT_H

#include "EffectFactory.h"

enum class BuildingType;

class EarnXMoneyPerMostAtConstruct : public Effect {
    public:
        EarnXMoneyPerMostAtConstruct();

        void effect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

    private:
        int money;
        BuildingType type;

};


REGISTER_CLASS(EarnXMoneyPerMostAtConstruct);

#endif
