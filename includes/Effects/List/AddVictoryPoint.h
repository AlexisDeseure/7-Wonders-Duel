#ifndef ADDVICTORYPOINT_H
#define ADDVICTORYPOINT_H

#include "EffectFactory.h"

class AddVictoryPoint : public Effect {
    public:
        AddVictoryPoint() : quantity(0) {};
        void effect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
        int getQuantity(){return quantity;};

    private:
        int quantity;

};

REGISTER_CLASS(AddVictoryPoint);

#endif
