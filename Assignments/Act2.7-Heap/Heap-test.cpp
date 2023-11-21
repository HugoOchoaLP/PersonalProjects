#include <iostream>
#include <chrono>
using namespace std;

#include "Heap.h"
#include "MinHeap.h"

template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "asc") {
        Heap<T> heap(list);
        for (int i = 0; i < list.size(); i++) {
            list[i] = heap.pop();
        }
    } else {
        MinHeap<T> heap(list);
        for (int i = 0; i < list.size(); i++) {
            list[i] = heap.pop();
        }
    }
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

template <class T>
void print(vector<T> list) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}


int main() {
    // Semilla para generar números aleatorios
    srand(time(0));

    vector<int> list = {8, 5, 17, 19, 21, 28};
    Heap<int> heap1(list);
    heap1.print();
    while (!heap1.isEmpty()) {
        cout << heap1.pop() << " ";
    }
    cout << endl;
    heap1.push(20);
    heap1.print();
    Heap<int> heap2 = {8, 5, 17, 19, 21, 28};
    heap2.push(34);
    heap2.print();

    MinHeap<int> minHeap = {28, 21, 17, 19, 5, 8};
    minHeap.print();
    while (!minHeap.isEmpty()) {
        cout << minHeap.pop() << " ";
    }
    cout << endl;

    vector<int> list1;
    vector<int> list2;
    createListInt(list1, 20);
    heapSort(list1,"asc");
    print(list1);
    createListInt(list2, 20);
    heapSort(list2,"desc");
    print(list2);

    return 0;
}