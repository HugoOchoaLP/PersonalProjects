#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#include "DoublyLinkedList.h"

// Vamos a arregalar el IP 
string formatearIp(string ip){   
    // Dividimos el string en segementos
    string seg; 
    istringstream ss(ip); // Con esto separamos el registro en palabras
    vector<string> ips; // Vector para guardar los segmentos
    while (getline(ss, seg, '.')) {
        ips.push_back(seg);
    }
    // Mientras que el tamaño de los segmentos sea menor a 3, le agregamos un 0 al inicio
    for (int i = 2; i < ips.size(); i++) {
        if (ips[i].size() == 1) {
            ips[i] = "00" + ips[i];
        } 
        if (ips[i].size() == 2) {
            ips[i] = "0" + ips[i];
        }
    }
    // Desplegamos el IP formateado
    cout << "IP formateado " << ips[0]+ips[1]+ips[2]+ips[3] << endl;
    // Retornamos el IP formateado
    return ips[0]+ips[1]+ips[2]+ips[3];
}

// Funcion de pivote para QS1 (fecha y hora)
DNode *pivotKey1(DoublyLinkedList &dll, DNode *head, DNode *tail){
    DNode *pivot = tail; // Pivot apunta a tail
    DNode *aux = head->prev; // Variable auxiliar que apunta al prev de head
    // Recorremos la lista
    for (DNode *index = head; index != tail; index = index->next){
        // Validamos si la llave 1 del index es menor a la llave 1 del pivot
        if (index->getKey1() < pivot->getKey1()){
            // Validamos si aux es == nullptr
            if (aux == nullptr){
                // Aux es igual a head
                aux = head;
                // Si aux != nullptr entonces aux es igual a aux->next
            } else {
                aux = aux->next;
            }
            aux->swap(index); // Hacemos el swap
        }
    }
    // Validamos si aux es nullptr
    if (aux == nullptr){
        aux = head;
        // Si es diferente a nullptr
    } else {
        aux = aux->next;
    }
    // Hacemos el cambio y regresamos aux
    aux->swap(pivot);
    return aux;
}

// QS1 (fecha y hora)
void quickSortKey1(DoublyLinkedList &dll, DNode *head, DNode *tail){
    // Validamos si head es diferente a tail y si head es diferente a tail->next
    if (head != tail && head != tail->next) {
        DNode *pivotNode = pivotKey1(dll, head, tail);
        // Validamos si el prev de pivotNode es diferente a nullptr
        if (pivotNode->prev != nullptr){
            // Hacemos la llamada recursiva
            quickSortKey1(dll, head, pivotNode->prev);
        }
        // Validamos si el next de pivotNode es diferente a nullptr
        if (pivotNode->next != nullptr){
            // Hacemos la llamada recursiva
            quickSortKey1(dll, pivotNode->next, tail);
        }
    }
}

// Para crear el archivo output202-1.out
void crearOutputFile1(DoublyLinkedList &dll){
    // Creamos el archivo de salida
    ofstream archivo("output602-1.out");
    if (!archivo){   
        // Si no se puede abrir el archivo se despliega un mensaje de error
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    }
    // Si el archivo se puede abrir entonces
    // Se crea un apuntador auxiliar que apunte a head
    DNode *aux = dll.head;
    // Recorremos la lista
    while (aux != nullptr){
        // Escribimos en el archivo
        archivo << aux->log.month << " " << aux->log.day << " " << aux->log.year << " " << aux->log.time << " " << aux->log.ip << " " << aux->log.message << endl;
        aux = aux->next; // Recorremos aux al siguiente nodo
    }
    archivo.close();
}

DNode *pivotKey2(DoublyLinkedList &dll, DNode *head, DNode *tail){   
    DNode *pivot = tail; // Pivot apunta a tail
    DNode *aux = head->prev; // Variable auxiliar que apunta al prev de head
    // Recorremos la lista
    for (DNode *index = head; index != tail; index = index->next){
        if (index->getKey2() < pivot->getKey2()){
            // Validamos si aux es nullptr
            if (aux == nullptr){
                // Aux es igual a head
                aux = head;
                // Si aux != a nullptr entonces aux es igual a aux->next
            } else {
                // Aux es igual a aux->next
                aux = aux->next;
            }
            // Hacemos el swap
            aux->swap(index);
        }
    }
    // Validamos si aux es nullptr
    if (aux == nullptr){
        // Aux es igual a head
        aux = head;
    } else {
        // Aux es igual a aux->next si aux != nullptr
        aux = aux->next;
    }
    // Hacemos el swap
    aux->swap(pivot);
    // Retornamos aux
    return aux;
}

void quickSortKey2(DoublyLinkedList &dll, DNode *head, DNode *tail){
    // Validamos si head es diferente a tail y si head es diferente a tail->next
    if (head != tail && head != tail->next) {
        // LLamos a la funcion pivotKeY2
        DNode *pivotNode = pivotKey2(dll, head, tail);
        // Hacemos las dos llamadas recursivas
        if (pivotNode->prev != nullptr){
            quickSortKey2(dll, head, pivotNode->prev);
        }
        if (pivotNode->next != nullptr){
            quickSortKey2(dll, pivotNode->next, tail);
        }
    }
}

// Para crear el archivo de output602-2.out
void crearOutputFile2(DoublyLinkedList &dll)
{   
    // Creamos el archivo de salida
    ofstream archivo("output602-2.out");
    // Validamos si el archivo se pudo abrir
    if (!archivo){
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    }
    // Aux apuntado a head
    DNode *aux = dll.head;
    while (aux != nullptr)
    {   // Imprimimos
        archivo << aux->log.month << " " << aux->log.day << " " << aux->log.year << " " << aux->log.time << " " << aux->log.ip << " " << aux->log.message << endl;
        aux = aux->next;
    }
    // Cerramos archivo
    archivo.close();
}


