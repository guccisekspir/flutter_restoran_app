#include "include/Restaurant.h"
#include "include/Product.h"
#include <iostream>

using namespace std;

int main(){
	Restaurant ocakbasi;
	
	Product myp("Ekmek", 1.5, "Unlu mamül");
	cout << myp.getName() << endl;
	cout << myp.getPrice() << endl;
	cout << myp.getType() << endl;

	Product myp2;
	cout << myp2.getName() << endl;
	cout << myp2.getPrice() << endl;
	cout << myp2.getType() << endl;

	return 0;
}