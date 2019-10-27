#include "../include/Product.h"

// Constructors

Product::Product(){
	_name = "unnamed";
	_price = 0;
}

Product::Product(string name, float price){
	_name = name;
	_price = price;
}

// Getters

int Product::getPrice(){
	return _price;
}

string Product::getName(){
	return _name;
}

// Setters

void Product::setName(string name){
	_name = name;
}

void Product::setPrice(int price){
	_price = price;
}

// ProductList Functions

ProductList::ProductList(){
	_size = 0;
}

void ProductList::addProduct(string name, float price){
	Product newProduct(name, price);
	products.push_back(newProduct);
	_size++;
}

void ProductList::deleteProduct(string name){
	vector<Product>::iterator iter = products.begin();
	while( iter != products.end() ){
		if( (*iter).getName() == name){
			products.erase(iter);
			_size--;
			return;
		}
		iter++;
	}
}

Product* ProductList::getProductByName(string name){
	vector<Product>::iterator iter = products.begin();
	while( iter != products.end() ){
		if( (*iter).getName() == name){
			return &(*iter);
		}
		iter++;
	}
	return nullptr;
}

// Getters & Setters

vector<Product>* ProductList::getProducts(){
	return &products;
}

int ProductList::getSize(){
	return _size;
}