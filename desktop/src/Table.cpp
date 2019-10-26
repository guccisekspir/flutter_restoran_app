#include "../include/Table.h"

// Constructors

Table::Table(){
	_name = "unnamed";
}

Table::Table(string name){
	_name = name;
}

void Table::addOrder(Product* product, int quantity){
	Order newOrder;
	newOrder._product = product;
	newOrder._quantity = quantity;
	orders.push_back(newOrder);
}

// Getters

string Table::getName(){
	return _name;
}

// Setters

void Table::setName(string name){
	_name = name;
}


TableList::TableList(){

}

void TableList::addTable(string name){
	
}