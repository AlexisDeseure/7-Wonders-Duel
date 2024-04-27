//
// Created by mateo on 27/04/2024.
//

#ifndef INC_7_WONDERS_DUEL_SCIENTIFICSYMBOLEFFECT_H
#define INC_7_WONDERS_DUEL_SCIENTIFICSYMBOLEFFECT_H
#include <iostream>
#include "Effect.h"
using namespace std;

namespace ScientificSymbolEffect {
    class ScientificSymbolEffect : public Effect{
    private:
        string symbolname;
    public:
        void apply(){};
    };
}

#endif //INC_7_WONDERS_DUEL_SCIENTIFICSYMBOLEFFECT_H
