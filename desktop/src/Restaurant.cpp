#include "../include/Restaurant.h"

// Constructors

Restaurant::Restaurant(){
	_name = "unnamed";
}

Restaurant::Restaurant(string name){
	_name = name;
}

// Getters

string Restaurant::getName(){
	return _name;
}

// Setters

void Restaurant::setName(string name){
	_name = name;
}