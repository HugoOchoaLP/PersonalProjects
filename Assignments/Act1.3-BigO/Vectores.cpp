#include <iostream>
#include <vector>
using namespace std;

// Escribe una función iterativa que dado un vector que contiene enteros positivos,
// regrese la suma de los enteros impares contenidos en el vector. 

// Notación Big O = O(n)
int imparesIterativa(vector<int> vector) {
    int suma = 0;
    for (int num : vector) { 
        if (num % 2 != 0) {  
            suma += num;
        }
    }
    return suma;
}

// Escribe una función recursiva que dado un vector que contiene enteros positivos,
// regrese la suma de los enteros impares contenidos en el vector.

// Notación Big O = O(1^n)
int imparesRecursiva(vector<int> list, int n = 0) {
    if (n == list.size()) {
        return 0;
    }

    if (list[n] % 2 == 1) {
        return list[n] + imparesRecursiva(list, n + 1);
    } else {
        return imparesRecursiva(list, n + 1);
    }
}

int main() {
    vector<int> list = {2, 4, 6, 8, 10, 246, 98, 15, 17};
    int resultadoIterativa = imparesIterativa(list);
    int resultadoRecursiva = imparesRecursiva(list);
    cout << "Usando una una funcion iterativa se encontro que la suma de los enteros impares es: " << resultadoIterativa << endl;
    cout << "Usando una una funcion recursiva se encontro que la suma de los enteros impares es: " << resultadoRecursiva << endl;
    return 0;
}



