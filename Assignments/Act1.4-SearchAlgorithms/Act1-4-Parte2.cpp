// Hugo Ochoa Lopez Portillo
// A00835999
// ITC

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Funcion para encontrar un caracter unico usando una busqueda secuencial
char findUniqueSequential(const string& str, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < str.length();i +=2) {
        // ++comparisons;
        if ((i == 0 || str[i] != str[i - 1]) && (i == str.length() - 1 || str[i] != str[i + 1])) {
            return str[i];
        }
        ++ comparisons;
    }
    return '\0';
}

// Funcion para encontrar un caracter unico usando una busqueda binaria
char findUniqueBinary(const string& str, int& comparisons) {
    comparisons = 0;
    int left = 0, right = str.length() - 1;
    while (left <= right) {
        ++comparisons;
        int mid = left + (right - left) / 2;
        if ((mid == 0 || str[mid] != str[mid - 1]) && (mid == str.length() - 1 || str[mid] != str[mid + 1])) {
            return str[mid];
        } else if (mid % 2 == 0) {
            if (str[mid] == str[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            if (str[mid] == str[mid - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return '\0'; // No se encontro un caracter unico
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);

        int seqComparisons, binaryComparisons;
        char uniqueSeq = findUniqueSequential(str, seqComparisons);
        char uniqueBin = findUniqueBinary(str, binaryComparisons);


        cout << uniqueSeq << " " << seqComparisons << " " << uniqueBin << " " << binaryComparisons << endl;
    }

    return 0;
}
