#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Incluimos los archivos con la estructura de registros y los algoritmos de ordenamiento
#include "Log.h"
#include "Heap.h"
#include "MinHeap.h"
#include "BST.h"
#include "TNode.h"

// Función para ordenar un vector con Heap Sort
template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "asc") {
        Heap<T> heap(list);
        for (int i = 0; i < list.size(); i++) {
            list[i] = heap.pop();
        }
    } else {
        MinHeap<T> heap(list);
        for (int i = 0; i < list.size(); i++) {
            list[i] = heap.pop();
        }
    }
}



int main()
{
    // Archivo de entrada
    ifstream fileIn("log602-3.txt");
    string line; // Variable para guardar el contenido del renglón leido
    string word; // Variable para guardar el contenido de cada palabra del campo message
    // Variables auxiliares de los registros
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    vector<Log> logs; // Vector para guardar los registros con la estructura Log
    int cont = 0; // Contador de registros
    // Ciclo para leer los registros 
    while (getline(fileIn, line)) { 
        stringstream ss(line); // Creamos una variable auxiliar ss para recorrer campo por campo
        // Guardamos la información de cada campo en la variable auxiliar correspondiente
        ss >> month >> day >> year >> time >> ip >> message;
        // Ciclo para recorrer cada palabra del campo message
        while (ss >> word) {
            message = message + " " + word;
        }
        Log log(year, month, day, time, ip, message); // Creamos el registro
        logs.push_back(log); // Lo agregamos al vector logs
        cont++; // Incrementamos el contador de registros
    }

    // Ya tenemos el vector de registros, ahora toca el menu
    int index = 0;
    cout << "1 Ordena los datos por IP, fecha y hora de mayor a menor (MaxHeap) " << endl;
    cout << "2 Ordena los datos por IP, fecha y hora de menor a mayor (MinHeap) " << endl;
    cout << "3 Despliega en pantalla cuales son las 10 ip's con mayor número de registros " << endl;
    cout << "4 Búsqueda de una ip en un árbol binario de búsqueda " << endl;
    cout << "5 Salir " << endl;
    // Ciclo para el menú
    while (index != 5) {
        cout << "Ingresa el número de la opción que deseas: ";
        cin >> index;
        cout << endl;
        if (index == 1){
            ofstream fileOutOp1("output602-1.out"); // Archivo de salida con los datos ordenados de mayor a menor
            // Ordenamos con Heap Sort y luego los ponemos en un Max Heap
            heapSort(logs, "asc");
            Heap<Log> hLogs(logs);
            // Escribimos los datos ordenados en el archivo de salida
            while(!hLogs.isEmpty()) {
                // Escribimos el primer dato hasta que no queden datos
                fileOutOp1 << hLogs.top(); 
                hLogs.pop(); 
            }
            fileOutOp1.close(); // Cerramos el archivo de salida
        } else if (index == 2){
            // Igual que en la opción 1 pero se usa un heap desc y un MinHeap
            ofstream fileOutOp2("output602-2.out");
            heapSort(logs, "desc");
            MinHeap<Log> minhLogs(logs);
            while(!minhLogs.isEmpty()) {
                fileOutOp2 << minhLogs.top();
                minhLogs.pop();
            }
            fileOutOp2.close();
        } else if (index == 3){ // Intente hacer esto una funcion pero me daba errores
            vector<string> soloIp; // Vector solo con las ips de los logs
            // Vector auxiliar en el cual vamos a andir a la izquierda el num 
            vector<string> auxSoloIp; // de veces que aparece la Ip en el documento
            for(int i = 0; i < logs.size(); i++) {
                string ip = logs[i].getIp(); // Obtenemos la ip de cada registro
                soloIp.push_back(ip); // La agregamos al vector soloIp
            }
            heapSort(soloIp,"asc"); // Ordenamos el vector de SoloIp con un HeapSort
            for(int i = 0; i < soloIp.size(); i++) { 
                int contador = 1; // Contador de cuantas veces aparece una misma Ip en el doc
                string auxIp = soloIp[i];
                while (auxIp == soloIp[i+1] && i+1 < soloIp.size()){
                    // Si encontramos dos Ips iguales sumamos i++ y contador +1
                    i++;
                    contador++;
                }
                // Desplegamos la cantidad de veces que se repite una IP y la IP en si
                string auxContador = "Cantidad: " + to_string(contador) + " IP: " + auxIp;
                auxSoloIp.push_back(auxContador); // Anadimos la IP y cuantas veces se repite en nuestro vector auxiliar
            }
            heapSort(auxSoloIp, "asc"); // Ordenamos el vector auxiliar de mayor a menor
            Heap<string> ipHeap(auxSoloIp); // Heap con solo las ips
            // Ahora se usa un cicclo for para desplegar las 10 ips mas repetidas
            for(int i = 0; i < 10; i++) {
                cout <<  ipHeap.top() << "\n";
                ipHeap.pop();
            }
        } else if (index == 4){
            vector<string> auxSoloIp; // Vector de solo Ips
            string ip; // Pedimos al usuario que nos de su Ip a buscar
            cout << "Ingresa la IP a buscar: " << endl;
            cout << "Formato: 10.14.255.xxx" << endl; // xxx es el numero que se busca
            cout << "Ejemplo: 10.14.255.032" << endl; // si pones .32 y no .032 no lo encuentra
            cin >> ip; 
            cout << endl;
            for(int i = 0; i < logs.size(); i++){
                string ip = logs[i].getIp();
                auxSoloIp.push_back(ip);
            }
            heapSort(auxSoloIp,"asc"); // Ordenamos el vector de solo Ips
            // Ahora es el turno de implementar el BST
            // Creamos un arbol de puras ips
            BST<string> tree;
            for(int j = 0; j < auxSoloIp.size(); j++) {
                tree.insert(auxSoloIp[j]); // Insertamos las Ips al arbol
            }
            // Filtro de existencia
            if(!tree.find(ip)){
                cout << "La IP no existe en el árbol\n";
            } else {
                // Si la IP existe la buscamos y luego contamos su cantidad de apariciones
                cout << "IP: " << ip << endl;
                cout << "La IP aparece " << tree.countIpReps(ip) << " veces en los registros" << endl;
            }
        } else if (index < 1 || index > 5){
            cout << "Ingresa un número válido" << endl;
        }
    }
    int rating;
    cout << "Ingresa tu calificación del funcionamiento del programa (0 al 10): ";
    cin >> rating;
    cout << endl;
    if (rating >= 0 && rating <= 6){
        cout << "Tu retroalimentacion es valiosa" << endl;
    } else if (rating >= 7 && rating <= 8){
        cout << "Que bien que te gusto el programa" << endl;
    } else if (rating >= 9 && rating <= 10) {
        cout << "Muchas gracias por tu retroalimentacion" << endl;
    } else {
        cout << "Ingresa un número válido" << endl;
    }
    return 0;
}
