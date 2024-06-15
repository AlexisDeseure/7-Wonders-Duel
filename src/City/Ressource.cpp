#include"Ressource.h"

#include "iostream"

Ressource::Ressource(std::vector<RessourceType> t, unsigned int a, unsigned int p) : types(std::move(t)),amount(a),price(p),isTradable((types.size() <= 1)),isMarketRuleHasChanged(false){}

void Ressource::updatePrice(int sum) {
    if (isTradable) {
        price += sum;
        return;
    }
    throw std::invalid_argument("error : ressource à choix ne peut pas avoir de prix");
}

void Ressource::add(int sum) {
    if (isTradable) {
        amount += sum;
        return;
    }
    throw std::invalid_argument("error : ressource à choix ne peut pas avoir de quantité");
}
void Ressource::operator+=(unsigned int sum) {
    if (isTradable) {
        amount += sum;
        return;
    }
    throw std::invalid_argument("error : ressource à choix ne peut pas avoir de quantité");
}

unsigned int Ressource::getAmount() const {
    if(isTradable){
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
    if (isTradable) {
        if (isMarketRuleHasChanged) return 1;
        else return price;
    }
    throw std::invalid_argument("error : ressource à choix ne peut pas avoir de prix");
}

void Ressource::print() const{
    std::cout<<"- "<<ressourceTypeToString(types[0]);
    if(isTradable){
        std::cout << " - number : "<<amount<<" - market price : ";
        if (isMarketRuleHasChanged) std::cout <<1;
        else std::cout << price;
    }
    else{
        for (auto r : std::vector<RessourceType>(types.begin()+1,types.end())){
            std::cout<<"/"<<ressourceTypeToString(r);
        }
        std::cout<<" - Ressource à choix";
    }
    std::cout<<std::endl;
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


