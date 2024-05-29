#ifndef EARNVICTORYPOINTPERLOTOFMONEYMOSTATENDGAME_H
#define EARNVICTORYPOINTPERLOTOFMONEYMOSTATENDGAME_H

#include "EffectFactory.h"
#include <vector>

class City;

class EarnVictoryPointPerLotOfMoneyMostAtEndGame : public Effect {
    public:
        EarnVictoryPointPerLotOfMoneyMostAtEndGame() = default;

        void effect(Game& game) override;
        void endEffect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
        void print() override {std::cout << "Gagner " << number << " point de victoire par lot de " << batch_size << " pièces de la ville la plus riche à la fin de la partie" << std::endl;};
    private:
        int number;
        int batch_size; //nombre de pièce par point de victoire

};


REGISTER_CLASS(EarnVictoryPointPerLotOfMoneyMostAtEndGame);


#endif // EARNVICTORYPOINTPERLOTOFMONEYMOSTATENDGAME_H
