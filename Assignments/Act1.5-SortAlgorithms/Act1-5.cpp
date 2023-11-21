// Hugo Ochoa Lopez Portillo
// A00835999
// ITC

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecucion: %.8f seconds.\n", elapsed.count() * 1e-9);
    cout << " " << endl;
}

// Imprime vectores de enteros y de caracteres
template<class T>
void print(vector<T> list) {
    for (auto l : list) {
        cout << l << " ";
    }
    cout << endl << endl;
}

// Imprime vectores de flotantes
template<class T>
void printFloat(vector<T> list) {
    for (auto l : list) {
        cout << fixed << setprecision(2) << l << " ";
    }
    cout << endl << endl;
}

template<class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++){
    int num = rand() % 100000 + 1;
    list.push_back(num);
  }
}


// Algoritmo de Ordenamiento por Intercambio
template<class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps) {
    // Iteración de cada una de las pasadas
    for (int i=0; i<list.size()-1; i++) {
        // Iteración del primer elemento con el resto
        for (int j=i+1; j<list.size(); j++) {
            // Incrementamos en 1 el número de comparaciones
            comparisons++;
            // Comparamos el list[i] con list[j]
            if (list[i] > list[j]) {
                // Incrementamos el valor de intercambios
                swaps++;
                // Intercambiamos i con j
                swap(list, i, j);
            }
        }
    }
}

// Algoritmos de ordenamiento burbuja
template<class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps) {
    int iter = 0;
    bool control = true;
    // Iteración por cada pasada
    while (iter < list.size()-1 && control) {
        // Inicializamos la variable de control
        control = false;
        // Comparamos en pares hasta dejar el valor mayor al final de la lista
        for (int i=1; i<list.size()-iter; i++) {
            // Incrementamos en 1 el número de comparaciones
            comparisons++;
            // Comparamos el list[i-1] con list[i]
            if (list[i-1] > list[i]) {
                // Incrementamos el valor de intercambios
                swaps++;
                // Intercambiamos i con j
                swap(list, i-1, i);
                // Si hubo intercambio cambiamos a true la variable de control
                control = true;
            }
        }
        // Incrementamos en 1 la variable iter
        iter++;
    }
}

// Algoritmo de ordenamiento Selection Sort
template<class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps){
    // Iteracion de cada una de las pasadas 
    for (int i=0; i<list.size()-1; i++){
        // Iteración del primer elemento con el resto
        int min = i;
        for (int j=i+1; j<list.size(); j++) {
            // Incrementamos en 1 el número de comparaciones
            comparisons++;
            // Comparamos el list[i] con list[j]
            if (list[j] < list[min]){
                // Asignamos a min j, que seria el nuevo valor mas pequeno
                min = j;
            } 
        }
        // Hacemos el intercambio
        if (min != i){
            swap(list,min,i);
            swaps++;
        }
    }
}

// Algoritmo de ordenamiento Insertion
template<class T>
void insertionSort (vector<T> &list, int &comparisons, int &swaps){
    for (int i=1; i<list.size();i++){
        int j = i-1;
        while (j>=0){
            comparisons++;
            // Comparamos los valores de j y j+1
            if (list[j+1] < list[j]){
                // Hacemos el intercambio
                swap(list,j,j+1);
                swaps++;
            } else {
                j = -1; // break
            }
            // Decrementamos el valor de j
            j--;
        } 
    }
}

