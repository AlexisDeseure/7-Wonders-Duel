#ifndef RESSOURCE_H
#define RESSOURCE_H
#include<iostream>
#include <array>

/*Une ressource n'a qu'un seul type, il faudra faire gaffe à la composition
avec City, bien faire une liste et que la fonction de rajout vérifie correctement qu'il n'y a pas déjà le type
*/


enum class RessourceType {
    Wood,
    Stone,
    Clay,
    Paper,
    Glass,
    LENGTH
};

extern const std::array<std::string, static_cast<int>(RessourceType::LENGTH)> ressource_name;

class Ressource {
    private:
        RessourceType type;
        unsigned int amount;
        unsigned int price;
        //amount = quantite de ressources
        // price = prix d'une seule ressource

    public:
        //friend std::ostream& operator<<(std::ostream& os, const Ressource& res);
        Ressource(RessourceType t, unsigned int a, unsigned int p) : type(t),amount(a),price(p){}


        unsigned int getPrice() const { return price; }


        void updatePrice(int sum) { price += sum; }; //baisser le prix = donner valeur négative

        unsigned int getAmount() const { return amount; }

        void add(int sum) { amount += sum; }; // à supprimer à terme
        void operator+=(unsigned int sum) { amount += sum; };

        RessourceType getType() const { return type; };

};

std::string ressourceTypeToString(RessourceType type);
RessourceType StringToRessourceType(std::string nom);
    

#endif
