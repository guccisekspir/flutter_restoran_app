#pragma once
#include <QString>
#include <vector>
#include <iostream>
using namespace std;

class Product{
	QString 	_name;
	float	_price;
public:
	Product();
	Product(QString name, float price);

	// Getters & Setters
	QString 	getName();
	int 	getPrice();
	void 	setName(QString name);
	void 	setPrice(int price);
};

class ProductList{
	vector<Product> products; 
	int 			_size;
public:
	ProductList();
	void addProduct(QString name, float price);
	void deleteProduct(QString name);
	Product* getProductByName(QString name);

	// Getters & Setters
	vector<Product>* getProducts();
	int getSize();
};