#include "include/Restaurant.h"
#include <iostream>

using namespace std;

int main(){
	Restaurant myRes;
	myRes.addTable("Table 1");
	myRes.addTable("Table 2");
	myRes.addTable("Table 3");
	
	myRes.addProduct("Tea", 3.5);
	myRes.addProduct("Coffee", 8);
	myRes.addProduct("Cola", 11);
	myRes.addProduct("Hamburger", 14);
	myRes.addProduct("Salad", 11);

	myRes.addOrder("Table 1", "Tea", 2);
	myRes.addOrder("Table 1", "Coffee", 2);
	myRes.addOrder("Table 2", "Hamburger", 2);
	myRes.addOrder("Table 2", "Cola", 2);
	myRes.addOrder("Table 3", "Tea", 5);

	myRes.printTables();

	return 0;
}