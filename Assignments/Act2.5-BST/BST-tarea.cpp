// Hugo Ochoa Lopez Portillo A00835999
// ITC
// 13/10/2023

#include <iostream>
using namespace std;
#include "BST.h"

int main()
{
    // Voy a crear un arbol binario predeterminado
    BST<int> arbol;
    arbol.insert(5);
    arbol.insert(3);
    arbol.insert(10);
    arbol.insert(1);
    arbol.insert(4);
    arbol.insert(12);
    arbol.insert(8);
    arbol.insert(7);

    cout << "Este programa trabaja usando un arbol binario prdeterminado" << endl;
    cout << "El arbol binario predeterminado es: " << endl;
    arbol.print();
    cout << endl;

    // Menu para el usuario
    int index;

    cout << "Bienvenido al programa de BST" << endl;
    cout << "1 Insertar" << endl;
    cout << "2 Borrar" << endl;
    cout << "3 Imprimir" << endl;
    cout << "4 Encontrar " << endl;
    cout << "5 Visitar" << endl;
    cout << "6 Altura" << endl;
    cout << "7 Ancestros" << endl;
    cout << "8 Nivel" << endl;
    cout << "9 Salir " << endl;
    cout << "Ingrese la opcion que desea: " << endl;
    cin >> index;

    // Menu
    if (index == 1){
        // Insertar
        int dato;
        cout << "Ingrese el dato que desea insertar: " << endl;
        cin >> dato;
        arbol.insert(dato);
        cout << "El arbol binario es: " << endl;
        arbol.print();
        cout << endl;
    }
    else if (index == 2){
        // Borrar
        int dato;
        cout << "Ingrese el dato que desea borrar: " << endl;
        cin >> dato;
        arbol.remove(dato);
        cout << "El arbol binario es: " << endl;
        arbol.print();
        cout << endl;
    } else if (index == 3){
        // Imprimir
        cout << "El arbol binario es: " << endl;
        arbol.print();
        cout << endl;
    } else if (index == 4){
        // Encontrar
        int dato;
        cout << "Ingrese el dato que desea encontrar: " << endl;
        cin >> dato;
        if (arbol.find(dato)){
            cout << "El dato si se encuentra en el arbol binario" << endl;
        } else {
            cout << "El dato no se encuentra en el arbol binario" << endl;
        }
    } else if (index == 5){
        // Visitar
        cout << "El arbol binario es: " << endl;
        arbol.print();
        cout << "El recorrido en preorden es: " << endl;
        arbol.visit(1);
        cout << endl;
        cout << "El recorrido en inorden es: " << endl;
        arbol.visit(2);
        cout << endl;
        cout << "El recorrido en postorden es: " << endl;
        arbol.visit(3);
        cout << endl;
        cout << "El recorrido en por niveles es: " << endl;
        arbol.visit(4);
        cout << endl;
    } else if (index == 6){
        // Altura
        arbol.height();
    } else if (index == 7){
        // Ancestros
        int dato;
        cout << "Ingrese el dato que desea encontrar sus ancestros: " << endl;
        cin >> dato;
        arbol.ancestors(dato);
    } else if (index == 8){
        // Nivel
        int data;
        cout << "Ingrese el dato que desea encontrar su nivel: " << endl;
        cin >> data;
        int level = arbol.whatLevelAmI(data); 
        if (level != -1) {
            cout << "Nivel de " << data << ": " << level << endl;
        } else {
            cout << data << " no se encontro en el arbol" << endl;
        }
    } else if (index == 9){
        // Salir
        cout << "Gracias por usar el programa" << endl;
    } else {
        cout << "Opcion invalida" << endl;
    }

    return 0;
}
