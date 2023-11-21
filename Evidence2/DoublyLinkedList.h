#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h


#include "DNode.h"


class DoublyLinkedList {
public:
    
    DNode* head = nullptr;
    DNode* tail = nullptr;
    int size = 0;

    DoublyLinkedList();
    void addFirst(Log log);
    void addLast(Log log);
    void clear(); // Borra toda la lista
    bool isEmpty();
    int getSize();
    void cantidadIpsA();
    void cantidadIpsMes();
    void print(string mode);
    Log getData(int index);
};

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoublyLinkedList::isEmpty() {
    return size == 0;
}

int DoublyLinkedList::getSize(){
    return size;
}

void DoublyLinkedList::clear(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::addFirst(Log log) {
    // Asignamos a head un nuevo nodo con log, head y nullptr
    head = new DNode(log, head, nullptr);
    // Validamos si la lista estaba vacía
    if (head->next == nullptr) {
        // Actualizamos tail
        tail = head;
    } else {
        // Actualizamos el nodo que estaba al principio
        head->next->prev = head;
    }
    // Incrementamos el tamaño de la lista
    size++;
}


void DoublyLinkedList::addLast(Log log) {
    // Asignamos a tail un nuevo nodo con log, null ptr y tail
    tail = new DNode(log, nullptr, tail);
    // Validamos si la lista estaba vacía
    if (tail->prev == nullptr) {
        // Actualizamos tail
        head = tail;
    } else {
        // Actualizamos el nodo que estaba al principio
        tail->prev->next = tail;
    }
    // Incrementamos el tamaño de la lista
    size++;
}
 
void DoublyLinkedList::cantidadIpsA(){
    // Definimos un apuntador auxiliar que sea igual a head
    DNode* aux = head;
    // Creamos un contador para contar la cantidad de ips del 2022
    int contador2022 = 0;
    // Creamos un contador para contar la cantidad de ips 2023
    int contador2023 = 0;
    // Recorremos la lista
    while(aux != nullptr){
        if(aux->log.year == "2022"){
            // Incrementamos el contador de 2022
            contador2022++;
        }
        else{
            // Incrementamos el contador de 2023
            contador2023++;
        }
        // Recorremos aux al siguiente nodo
        aux = aux->next;
    }
    cout << "Cantidad de registros en el 2022: " << contador2022 << endl;
    cout << "Cantidad de registros en el 2023: " << contador2023 << endl <<endl;
}

void DoublyLinkedList::cantidadIpsMes(){
    DNode* aux = head; // Definimos un apuntador auxiliar que sea igual a head
    // Creamos contadores para contar la cantidad de ips de cada mes
    int contadorJan = 0;
    int contadorFeb = 0;
    int contadorMar = 0;
    int contadorApr = 0;
    int contadorMay = 0;
    int contadorJun = 0;
    int contadorJul = 0;
    int contadorAug = 0;
    int contadorSep = 0;
    int contadorOct = 0;
    int contadorNov = 0;
    int contadorDec = 0;
    // Recorremos por mes, si encuentra un mes, incrementa el contador
    while(aux != nullptr){
        if(aux->log.month == "Jan"){
            contadorJan++;
        }
        else if(aux->log.month == "Feb"){
            contadorFeb++;
        }
        else if(aux->log.month == "Mar"){
            contadorMar++;
        }
        else if(aux->log.month == "Apr"){
            contadorApr++;
        }
        else if(aux->log.month == "May"){
            contadorMay++;
        }
        else if(aux->log.month == "Jun"){
            contadorJun++;
        }
        else if(aux->log.month == "Jul"){
            contadorJul++;
        }
        else if(aux->log.month == "Aug"){
            contadorAug++;
        }
        else if(aux->log.month == "Sep"){
            contadorSep++;
        }
        else if(aux->log.month == "Oct"){
            contadorOct++;
        }
        else if(aux->log.month == "Nov"){
            contadorNov++;
        }
        else if(aux->log.month == "Dec"){
            contadorDec++;
        }
        // Recorremos aux al siguiente nodo
        aux = aux->next;
    }
    // Imprimimos la cantidad de ips de cada mes
    cout << "Cantidad de IPs del mes de Enero en 2022 y 2023: " << contadorJan << endl;
    cout << "Cantidad de IPs del mes de Febrero en 2022 y 2023: " << contadorFeb << endl;
    cout << "Cantidad de IPs del mes de Marzo en 2022 y 2023: " << contadorMar << endl;
    cout << "Cantidad de IPs del mes de Abril en 2022 y 2023: " << contadorApr << endl;
    cout << "Cantidad de IPs del mes de Mayo en 2022 y 2023: " << contadorMay << endl;
    cout << "Cantidad de IPs del mes de Junio en 2022 y 2023: " << contadorJun << endl;
    cout << "Cantidad de IPs del mes de Julio en 2022 y 2023: " << contadorJul << endl;
    cout << "Cantidad de IPs del mes de Agosto en 2022 y 2023: " << contadorAug << endl;
    cout << "Cantidad de IPs del mes de Septiembre en 2022 y 2023: " << contadorSep << endl;
    cout << "Cantidad de IPs del mes de Octubre en 2022 y 2023: " << contadorOct << endl;
    cout << "Cantidad de IPs del mes de Noviembre en 2022 y 2023: " << contadorNov << endl;
    cout << "Cantidad de IPs del mes de Diciembre en 2022 y 2023: " << contadorDec << endl;
}

void DoublyLinkedList::print(string mode){
    // Validamos si el modo es asc o desc
    if (mode == "asc") {
        // Definimos un apuntador auxiliar que sea igual a head
        DNode* aux = head;
        while (aux != nullptr) {
            // Imprimimos el valor de data
            cout << aux->log;
            // recorremos aux al apuntador de next
            aux = aux->next;
        }
        // Imprimos un salto de linea
        cout << endl;
    } else {
        // Definimos un apuntador auxiliar que sea igual a head
        DNode* aux = tail;
        while (aux != nullptr) {
            // Imprimimos el valor de data
            cout << aux->log;
            // recorremos aux al apuntador de next
            aux = aux->prev;
        }
        // Imprimos un salto de linea
        cout << endl;    
    }
}

Log DoublyLinkedList::getData(int index) {
    // Validamos si el índice es válido
    if (index >= 0 && index < size) {
        // Validamos si el índice es 0
        if (index == 0) {
            // Retornamos el valor de head
            return head->log;
        } else if (index == size - 1) {
            // Retornamos el valor de tail
            return tail->log;
        } else {
            // Definimos un apuntador auxiliar que sea igual a head
            DNode* aux = head;
            // Recorremos la lista hasta llegar al índice
            for (int i = 0; i < index; i++) {
                // Recorremos aux al siguiente nodo
                aux = aux->next;
            }
            // Retornamos el valor de data
            return aux->log;
        }
    } else {
        // Retornamos un valor por defecto
        return Log();
    }
}

#endif /* DoublyLinkedList_h */