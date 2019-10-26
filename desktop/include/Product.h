#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Product{
	string _name;
	float _price;
public:
	Product();
	Product(string name, float price);

	// Getters
	string getName();
	int getPrice();

	// Setters
	void setName(string name);
	void setPrice(int price);
};

class ProductList{
	vector<Product> products; 
public:
	ProductList();
	void addProduct(string name, float price);
	Product* getProductByName(string name);
};