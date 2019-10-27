#pragma once
#include <vector>
#include <string>
#include <iomanip>

#include "Product.h"
#include "Table.h"

using namespace std;

class Restaurant{
	string 		_name;
	float 		_balance;
	ProductList productList;
	TableList 	tableList;
	// vector<Waiter> waiters; 
public:
	Restaurant(string name);
	void addTable(string name);
	void deleteTable(string name);

	void addProduct(string name, float price);
	void deleteProduct(string name);

	bool addOrder(string tableName, string productName, int quantity);
	bool deleteOrder(string tableName, string productName, int quantity);
	
	void checkOut(string name);

	void printTables();
	void printProducts();

	// Getters & Setters
	string 	getName();
	void 	setName(string name);
	float 	getBalance();
	void  	setBalance(int balance);
	int 	getTableSize();
	int 	getProductSize();
};