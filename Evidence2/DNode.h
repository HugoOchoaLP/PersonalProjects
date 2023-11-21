#ifndef DNode_h
#define DNode_h
#pragma once
#include "Log.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Estructura de los nodos de la doubly linked list
struct DNode {
    Log log;
    DNode* next;
    DNode* prev;
    DNode();
    DNode(struct Log log);
    DNode(struct Log log, DNode* next, DNode* prev);
    void swap(DNode* node1);
    long long getKey1();
    string getKey2();
};

DNode::DNode() {
    next = nullptr;
    prev = nullptr;
}

DNode::DNode(struct Log log) {
    this->log = log;
    this->next = nullptr;
    this->prev = nullptr;
}

DNode::DNode(struct Log log, DNode* next, DNode* prev) {
    this->log = log;
    this->next = next;
    this->prev = prev;
}

void DNode::swap(DNode* node1){
    Log aux = node1->log;
    node1->log = this->log;
    this->log = aux;
}

long long DNode::getKey1(){
    return log.key1Generator();
}

string DNode::getKey2(){
    return log.key2Generator();
}

#endif /* DNode_h */