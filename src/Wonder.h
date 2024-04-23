#pragma once
#include<iostream>
#include <string>
class Wonder {
private : 
	Wonder(int cost , bool activated = false);
	bool activated; 
public : 
	int construction_cost;
	void build(); 
	void select(); 

};







