#include "tableList.h"


TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }
        iter++;
    }
    return nullptr;
}

// Getters & Setters
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }ist::getTables(){
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }e(){
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }
TableList::TableList(){
    _size = 0;
}

bool TableList::addTable(QString name){
    for(auto table : tables){
        if(table.getName() == name){
            return false;
        }
    }
    Table newTable(name);
    tables.push_back(newTable);
    _size++;
    return true;
}

bool TableList::deleteTable(QString name){
    vector<Table>::iterator iter = tables.begin();
    while(iter != tables.end() ){
        if((*iter).getName() == name){
            tables.erase(iter);
            _size--;
            return true;
        }
        iter++;
    }
    return false;
}

Table* TableList::getTableByName(QString name){
    vector<Table>::iterator iter = tables.begin();
    while( iter != tables.end() ){
        if( (*iter).getName() == name){
            return &(*iter);
        }