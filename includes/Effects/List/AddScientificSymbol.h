#ifndef ADDSCIENTIFICSYMBOL_H
#define ADDSCIENTIFICSYMBOL_H

#include "EffectFactory.h"

enum class SymboleType;


class AddScientificSymbol : public Effect {
public:
    AddScientificSymbol();
    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void print() override;
private:
    SymboleType symbol;
    int quantity;
};

REGISTER_CLASS(AddScientificSymbol);

#endif
