#ifndef List_h
#define List_h

template <class T>
class List {
private:
    vector<T> list;
    int size;
public:
    List();
    void insert(T data);
    void removeLast();
    T getData(int index);
    int getSize();
    T getMax();
    void print();
};

// Hacer constructor por default
template <class T>
List<T>::List() {
    // Inicializo el tamaño de la lista en 0
    size = 0;
}

// Hacer metodo de insert
template <class T>
void List<T>::insert(T data) {
    // Insertar el dato al final de la lista
    list.push_back(data);
    // Incrementamos el tamaño de la lista
    size++;
}

// Remueve el último elemento de la lista
template <class T>
void List<T>::removeLast() {
    // Validamos que la lista no este vacia
    if (size > 0) {
        // Desplegamos el ultimo elemento de la lista
        cout << "El elemento a eliminar es: " << list[size-1] << endl;
        // removemos el ultimo elemento de la lista
        list.pop_back();
        // decrementamos el tamaño de la lista
        size--;
    } else { // Si la lista ya no tiene elementos el programa arroja este texto
        throw out_of_range("No hay elementos");
    }
}

// Obetener el dato de un elemento de la lista
template <class T>
T List<T>::getData(int index) {
    // Validamos que exista el dato a obtener
    if (index >= 0 && index < size) {
        // Retornamos el dato
        return list[index];
    } else {
        // Retornamos un dato nulo
        throw out_of_range("Posicion invalida");
    }
}

// Obtener el tamaño de la lista
template <class T>
int List<T>::getSize() {
    return size;
}

// Obtener el dato maximo de la lista
template <class T>
T List<T>::getMax() {
    // Validamos que la lista no este vacia
    if (size > 0) {
        // Inicializamos el dato maximo con el primer elemento de la lista
        T max = list[0];
        // Recorremos la lista para encontrar el dato maximo
        for (int i=1; i<size; i++) {
            // Validamos si el dato actual es mayor al dato máximo
            if (list[i] > max) {
                // Actualizamos el dato máximo
                max = list[i];
            }
        }
        // Retornamos el dato máximo
        return max;
    } else {
        // Retornamos un dato nulo
        throw out_of_range("La lista está vacía");
    }
}
// Hacer método de print
template <class T>
void List<T>::print() {
    // Recorrer la lista par imprimir cada uno de sus elementos
    // De manera tradicional
    for (int i=0; i<size; i++) {
        // imprimimos el elemento
        cout << "[" << i << "] - " << list[i] << " " << endl;
    }
    // De manera especial en los vectores
    // for (auto el : list) {
    //     // imprimimos el elemento
    //     cout << el << " ";
    // }
    // Saltamos renglón
    
}

#endif