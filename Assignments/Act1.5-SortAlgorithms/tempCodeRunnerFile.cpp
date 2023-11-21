#include <iostream>
using namespace std;
#include <vector>

template <class T>
void swap(vector<T> &list, int a, int b){
    if (list[a] != list[b]){
        T aux = list[a];
        list [a] = list[b];
        list [b] = aux;
    }
}

template <class T>
void print(vector<T> list){
    for (auto l : list){
        cout << l << " ";
    }
    cout << endl;
}

template <class T>
void swapSort(vector<T> &list)
{
    
}

int main()
{

    vector<int> list = {2,3,5,7,1,13,18,9};
    print(list);
    swap(list,0,1);
    print(list);

    return 0;
}