template<class T>
void merge(vector<T> &list, int left, int mid, int right){
    // Creamos la lista temporal del lado izquierdo
    vector<T> listLeft;
    for (int i=left; i <= mid; i++){
        listLeft.push_back(list[i]);
    }
    // Creamos la lista temporal del lado derecho
    vector<T> listRight;
    for (int j=mid+1; j <= right; j++){
        listRight.push_back(list[j]);
    }
    // Definimos un indice auxiliar donde voy a ir ordenando los numeros
    int auxIndex = left;
    // Comparamos las listas
    // Creamos dos indices, uno para cada lista
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < listLeft.size() && rightIndex < listRight.size()) { // Compara mientras hay elementos por comparar
        // Comparamos listLeft[leftIndex] con listRight[rightIndex]
        if (listLeft[leftIndex] < listRight[rightIndex]){
            // El valor de la izquierda es menor al de la derecha
            list[auxIndex] = listLeft[leftIndex];
            // Incrementamos el valor de leftIndex
            leftIndex++;
        } else {
            // El valor de la derecha es menor al valor de la izquierda
            list[auxIndex] = listRight[rightIndex];
            // Incrementamos el valor de rightIndex
            rightIndex++;
        }
        // Incrementamos indice auxiliar
        auxIndex++;
    }
    // Se vacian los valores pendientes que ya no se pueden comparar
    // Vaciamos los valores restantes del lado izquierdo
    while (leftIndex < listLeft.size()){
        // El valor de la izquierda es menor al de la derecha
        list[auxIndex] = listLeft[leftIndex];
        // Incrementamos el valor de leftIndex
        leftIndex++;
        // Incrementamos el indice auxiliar
        auxIndex++;
    }
    // Vaciamos los valores restantes del lado derecha
    while (rightIndex < listRight.size()){
        // El valor de la derecha es menor al valor de la izquierda
        list[auxIndex] = listRight[rightIndex];
        // Incrementamos el valor de rightIndex
        rightIndex++;
        // Incrementamos el indice auxiliar
        auxIndex++;
    }
}

template<class T>
void mergeSort(vector<T> &list, int left, int right){
    if (left < right) {   // Condicion de control
        // Vamos a calcular mid
        int mid = left + (right-left)/2;
        // Ordenamos la lista de la izquierda
        mergeSort(list,left,mid);
        // Ordenamos la lista de la derecha
        mergeSort(list,mid+1,right);
        // Merge
        merge(list,left,mid,right);
    }
}

template<class T>
int getPivot(vector<T> &list, int left, int right){
    // Definimos el pivote
    int pivot = right;
    // Definimos un indice auxiliar
    int auxIndex = left-1;
    // Iteramos la lista desde left hasta right - 1
    for (int index=left; index<right; index++){
        // Comparamos el valor de index con el valor del pivot
        if (list[index] < list[pivot]){
            // Incrementamos el indice auxiliar
            auxIndex++;
            // Intercambiamos el indice auxiliar con index
            swap(list,index,auxIndex);
        }
    }
    // Incrementamos el indice auxiliar
    auxIndex++;
    // Intercambiamos el indice auxiliar con el pivot
    swap(list,pivot,auxIndex);
    // Regresamos el valor del indice auxiliar
    return auxIndex;
}

// Quick sort
template<class T>
void quickSort(vector<T> &list, int left, int right){
    if (left < right){
        // Obtenemos la posicion final del pivote
        int pivot = getPivot(list, left, right);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, left, pivot-1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot+1, right);
    }
}

// Shell sort
template<class T>
void shellSort(vector<T> &list, int n) {
  // Reordenar elementos en cada uno de n/2, n/4, n/8, etc.
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i ++) {
      int temp = list[i];
      int j;
      for (j = i; j >= interval && list[j - interval] > temp; j -= interval) {
        list[j] = list[j - interval];
      }
      list[j] = temp;
    }
  }
}

// Algoritmo de busqueda binaria
int binarySearch(vector<int> list, int data){
    // Ordenamos con sort de menos a mas 
    if (data == 0){
        throw out_of_range("Se acabo el programa");
    }
    if (data >= 1000001 || data < 1) {
        cout << "El numero no esta dentro del rango de valores de la lista" << endl << endl;
    } else {
        sort(list.begin(), list.end());
        // Incializamos left y right 
        int left = 0;
        int right = list.size()-1;
        // Hacemos un ciclo mientras left <= right
        while (left <= right) {
            // Calculamos el valor de en medio
            int mid = left + (right - left) / 2;
            // Comparamos el valor buscado con el valor de la lista en el indice mid
            if (data == list[mid]){
                // Ya lo encontramos
                return mid;
            } else {
                 // No son iguales, revisamos si es menor
                if (data < list[mid]){
                    // Si es menor
                    right = mid - 1;
                } else {
                    // es mayor 
                    left = mid + 1;
                }
            }
        }    
    }
    // Se termina el ciclo, no se encontro el valor
    // throw out_of_range("No se encontro el valor buscado");
    return -1;
}

