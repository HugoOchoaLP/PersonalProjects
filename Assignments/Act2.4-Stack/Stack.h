#ifndef Stack_h
#define Stack_h

#include "Node.h"

template <class T>
class Stack {
private:
    Node<T>* head;
    int size;
public:
    Stack();
    void push(T data); // Agrega un elemento arriba de la pila
    void pop(); // Elemina el elemento de arriba de la pila (saco una papa)
    T top(); // Regresa el valor de elemento de arriba de la pila
    bool isEmpty(); // Regresa si la pila esta vacia 
    void print();
};

template <class T>
Stack<T>::Stack(){
    head = nullptr;
    size = 0;
}

// Print
template<class T>
void Stack<T>::print(){
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

// isEmpty
template<class T>
bool Stack<T>::isEmpty(){
    return size == 0;
}

// Push 
// Reemplaza el valor de head
template <class T>
void Stack<T>::push(T data){
    head = new Node<T>(data,head);
}

// Top
template <class T>
T Stack<T>::top(){
    // Solo regresamos el valor de enfrente
    return head -> data;
}

// Pop
template <class T>
void Stack<T>::pop(){
    if(head != nullptr){
        Node<T>* aux = head;
        head = aux->next;
        delete aux;
    }
}



#endif