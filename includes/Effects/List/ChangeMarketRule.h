#ifndef CHANGEMARKETRULE_H
#define CHANGEMARKETRULE_H

#include "EffectFactory.h"
enum class RessourceType;

class ChangeMarketRule : public Effect {
public:
    ChangeMarketRule();
    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void print() override;

private:
    RessourceType ressource;

};

REGISTER_CLASS(ChangeMarketRule);

#endif
