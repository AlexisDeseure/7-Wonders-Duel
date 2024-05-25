#include "AddScientificSymbol.h"
#include "ScientificSymbol.h"
#include "Game.h"
#include "Player.h"
#include "City.h"


AddScientificSymbol::AddScientificSymbol() : symbol(SymboleType::LENGTH), quantity(0) {}

void AddScientificSymbol::effect(Game& game) {
    game.getTurnPlayer().getCity().getScientificSymbol(symbol) += quantity;
}

void AddScientificSymbol::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
    symbol = StringToSymboleType(string_parameters[0]);
}
