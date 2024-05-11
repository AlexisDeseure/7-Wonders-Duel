#ifndef RESSOURCE_H
#define RESSOURCE_H
#include<iostream>
/*Une ressource n'a qu'un seul type, il faudra faire gaffe à la composition
avec City, bien faire une liste et que la fonction de rajout vérifie correctement qu'il n'y a pas déjà le type
*/


enum class RessourceType {
    Wood,
    Stone,
    Clay,
    Paper,
    Glass,
    RessourceTypeCount
};

class Ressource {
private:
    RessourceType type;
    unsigned int amount;
    unsigned int price;

public:
    friend std::ostream& operator<<(std::ostream& os, const Ressource& res);
    Ressource(RessourceType t, unsigned int a, unsigned int p) : type(t),amount(a),price(p){}

    void addMaterials(int sum) { amount += sum; }; //Rajoute sur matériaux
    unsigned int getPrice() const { return price; }


    void updatePrice(int sum) { price += sum; }; //Soustraire des ressources = donner valeur négative
   //amount = quantite de ressources
  // price = prix d'une seule ressource
   unsigned int getAmount() const {
        return amount;
   }
   void operator+=(unsigned int sum) { amount += sum; };
   RessourceType getType() const { return type; };

};
    

#endif