// Algoritmo de busaqueda secuencial
int sequentialSearch(vector<int> list, int n)
{
    int size = list.size() - 1;
    while(size >= 0)
    {
        if(list[size] == n)
        {
            return size;
            break;
        }
        else
        {
            size -= 1;
        }
    }
    return -1;
}

// Crea un vector aleatorio de flotantes
void createListFloat(vector<float> &listFloat, int quantity){
    for (int i = 0; i < quantity; i++){
        float num = ((1000000.001 - 0.001) * ((float)rand() / RAND_MAX)) + 0.001;
        listFloat.push_back(num);
    }
}

// Busqueda binaria de flotantes
float binarySearchFloat(vector<float> list, float data){
    // Ordenamos con sort de menos a mas 
    if (data == 0){
        throw out_of_range("Se acabo el programa");
    }
    if (data >= 1000001 || data < 1) {
        cout << "El numero no esta dentro del rango de valores de la lista" << endl << endl;
    } else {
        sort(list.begin(), list.end());
        // Incializamos left y right 
        int left = 0;
        int right = list.size()-1;
        // Hacemos un ciclo mientras left <= right
        while (left <= right) {
            // Calculamos el valor de en medio
            int mid = left + (right - left) / 2;
            // Comparamos el valor buscado con el valor de la lista en el indice mid
            if (data == list[mid]){
                // Ya lo encontramos
                return mid;
            } else {
                 // No son iguales, revisamos si es menor
                if (data < list[mid]){
                    // Si es menor
                    right = mid - 1;
                } else {
                    // es mayor 
                    left = mid + 1;
                }
            }
        }    
    }
    // Se termina el ciclo, no se encontro el valor
    // throw out_of_range("No se encontro el valor buscado");
    return -1;
}

// Busqueda secuencial de flotantes
int sequentialSearchFloat(vector<float> list, float n)
{
    int size = list.size() - 1;
    while(size >= 0)
    {
        if(list[size] == n)
        {
            return size;
            break;
        }
        else
        {
            size -= 1;
        }
    }
    return -1;
}

// Crea un vector aleatorio de caracteres
void createListChar(vector<char> &listChar, int quantity){
    // Rango de caracteres para escoger
    char startChar = 'A'; 
    char endChar = 'Z';   

    for (int i = 0; i < quantity; i++){
        char randomChar = startChar + rand() % (endChar - startChar + 1);
        listChar.push_back(randomChar);
    }
}

// Busqueda binaria de caracteres
int binarySearchChar(vector<char> list, char data){
    // Ordenamos con sort de menos a mas 
    if (data == 0){
        throw out_of_range("Se acabo el programa");
    }
    if (data >= 1000001 || data < 1) {
        cout << "El numero no esta dentro del rango de valores de la lista" << endl << endl;
    } else {
        sort(list.begin(), list.end());
        // Incializamos left y right 
        int left = 0;
        int right = list.size()-1;
        // Hacemos un ciclo mientras left <= right
        while (left <= right) {
            // Calculamos el valor de en medio
            int mid = left + (right - left) / 2;
            // Comparamos el valor buscado con el valor de la lista en el indice mid
            if (data == list[mid]){
                // Ya lo encontramos
                return mid;
            } else {
                 // No son iguales, revisamos si es menor
                if (data < list[mid]){
                    // Si es menor
                    right = mid - 1;
                } else {
                    // es mayor 
                    left = mid + 1;
                }
            }
        }    
    }
    // Se termina el ciclo, no se encontro el valor
    // throw out_of_range("No se encontro el valor buscado");
    return -1;
}

// Busqueda secuencial de caracteres
int sequentialSearchChar(vector<char> list, char n)
{
    int size = list.size() - 1;
    while(size >= 0)
    {
        if(list[size] == n)
        {
            return size;
            break;
        }
        else
        {
            size -= 1;
        }
    }
    return -1;
}

