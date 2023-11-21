

#include <iostream>
#include <vector>
using namespace std;

#include "List.h"

int main()
{
    List<int> list;

    // Insertar datos a la lista
    list.insert(5); // Inserta el numero 5 como un dato a la lista
    list.insert(10); // Inserta el numero 10 como un dato a la lista
    // Imprimimos la lista
    list.print();
    // Probamos getMax
    cout << "El dato maximo es " << list.getMax() << endl;
    // Encontramos el valor maximo de la lista
    // list.getMax();
    // Eliminar el último elemento de la lista llamada list
    try {
        list.removeLast();
        list.removeLast();
        list.removeLast();
        list.removeLast();
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    // Imprimimos la lista
    list.print();
    // Obenemos el valor de la posición 0
    // Insertar datos otra vez
    list.insert(5);
    list.insert(10);
    // Imprimimos la lista
    list.print();
    try {
        cout << "El valor de la posicion 0 es: " << list.getData(0) << endl;
        cout << "El valor de la posicion 1 es: " << list.getData(1) << endl;
        cout << "El valor de la posicion 2 es: " << list.getData(2) << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}