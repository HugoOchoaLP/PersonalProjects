// Hugo Ochoa Lopez Portillo 
// A00835999
// ITC
#include <iostream>
#include <chrono>
using namespace std;

#include "Heap.h"
#include "MinHeap.h"

template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "desc") {
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

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

template <class T>
void print(vector<T> list) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}


int main()
{
    vector<int> list1 = {8, 5, 17, 19, 21, 28};
    Heap<int> heap1(list1);
    heap1.print();

    // Declaramos variables
    vector<int> list;
    Heap<int> heap = {};
    MinHeap<int> minHeap = {};
    // Semilla para generar números aleatorios
    srand(time(0));
    // Menu del usuario
    int tipoLista;
    cout << "Tipo de lista (enteros)" << endl;
    cout << "1 Generada por el usuario " << endl;
    cout << "2 Generada aleatoriamente " << endl;
    cin >> tipoLista;
    cout << endl;
    // Si el usuario elige la opcion 1
    if (tipoLista == 1){
        // Se le pide al usuario que ingrese el tamaño de la lista
        int size;
        cout << "Ingresa el tamaño de la lista" << endl;
        cin >> size;
        cout << endl;
        // Se le pide al usuario que ingrese los elementos de la lista
        for (int i = 0; i < size; i++)
        {
            int num;
            cout << "Ingresa el elemento " << i + 1 << " de la lista" << endl;
            cin >> num;
            list.push_back(num);
        }
        cout << endl;
    } else if (tipoLista == 2){
        // Si el usuario elige la opcion 2
        // Se le pide al usuario que ingrese el tamaño de la lista
        int size;
        cout << "Ingresa el tamaño de la lista" << endl;
        cin >> size;
        cout << endl;
        // Se crea la lista aleatoria
        createListInt(list, size);
        cout << "Lista aleatoria" << endl;
        print(list);
        cout << endl;
    } else {
        // Si el usuario no ingresa una opcion valida
        cout << "Opcion no valida" << endl;
        return 0;
    }
    // Heap Sort o Min Sort
    int tipoHeap;
    cout << "1 Heap " << endl;
    cout << "2 MinHeap " << endl;
    cin >> tipoHeap;
    cout << endl;
    // Si el usuario elige la opcion 1
    if (tipoHeap == 1){
        // Hacemos que la lista sea un HeapSort
        heap = list;
        heap.print();
        cout << endl;
    } else if (tipoHeap == 2){
        // Hacemos que la lista sea un MinSort
        minHeap = list;
        minHeap.print();
        cout << endl;
    } else {
        cout << "Opcion no valida" << endl;
        return 0;
    }
    // Menu
    int index;
    cout << "1 Ordenar de manera ascendente " << endl;
    cout << "2 Ordenar de manera descendente " << endl;
    cout << "3 Push " << endl;
    cout << "4 Pop " << endl;
    cout << "5 Top " << endl;
    cout << "6 Empty " << endl;
    cout << "7 Size " << endl;
    cout << "8 Salir " << endl;
    cin >> index;
    cout << endl;
    if (index == 1){
        heapSort(list, "asc");
        print(list);
        cout << endl;
    } else if (index == 2){
        heapSort(list, "desc");
        print(list);
        cout << endl;
    } else if (index == 3){
        int num;
        cout << "Ingresa el numero que quieres agregar" << endl;
        cin >> num;
        cout << endl;
        if (tipoHeap == 1){
            heap.push(num);
            heap.print();
            cout << endl;
        } else if (tipoHeap == 2){
            minHeap.push(num);
            minHeap.print();
            cout << endl;
        }
    } else if (index == 4){
        if (tipoHeap == 1){
            heap.pop();
            heap.print();
            cout << endl;
        } else if (tipoHeap == 2){
            minHeap.pop();
            minHeap.print();
            cout << endl;
        }
    } else if (index == 5){
        if (tipoHeap == 1){
            cout << heap.top() << endl;
            cout << endl;
        } else if (tipoHeap == 2){
            cout << minHeap.top() << endl;
            cout << endl;
        }
    } else if (index == 6){
        if (tipoHeap == 1){
            cout << heap.isEmpty() << endl;
            cout << endl;
        } else if (tipoHeap == 2){
            cout << minHeap.isEmpty() << endl;
            cout << endl;
        }
    } else if (index == 7){
        if (tipoHeap == 1){
            cout << heap.getSize() << endl;
            cout << endl;
        } else if (tipoHeap == 2){
            cout << minHeap.getSize() << endl;
            cout << endl;
        }
    } else if (index == 8){
        return 0;
    } else {
        cout << "Opcion no valida" << endl;
        return 0;
    }
    return 0;
}
