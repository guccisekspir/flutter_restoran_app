#include <string>

using namespace std;

class Product{
	string _name;
	float _price;
	string _type;
public:
	Product(): _name("unnamed"), _price(0), _type("uncategorized") {}
	Product(string name, float price, string type);

	string getName();
	int getPrice();
	string getType();
};