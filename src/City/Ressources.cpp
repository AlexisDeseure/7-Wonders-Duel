#include"Ressource.h"

const std::array<std::string, static_cast<int>(RessourceType::LENGTH)> ressource_name { "Wood", "Stone", "Clay", "Paper", "Glass"};

std::string ressourceTypeToString(RessourceType type){
    if (type == RessourceType::LENGTH){
        throw "RessourceType out of range";
    }
    return ressource_name[static_cast<std::size_t>(type)];
}

RessourceType StringToRessourceType(std::string nom){
    for (std::size_t i = 0; i < static_cast<int>(RessourceType::LENGTH); i++){
        if (nom == ressource_name[i]){
            return static_cast<RessourceType>(i);
        }
    }
    throw "RessourceType not found";
}

//std::ostream& operator<<(std::ostream& os, const Ressource& ressource) {
//    os << "Amount: " << ressource.getAmount() << "\n" << "Price: " << ressource.getPrice();
//    os << "\n";
//    os << "Type : ";
//    if (static_cast<int>(ressource.getType()) == 0) os << "Wood";
//    if (static_cast<int>(ressource.getType()) == 1) os << "Stone";
//    if (static_cast<int>(ressource.getType()) == 2) os << "Clay";
//    if (static_cast<int>(ressource.getType()) == 3) os << "Paper";
//    if (static_cast<int>(ressource.getType()) == 4) os << "Glass";
//    if (static_cast<int>(ressource.getType()) == 5) os << "LENGTH";
//
//    return os;
//}

