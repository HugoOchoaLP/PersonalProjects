#include <iostream>
using namespace std;
#include "Stack.h"

int main()
{

    // Menu para el usuario
    cout << "Este programa es para datos de tipo entero" << endl;
    cout << endl; 
    
    // Numero de elementos de la lista
    int numElements;
    cout << "Ingresa el numero de elementos de la lista:" << endl;
    cin >> numElements;
    cout << endl;
    
    // Creacion de listas
    Stack<int> list;

    // Creacion de listas 
    for (int i = 0; i < numElements; i++){
        int num;
        cout << "Ingresa el elemento numero " << i + 1 << endl;
        cin >> num;
        list.push(num);
    }

    // Menu a desplegar
    int index;
    cout << "1 Push " << endl;
    cout << "2 Pop " << endl;
    cout << "3 Top " << endl;
    cin >> index;
    cout << endl << endl;

    // Menu
    if (index == 1){
        int data;
        cout << "Dame el numero que deseas agregar a la pila " << endl;
        cin >> data;
        cout << endl;
        list.push(data);
        cout << "Fila actualizada: " << endl;
        list.print();
        cout << endl;
    } else if (index == 2){
        list.pop();
        cout << "La lista es la siguiente, despues del pop: " << endl;
        list.print();
        cout << endl;
    } else if (index == 3){
        cout << "El valor al frente de la lista es: " << list.top() << endl;
        cout << endl;
    } else {
        cout << "Opcion no valida" << endl;
    }

    return 0;
}
