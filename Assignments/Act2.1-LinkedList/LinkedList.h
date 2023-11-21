// Hugo Ochoa Lopez Portillo
// A00835999
// 25/09/2023

#ifndef LinkedList_h
#define LinkedList_h
#include <random>
#include <iomanip>
#include <cstdlib>

#include "Node.h"

template <class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    void addFirst(T data);
    void addLast (T data);
    void insert (int index, T data);
    void print();
    int getSize();
    bool isEmpty();
    void updateData(T oldData, T newData);
    void updateAt(int index, T data); 
    T getData(int index);
    bool deleteData(T data); 
    bool deleteAt(int index);
    int findData(T data);
    T& operator[](int index);
    void deleteList();
    LinkedList<T>& operator=(const LinkedList<T>& list);
    void createListInt(LinkedList<T>& list, int quantity);
    void manualListInt(LinkedList<T>& list, int quantity);
    void createListFloat(LinkedList<T>& list, int quantity);
    void manualListFloat(LinkedList<T>& list, int quantity);
};

template<class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

template<class T>
int LinkedList<T>::getSize(){
    return size;
}


template<class T>
void LinkedList<T>::print(){
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


template <class T>
void LinkedList<T>::addFirst(T data){
    // Creamos un nodo nuevo
    Node<T>* newNode = new Node<T>(data);
    // El apuntador next del nodo nuevo apunta a head
    newNode->next = head;
    // Head apunta al nodo nuevo
    head = newNode;
    // Incrementamos el tamano de la lista
    size++;
}

template<class T>
void LinkedList<T>::addLast(T data){
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

template<class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

template<class T>
void LinkedList<T>::insert(int index, T data){
    // Validamos que el indice exista en la lista
    if (index >= 0 && index < size){
        // Definimos un indice auxiliar igual a 0
        int auxIndex = 0;
        // Definimos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista
        while(auxIndex != index){
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el valor del indice auxiliar
            auxIndex++;
        }
        // Insertamos el valor
        aux->next = new Node<T>(data, aux->next);
        // Incrementamos el valor de size
        size++;
    } else {
        throw out_of_range("El indice no se encuentra en la lista");
    }
}


template <class T>
void LinkedList<T>::updateAt(int index, T data){
    // Validamos que el indice exista en la lista
    if (index >= 0 && index < size){
        // Definimos un indice auxiliar igual a 0
        int auxIndex = 0;
        // Definimos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista
        while(auxIndex != index){
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el valor del indice auxiliar
            auxIndex++;
        }
        // Insertamos el valor
        aux->data = data;
    } else {
        throw out_of_range("El indice no se encuentra en la lista");
    }
}

template <class T>
void LinkedList<T>::updateData(T oldData, T newData){
    // Validamos que los datos sean diferentes entre ellos
    if (oldData != newData){
        // Creamos un indice auxiliar
        int auxIndex = 0;
        // Definimos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista
        while(aux->data != oldData){
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el valor del indice auxiliar
            auxIndex++;
            // Throw out para el caso de que el valor no exista en la lista
            if(aux->next == nullptr){
                throw out_of_range("El valor a reemplazar no existe en la lista");
            }
        }
        // Insertamos el valor
        aux->data = newData;
    } else {
        throw out_of_range("El valor ya se encuentra en la lista");
    }
}

template <class T>
T LinkedList<T>::getData(int index){
    // Validamos que el indice exista en la lista
    if (index >= 0 && index < size){
        // Definimos un indice auxiliar igual a 0
        int auxIndex = 0;
        // Definimos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista
        while(auxIndex < index){
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el indice auxiliar
            auxIndex++;
        }
        // Regresamos el valor de data del indice
        return aux->data; 
    } else {
        throw out_of_range("El indice no se encuentra en la lista");
    }
}

template <class T>
T& LinkedList<T>::operator[](int index){
    // Validamos que el indice exista en la lista
    if (index >= 0 && index < size){
        // Definimos un indice auxiliar igual a 0
        int auxIndex = 0;
        // Definimos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista
        while(auxIndex < index){
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el valor del indice auxiliar
            auxIndex++;
        }
        // Regresamos el valor de data del indice
        return aux->data; 
    } else {
        throw out_of_range("El indice no se encuentra en la lista");
    }
}

template <class T>
int LinkedList<T>::findData(T data){
    // Definimos un contador auxiliar igual a head
    Node<T>* aux = head;
    // Definimos un indice auxiliar
    int auxIndex = 0;
    // Recorremos la lista para validar si ya lo encontramos 
    while (aux != nullptr){
        // Validamos si data es el valor de aux
        if (data == aux->data){
            // Ya lo encontramos 
            return auxIndex;
        } else {
            // Recorremos aux 
            aux = aux->next;
            // Incrementamos el indice auxliar
            auxIndex++;
        }
    }
    // Al salir del while asumimos que no lo encontramos 
    return -1;
}

template<class T>
bool LinkedList<T>::deleteAt(int index){
    // Validamos si el índice es válido
    if (index >= 0 && index < size) {
        // Caso especial en caso de que se quiera borrar el primer elemento de la lista
        if (index == 0) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        } else {
            // Definimos un indice auxiliar = 0
            int auxIndex = 0;
            // Definimos dos apuntadores auxiliares, uno apunta a head y otro a nullptr
            Node<T>* aux = head;
            Node<T>* auxPrev = nullptr;
            // Recorremos la lista
            while (auxIndex != index) {
                // Igualamos auxPrev con aux
                auxPrev = aux;
                // Pero ahora aux apunta al siguiente elemento y ya no es igual a auxPrev
                aux = aux->next;
                // Aumentamos el indice auxiliar
                auxIndex++;
            }
            // Una vez que ya llegamos al indice quitamos el nodo en ese indice
            auxPrev->next = aux->next;
            delete aux;
        }
        // Restamos uno al tamano de la lista porque liberamos un espacio de memoria
        size--;
        return true;
    } else {
        return false;
    }
}

template <class T> 
bool LinkedList<T>::deleteData(T data){
    // Validamos si la lista esta vacia
    if (!isEmpty()){
        // Validamos si el elemento a borrar es el primero
        if (head->data == data){
            // Creamos un nodo auxiliar igual a head
            Node<T>* aux = head;
            // Asignamos head al siguiente elemento
            head = head->next;
            // Decremento el tamano de la lista
            size--;
            // Libero el nodo auxiliar
            delete aux;
            // Regresamos verdadero
            return true;
        } else {
            // Creamos un nodo auxiliar igual a head
            Node<T>* aux = head->next;
            // Creamos un nodo auxiliar que apunte al nodo anterior a aux
            Node<T>* auxPrev = head;
            // Recorremos la lista hasta encontrar el dato buscado
            while (aux != nullptr) {
                // Validamos si el aux data es el elemento a borrar
                if (aux->data == data){
                    // Actualizamos el apuntador next del nodo auxiliar previo
                    auxPrev->next = aux->next;
                    // Decrementamos el tamano de la lista
                    size--;
                    // Liberamos el nodo auxiliar
                    delete aux;
                    // Regresamos verdadero
                    return true;
                }
                // Recorremos los valores auxiliares
                auxPrev = aux;
                aux = aux->next;
            }
            // No se encontro data en la lista 
            return false;
        }
    } else {
        // La lista esta vacia
        return false;
    }
}

template<class T>
void LinkedList<T>::deleteList(){
    while(!isEmpty()){
        deleteAt(0);
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list) {
    // Checar que no sea la misma lista
    if (this != &list) { 
        // Borrar la lista actual
        deleteList();

        // Creamos un puntero auxiliar para recorrer la lista
        Node<T>* aux = list.head;

        // Anadimos elementos a la lista actual
        while (aux != nullptr) {
            addLast(aux->data);
            aux = aux->next;
        }
    }
    // Regresa una referncia al objeto actual
    return *this;
}

// Crear lista random de enteros
template <class T>
void createListInt(LinkedList<T>& list, int quantity){
  for (int i = 0; i < quantity; i++){
    int num = rand() % 100000 + 1;
    list.addLast(num);
  }
}



// Crear lista de enteros dados por el usuario
template <class T>
void manualListInt(LinkedList<T>& list, int quantity){
    for (int i = 0; i < quantity; i++){
        int num;
        cout << "Ingresa el elemento numero " << i + 1 << endl;
        cin >> num;
        list.addLast(num);
    }
}

// Crear lista random de flotantes
template <class T>
void createListFloat(LinkedList<T>& list, int quantity){
  for (int i = 0; i < quantity; i++){
    float num = static_cast <float>(rand()) / RAND_MAX*1000;
    list.addLast(num);
  }
}

// Crear lista de flotantes dados por el usuario
template <class T>
void manualListFloat(LinkedList<T>& list, int quantity){
    for (int i = 0; i < quantity; i++){
        float num;
        cout << "Ingresa el elemento numero " << i + 1 << endl;
        cin >> num;
        list.addLast(num);
    }
}




#endif