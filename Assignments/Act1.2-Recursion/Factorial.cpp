#include <iostream>
using namespace std;

// Funcion recursiva del factorial
int factorial(int n){
    if(n > 0){
        return n * factorial(n-1);
    } else {
        return 1;
    }
}

int main()
{
    
    int n = 4;
    int fact = factorial(n);
    cout << "El factorial es " << fact << endl;
    return 0;
}
