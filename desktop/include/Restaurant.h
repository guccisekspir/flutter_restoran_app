#include <vector>
#include <string>

#include "Product.h"
#include "Table.h"

using namespace std;

class Restaurant{
	string _name;
	vector<Product> products; // Değiştirilebilir ürün listesi
	vector<Table> tables;
	// vector<Waiter> waiters; 
};