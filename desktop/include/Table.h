#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;

struct Order{
	Product* _product;
	int _quantity;
	//Order()
};

class Table{
	string _name;
	vector<Order> _orders;

public:
	Table();
	Table(string name);

	void addOrder(Product* product, int quantity);
	
	// Getters
	string getName();
	vector<Order> getOrders();

	// Setters
	void setName(string name);
};

class TableList{
	vector<Table> tables;
public:
	TableList();
	void addTable(string name);
	Table* getTableByName(string name);

	// Getter
	vector<Table>* getTables();
};