// Hugo Ochoa Lopez Portillo
// A00835999
// ITC

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// Estructura de datos del registro
struct LogEntry {
    long long key;
    string ip;
    string message;

    // Sobrecarga del operador < para comparar el long long
    bool operator<(const LogEntry& other) const {
        return key < other.key;
    }

    // Sobrecarga del operador >
    bool operator>(const LogEntry& other) const {
        return key > other.key;
    }
};


// Función para intercambiar valores de un vector
template<class T>
void swap(vector<T> &list, long long a, long long b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

// Función para asignar valores numéricos a los meses
int numMes(const string& mes) {
    // Static es que el arreglo solo se inicializará una vez en la primera llamada a la función y conserva su valor para las siguientes llamadas
    static const string meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; i++) {
        if (mes == meses[i]) {
            return i + 1; // Se devuelve el valor numérico del mes
        }
    }
    return 0; // Mes no válido
}

// Función para eliminar los dos puntos del tiempo
void eliminarDosPuntos(string& cadena) {
    cadena.erase(remove(cadena.begin(), cadena.end(), ':'), cadena.end());
}

// Pivote de Quick Sort 
template<class T>
int getPivot(vector<T> &list, int left, int right){
    // Definimos el pivote
    int pivot = right;
    // Definimos un indice auxiliar
    int auxIndex = left-1;
    // Iteramos la lista desde left hasta right - 1
    for (int index=left; index<right; index++){
        // Comparamos el valor de index con el valor del pivot
        if (list[index] < list[pivot]){
            // Incrementamos el indice auxiliar
            auxIndex++;
            // Intercambiamos el indice auxiliar con index
            swap(list,index,auxIndex);
        }
    }
    // Incrementamos el indice auxiliar
    auxIndex++;
    // Intercambiamos el indice auxiliar con el pivot
    swap(list,pivot,auxIndex);
    // Regresamos el valor del indice auxiliar
    return auxIndex;
}

// Quick sort
template<class T>
void quickSort(vector<T> &list, int left, int right){
    if (left < right){
        // Obtenemos la posicion final del pivote
        int pivot = getPivot(list, left, right);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, left, pivot-1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot+1, right);
    }
}

void binaryRange(vector<LogEntry> &entrada, long long entradaInicio, long long entradaFinal) {
    // Creamos un vector auxiliar
    vector<LogEntry> entradaAux;
    // Incializamos begin y end, que son los indices de la lista
    int begin = 0;
    int end = entrada.size();
    // Hacemos un ciclo mientras left <= right
    while (begin <= end) {
        // Calculamos el valor de en medio
        int mid = begin + (end - begin) / 2;
        // Obtenemos el valor de mid y lo compararmos con entradaInicio y entradaFinal
        if (entrada[mid].key >= entradaInicio && entrada[mid].key <= entradaFinal) {
            //cout << entrada[mid].key << endl;
            // Agrega el registro de la posición mid al vector entradaAux
            entradaAux.push_back(entrada[mid]);
            int left = mid - 1;

            // Agrega los registros de la izquierda
            while (entrada[left].key >= entradaInicio) {
                entradaAux.push_back(entrada[left]);
                //cout << entrada[left].key << endl;
                left -= 1;
            }

            // Agrega los registros de la derecha
            int right = mid + 1;
            while (entrada[right].key <= entradaFinal) {
                entradaAux.push_back(entrada[right]);
                //cout << entrada[right].key << endl;
                right += 1;
            }
            // Rompe el ciclo
            break;
        } 
        else if(entrada[mid].key > entradaFinal) {
            end = mid - 1;
        } 
        else{
            begin = mid + 1;
        }
    }
    // Ordenamos el vector entradaAux
    entrada = entradaAux;
    quickSort(entrada, 0, entrada.size()-1);
}


// Conversion de numeros a meses para el archivo de salida
string monthToNum(const string& month) {
    // Igualar el numero de mes a su abreviacion en ingles
    if (month == "01") return "Jan";
    else if (month == "02") return "Feb";
    else if (month == "03") return "Mar";
    else if (month == "04") return "Apr";
    else if (month == "05") return "May";
    else if (month == "06") return "Jun";
    else if (month == "07") return "Jul";
    else if (month == "08") return "Aug";
    else if (month == "09") return "Sep";
    else if (month == "10") return "Oct";
    else if (month == "11") return "Nov";
    else if (month == "12") return "Dec";
    // Para manejar errores
    else return ""; 
}

string convertToFormattedKey(long long key) {
    // Convierte la llave en una cadena de caracteres
    string keyStr = to_string(key);

    // Extrae los componentes de fecha y hora de la llave 
    string year = keyStr.substr(0, 4);
    string month = monthToNum(keyStr.substr(4, 2)); 
    string day = keyStr.substr(6, 2);
    string time = keyStr.substr(8, 2) + ":" + keyStr.substr(10, 2) + ":" + keyStr.substr(12, 2);

    // Construye la cadena de caracteres en el formato deseado
    string formattedKey = month + " " + day + " " + year + " " + time;

    return formattedKey;
}



