

#include <QString>
#include <vector>
#include <iostream>

using namespace std;

class ProductList{
        vector<Product> products;
        int 			_size;
    public:
        ProductList();
        bool addProduct(QString name, float price);
        bool deleteProduct(QString name);
        Product* getProductByName(QString name);

        // Getters & Setters
        vector<Product>* getProducts();
        int getSize();
};
