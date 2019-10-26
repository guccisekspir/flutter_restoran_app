#pragma once
#include <vector>
#include <string>
#include <iomanip>

#include "Product.h"
#include "Table.h"

using namespace std;

class Restaurant{
	string _name;
	ProductList productList;
	TableList tables;
	// vector<Waiter> waiters; 
public:
	Restaurant();
	Restaurant(string name);
	void addTable(string name);
	void addProduct(string name, float price);
	bool addOrder(string tableName, string productName, int quantity);

	void printTables();

	// Getters
	string getName();

	// Setters
	void setName(string name);
};