#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include <QString>
#include <iostream>
#include "product.h"
using namespace std;

struct Order{
    Product* _product;
    int 	 _quantity;
    //Order()
};

class Table{
    QString		  _name;
    vector<Order> _orders;
public:
    Table(QString name);

    void addOrder(Product* product, int quantity);
    void deleteOrder(QString name, int quantity);
    float paymentAmount();
    void clearOrders();

    // Getters & Setters
    QString		  	getName();
    vector<Order> 	getOrders();
    void 			setName(QString name);
};

class TableList{
    vector<Table> tables;
    int 		  _size;
public:
    TableList();
    bool addTable(QString name);
    bool deleteTable(QString name);
    Table* getTableByName(QString name);

    // Getters & Setters
    vector<Table>* getTables();
    int getSize();
};

#endif // TABLE_H
