#include <iostream>
using namespace std;
#include "LinkedList.h"

int main()
{
    
    LinkedList<string> list;
    try {
        list.insert(2,"Vaso");
    } catch (out_of_range &e){
        cout << e.what() << endl;
    }
    list.addLast("Cuchara");
    list.addFirst("Olla");
    list.addFirst("Estufa");
    list.addFirst("Jarra");
    list.addFirst("Plato");
    list.print();
    list.addLast("Cuchara");
    list.print();
    try {
        list.insert(2,"Vaso");
    } catch (out_of_range &e){
        cout << e.what() << endl;
    }
    cout << "Tamano de la lista: " << list.getSize() << endl;
    list.print();
    list.updateAt(1,"Cuchillo");
    list.print();
    cout << "" << list.getData(1) << endl;
    cout << "" << list.findData("Cuchillo") << endl;

    // Clase del 25/09/2023
    list.updateData("Cuchillo","Horno");
    list.print();
    list[1] = "Tarro";
    list.print();
    list.deleteData("Plato");
    list.print();
    list.deleteData("Olla");
    list.print();
    list.deleteData("Campana");
    list.print();

    
    LinkedList<string> list1;
    list1.addFirst("Olla");
    list1.addLast("Cuchara");
    list1.addLast("Plato");
    list1.print();
    
    LinkedList<string> list2;
    list2.addFirst("Sarten");
    list2.addLast("Tenedor");
    list2.addLast("Cuchillo");
    list2.print();
    
    // Sobrecarga de operador =
    list1 = list2;
    cout << "Lista despues de la sobrecarga de operador:" << endl;
    list1.print();  
    return 0;
}
