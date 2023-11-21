#ifndef MinHeap_h
#define MinHeap_h
#include <vector>
using namespace std;

template <class T>
class MinHeap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);
public:
    MinHeap();
    MinHeap(vector<T> list);
    MinHeap(initializer_list<T> list);
    T pop(); // elimina el elemento de mayor prioridad en el heap
    void push(T data); // inserta un elemento en el heap
    int getSize();
    void print();
    bool isEmpty();
    T top(); // Regresa el valor del dato que está con mayor prioridad en la fila priorizada.
};

template <class T>
MinHeap<T>::MinHeap()
{
}

template <class T>
void MinHeap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void MinHeap<T>::downSort(int father)
{
    // Haces el proceso por cada uno de los padres
    int son1;
    int son2;
    int littleBoy;
    // Hacemos el proceso hasta que el nodo father ya no tenga hijos
    while (father * 2 + 1 < heap.size())
    {
        // Asignamos el valor del primer hijo
        son1 = father * 2 + 1;
        // validams si tiene un 2do hijo
        if (father * 2 + 2 < heap.size())
        {
            // Asignamos el valor del segundo hijo
            son2 = father * 2 + 2;
            // le asignamos a bigBoy el menor de los hijos
            heap[son1] < heap[son2] ? littleBoy = son1 : littleBoy = son2;
        }
        else
        {
            // El primer hijo es el mayor
            littleBoy = son1;
        }
        // Validamos si tenemos que hacer el intercambio
        if (heap[littleBoy] < heap[father])
        {
            // Intercambiamos los valores
            swap(father, littleBoy);
            // le asignamos a father el valor del hijo más grande
            father = littleBoy;
        }
        else
        {
            father = heap.size();
        }
    }
}

template <class T>
MinHeap<T>::MinHeap(vector<T> list)
{
    // igualamos la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int father = list.size() / 2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (father >= 0)
    {
        // Llamamos al downSort para cada uno de los padres
        downSort(father);
        // recorremos al siguiente papa de derecha a izquierda
        father--;
    }
}

template <class T>
MinHeap<T>::MinHeap(initializer_list<T> list)
{
    // igualamos la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int father = list.size() / 2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (father >= 0)
    {
        // Llamamos al downSort para cada uno de los padres
        downSort(father);
        // recorremos al siguiente papa de derecha a izquierda
        father--;
    }
}

template <class T>
T MinHeap<T>::pop() {
    if (!heap.empty()) {
        // Gaurdamos el valor de mayor prioridad del heap
        T auxMax = heap[0];
        // Intercambiamos el primer elemento (el de mayor prioridad) con el último elemento de la lista
        swap(0, heap.size()-1);
        // Eliminamos el último nodo de la lista
        heap.pop_back();
        // Hacemos el reacomod hacía abajo del primer elemento (downSort(0))
        downSort(0);
        // regresamos el valor de mayor prioridad
        return auxMax;
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

template <class T>
void MinHeap<T>::push(T data) {
    // Validamos si el heap esta vacío
    if (!isEmpty()) {
        // Insertamos el elemento en la última posición del heap
        heap.push_back(data);
        // Determinamos la posición del elemento agregado
        int son = heap.size()-1;
        // Hacemos el reacomodo hacia arriba
        while (son > 0) {
            // Calculamos el padre 
            int father = (son - 1) / 2;
            // Comparamos el hijo con el padre
            if (heap[son] < heap[father]) {
                // Los intercambiamos
                swap(son, father);
                // Hacemos el hijo igual al padre
                son = father;
            } else {
                // Me salgo del ciclo
                son = 0;
            }
        }
    } else {
        heap.push_back(data);
    }
}

template <class T>
int MinHeap<T>::getSize()
{
    return heap.size();
}

template <class T>
void MinHeap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

template <class T>
bool MinHeap<T>::isEmpty() {
    return heap.empty();
}

template <class T>
T MinHeap<T>::top() {
    if (!isEmpty()) {
        return heap[0];
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

#endif /* MinHeap_h */