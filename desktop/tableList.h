#include <vector>
#include <QString>
#include <iostream>
#include "product.h"
using namespace std;


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