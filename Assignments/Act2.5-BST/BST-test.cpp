#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
    
    BST<int> bst;

    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(5);
    bst.insert(35);
    bst.insert(15);
    bst.insert(25);
    bst.print();
    bst.remove(20);
    cout << "Segundo Arbol" << endl;
    bst.print();

    int a = 5;
    int b = 10;
    a < b ? cout << "Hola" : cout << "Crayola";
    cout << endl;

    bst.find(5) ? cout << "Si" : cout << "No";
    
    return 0;
}
