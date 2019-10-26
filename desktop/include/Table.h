#include <vector>
#include <string>
#include <Product.h>

struct Order{
	Product* _product;
	int _quantity;
	//Order()
};

class Table{
	string _name;
	vector<Order> orders;

public:
	Table();
	Table(string name);

	void addOrder(Product* product, int quantity);
	
	// Getters
	string getName();

	// Setters
	void setName(string name);
};

class TableList{
	vector<Table> tables;
public:
	TableList();
	void addTable(string name);
	Table* getTableByName(string name);
};