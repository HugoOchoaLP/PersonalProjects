// Validamos si la lista esta vacia
    if (isEmpty()){
        head = new Node<T>(data);
    } else {
        // Definimos un apuntador auxiliar igual a head para recorrer la lista
        Node<T>* aux = head;
        // Vamos a recorrer la lista hasta llegar al ultimo nodo
        while (aux->next != nullptr){
            // Recorremos aux
            aux = aux->next;
         }
        // Creamos un nodo nuevo 
        aux->next = new Node<T>(data);
    }
    // Incrementamos el tamano de la lista
    size++;
}