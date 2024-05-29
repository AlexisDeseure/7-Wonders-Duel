#ifndef EARNVICTORYPOINTSPERPROGRESSTOKENATENDGAME_H
#define EARNVICTORYPOINTSPERPROGRESSTOKENATENDGAME_H

#include "EffectFactory.h"
#include <vector>

class City;

class EarnVictoryPointsPerProgressTokenAtEndGame : public Effect {
public:
    EarnVictoryPointsPerProgressTokenAtEndGame() = default;

    void effect(Game& game) override;
    void endEffect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void print() override {std::cout << "Gagner " << number << " points de victoire par jeton progrès à la fin de la partie" << std::endl;};
private:
    int number;
};


REGISTER_CLASS(EarnVictoryPointsPerProgressTokenAtEndGame);

#endif