DoublyLinkedList seqSearchAlg(const DoublyLinkedList& list, const string& stIP, const string& endIP) {
    // Validamos si la lista esta vacia
    DoublyLinkedList result;
    // Aux que apunta a head
    DNode* aux = list.head;
    // Mientras Aux !=  nullptr
    while (aux != nullptr) {
        // Comprobamos el rango
        if (aux->log.ip >= stIP && aux->log.ip <= endIP) {
            // Lo anadimos a la nueva DLL
            result.addLast(aux->log);
        }
        // Seguimos
        aux = aux->next;
    }
    // Regresamos la DLL
    return result;
}

// Funciones para guardar el rango y desplegralo de manera ascendnete y descendente
void fileAsc(DoublyLinkedList& list, const string& filename) {
    // Creamos el archivo
    ofstream file(filename);
    // Current apuntado a head
    DNode* current = list.head;
    // Recorremos la lista y escribimos en el archivo
    while (current != nullptr) {
        file << current->log.month << " " 
             << current->log.day << " " 
             << current->log.year << " " 
             << current->log.time << " " 
             << current->log.ip << " " 
             << current->log.message << "\n";
        current = current->next; // Recorremos current al next, esto lo hace asc
    }
    // Una vez que current == nullptr ya no hay nada que escribir
    file.close();
}

void fileDesc(DoublyLinkedList& list, const string& filename) {
    // Creamos el archivo
    ofstream file(filename);
    // Current apuntado a tail
    DNode* current = list.tail;
    while (current != nullptr) {
        file << current->log.month << " " 
             << current->log.day << " " 
             << current->log.year << " " 
             << current->log.time << " " 
             << current->log.ip << " " 
             << current->log.message << "\n";
        current = current->prev; // Recorremos current al prev, esto lo hace desc
    }
    // Una vez que current == nullptr ya no hay nada que escribir
    file.close();
}

int main()
{
    string nombreArchivo = "log602-2.txt"; // Nombre del archivo
    DoublyLinkedList dll; // Doubly Linked List
    // Comprobamos que se pudo abrir el archivo
    ifstream archivo("log602-2.txt");
    if (!archivo)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        exit(1);
    }
    // Variables auxiliar para poder leer el archivo
    string linea;
    int numRegistros = 0;
    // Leemos el archivo 
    while (getline(archivo, linea))
    {
        Log registroLog; //  Creamos un objeto de tipo Log
        istringstream ss(linea); // Con esto separamos el registro en palabras
        // Leemos cada palabra del registro
        ss >> registroLog.month >> registroLog.day >> registroLog.year >> registroLog.time >> registroLog.ip;
        // Concatenamos las palabras que forman el mensaje
        getline(ss >> ws, registroLog.message);
        registroLog.key1Generator(); // Creamos la llave para ordenar por fecha y hora
        registroLog.key2Generator(); // Creamos la llave para ordenar por ip, fecha y hora
        registroLog.separarTiempo(); // Separamos el tiempo en hora, minuto y segundo
        registroLog.formatearIp(); // Formateamos la ip para poder hacer el quick sort

        numRegistros++; // Incrementamos el contador de registros
        dll.addLast(registroLog); // Agregamos el registro a la lista
    }
    // Cerramos el archivo
    archivo.close();
    
    // Variables auxiliares
    DNode *head = dll.head; 
    DNode *tail = dll.tail;
    string ip1;
    string ip2;
    DoublyLinkedList range;

    // Seccion del menu
    int index = 0; // Index del menu
    do
    {
        cout << "Selecciona una opción" << endl;
        cout << "1 Ordena los datos por fecha y hora." << endl;
        cout << "2 Ordena los datos por ip, fecha y hora." << endl;
        cout << "3 Búsqueda por rango de ip's con búsqueda secuencial." << endl;
        cout << "4 Sumatoria de datos." << endl;
        cout << "5 Salir" << endl;
        cin >> index;

        switch (index)
        {
        // Ordenar los datos por fecha y hora
        case 1:
            quickSortKey1(dll, head, tail);
            crearOutputFile1(dll);
            cout << "Los datos han sido ordenando por fecha y hora en output602-1.out." << endl;
            break;
        // Ordenar los datos por ip, fecha y hora
        case 2:
            quickSortKey2(dll, head, tail);
            crearOutputFile2(dll);
            cout << "Los datos han sido ordenando por ip, fecha y hora en output602-2.out." << endl;
            break;
        // Busqueda por rango de ip's
        case 3:
            cout << "Formato de ingreso, no introducir 0s de mas" << endl;
            cout << "Correcto 10.14.0.104, Incorrecto 10.14.000.104" << endl;
            cout << "Ingresa el IP inicial de tu rango de IP's" << endl;
            cin >> ip1;
            cout << "Ingresa el IP final de tu rango de Ip's" << endl;
            cin >> ip2;
            // Llamamos a la dll donde vamos a almacenar el rango del usuario
            range  = seqSearchAlg(dll, ip1, ip2);
            quickSortKey2(range, range.head, range.tail);
            // Escribir los datos
            fileAsc(range, "iprange602-a.out");
            fileDesc(range, "iprange602-d.out");
            cout << "Los datos han sido ordenando por ip, fecha y hora en iprange602-a.out." << endl;
            cout << "Los datos han sido ordenando por ip, fecha y hora en iprange602-d.out." << endl;
            break;
        case 4:
            dll.cantidadIpsA(); // Para mostrar la suma de ips acumuladas por año
            dll.cantidadIpsMes(); // Para mostrar la suma de ips acumuladas por mes
            break;
        }
    } while (index != 5);
}

