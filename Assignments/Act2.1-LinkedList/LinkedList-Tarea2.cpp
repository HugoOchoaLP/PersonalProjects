#include <iostream>
using namespace std;
#include "LinkedList.h"
#include <chrono>
#include <random>

int main()
{
    // Semilla para generar números aleatorios
    srand(time(0));

    // Menu para el usuario
    // Tipo de dato de la lista
    int indexVector;
    cout << "Ingresa el tipo de dato de tu lista:" << endl;
    cout << "1 Vector de enteros" << endl;
    cout << "2 Vector de flotantes" << endl;
    cin >> indexVector;
    cout << endl; 
    if (indexVector < 1 || indexVector > 2){
        cout << "Opcion no valida" << endl;
        return 0;
    }

    // Numero de elementos de la lista
    int numElements;
    cout << "Ingresa el numero de elementos de la lista:" << endl;
    cin >> numElements;
    cout << endl;

    // Tipo de lista
    int listType;
    cout <<"Ingresa 1 si los datos seran aleatorios" << endl;
    cout <<"Ingresa 2 si los datos seran ingresados por ti" << endl;
    cin >> listType;
    cout << endl;

    if (listType < 1 || listType > 2){
        cout << "Opcion no valida" << endl;
        return 0;
    }

    // Creacion de listas
    LinkedList<int> list;
    LinkedList<int> listAux;
    LinkedList<float> listFloat;
    LinkedList<float> listAuxFloat;

    // Creacion de listas 
    // Lista de enteros aleatorios
    if (indexVector == 1 && listType == 1){
        createListInt(list, numElements);
        listAux = list;
        list.print();
        cout << endl;
    } else if (indexVector == 1 && listType == 2){
        // Lista de enteros ingresados por el usuario
        manualListInt(list, numElements);
        listAux = list;
        list.print();
        cout << endl;
    } else if (indexVector == 2 && listType == 1){
        // Lista de flotantes aleatorios
        createListFloat(listFloat, numElements);
        listAuxFloat = listFloat;
        listFloat.print();
        cout << endl;
    } else if (indexVector == 2 && listType == 2){
        // Lista de flotantes ingresados por el usuario
        manualListFloat(listFloat, numElements);
        listAuxFloat = listFloat;
        listFloat.print();
        cout << endl;
    } else {
        cout << "Opcion no valida" << endl;
    }

    int index;
    cout << "Escriba el numero de operacion que desee realizar: " << endl;
    cout << "1 Agrega un elemento al principio de la lista" << endl;
    cout << "2 Agrega un elemento al final de la lista" << endl;
    cout << "3 Insertar un elemento despues del indice dado" << endl;
    cout << "4 Borrar un elemento dado de la lista" << endl;
    cout << "5 Borrar un elemento en una posicion de la lista" << endl;
    cout << "6 Obtener el elemento de una posicion dada de la lista" << endl;
    cout << "7 Actualizar un elemento dado de la lista" << endl;
    cout << "8 Actualizar un elemento que se encuentra en una posicion dada de la lista" << endl;
    cout << "9 Encuentra un elemento dado en la lista" << endl;
    cout << "10 Obtener el elemento de una posicion de la lista. (Sobre cargo operador [ ])" << endl;
    cout << "11 Actualizar el elemento de una posicion de la lista. (Sobre cargo operador [ ])" << endl;
    cout << "12 Iguala una lista con los datos de otra lista (Sobre carga operador =) (Duplica la lista)" << endl << endl;
    cin >> index;
    cout << " " << endl;

    if (index == 1 && indexVector == 1){
        // Add first
        int data;
        cout << "Ingresa el dato que deseas agregar al inicio de la lista:" << endl;
        cin >> data;
        cout << endl;
        listAux.addFirst(data);
        cout << "Lista actualizada: " << endl;
        listAux.print();
        cout << endl;
    } else if (index == 2 && indexVector == 1){
        // Add last
        int data;
        cout << "Ingresa el dato que deseas agregar al final de la lista:" << endl;
        cin >> data;
        cout << endl;
        listAux.addLast(data);
        cout << "Lista actualizada: " << endl;
        listAux.print();
        cout << endl;
    } else if (index == 3 && indexVector == 1){
        // Insert
        int data;
        int index;
        cout << "Ingresa el dato que deseas agregar a la lista:" << endl;
        cin >> data;
        cout << endl;
        cout << "Ingresa el indice al que le deseas agregar el dato a la derecha:" << endl;
        cin >> index;
        cout << endl;
        listAux.insert(data, index);
        cout << "Lista actualizada: " << endl;
        listAux.print();
        cout << endl;
    } else if (index == 4 && indexVector == 1){
        // Delete data
        int data;
        cout << "Ingresa el dato que deseas borrar de la lista:" << endl;
        cin >> data;
        cout << endl;
        listAux.deleteData(data);
        cout << "Lista actualizada: " << endl;
        listAux.print();
        cout << endl;
    } else if (index == 5 && indexVector == 1){
        // Delete at
        int index;
        cout << "Ingresa el indice del dato que deseas borrar de la lista:" << endl;
        cin >> index;
        cout << endl;
        listAux.deleteAt(index);
        cout << "Lista actualizada: " << endl;
        listAux.print();
        cout << endl;
    } else if (index == 6 && indexVector == 1){
        // Get data
        int index;
        cout << "Ingresa el indice del dato que deseas obtener de la lista:" << endl;
        cin >> index;
        cout << endl;
        cout << "El dato en la posicion " << index << " es: " << listAux.getData(index) << endl;
        cout << endl;
    } else if (index == 7 && indexVector == 1){
        // Update data
        int data;
        cout << "Ingresa el dato que deseas actualizar de la lista:" << endl << endl;
        cin >> data;
        cout << endl;
        int newData;
        cout << "Ingresa el nuevo dato:" << endl << endl;
        cin >> newData;
        cout << endl;
        listAux.updateData(data, newData);
        cout << "Lista modificada:" <<endl;
        listAux.print();
        cout << "Lista original:" <<endl;
        list.print();
        cout << endl;
    } else if (index == 8 && indexVector == 1){
        // Update at
        int indexUpdate;
        cout << "Ingresa el indice del dato que deseas actualizar de la lista:" << endl << endl;
        cin >> indexUpdate;
        cout << endl;
        int newData;
        cout << "Ingresa el nuevo dato:" << endl << endl;
        cin >> newData;
        cout << endl;
        listAux.updateAt(indexUpdate, newData);
        cout << "Lista modificada:" <<endl;
        listAux.print();
        cout << "Lista original:" <<endl;
        list.print();
        cout << endl;
    } else if (index == 9 && indexVector == 1){
        // Find data
        int data;
        cout << "Ingresa el dato que deseas encontrar en la lista:" << endl << endl;
        cin >> data;
        cout << endl;
        cout << "El dato " << data << " se encuentra en la posicion " << listAux.findData(data) << endl;
        cout << endl;
    } else if (index == 10 && indexVector == 1){
        // Get data (sobrecarga operador [])
        int indexGet;
        cout << "Ingresa el indice del dato que deseas obtener de la lista:" << endl << endl;
        cin >> indexGet;
        cout << endl;
        cout << "El dato en la posicion " << indexGet << " es: " << listAux[indexGet] << endl;
        cout << endl;
    } else if (index == 11 && indexVector == 1){
        // Update data (sobrecarga operador [])
        int indexUpdate;
        cout << "Ingresa el indice del dato que deseas actualizar de la lista:" << endl << endl;
        cin >> indexUpdate;
        cout << endl;
        int newData;
        cout << "Ingresa el nuevo dato:" << endl << endl;
        cin >> newData;
        cout << endl;
        listAux[indexUpdate] = newData;
        cout << "Lista modificada:" <<endl;
        listAux.print();
        cout << endl;
    } else if (index == 12 && indexVector == 1){
        // Sobrecarga de operador =
        // Solicitar datos de la nueva lista
        LinkedList<int> listNew;
        cout << "Ingresa el numero de elementos de la nueva lista:" << endl;
        cin >> numElements;
        cout << endl;
        manualListInt(listNew, numElements);
        cout << endl;
        // Igualar listas
        listAux = listNew;
        cout << "Nueva lista:" <<endl;
        listNew.print();
        cout << endl;
    } else if (index == 1 && indexVector == 2){
        // Add first
        float data;
        cout << "Ingresa el dato que deseas agregar al inicio de la lista:" << endl;
        cin >> data;
        cout << endl;
        listAuxFloat.addFirst(data);
        cout << "Lista actualizada: " << endl;
        listAuxFloat.print();
        cout << endl;
    } else if (index == 2 && indexVector == 2){
        // Add last
        float data;
        cout << "Ingresa el dato que deseas agregar al final de la lista:" << endl;
        cin >> data;
        cout << endl;
        listAuxFloat.addLast(data);
        cout << "Lista actualizada: " << endl;
        listAuxFloat.print();
        cout << endl;
    } else if (index == 3 && indexVector == 2){
        // Insert
        float data;
        int index;
        cout << "Ingresa el dato que deseas agregar a la lista:" << endl;
        cin >> data;
        cout << endl;
        cout << "Ingresa el indice al que le deseas agregar el dato a la derecha:" << endl;
        cin >> index;
        cout << endl;
        listAuxFloat.insert(index, data);
        cout << "Lista actualizada: " << endl;
        listAuxFloat.print();
        cout << endl;
    } else if (index == 4 && indexVector == 2){
        // Delete data
        float data;
        cout << "Ingresa el dato que deseas borrar de la lista:" << endl;
        cin >> data;
        cout << endl;
        listAuxFloat.deleteData(data);
        cout << "Lista actualizada: " << endl;
        listAuxFloat.print();
        cout << endl;
    } else if (index == 5 && indexVector == 2){
        // Delete at
        int index;
        cout << "Ingresa el indice del dato que deseas borrar de la lista:" << endl;
        cin >> index;
        cout << endl;
        listAuxFloat.deleteAt(index);
        cout << "Lista actualizada: " << endl;
        listAuxFloat.print();
        cout << endl;  
    } else if (index == 6 && indexVector == 2){
        // Get data
        int index;
        cout << "Ingresa el indice del dato que deseas obtener de la lista:" << endl;
        cin >> index;
        cout << endl;
        cout << "El dato en la posicion " << index << " es: " << listAuxFloat.getData(index) << endl;
        cout << endl;
    } else if (index == 7 && indexVector == 2){
        // Update data
        float data;
        cout << "Ingresa el dato que deseas actualizar de la lista:" << endl << endl;
        cin >> data;
        cout << endl;
        float newData;
        cout << "Ingresa el nuevo dato:" << endl << endl;
        cin >> newData;
        cout << endl;
        listAuxFloat.updateData(data, newData);
        cout << "Lista modificada:" <<endl;
        listAuxFloat.print();
        cout << "Lista original:" <<endl;   
        listFloat.print();
        cout << endl;
    } else if (index == 8 && indexVector == 2){
        // Update at
        int indexUpdate;
        cout << "Ingresa el indice del dato que deseas actualizar de la lista:" << endl << endl;
        cin >> indexUpdate;
        cout << endl;
        float newData;
        cout << "Ingresa el nuevo dato:" << endl << endl;
        cin >> newData;
        cout << endl;
        listAuxFloat.updateAt(indexUpdate, newData);
        cout << "Lista modificada:" <<endl;
        listAuxFloat.print();
        cout << "Lista original:" <<endl;
        listFloat.print();
        cout << endl;
    } else if (index == 9 && indexVector == 2){
        // Find data
        float data;
        cout << "Ingresa el dato que deseas encontrar en la lista:" << endl << endl;
        cin >> data;
        cout << endl;
        cout << "El dato " << data << " se encuentra en la posicion " << listAuxFloat.findData(data) << endl;
        cout << endl;
    } else if (index == 10 && indexVector == 2){
        // Get data (sobrecarga operador [])
        int indexGet;
        cout << "Ingresa el indice del dato que deseas obtener de la lista:" << endl << endl;
        cin >> indexGet;
        cout << endl;
        cout << "El dato en la posicion " << indexGet << " es: " << listAuxFloat[indexGet] << endl;
        cout << endl;
    } else if (index == 11 && indexVector == 2){
        // Update data (sobrecarga operador [])
        int indexUpdate;
        cout << "Ingresa el indice del dato que deseas actualizar de la lista:" << endl << endl;
        cin >> indexUpdate;
        cout << endl;
        float newData;
        cout << "Ingresa el nuevo dato:" << endl << endl;
        cin >> newData;
        cout << endl;
        listAuxFloat[indexUpdate] = newData;
        cout << "Lista modificada:" <<endl;
        listAuxFloat.print();
        cout << endl;
    } else if (index == 12 && indexVector == 2){
        // Sobrecarga de operador =
        // Solicitar datos de la nueva lista
        LinkedList<float> listNew;
        cout << "Ingresa el numero de elementos de la nueva lista:" << endl;
        cin >> numElements;
        cout << endl;
        manualListFloat(listNew, numElements);
        cout << endl;
        // Igualar listas
        listAuxFloat = listNew;
        cout << "Nueva lista:" <<endl;
        listNew.print();
        cout << endl;
    } else {
        cout << "Opcion no valida" << endl;
    }
    return 0;
}
