// Hugo Ochoa Lopez Portillo 
// A00835999
// ITC

#include <iostream>
using namespace std;
#include "DoublyLinkedList.h"
#include <chrono>
#include <random>

int main(){

    // Semilla para generar números aleatorios
    srand(time(0));

    // Menu para el usuario
    cout << "Este programa es para datos de tipo entero" << endl;
    cout << endl; 
    
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

    // Creacion de listas
    DoublyLinkedList<int> list;
    DoublyLinkedList<int> listAux;

    // Creacion de listas 
    // Lista de enteros aleatorios
    if (listType == 1){
        createListInt(list, numElements);
        listAux = list;
        listAux.print("asc");
        cout << endl;
    // Lista de enteros ingresados por el usuario
    } else if (listType == 2){
        manualListInt(list, numElements);
        listAux = list;
        listAux.print("asc");
        cout << endl;
    } else {
        cout << "Opcion no valida" << endl;
    }

    // Menu para el usuario
    int index;
    cout << "Escriba el numero de operacion que desee realizar: " << endl;
    cout << "1 Agrega un elemento al principio de la lista" << endl;
    cout << "2 Agrega un elemento al final de la lista" << endl;
    cout << "3 Insertar un elemento despues del indice dado" << endl;
    cout << "4 Borrar un elemento dado de la lista" << endl;
    cout << "5 Borrar un elemento en una posición de la lista" << endl;
    cout << "6 Obtener el elemento de una posicion dada de la lista" << endl;
    cout << "7 Actualizar un elemento dado de la lista" << endl;
    cout << "8 Actualizar un elemento que se encuentra en una posicion dada de la lista" << endl;
    cout << "9 Encuentra un elemento dado en la lista" << endl;
    cout << "10 Obtener el elemento de una posicion de la lista. (Sobre cargo operador [ ])" << endl;
    cout << "11 Actualizar el elemento de una posicion de la lista. (Sobre cargo operador [ ])" << endl;
    cout << "12 Iguala una lista con los datos de otra lista (Sobre carga operador =) (Duplica la lista)" << endl;
    cout << "13 Limpiar la lista" << endl;
    cout << "14 Ordena la lista (Shell Sort)" << endl;
    cout << "15 Duplica la lista (La lista debe de contener cada elemento 2 veces)" << endl;
    cout << "16 Remueve los elementos duplicados (Ordena primero la lista)" << endl << endl;
    cin >> index;
    cout << " " << endl;

    if (index == 1){
        // Add first
        int data;
        cout << "Ingresa el dato que deseas agregar al principio de la lista: " << endl;
        cin >> data;
        cout << endl;
        listAux.addFirst(data);
        cout << "Lista actualizada: " << endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 2){
        // Add last 
        int data;
        cout << "Ingresa el dato que deseas agregar al final de la lista: " << endl;
        cin >> data;
        cout << endl;
        listAux.addLast(data);
        cout << "Lista actualizada: " << endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 3){
        // Insert
        int data;
        int pos;
        cout << "Ingresa el dato que deseas agregar a la lista: " << endl;
        cin >> data;
        cout << endl;
        cout << "Ingresa la posicion en la que deseas agregar el dato a su derecha: " << endl;
        cin >> pos;
        cout << endl;
        listAux.insert(pos, data);
        cout << "Lista actualizada: " << endl;
        listAux.print("asc");   
        cout << endl;
    } else if (index == 4){
        // Delete data
        int data;
        cout << "Ingresa el dato que deseas borrar de la lista: " << endl;
        cin >> data;
        cout << endl;
        listAux.deleteData(data);
        cout << "Lista modificada:" <<endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 5){
        // Delete at
        int pos;
        cout << "Ingresa la posicion del dato que deseas borrar de la lista: " << endl;
        cin >> pos;
        cout << endl;
        listAux.deleteAt(pos);
        cout << "Lista modificada:" <<endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 6){
        // Get data
        int pos;
        cout << "Ingresa la posicion del dato que deseas obtener de la lista: " << endl;
        cin >> pos;
        cout << endl;
        cout << "El dato en la posicion " << pos << " es: " << listAux.getData(pos) << endl;
        cout << endl;
    } else if (index == 7){
        // Update data
        int data;
        int newData;
        cout << "Ingresa el dato que deseas actualizar de la lista: " << endl;
        cin >> data;
        cout << endl;
        cout << "Ingresa el nuevo dato: " << endl;
        cin >> newData;
        cout << endl;
        listAux.updateData(data, newData);
        cout << "Lista modificada:" <<endl;
        listAux.print("asc");
    } else if (index == 8){
        // Update at
        int pos;
        int newData;
        cout << "Ingresa la posicion del dato que deseas actualizar de la lista: " << endl;
        cin >> pos;
        cout << endl;
        cout << "Ingresa el nuevo dato: " << endl;
        cin >> newData;
        cout << endl;
        listAux.updateAt(pos, newData);
        cout << "Lista modificada:" <<endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 9){
        // Find data
        int data;
        cout << "Ingresa el dato que deseas encontrar en la lista: " << endl;
        cin >> data;
        cout << endl;
        cout << "El dato " << data << " se encuentra en la posicion " << listAux.findData(data) << endl;
        cout << endl;
    } else if (index == 10){
        // Get data ([])
        int pos;
        cout << "Ingresa la posicion del dato que deseas obtener de la lista: " << endl;
        cin >> pos;
        cout << endl;
        cout << "El dato en la posicion " << pos << " es: " << listAux[pos] << endl;
        cout << endl;
    } else if (index == 11){
        // Update data ([])
        int pos;
        int newData;
        cout << "Ingresa la posicion del dato que deseas actualizar de la lista: " << endl;
        cin >> pos;
        cout << endl;
        cout << "Ingresa el nuevo dato: " << endl;
        cin >> newData;
        cout << endl;
        listAux[pos] = newData;
        cout << "Lista modificada:" <<endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 12){
        DoublyLinkedList<int> listNew;
        cout << "Ingresa el numero de elementos de la nueva lista:" << endl;
        cin >> numElements;
        cout << endl;
        cout << "Ingresa los elementos de la nueva lista:" << endl;
        for (int i = 0; i < numElements; i++){
            int data;
            cin >> data;
            listNew.addLast(data);
        }
        cout << endl;
        // Igualar listas
        listAux = listNew;
        cout << "Nueva lista:" <<endl;
        listNew.print("asc");
        cout << endl;
        cout << "Lista original:" <<endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 13){
        // Clear
        listAux.clear();
        cout << "Lista actualizada: " << endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 14){
        // Sort
        listAux.sort();
        cout << "Lista ordenada: " << endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 15){
        // Duplicate
        listAux.sort();
        listAux.duplicate();
        cout << "Lista duplicada: " << endl;
        listAux.print("asc");
        cout << endl;
    } else if (index == 16){
        // Remove duplicates 
        listAux.sort();
        listAux.removeDuplicates();
        cout << "Lista sin duplicados: " << endl;
        listAux.print("asc");
        cout << endl;
    } else {
        cout << "Opcion no disponible" << endl;
    }

    return 0;
}