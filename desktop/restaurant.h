#pragma once
#include <vector>
#include <QString>
#include <iomanip>

#include "product.h"
#include "table.h"

using namespace std;

class Restaurant{
	QString 		_name;
	float 		_balance;
	ProductList productList;
	TableList 	tableList;
	// vector<Waiter> waiters; 
public:
	Restaurant(QString name);
	void addTable(QString name);
	void deleteTable(QString name);

	void addProduct(QString name, float price);
	void deleteProduct(QString name);

	bool addOrder(QString tableName, QString productName, int quantity);
	bool deleteOrder(QString tableName, QString productName, int quantity);
	
	void checkOut(QString name);

	void printTables();
	void printProducts();

	// Getters & Setters
	QString 	getName();
	void 	setName(QString name);
	float 	getBalance();
	void  	setBalance(int balance);
	int 	getTableSize();
	int 	getProductSize();
};