int binarySearch(vector<int> list, int data){
    // Ordenamos con sort de menos a mas 
    if (data == 0){
        throw out_of_range("Se acabo el programa");
    }
    if (data >= 1000001 || data < 1) {
        cout << "El numero no esta dentro del rango de valores de la lista" << endl << endl;
    } else {
        sort(list.begin(), list.end());
        // Incializamos left y right 
        int left = 0;
        int right = list.size()-1;
        // Hacemos un ciclo mientras left <= right
        while (left <= right) {
            // Calculamos el valor de en medio
            int mid = left + (right - left) / 2;
            // Comparamos el valor buscado con el valor de la lista en el indice mid
            if (data == list[mid]){
                // Ya lo encontramos
                return mid;
            } else {
                 // No son iguales, revisamos si es menor
                if (data < list[mid]){
                    // Si es menor
                    right = mid - 1;
                } else {
                    // es mayor 
                    left = mid + 1;
                }
            }
        }    
    }
    // Se termina el ciclo, no se encontro el valor
    // throw out_of_range("No se encontro el valor buscado");
    return -1;
}