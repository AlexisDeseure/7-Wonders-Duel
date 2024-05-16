#include"Ressource.h"

std::string ressourceTypeToString(RessourceType type){
    switch (type) {
        case RessourceType::Wood:
            return "Wood";
        case RessourceType::Stone:
            return "Stone";
        case RessourceType::Clay:
            return "Clay";
        case RessourceType::Paper:
            return "Paper";
        case RessourceType::Glass:
            return "Glass";
        case RessourceType::RessourceTypeCount:
            return "RessourceTypeCount";
    }
    return "Unknown";
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
//    if (static_cast<int>(ressource.getType()) == 5) os << "RessourceTypeCount";
//
//    return os;
//}

