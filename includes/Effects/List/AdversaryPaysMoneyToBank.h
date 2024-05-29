#ifndef ADVERSARYPAYSMONEYTOBANK_H
#define ADVERSARYPAYSMONEYTOBANK_H

#include "EffectFactory.h"

class AdversaryPaysMoneyToBank : public Effect {
public:
    AdversaryPaysMoneyToBank() : quantity(0) {};

    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void print() override{ std::cout << "L'adversaire paye " << quantity << " pièces" << std::endl;};

private:
    int quantity;
};

REGISTER_CLASS(AdversaryPaysMoneyToBank);

#endif
