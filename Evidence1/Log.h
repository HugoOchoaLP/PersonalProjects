#pragma once

struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    long long key;
    bool operator<(Log Log);
    bool operator>(Log Log);  // Sobrecarga de operadores es o punto o espacio

    Log(string year, string month, string day, string time, string ip, string message);
};

Log::Log(string year, string month, string day, string time, string ip, string message){
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    // Falta hacer algo en el consultor para que se genere la llave
    // Hacer una funcion que genere la llave
    // key = keyGenerator();
}

bool Log::operator<(Log log){
    return this->key < log.key;
}

bool Log::operator>(Log log){
    return this->key > log.key;
}