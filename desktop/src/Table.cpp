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
	_orders.push_back(newOrder);
}

// Getters

string Table::getName(){
	return _name;
}

vector<Order> Table::getOrders(){
	return _orders;
}

// Setters

void Table::setName(string name){
	_name = name;
}

/* TableList Functions*/

TableList::TableList(){

}

void TableList::addTable(string name){
	Table newTable(name);
	tables.push_back(newTable);
}

Table* TableList::getTableByName(string name){
	vector<Table>::iterator iter = tables.begin();
	while( iter != tables.end() ){
		if( (*iter).getName() == name){
			cout << (*iter).getName() << " adlı masa bulundu!" << endl;
			return &(*iter);
		}
		iter++;
	}

/* 	
	for(auto table : tables){
		if(table.getName() == name){
			cout << table.getName() << " adlı masa bulundu!" << endl;
			return &table;
		}
	}
 */	return nullptr;
}

// Getters

vector<Table>* TableList::getTables(){
	return &tables;
}