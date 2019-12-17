#include "productlist.h"


ProductList::ProductList(){
    _size = 0;
}

bool ProductList::addProduct(QString name, float price){
    for(auto product : products){
        if(product.getName() == name){
            return false;
        }
    }
    Product newProduct(name, price);
    products.push_back(newProduct);
    _size++;
    return true;
}

bool ProductList::deleteProduct(QString name){
    vector<Product>::iterator iter = products.begin();
    while( iter != products.end() ){
        if( (*iter).getName() == name){
            products.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Product* ProductList::getProductByName(QString name){
    vector<Product>::iterator iter = products.begin();
    while( iter != products.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }
        iter++;
    }
    return nullptr;
}

// Getters & Setters

vector<Product>* ProductList::getProducts(){
    return &products;
}

int ProductList::getSize(){
    return _size;
}
