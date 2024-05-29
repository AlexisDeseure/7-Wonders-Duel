#ifndef BUILDINGCOSTREDUCEDBYX_H
#define BUILDINGCOSTREDUCEDBYX_H

#include "EffectFactory.h"

enum class BuildingType;

class BuildingCostReducedByX: public Effect {
public:
    BuildingCostReducedByX(): reduction(0) {};

    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void eachTurnEffect(Game& game, Card& card) override;
    void print() override;

private:
    int reduction;
    BuildingType type;
};

REGISTER_CLASS(BuildingCostReducedByX);

#endif // BUILDINGCOSTREDUCEDBYX_H
