#pragma once

class ConflictPawn {

private : 
	int current_position; 
	// Les positions militaires sont
	// de -x jusqu'au x 
	ConflictPawn() :current_position(0) {};
	int move(int a = 0) ; 


};