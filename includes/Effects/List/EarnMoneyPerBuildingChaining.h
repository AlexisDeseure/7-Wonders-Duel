#ifndef EARNMONEYPERBUILDINGCHAINING_H
#define EARNMONEYPERBUILDINGCHAINING_H

#include "EffectFactory.h"

class EarnMoneyPerBuildingChaining : public Effect {
public:
    EarnMoneyPerBuildingChaining() : money(0) {};

    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void eachTurnEffect(Game& game, Card& card) override;
    void print() override { std::cout << "Obtenir " << money << " pièces par bâtiment obtenus par chaînage" << std::endl; };
private:
    int money;

};


REGISTER_CLASS(EarnMoneyPerBuildingChaining);

#endif
