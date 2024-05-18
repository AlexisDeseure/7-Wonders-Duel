#ifndef CHANGEMARKETRULE_H
#define CHANGEMARKETRULE_H

#include "EffectFactory.h"
enum class RessourceType;

class ChangeMarketRule : public Effect {
public:
    ChangeMarketRule();
    void effect(City* city) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

private:
    RessourceType ressource;

};

REGISTER_CLASS(ChangeMarketRule);

#endif
