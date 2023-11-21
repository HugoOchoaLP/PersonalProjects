#ifndef Queue_h
#define Queue_h

#include "Node.h"

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    Queue();
    void push(T data); // Agrega un elemento al final de la fila
    void pop(); // Elimina el primer elemento de la fila
    T front(); // Regresa el primer elemento de la fila
    bool isEmpty();
    void print();
};

template <class T>
Queue<T>::Queue(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Push
template <class T>
void Queue<T>::push(T data){
    // Validamos si la lista esta vacia
    if (isEmpty()){
        head = new Node<T>(data);
    } else {
        // Definimos un apuntador auxiliar igual a head para recorrer la lista
        Node<T>* aux = head;
        // Vamos a recorrer la lista hasta llegar al ultimo nodo
        while (aux->next != nullptr){
            // Recorremos aux
            aux = aux->next;
         }
        // Creamos un nodo nuevo 
        aux->next = new Node<T>(data);
    }
    // Incrementamos el tamano de la lista
    size++;
}

// Pop
template <class T>
void Queue<T>::pop(){
    // Actualizar el valor de head
    Node<T>* aux = head;
    head = aux->next;
    delete aux;
}

// Front
template <class T>
T Queue<T>::front(){
    // Solo regresamos el valor de enfrente
    return head -> data;
}

// isEmpty
template<class T>
bool Queue<T>::isEmpty(){
    return size == 0;
}

// Print
template<class T>
void Queue<T>::print(){
    // Definimos un apuntador de tipo nodo igual a head
    Node<T>* aux = head;
    while (aux != nullptr){ // Mientras el atributo next de mi apuntador sea diferente a nulo
        // Imprimimos el valor del nodo
        cout << aux->data;
        if (aux->next != nullptr){
        // Asignamos a aux el valor de next de aux
            cout << " -> ";
        }
        // Asignamos a aux el valor de next de aux
        aux = aux->next;
    }
    // Imprimimos un salto de linea 
    cout << endl;
}


#endif // Queue_h