#pragma once

enum class RessourceType {
    Wood,
    Stone,
    Clay,
    Paper,
    Glass
};
class Ressource {

private : 
    RessourceType type; 
    int amount; 
    int price; 
public : 
<<<<<<< HEAD
    Ressource( RessourceType t , int p, int a = 0 );
    void add(int a ); 
    int getprice() {
        return price;
    }
    void updatePrice(int p) {
        price = p;
    } ;
=======
    void add(); 
    void getprice(); 
    void updatePrice(); 
>>>>>>> 2342842dcea19896e8e7c6fa55daebf881628bda

};









