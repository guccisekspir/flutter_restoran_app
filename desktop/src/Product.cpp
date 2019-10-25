#include "../include/Product.h"

Product::Product(string name, float price, string type){
	_name = name;
	_price = price;
	_type = type;
}

int Product::getPrice(){
	return _price;
}

string Product::getName(){
	return _name;
}

string Product::getType(){
	return _type;
}