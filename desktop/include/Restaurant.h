#include <vector>
#include <string>

#include "Product.h"
#include "Table.h"

using namespace std;

class Restaurant{
	string _name;
	ProductList productList;
	vector<Table> tables;
	// vector<Waiter> waiters; 
public:
	Restaurant();
	Restaurant(string name);
	void addTable();

	// Getters
	string getName();

	// Setters
	void setName(string name);

	void addTable();
};