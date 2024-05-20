#ifndef EARNXVICTORYPOINTPERLOTOFMONEYMOSTATENDGAME_H
#define EARNXVICTORYPOINTPERLOTOFMONEYMOSTATENDGAME_H

#include "EffectFactory.h"
#include <vector>

class City;

class EarnXVictoryPointPerLotOfMoneyMostAtEndGame : public Effect {
    public:
        EarnXVictoryPointPerLotOfMoneyMostAtEndGame() = default;

        void effect(Game& game) override;
        void endEffect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

    private:
        int number;
        int batch_size; //nombre de pièce par point de victoire

};


REGISTER_CLASS(EarnXVictoryPointPerLotOfMoneyMostAtEndGame);


#endif // EARNXVICTORYPOINTPERLOTOFMONEYMOSTATENDGAME_H
