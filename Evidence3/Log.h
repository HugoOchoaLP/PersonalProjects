#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Log {
    // Divido el registro en 7 partes, como en la primera evidencia
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    // Sobrecarga de > y < para poder ordenar los registros
    bool operator<(Log log); 
    bool operator>(Log log);
    // Keys
    long long key1; // Sin IP (1era evidencia)
    string key2; // Con IP (2da evidencia)
    long long key1Generator(); 
    string key2Generator();
    Log(string year, string month, string day, string time, string ip, string message); // Constructor
    Log() = default; 
    friend ostream& operator<<(ostream& os, Log log); // Sobrecarga de operador << para poder imprimir los registros
    // Getters
    string getIp(); // Función para obtener la ip con el formato deseado
    string getMonth(); // Función para obtener el mes
    string getYear(); // Función para obtener el año
    string getDay(); // Función para obtener el día
    string getTime(); // Función para obtener la hora
    string getMessage(); // Función para obtener el mensaje
};

// Getters
string Log :: getYear(){
    return year;
}

string Log :: getMonth(){
    return month;
}

string Log :: getDay(){
    return day;
}

string Log :: getTime(){
    return time;
}

string Log :: getMessage(){
    return message;
}

// Constructor
Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    // Generamos las keys
    key1 = key1Generator(); // key1 es un long long y es la key sin la ip
    key2 = key2Generator(); // key2 es un string y es la key con la ip
}
 


// Get IP y formatear IP
string Log :: getIp(){
    // Formato de ip "xx.xx.xxx.xxx"
    // "12.45.789.111213"
    if(ip.size() < 13)
    {
        // Es importante considerar que 
        // Todas las IPs empiezan con "10.14.255.", solo cambian los ultimos tres posibles numeros
        string auxIp = "10.14.255.";
        string aux = "";
        int cont = 0;
        // Se inicializa en el lugra 10 porque es el punto y a partir de ahi cambian los ultimos
        // tres numeros
        for(int j = 10; j < ip.size(); j++){
            aux += ip[j]; // Se obtiene el numero que esta en la posicion j y se guarda en aux
            cont++; // Se aumenta el contador para saber cuantos numeros se han guardado
            // Si j es igual al tamaño de la ip menos 1, significa que ya se llego al final
            if(j == ip.size()-1){ 
                // Si el tamano es 1 agregamos 00 a la izquierda
                if (cont == 1) {
                    aux = "00" + aux;
                    // Si el tamano es 2 agregamos 0 a la izquierda
                } else if (cont == 2) {
                    aux = "0" + aux;
                    // Si el tamano es 3 no se agrega nada
                    // De hecho no es necesario este pedazo de codigo porque si el tamano es 12 
                    // no entra al ciclo inicial
                } /*else {
                    aux = aux;
                }
                */
                // Se agrega la cadena auxiliar a la ip y se reinicia el segmento
                auxIp += aux;
            }
        }
        // Se regresa la ip formateada
        return auxIp;
    } else {
        // Si la ip ya esta formateada se regresa tal cual
        return ip;
    }
}

// Generador de llave sin IP (Key 1)
long long Log::key1Generator() {
    // Arreglo de meses para despues igualar a cada uno con su valor numerico
    const string meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    // Variables auxiliares para darles valores a month y time
    string monthAux = month;
    string timeAux = time;

    // Ciclo para obtener el valor numerico de los meses
    for(int i = 0; i < 12; i++) {
        if(meses[i] == monthAux && i < 9) {
            // En caso de ser entre Jan y Sep se agrega un 0 a la izquierda
            monthAux = "0" + to_string(i+1);
        } else if(meses[i] == month) {
            // No es necesario agregar un 0 a la izquierda de Oct a Dec
            monthAux = to_string(i+1);
        }
    }

    // El formato de la hora es "hh:mm:ss"
    // Vamos a quitar los dos puntos para que quede "hhmmss"
    string horaAux = ""; 
    for(int j = 0; j < timeAux.size(); j++) {
        if(timeAux[j] >= 48 && timeAux[j] <= 57) {   
            horaAux += timeAux[j];
        }
    }
    timeAux = horaAux;

    // Se convierte todo a long long para poder hacer la comparacion
    return stoll(year + monthAux + day + timeAux);
}

// Generador de llave con IP (Key 2)
// Es similiar en muchas partes a Key 1
string Log::key2Generator() {
    const string meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    string monthAux = month;
    string timeAux = time;
    // Ahora tambien llamamos a la funcion getIp para obtener la ip formateada
    string ipAux = getIp();

    // Esto es igual que en Key 1
    for(int i = 0; i < 12; i++) {
        if(meses[i] == monthAux && i < 9) {
            // En caso de ser entre Jan y Sep se agrega un 0 a la izquierda
            monthAux = "0" + to_string(i+1);
        } else if(meses[i] == month) {
            // No es necesario agregar un 0 a la izquierda de Oct a Dec
            monthAux = to_string(i+1);
        }
    }

    // Igual que en Key 1
    string horaAux = ""; 
    for(int j = 0; j < timeAux.size(); j++) {
        if(timeAux[j] >= 48 && timeAux[j] <= 57) {   
            horaAux += timeAux[j];
        }
    }
    timeAux = horaAux;

    // Para las ip es necesario remover los '.' solamente.
    // Para las ip solo le quitamos los .
    string aux = "";
    for(int k = 0; k < ipAux.size(); k++) {
        // Seguimos la misma logica que en la hora
        if(ipAux[k] >= 48 && ipAux[k] <= 57) {
            aux += ipAux[k];
        }
    }
    ipAux = aux;

    // Se regresa la llave con el formato deseado (inlcuyendo la ip)
    return year + monthAux + day + horaAux + ipAux;
}

bool Log::operator<(Log log) {
    // Comparacion > usando key1 y key2
    if (key1 != log.key1) {
        return key1 < log.key1;
    } else {
        return key2 < log.key2;
    }
}

bool Log::operator>(Log log)
{
    // Comparación > usando key1 y key2
    if (key1 != log.key1) {
        return key1 > log.key1;
    } else {
        return key2 > log.key2;
    }
}

// Sobrecarga de operador << para poder imprimir los registros
ostream& operator<<(ostream& os, Log log) {
    os << log.month << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " " << log.message << endl;
    return os;
}