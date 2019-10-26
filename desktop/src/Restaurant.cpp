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

void Restaurant::addOrder(string tableName, string productName, int quantity){

	tables.getTableByName(tableName)->addOrder(productList.getProductByName(productName), quantity);
}

void Restaurant::printTables(){
	for(auto table : *tables.getTables()){
		cout << table.getName() <<  endl;
		float sum = 0;
		for(auto order : table.getOrders()){
			cout << order._quantity << " x " <<
			setw(15) << setfill('_') << left <<
			order._product->getName() << 
			setw(15) << setfill('_') << right << 
			order._product->getPrice() * order._quantity  
			<< "₺" <<  endl; 
			
			sum += order._product->getPrice() * order._quantity;
		}
		cout << setw(30) << setfill('_') << right <<
		"Total:" << sum << "₺" << endl << endl;
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
