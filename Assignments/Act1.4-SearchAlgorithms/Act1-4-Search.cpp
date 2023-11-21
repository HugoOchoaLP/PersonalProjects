// Hugo Ochoa Lopez Portillo
// A00835999
// ITC

#include <iostream>
using namespace std;
#include <vector>
#include <chrono>
#include <algorithm>

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

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecucion: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000000 + 1;
    list.push_back(num);
    //cout << num << " ";
  }
}


int main(){

    // Semilla para generar números aleatorios
    srand(time(0));

    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Crear una lista de 10000 de enteros
    vector<int> list;
    createListInt(list, 10000);
    
    

  

    // vector <int> list = {5,23,12,27,32,34,38,40,45};

    int n;
    cout << "Ingresa un numero entre el 1 y 1,000,000" << endl << endl;
    cin >> n;
    cout << endl; 
    // int n = 23;
    // Busqueda binaria
    startTime(begin);
    int index = binarySearch(list,n);
    getTime(begin, end);
    if (index >= 0) {
        cout << endl << "En la busqueda binaria el valor " << n << " se encuentra en la posicion " << index << endl << endl;
    } else {
        cout << endl << "En la busqueda binaria el valor " << n << " no se encuentra en la lista" << endl << endl; 
    }

    // Busqueda secuencial
    startTime(begin);
    int indexSequential = sequentialSearch(list,n);
    getTime(begin, end);
    if (indexSequential >= 0){
        cout << endl << "En la busqueda sequencial el valor " << n << " se encuentra en la posicion " << indexSequential << endl << endl;
    } else {
        cout << endl << "En la busqueda secuencial el valor " << n << " no se encuentra en la lista" << endl << endl; 
    }   

    return 0;
}