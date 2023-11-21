#include <iostream>
using namespace std;

int sumInt(int a, int b) {
    return a + b;
}

double sumDouble(double a, double b) {
    return a + b;
}

string sumString(string a, string b) {
    return a + b;
}

// Función de sumas dos valores con templates
template <class T>
T sum(T a, T b) {
    return a + b;
}

int main()
{
    int a = 5;
    int b = 10;
    int c = sumInt(a, b);

    double x = 5.5;
    double y = 10.5;
    double z = sumDouble(x, y);

    string s1 = "5";
    string s2 = "10";
    string s3 = sumString(s1, s2);

    c = sum(a, b);
    z = sum(x, y);
    s3 = sum(s1, s2);

    cout << "a: " << a << " + b: " << b << " = c: " << c << endl;
    cout << "x: " << x << " + y: " << y << " = z: " << z << endl;
    cout << "s1: " << s1 << " + s2: " << s2 << " = s3: " << s3 << endl;
    return 0;
}