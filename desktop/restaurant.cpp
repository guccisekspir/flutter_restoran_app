#include "restaurant.h"

// Constructors

Restaurant::Restaurant(QString name){
    _name = name;
    _balance = 0;
}

bool Restaurant::addTable(QString name){
    return tableList.addTable(name);
}

bool Restaurant::deleteTable(QString name){
    return tableList.deleteTable(name);
}

bool Restaurant::addProduct(QString name, float price){
    return productList.addProduct(name, price);
}

bool Restaurant::deleteProduct(QString name){
    return productList.deleteProduct(name);
}

bool Restaurant::addOrder(QString tableName, QString productName, int quantity){
    Product* product = productList.getProductByName(productName);
    Table* table = tableList.getTableByName(tableName);
    if( product != nullptr && table != nullptr){
        table->addOrder(product, quantity);
        return true;
    }
    return false;
}

bool Restaurant::deleteOrder(QString tableName, QString productName, int quantity){
    Product* product = productList.getProductByName(productName);
    Table* table = tableList.getTableByName(tableName);
    if( product != nullptr && table != nullptr){
        table->deleteOrder(product->getName(), quantity);
        return true;
    }
    return false;
}

void Restaurant::checkOut(QString name){
    Table* table = tableList.getTableByName(name);
    _balance += table->paymentAmount();
    table->clearOrders();
}


/*
void Restaurant::printTables(){
    cout << "\t*** " << _name << " AUTOMATION SYSTEM ***" << endl << endl;
    for(auto table : *tableList.getTables()){
        if( table.getOrders().size() <= 0){
            cout << table.getName() << " is free." << endl << endl;
        } else{
            cout << table.getName() <<  endl;
            float sum = 0;
            for(auto order : table.getOrders()){
                cout << setw(2) << setfill(' ') << right <<
                order._quantity << " x " <<
                setw(20) << setfill('_') << left <<
                order._product->getName() <<
                setw(5) << setfill('_') << right <<
                order._product->getPrice() * order._quantity
                << "₺" <<  endl;

                sum += order._product->getPrice() * order._quantity;
            }
            cout << setw(28) << setfill(' ') << right <<
            "Total: " << sum << "₺" << endl << endl;
        }
    }
    cout << "Balance: " << _balance << "₺" << endl;
    cout << endl;
}

void Restaurant::printProducts(){
    cout << "\t*** " << _name << " PRODUCT LIST ***" << endl << endl;
    int count=0;
    for(auto product : *productList.getProducts()){
        cout << count++ << ". " << product.getName() << " " << product.getPrice() << "₺" << endl;;
    }

    cout << endl;
}
*/


// Getters & Setters

QString Restaurant::getName(){
    return _name;
}

void Restaurant::setName(QString name){
    _name = name;
}

float Restaurant::getBalance(){
    return _balance;
}

void Restaurant::setBalance(int balance){
    _balance = balance;
}

int Restaurant::getTableSize(){
    return tableList.getSize();
}

int Restaurant::getProductSize(){
    return productList.getSize();
}

Table* Restaurant::getTable(QString tableName){
    return tableList.getTableByName(tableName);
}

vector<Table> Restaurant::getTables(){
    return *tableList.getTables();
}

vector<Product> Restaurant::getProducts(){
    return *productList.getProducts();
}
