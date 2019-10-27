#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Product{
	string 	_name;
	float	_price;
public:
	Product();
	Product(string name, float price);

	// Getters & Setters
	string 	getName();
	int 	getPrice();
	void 	setName(string name);
	void 	setPrice(int price);
};

class ProductList{
	vector<Product> products; 
	int 			_size;
public:
	ProductList();
	void addProduct(string name, float price);
	void deleteProduct(string name);
	Product* getProductByName(string name);

	// Getters & Setters
	vector<Product>* getProducts();
	int getSize();
};