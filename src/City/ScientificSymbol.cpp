#include "ScientificSymbol.h"
#include "iostream"

std::string symboleTypeToString(SymboleType type){
    if (type == SymboleType::LENGTH){
        throw std::invalid_argument("SymboleType out of range");
    }
    return symbole_name[static_cast<std::size_t>(type)];
}

SymboleType StringToSymboleType(std::string nom){
    for (std::size_t i = 0; i < static_cast<int>(SymboleType::LENGTH); i++){
        if (nom == symbole_name[i]){
            return static_cast<SymboleType>(i);
        }
    }
    throw std::invalid_argument("SymboleType not found");
}

void ScientificSymbol::print() const {
    std::cout<<"- "<<symboleTypeToString(symbol_type)<<" : "<<count<<std::endl;
};
