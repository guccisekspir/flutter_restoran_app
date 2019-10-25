#include <vector>
#include <Product.h>

struct Order{
	Product* product;
	int quantity;
};

class Table{
	vector<Order> orders;
};