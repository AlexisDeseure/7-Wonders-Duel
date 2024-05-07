//Crée par Mateo
#ifndef PROJET_RESSOURCE_H
#define PROJET_RESSOURCE_H
#include<iostream>
/*Une ressource n'a qu'un seul type, il faudra faire gaffe à la composition
avec City, bien faire une liste et que la fonction de rajout vérifie correctement qu'il n'y a pas déjà le type
*/
#include<includes\City\City.h>
    enum class RessourceType {
        Wood,
        Stone,
        Clay,
        Paper,
        Glass
    };

    class Ressource {
    private:
        RessourceType type;
        int amount;
        int price;
     //   const City::City* city;
        // pas besoin de mettre city

    public:
        void addMaterials(int sum) { amount += sum; }; //Rajoute sum matériaux
        int getPrice() const { return price; };
        
        void updatePrice(int sum) { price += sum; }; //Soustraire des ressources = donner valeur négative
       //amount = quantite de ressources 
      // price = prix d'une seule ressource 
        int getAmount() const {
            return amount; 
       }
   
    };

#endif //PROJET_RESSOURCE_H

















