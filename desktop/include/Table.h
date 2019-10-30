#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;

struct Order{
	Product* _product;
	int 	 _quantity;
	//Order()
};

class Table{
	string 		  _name;
	vector<Order> _orders;

public:
	Table(string name);

	void addOrder(Product* product, int quantity);
	void deleteOrder(string name, int quantity);
	float paymentAmount();
	void clearOrders();

	// Getters & Setters
	string 		  	getName();
	vector<Order> 	getOrders();
	void 			setName(string name);
};

class TableList{
	vector<Table> tables;
	int 		  _size;
public:
	TableList();
	void addTable(string name);
	void deleteTable(string name);
	Table* getTableByName(string name);

	// Getters & Setters
	vector<Table>* getTables();
	int getSize();
};