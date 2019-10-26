#include "../include/Restaurant.h"

// Constructors

Restaurant::Restaurant(){
	_name = "unnamed";
}

Restaurant::Restaurant(string name){
	_name = name;
}

void Restaurant::addTable(string name){
	tables.addTable(name);
}

void Restaurant::addProduct(string name, float price){
	productList.addProduct(name, price);
}

bool Restaurant::addOrder(string tableName, string productName, int quantity){
	Product* product = productList.getProductByName(productName);
	Table* table = tables.getTableByName(tableName);
	if( product != nullptr && table != nullptr){
		table->addOrder(product, quantity);
		return true;
	}
	return false;
}

void Restaurant::printTables(){
	for(auto table : *tables.getTables()){
		cout << table.getName() <<  endl;
		float sum = 0;
		for(auto order : table.getOrders()){
			cout << setw(2) << setfill(' ') << right <<
			order._quantity << " x " <<
			setw(20) << setfill('_') << left <<
			order._product->getName() << 
			setw(5) << setfill('_') << right << 
			order._product->getPrice() * order._quantity  
			<< "₺" <<  endl; 
			
			sum += order._product->getPrice() * order._quantity;
		}
		cout << setw(28) << setfill(' ') << right <<
		"Total: " << sum << "₺" << endl << endl;
	}
	cout << endl;
}

// Getters

string Restaurant::getName(){
	return _name;
}

// Setters

void Restaurant::setName(string name){
	_name = name;
}
