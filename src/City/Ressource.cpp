#include"Ressource.h"

const std::array<std::string, static_cast<int>(RessourceType::LENGTH)> ressource_name { "Wood", "Stone", "Clay", "Paper", "Glass"};


Ressource::Ressource(std::vector<RessourceType> t, unsigned int a, unsigned int p) : types(std::move(t)),amount(a),price(p), isTradeable(true){
    if (types.size() > 1) {
        isTradeable = false;
        price = 0;  //convention pour les ressources non échangeables (ressources à choix)
    }
}

void Ressource::updatePrice(int sum) {
    if (isTradeable) {
        price += sum;
    }
    throw std::invalid_argument("error : ressource à choix ne peut pas avoir de prix");
}

void Ressource::add(int sum) {
    if (isTradeable) {
        amount += sum;
    }
    throw std::invalid_argument("error : ressource à choix ne peut pas avoir de quantité");
}
void Ressource::operator+=(unsigned int sum) {
    if (isTradeable) {
        amount += sum;
    }
    throw std::invalid_argument("error : ressource à choix ne peut pas avoir de quantité");
}

unsigned int Ressource::getAmount() const {
    if(isTradeable){
        return amount;
    }
    throw std::invalid_argument("error : ressource à choix n'a pas de quantité");
}

RessourceType Ressource::getType() const {
    if (types.size() == 1) {
        return types[0];
    }
    throw std::invalid_argument("error : ressource à choix n'a pas de type unique");
}

unsigned int Ressource::getPrice() const {
    if (isTradeable) {
        return price;
    }
    throw std::invalid_argument("error : ressource à choix ne peut pas avoir de prix");
}




std::string ressourceTypeToString(RessourceType type){
    if (type == RessourceType::LENGTH){
        throw std::invalid_argument("RessourceType out of range");
    }
    return ressource_name[static_cast<std::size_t>(type)];
}

RessourceType StringToRessourceType(std::string nom){
    for (std::size_t i = 0; i < static_cast<int>(RessourceType::LENGTH); i++){
        if (nom == ressource_name[i]){
            return static_cast<RessourceType>(i);
        }
    }
    throw std::invalid_argument("RessourceType not found");
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

