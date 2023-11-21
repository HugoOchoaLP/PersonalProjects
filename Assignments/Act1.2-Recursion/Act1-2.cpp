// Hugo Ochoa Lopez Portillo
// A00835999
// ITC

#include <iostream>
using namespace std;

// Funcion de suma iterativa
int sumIterative(int n){
    int sum = 0;
    for (int i=1; i<=n; i++){
        sum = sum + i; // Tambien funciona sum+= = 1;
    }
    return sum;
}

// Funcion de suma recursiva
int sumRecursion(int n){
    // Condicion de control
    if (n > 1){
        return n + sumRecursion(n-1);
    } else {
        return 1;
    }
}

int sumFormula(int n) {
    return n * (n+1)/2;
}

// Calcular Fibonacci iterativamente
int fibonacciIterative(int n){
    if (n == 1 || n == 2){
        return 1;
    } else {
        int f1 = 1;
        int f2 = 1;
        for (int i = 3; i <=n; i++){
            int aux = f2;
            f2 = f1 + f2;
            f1 = aux;
        }
        return f2;
    }
}

// Calcular Fibonacci recursivamente
int fibonacciRecursive(int n){
    if (n == 1 || n == 2){
        return 1;
    } else {
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }
}

// Calcular bacterias iterativamente
int bacteriasIterative(int days){
    int bacterias = 1;
    float rate = 1.44;
    for (int i=1; i<=days; i++){
        bacterias = bacterias + bacterias * rate;
    }
    return bacterias;
}

// Calcular bacterias recursivamente
int bacteriasRecursive(int days){
    if (days>0){
        int bacterias = bacteriasRecursive(days-1);
        float born = bacterias*1.44;
        return bacterias + born;
    } else { 
        return 1;
    }
}

// Calcular inversion iterativamente
float investmentIterative(float balance, int months){
    float interestRate = 18.75;
    float newBalance = balance;
    for (int i= 1; i<=months; i++){
        newBalance = newBalance * (1 + interestRate / 100);
    }
    return newBalance;
}

// Calcular inversion recursivamente
float investmentRecursive(float balance, int months){
    if (months > 0){
        return investmentRecursive(balance,months-1) * (1 + 18.75/100);
    } else {
        return balance;
    }
}

// Calcular potencia iterativamente
int powInterative(int n, int y){
    int result = n;
    for (int i=1; i<y; i++){
        result = result * n; // Tambien funciona sum+= = 1;
    }
    return result;
}

// Calcular potencia recursiva
int powRecursive(int n, int y){
    if (y > 1){
        return powRecursive(n,y-1) * n;
    } else {
        return n;
    }
}

int main()
{
    // Suma iterativa
    int sum1 = sumIterative(5);
    cout << "La suma del 1 al 5 es: " << sum1 << endl;
    // Suma recursiva
    int sum2 = sumRecursion(5);
    cout << "La suma del 1 al 5 es: " << sum2 << endl;
    // Suma con formula
    int sum3 = sumFormula(5);
    cout << "La suma del 1 al 5 es: " << sum3 << endl;
    // Fibonacci iterativo
    cout << "El numero fibonacci de 6 es: " << fibonacciIterative(6) << endl;
    // Fibonacci recursivo
    cout << "El numero fibonacci de 6 es: " << fibonacciRecursive(6) << endl;
    // Bacterias iterativas
    cout << "El numero de bacterias en el dia 4 es: " << bacteriasIterative(10) << endl;
    // Bacterias recursivas
    cout << "El numero de bacterias en el dia 4 es: " << bacteriasRecursive(10) << endl;
    // Inversion iterativa
    cout << "El balance de una cuenta con $10,000 despues de tres meses es: " << investmentIterative(10000,3) << endl;
    // Inversion recursiva
    cout << "El balance de una cuenta con $10,000 despues de tres meses es: " << investmentRecursive(10000,3) << endl;
    // Potencia iterativa
    cout << "El resultado del numero 5 elevado a la 3er potencia es: " << powInterative(5,3) << endl;
    // Potencia recursiva
    cout << "El resultado del numero 5 elevado a la 3er potencia es: " << powRecursive(5,3) << endl;

    return 0;
}
