#include "restaurant.h"
#include <iostream>

using namespace std;

int main(){
	Restaurant myRes("MyCafe");

	// Masa listesi oluşturma
	myRes.addTable("Table 1");
	myRes.addTable("Table 2");
	myRes.addTable("Table 3");
	
	// Ürün listesi oluşturma
	myRes.addProduct("Tea", 3.5);
	myRes.addProduct("Coffee", 8);
	myRes.addProduct("Cola", 11);
	myRes.addProduct("Hamburger", 14);
	myRes.addProduct("Salad", 11);

	// Masaya sipariş ekleme
	myRes.addOrder("Table 1", "Tea", 2);
	myRes.addOrder("Table 1", "Coffee", 2);
	myRes.addOrder("Table 2", "Hamburger", 2);
	myRes.addOrder("Table 2", "Cola", 2);
	myRes.addOrder("Table 3", "Tea", 5);

	myRes.printTables();

	// Hesap kapatma
	myRes.checkOut("Table 1");
	
	// Masadan sipariş silme
	myRes.deleteOrder("Table 2", "Hamburger", 2);
	myRes.printTables();

	// Masa listesinden eleman silme
	myRes.deleteTable("Table 1");
	myRes.printTables();

	myRes.printProducts();
	myRes.deleteProduct("Hamburger");
	myRes.printProducts();

	cout << myRes.getProductSize() << endl;
	cout << myRes.getTableSize() << endl;
	return 0;
}