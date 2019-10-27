#include "../include/Table.h"

// Constructors

Table::Table(string name){
	_name = name;
}

void Table::addOrder(Product* product, int quantity){
	Order newOrder;
	newOrder._product = product;
	newOrder._quantity = quantity;
	_orders.push_back(newOrder);
}

void Table::deleteOrder(string name, int quantity){
	vector<Order>::iterator iter = _orders.begin();
	while(iter != _orders.end()){
		if((*iter)._product->getName() == name){
			(*iter)._quantity -= quantity;
			if((*iter)._quantity <= 0){
				_orders.erase(iter);
			}
			return;
		}
		iter++;
	}
}

float Table::paymentAmount(){
	float amount = 0;
	for(auto order : _orders){
		amount += order._product->getPrice() * order._quantity;
	}
	return amount;
}

void Table::clearOrders(){
	_orders.clear();
}

// Getters & Setters

string Table::getName(){
	return _name;
}

vector<Order> Table::getOrders(){
	return _orders;
}

void Table::setName(string name){
	_name = name;
}

/* TableList Functions*/

TableList::TableList(){
	_size = 0;
}

void TableList::addTable(string name){
	Table newTable(name);
	tables.push_back(newTable);
	_size++;
}

void TableList::deleteTable(string name){
	vector<Table>::iterator iter = tables.begin();
	while(iter != tables.end() ){
		if((*iter).getName() == name){
			tables.erase(iter);
			_size--;
			return;
		}
		iter++;
	}
}

Table* TableList::getTableByName(string name){
	vector<Table>::iterator iter = tables.begin();
	while( iter != tables.end() ){
		if( (*iter).getName() == name){
			return &(*iter);
		}
		iter++;
	}
	return nullptr;
}

// Getters & Setters

vector<Table>* TableList::getTables(){
	return &tables;
}

int TableList::getSize(){
	return _size;
}