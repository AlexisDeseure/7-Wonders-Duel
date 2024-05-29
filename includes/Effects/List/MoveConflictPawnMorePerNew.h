#ifndef MOVECONFLICTPAWNMOREPERNEW_H
#define MOVECONFLICTPAWNMOREPERNEW_H

#include "EffectFactory.h"

enum class BuildingType;

class MoveConflictPawnMorePerNew: public Effect {
public:
    MoveConflictPawnMorePerNew(): shields(0) {};
    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void eachTurnEffect(Game& game, Card& card) override;
    void print() override;
private:
    int shields;
    BuildingType type;
};

REGISTER_CLASS(MoveConflictPawnMorePerNew);

#endif