int main() {
    // Archivo de entrada
    ifstream fileIn("log602.txt");
    // Archivo de salida
    ofstream fileOut("output602.txt");

    // Verificar que el archivo de entrada exista
    if (!fileOut.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1; // Sale del programa con un código de error
    }

    // Vector para almacenar los datos
    vector<LogEntry> list;
    // Vector auxiliar para almacenar los datos
    vector<LogEntry>listAux;

    string line; // Variable auxiliar para guardar el contenido del renglón leido
    string word; // Variable auxiliar para guardar el contenido de cada palabra del campo message
    // Variables auxiliares para guardar el contenido de cada campo del archivo
    string year;
    string month; 
    string day; 
    string time; 
    string ip; 
    string message;
    // Variable auxiliar para guardar el contador de registros
    int cont = 0;
    // Ciclo para leer todo los renglones del archivo de entrada
    while (getline(fileIn, line)) {
        // Creamos una variable auxiliar ss para recorrer campo por campo
        stringstream ss(line);
        // Guardamos la información de cada campo en la variable auxiliar correspondiente
        ss >> month >> day >> year >> time >> ip;
        
        // Asignar valor numérico al mes
        int mesNumerico = numMes(month);
        month = to_string(mesNumerico);
        
        if (month == "0") {
            cerr << "Error: Mes no válido en la línea " << cont + 1 << ": " << line << endl;
            continue;
        }

        // Leer el resto de la línea (message)
        getline(ss, message);

        // Asegurarse de que el día y la hora tengan dos dígitos
        // Se usa el operador ternario ?
        // condición ? valor si es verdadero : valor si es falso
        month = (month.size() == 1) ? "0" + month : month;

        // Eliminar los dos puntos del tiempo
        eliminarDosPuntos(time);

        // Formatear fecha y hora como un número largo
        // Convertimos las variables a string
        long long fechaHora = stoll(year + month + day + time);
        list.push_back({fechaHora, ip, message});


        // Aumentamos el contador 
        cont++;

        
    }

    // Ordenamos los datos por Quick Sort
    listAux = list;
    quickSort(listAux,0,listAux.size()-1);
    // Mostrar los valores ordenados junto con su IP y mensaje
    cout << "Datos ordenados por Quick Sort" << endl << endl;

    // Escribir los datos ordenados en el archivo de salida
    // Se usa substr para darle el formato original al archivo de salida
    for (const LogEntry& entry : listAux) {
        // Se convierte el long long a string
        // Por ejemplo 
        // entry.timestamp = 20220105211008 
        // timestampStr = "20220105211008"
        string timestampStr = to_string(entry.key);
        // string substr(tamano pos, tamano len);
        string year = timestampStr.substr(0, 4);
        // Usa la funcion monthToNum para convertir el numero del mes a su abreviacion en ingles
        string month = monthToNum(timestampStr.substr(4, 2));
        string day = timestampStr.substr(6, 2);
        string time = timestampStr.substr(8, 2) + ":" + timestampStr.substr(10, 2) + ":" + timestampStr.substr(12, 2);

        // Escribe el registro con el nuevo formato en el archivo de salida
        fileOut << month << " " << day << " " << year << " " << time << " " << entry.ip << " " << entry.message << endl;
    }


    // Cierra el archivo de salida
    fileOut.close();

    // Solicitar al usuario las fechas y horas de inicio y fin en el formato "YYYYMMDDHHMMSS"
    string startKeyStr;
    string endKeyStr;
    cout << "Ingresa la fecha y hora de inicio en formato 'YYYYMMDDHHMMSS', EJ '20220105004132'" << endl;
    getline(cin, startKeyStr);
    cout << "Ingresa la fecha y hora de fin en formato 'YYYYMMDDHHMMSS', EJ '20230825105252'" << endl;
    getline(cin, endKeyStr);

    // Convertir las fechas y horas ingresadas a números enteros
    long long startTime = stoll(startKeyStr);
    long long endTime = stoll(endKeyStr);

    // Realizar la búsqueda binaria 
    binaryRange(listAux, startTime, endTime);

    // Mostrar los registros correspondientes al rango en el nuevo formato
    cout << "Registros en el rango especificado y escritos en range602.txt:" << endl;
    ofstream outputFile("range602.txt");

    for (const LogEntry& entry : listAux) {
        // Convertir el timestamp al formato "Mes DD YYYY HH:MM:SS"
        string formattedTimestamp = convertToFormattedKey(entry.key);
        // Mostrar el registro en pantalla con el nuevo formato
        cout << formattedTimestamp << " " << entry.ip << " " << entry.message << endl;
        // Escribir el registro en range602.txt con el nuevo formato
        outputFile << formattedTimestamp << " " << entry.ip << " " << entry.message << endl;
    }

    // Cerrar el archivo de salida
    outputFile.close();

    return 0;
}
