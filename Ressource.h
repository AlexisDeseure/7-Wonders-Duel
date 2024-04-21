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
    Ressource( RessourceType t , int p, int a = 0 );
    void add(int a ); 
    int getprice() {
        return price;
    }
    void updatePrice(int p) {
        price = p;
    } ;

};