int main() {

    // Semilla para generar números aleatorios
    srand(time(0));

    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Menu para el usuario
    int indexVector;
    cout << "Ingresa el tipo de vector que deseas crear:" << endl;
    cout << "1 Vector de enteros" << endl;
    cout << "2 Vector de flotantes" << endl;
    cout << "3 Vector de caracteres" << endl << endl;
    cin >> indexVector;
    cout << endl; 

    int numElements;
    cout << "Ingresa el número de elementos aleatorios que contendra el vector:" << endl << endl;
    cin >> numElements;
    cout << endl;

    // Empieza seccion de enteros
    if (indexVector == 1){
        vector<int> list;
        createListInt(list, numElements);
        vector<int> listAux;
        cout << "Lista random sin ordenar: " << endl << endl;
        print(list);
        int comparisons = 0;
        int swaps = 0;
        int indexInt;
        cout << "Escriba el número de operación que desee realizar: " << endl;
        cout << "1 Swap Sort" << endl;
        cout << "2 Bubble Sort" << endl;
        cout << "3 Selection Sort" << endl;
        cout << "4 Insertion" << endl;
        cout << "5 Merge Sort" << endl;
        cout << "6 Quick Sort" << endl;
        cout << "7 Shell Sort" << endl;
        cout << "8 Buscar un elemento específico usando búsqueda lineal y secuencial" << endl << endl;
        cin >> indexInt;
        cout << " " << endl;
        if (indexInt == 1){
            // Swap Sort
            int comparisons = 0;
            int swaps = 0;
            listAux = list;
            startTime(begin);
            swapSort(listAux, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Intercambio:" << endl << endl;
            print(listAux);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexInt == 2){
            // Bubble Sort
            listAux = list;
            comparisons= 0;
            swaps = 0;
            startTime(begin);
            bubbleSort(listAux, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Burbuja:" << endl << endl;
            print(listAux);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexInt == 3){
            // Selection Sort
            listAux = list;
            comparisons= 0;
            swaps = 0;
            startTime(begin);
            selectionSort(listAux, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Selection:" << endl << endl;
            print(listAux);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexInt == 4){
            // Insertion 
            listAux = list;
            comparisons= 0;
            swaps = 0;
            startTime(begin);
            insertionSort(listAux, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Insertion:" << endl << endl;
            print(listAux);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexInt == 5){
            // Merge Sort
            listAux = list;
            startTime(begin);
            mergeSort(listAux,0,listAux.size()-1);
            getTime(begin, end);
            cout << "Ordenamiento por Merge" << endl << endl;
            print(listAux);
        } else if (indexInt == 6){
            // Quick sort
            listAux = list;
            startTime(begin);
            quickSort(listAux,0,listAux.size()-1);
            getTime(begin, end);
            cout << "Ordenamiento por Quick" << endl << endl;
            print(listAux);
        } else if (indexInt == 7){
            // Shell sort
            listAux = list;
            startTime(begin);
            shellSort(listAux,listAux.size());
            getTime(begin, end);
            cout << "Ordenamiento por Shell" << endl << endl;
            print(listAux);
        } else if (indexInt == 8){
            // Buscar un valor con busqueda binaria y secuencial
            int target;
            cout << "Ingresa un número entre el 1 y 1,000,000" << endl << endl;
            cin >> target;
            cout << endl;
            // Busqueda binaria
            startTime(begin);
            int index = binarySearch(list,target);
            getTime(begin, end);
            if (index >= 0) {
                cout << "En la búsqueda binaria el valor " << target << " se encuentra en la posición " << index << endl;
            } else {
                cout << "En la búsqueda binaria el valor " << target << " no se encuentra en la lista" << endl; 
            } 
            // Busqueda secuencial
            startTime(begin);
            int indexSequential = sequentialSearch(list,target);
            getTime(begin, end);
            if (indexSequential >= 0){
                cout << "En la búsqueda sequencial el valor " << target << " se encuentra en la posición " << indexSequential << endl;
            } else {
                cout << "En la búsqueda secuencial el valor " << target << " no se encuentra en la lista" << endl; 
            }   
        } else {
            // Decir que es una opcion incorrecta
            cout << "Opción no disponible" << endl << endl;  
        } 
    } else if (indexVector == 2){
        // Crear vector de floats
        vector<float> listFloat;
        createListFloat(listFloat, numElements);
        vector<float> listAuxFloat;
        cout << "Lista random sin ordenar: " << endl << endl;
        printFloat(listFloat);
        int comparisons = 0;
        int swaps = 0;
        int indexFloat;
        cout << "Escriba el número de operación que desee realizar: " << endl;
        cout << "1 Swap Sort" << endl;
        cout << "2 Bubble Sort" << endl;
        cout << "3 Selection Sort" << endl;
        cout << "4 Insertion" << endl;
        cout << "5 Merge Sort" << endl;
        cout << "6 Quick Sort" << endl;
        cout << "7 Shell Sort" << endl;
        cout << "8 Buscar un elemento específico usando búsqueda lineal y secuencial" << endl << endl;
        cin >> indexFloat;
        cout << " " << endl;
        if (indexFloat == 1){
            // Swap Sort
            int comparisons = 0;
            int swaps = 0;
            listAuxFloat = listFloat;
            startTime(begin);
            swapSort(listAuxFloat, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Intercambio:" << endl << endl;
            printFloat(listAuxFloat);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexFloat == 2){
            // Bubble Sort
            listAuxFloat = listFloat;
            comparisons= 0;
            swaps = 0;
            startTime(begin);
            bubbleSort(listAuxFloat, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Burbuja:" << endl << endl;
            printFloat(listAuxFloat);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexFloat == 3){
            // Selection Sort
            listAuxFloat = listFloat;
            comparisons= 0;
            swaps = 0;
            startTime(begin);
            selectionSort(listAuxFloat, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Selection:" << endl << endl;
            printFloat(listAuxFloat);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexFloat == 4){
            // Insertion 
            listAuxFloat = listFloat;
            comparisons= 0;
            swaps = 0;
            startTime(begin);
            insertionSort(listAuxFloat, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Insertion:" << endl << endl;
            printFloat(listAuxFloat);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexFloat == 5){
            // Merge Sort
            listAuxFloat = listFloat;
            startTime(begin);
            mergeSort(listAuxFloat,0,listAuxFloat.size()-1);
            getTime(begin, end);
            cout << "Ordenamiento por Merge" << endl << endl;
            printFloat(listAuxFloat);
        } else if (indexFloat == 6){
            // Quick sort
            listAuxFloat = listFloat;
            startTime(begin);
            quickSort(listAuxFloat,0,listAuxFloat.size()-1);
            getTime(begin, end);
            cout << "Ordenamiento por Quick" << endl << endl;
            printFloat(listAuxFloat);
        } else if (indexFloat == 7){
            //Shell sort
            listAuxFloat = listFloat;
            startTime(begin);
            shellSort(listAuxFloat,listAuxFloat.size());
            getTime(begin, end);
            cout << "Ordenamiento por Shell" << endl << endl;
            printFloat(listAuxFloat); 
        } else if (indexFloat == 8){
            // Buscar un valor con busqueda binaria y secuencial
            float target;
            cout << "Ingresa un número entre el 1 y 1,000,000" << endl << endl;
            cin >> target;
            cout << endl;
            // Busqueda binaria
            startTime(begin);
            float index = binarySearchFloat(listFloat,target);
            getTime(begin, end);
            if (index >= 0) {
                cout << "En la búsqueda binaria el valor " << target << " se encuentra en la posición " << index << endl;
            } else {
                cout << "En la búsqueda binaria el valor " << target << " no se encuentra en la lista" << endl; 
            } 
            // Busqueda secuencial
            startTime(begin);
            int indexSequential = sequentialSearchFloat(listFloat,target);
            getTime(begin, end);
            if (indexSequential >= 0){
                cout << "En la búsqueda sequencial el valor " << target << " se encuentra en la posición " << indexSequential << endl;
            } else {
                cout << "En la búsqueda secuencial el valor " << target << " no se encuentra en la lista" << endl; 
            }   
        } else {
            // Decir que es una opcion incorrecta
            cout << "Opción no disponible" << endl << endl;  
        }
    } else if (indexVector == 3){
        // Crear vector de caracteres
        vector<char> listChar;
        createListChar(listChar, numElements);
        vector<char> listAuxChar;
        cout << "Lista random sin ordenar: " << endl << endl;
        print(listChar);
        int comparisons = 0;
        int swaps = 0;
        int indexChar;
        cout << "Escriba el número de operación que desee realizar: " << endl;
        cout << "1 Swap Sort" << endl;
        cout << "2 Bubble Sort" << endl;
        cout << "3 Selection Sort" << endl;
        cout << "4 Insertion" << endl;
        cout << "5 Merge Sort" << endl;
        cout << "6 Quick Sort" << endl;
        cout << "7 Shell Sort" << endl;
        cout << "8 Buscar un elemento especifico usando búsqueda lineal y secuencial" << endl << endl;
        cin >> indexChar;
        cout << " " << endl;
        if (indexChar == 1){
            // Swap Sort
            int comparisons = 0;
            int swaps = 0;
            listAuxChar = listChar;
            startTime(begin);
            swapSort(listAuxChar, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Intercambio:" << endl << endl;
            print(listAuxChar);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexChar == 2){
            // Bubble Sort
            listAuxChar = listChar;
            comparisons= 0;
            swaps = 0;
            startTime(begin);
            bubbleSort(listAuxChar, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Burbuja:" << endl << endl;
            print(listAuxChar);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexChar == 3){
            // Selection Sort
            listAuxChar = listChar;
            comparisons= 0;
            swaps = 0;
            startTime(begin);
            selectionSort(listAuxChar, comparisons, swaps);
            getTime(begin, end);
            cout << "Ordenamiento por Selection:" << endl << endl;
            print(listAuxChar);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexChar == 4){
            // Insertion 
            listAuxChar = listChar;
            comparisons= 0;
            swaps = 0;
            //startTime(begin);
            insertionSort(listAuxChar, comparisons, swaps);
            //getTime(begin, end);
            cout << "Ordenamiento por Insertion:" << endl << endl;
            print(listAuxChar);
            cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl << endl;
        } else if (indexChar == 5){
            // Merge Sort
            listAuxChar = listChar;
            startTime(begin);
            mergeSort(listAuxChar,0,listAuxChar.size()-1);
            getTime(begin, end);
            cout << "Ordenamiento por Merge" << endl << endl;
            print(listAuxChar);
        } else if (indexChar == 6){
            // Quick sort
            listAuxChar = listChar;
            startTime(begin);
            quickSort(listAuxChar,0,listAuxChar.size()-1);
            getTime(begin, end);
            cout << "Ordenamiento por Quick" << endl << endl;
            print(listAuxChar);
        } else if (indexChar == 7){
            // Shell sort
            listAuxChar = listChar;
            startTime(begin);
            shellSort(listAuxChar,listAuxChar.size());
            getTime(begin, end);
            cout << "Ordenamiento por Shell" << endl << endl;
            print(listAuxChar);
        } else if (indexChar == 8){
            // Buscar un valor con busqueda binaria y secuencial
            char target;
            cout << "Ingresa una letra entre A y Z" << endl << endl;
            cin >> target;
            cout << endl;
            // Busqueda binaria
            startTime(begin);
            int index = binarySearchChar(listChar,target);
            getTime(begin, end);
            if (index >= 0) {
                cout << "En la búsqueda binaria el valor " << target << " se encuentra en la posición " << index << endl;
            } else {
                cout << "En la búsqueda binaria el valor " << target << " no se encuentra en la lista" << endl; 
            } 
            // Busqueda secuencial
            startTime(begin);
            int indexSequential = sequentialSearchChar(listChar,target);
            getTime(begin, end);
            if (indexSequential >= 0){
                cout << "En la búsqueda sequencial el valor " << target << " se encuentra en la posición " << indexSequential << endl;
            } else {
                cout << "En la búsqueda secuencial el valor " << target << " no se encuentra en la lista" << endl; 
            }   
        }
    } else {
        // Decir que es una opcion incorrecta
        cout << "Tipo de vector no disponible" << endl << endl;
    }

    //vector<int> list = {15,7,3,9,12,5,2};
    
    return 0;
}