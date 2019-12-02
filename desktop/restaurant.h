#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <QString>
#include <vector>
#include <iomanip>

#include "product.h"
#include "table.h"
using namespace std;

class Restaurant{
    QString		_name;
    float 		_balance;
    ProductList productList;
    TableList 	tableList;
    // vector<Waiter> waiters;
public:
    Restaurant(){_name = "Unnamed";}
    Restaurant(QString name);
    bool addTable(QString name);
    bool deleteTable(QString name);

    bool addProduct(QString name, float price);
    bool deleteProduct(QString name);

    bool addOrder(QString tableName, QString productName, int quantity);
    bool deleteOrder(QString tableName, QString productName, int quantity);

    void checkOut(QString name);

    void printTables();
    void printProducts();

    // Getters & Setters
    QString	getName();
    void 	setName(QString name);
    float 	getBalance();
    void  	setBalance(int balance);
    int 	getTableSize();
    int 	getProductSize();
    Table*  getTable(QString tableName);
    vector<Table> getTables();
    vector<Product> getProducts();
};

#endif // RESTAURANT_H
