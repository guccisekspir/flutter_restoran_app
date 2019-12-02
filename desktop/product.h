#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <vector>
#include <iostream>
using namespace std;

class Product{
        QString	_name;
        float	_price;
    public:
        Product();
        Product(QString name, float price);

        // Getters & Setters
        QString getName();
        float 	getPrice();
        void 	setName(QString name);
        void 	setPrice(int price);
};

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

#endif // PRODUCT_H
