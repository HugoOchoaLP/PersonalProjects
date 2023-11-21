// Hugo Ochoa Lopez Portillo 
// A00835999
// ITC

// Aqui use el mismo TNode que en la Act de BST
#pragma once 

template<class T>
struct TNode {
    T data;
    TNode<T>* right;
    TNode<T>* left;
    TNode();
    TNode(T data);
    TNode(T data, TNode<T>* right, TNode<T>* left);
};

template<class T>
TNode<T>::TNode() {
    right = nullptr;
    left = nullptr;
}

template<class T>
TNode<T>::TNode(T data) {
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
}

template<class T>
TNode<T>::TNode(T data, TNode<T>* right, TNode<T>* left) {
    this->data = data;
    this->right = right;
    this->left = left;
}