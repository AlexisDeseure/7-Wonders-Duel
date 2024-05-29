#ifndef MOVECONFLICTPAWN_H
#define MOVECONFLICTPAWN_H

#include "EffectFactory.h"

class MoveConflictPawn : public Effect {
public:
    MoveConflictPawn() : amount(0) {};

    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void print() override {std::cout << "Gagner " << amount << " boucliers" << std::endl;};
private:
    int amount;
};

REGISTER_CLASS(MoveConflictPawn);

#endif
