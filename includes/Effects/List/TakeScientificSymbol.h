#ifndef TAKESCIENTIFICSYMBOL_H
#define TAKESCIENTIFICSYMBOL_H

#include "EffectFactory.h"

enum class SymboleType;


class TakeScientificSymbol : public Effect {
public:
    TakeScientificSymbol();
    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

private:
    SymboleType symbol;
    int quantity;
};

REGISTER_CLASS(TakeScientificSymbol);

#endif
