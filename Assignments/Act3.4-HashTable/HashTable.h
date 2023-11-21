#ifndef HashTable_h
#define HashTable_h

using namespace std;
#include <iostream>

#include <vector>

class HashTable {
private:
    vector<string> table;
    int hash(string data);
public: 
    HashTable();
    void insert(string data);
    bool findData(string data);
};

HashTable::HashTable() {
    table.resize(100); // Haciendo que table sea de tamanao 100
}

void HashTable::insert(string data){
    int index = hash(data);
    table[index] = data;
}

bool HashTable::findData(string data) {
    int index = hash(data);
    if (table[index] == data) {
        return index;
    } else {
        return -1;
    }
}

int HashTable::hash(string data){
    //return
}






#endif /* HashTable_h */