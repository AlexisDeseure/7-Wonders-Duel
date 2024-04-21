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
    void add(); 
    void getprice(); 
    void updatePrice(); 

};









