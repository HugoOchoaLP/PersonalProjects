#ifndef BST_h
#define BST_h

#include "TNode.h"
#include <iostream>
#include <queue> // Para el recorrido por niveles
using namespace std;

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(BST<T>* aux, int level);
    int children(TNode<T>* aux);
    bool findAncestors(TNode<T>* node, T data);
public:
    BST();
    void insert(T data);
    void print();
    bool isEmpty();
    void printTree(TNode<T>* aux, int level);
    bool find(T data);
    bool remove(T data);
    void visit(int type);
    void height();
    void preorder(TNode<T>* node);
    void inorder(TNode<T>* node);
    void postorder(TNode<T>* node);
    void levelByLevel();
    void ancestors(T data);
    int whatLevelAmI(T data);
    int findLevel(TNode<T>* node, T data, int level);
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

// Regresa la cantidad de hijos del nodo
template <class T>
int BST<T>::children(TNode<T>* aux) {
    if (aux->left == nullptr && aux->right == nullptr) {
        return 0;
    } 
    if (aux->left != nullptr && aux->right != nullptr) {
        return 2;
    }
    return 1;
}


template<class T>
bool BST<T>::remove(T data){
    // Validar si el arbol esta vacio
    if (isEmpty()) {
        // El arbol esta vacio
        return false;
    }
    // Buscar el nodo (debemos de mantener un apuntador al padre)
    TNode<T>* aux = root;
    TNode<T>* parent = nullptr;
    // Iteramos mientras aux no sea nulo
    while (aux != nullptr) {
        // Validamos si el valor de aux es igual a data
        if (aux->data == data) {
            // Si es igual, validamos si aux tiene 0 hijos
            if (children(aux) == 0) {
                // Validamos si aux es la raiz
                if (parent == nullptr) {
                    // Si es igual root va a ser igual a nulo
                    root = nullptr;
                    // Borramos aux
                    delete aux;
                    // Regresamos true
                    return true;
                } else {
                    // No es la raiz, validamos si aux es menor que parent
                    if (aux->data < parent->data) {
                        // Si es menor el apuntador del lado izquierdo de parent va a ser igual a nulo
                        parent->left = nullptr;
                    } else {
                        // No es menor, apuntador del lado derecho de parent va a ser igual a nulo
                        parent->right = nullptr;
                    }
                    // Borramos aux
                    delete aux;
                    // Regresamos true
                    return true;
                }
            } else if (children(aux) == 1) {
                // Validamos si aux es la raiz
                if (parent == nullptr) {
                    // Si es la raiz, validamos si aux tiene hijo izquierdo
                    if (aux->left != nullptr) {
                        // Si tiene hijo izquierdo, root va a ser igual al hijo izquierdo de aux
                        root = aux->left;
                    } else {
                        // No tiene hijo izquierdo, root va a ser igual al hijo derecho de aux
                        root = aux->right;
                    }
                    // Borramos aux
                    delete aux;
                    // Regresamos true
                    return true;
                } else {
                    // No es la raiz, validamos si aux es menor que parent
                    if (aux->data < parent->data) {
                        // Si es menor, validamos si aux tiene hijo izquierdo
                        if (aux->left != nullptr) {
                            // Si tiene hijo izquierdo, el apuntador del lado izquierdo de parent va a ser igual al hijo izquierdo de aux
                            parent->left = aux->left;
                        } else {
                            // No tiene hijo izquierdo, el apuntador del lado izquierdo de parent va a ser igual al hijo derecho de aux
                            parent->left = aux->right;
                        }
                    } else {
                        // No es menor, validamos si aux tiene hijo izquierdo
                        if (aux->left != nullptr) {
                            // Si tiene hijo izquierdo, el apuntador del lado derecho de parent va a ser igual al hijo izquierdo de aux
                            parent->right = aux->left;
                        } else {
                            // No tiene hijo izquierdo, el apuntador del lado derecho de parent va a ser igual al hijo derecho de aux
                            parent->right = aux->right;
                        }
                    }
                    // Borramos aux
                    delete aux;
                    // Regresamos true
                    return true;
                }
            } else {
                // Validamos si aux es la raiz
                if (parent == nullptr) {
                    // Si es la raiz, buscamos el nodo mas grande del lado izquierdo
                    TNode<T>* largest = aux->left;
                    TNode<T>* largestParent = aux;
                    // Iteramos mientras el hijo derecho de largest no sea nulo
                    while (largest->right != nullptr) {
                        // largestParent va a ser igual a largest
                        largestParent = largest;
                        // largest va a ser igual al hijo derecho de largest
                        largest = largest->right;
                    }
                    // El valor de aux va a ser igual al valor de largest
                    aux->data = largest->data;
                    // Validamos si largest es igual al hijo izquierdo de aux
                    if (largest == aux->left) {
                        // Si es igual, el hijo izquierdo de aux va a ser igual al hijo izquierdo de largest
                        aux->left = largest->left;
                    } else {
                        // No es igual, el hijo derecho de largestParent va a ser igual al hijo izquierdo de largest
                        largestParent->right = largest->left;
                    }
                    // Borramos largest
                    delete largest;
                    // Regresamos true
                    return true;
                } else {
                    // No es la raiz, validamos si aux es menor que parent
                    if (aux->data < parent->data) {
                        // Si es menor, buscamos el nodo mas grande del lado izquierdo
                        TNode<T>* largest = aux->left;
                        TNode<T>* largestParent = aux;
                        // Iteramos mientras el hijo derecho de largest no sea nulo
                        while (largest->right != nullptr) {
                            // largestParent va a ser igual a largest
                            largestParent = largest;
                            // largest va a ser igual al hijo derecho de largest
                            largest = largest->right;
                        }
                        // El valor de aux va a ser igual al valor de largest
                        aux->data = largest->data;
                        // Validamos si largest es igual al hijo izquierdo de aux
                        if (largest == aux->left) {
                            // Si es igual, el hijo izquierdo de aux va a ser igual al hijo izquierdo de largest
                            aux->left = largest->left;
                        } else {
                            // No es igual, el hijo derecho de largestParent va a ser igual al hijo izquierdo de largest
                            largestParent->right = largest->left;
                        }
                        // Borramos largest
                        delete largest;
                        // Regresamos true
                        return true;
                    } else {
                        // No es menor, buscamos el nodo mas grande del lado izquierdo
                        TNode<T>* largest = aux->left;
                        TNode<T>* largestParent = aux;
                        // Iteramos mientras el hijo derecho de largest no sea nulo
                        while (largest->right != nullptr) {
                            // largestParent va a ser igual a largest
                            largestParent = largest;
                            // largest va a ser igual al hijo derecho de largest
                            largest = largest->right;
                        }
                        // El valor de aux va a ser igual al valor de largest
                        aux->data = largest->data;
                        // Validamos si largest es igual al hijo izquierdo de aux
                        if (largest == aux->left) {
                            // Si es igual, el hijo izquierdo de aux va a ser igual al hijo izquierdo de largest
                            aux->left = largest->left;
                        } else {
                            // No es igual, el hijo derecho de largestParent va a ser igual al hijo izquierdo de largest
                            largestParent->right = largest->left;
                        }
                        // Borramos largest
                        delete largest;
                        // Regresamos true
                        return true;
                    }
                }
            }
        } else {
            // No es igual, validamos si data es menor que aux->data
            if (data < aux->data) {
                // Si es menor, parent va a ser igual a aux
                parent = aux;
                // aux va a ser igual al hijo izquierdo de aux
                aux = aux->left;
            } else {
                // No es menor, parent va a ser igual a aux
                parent = aux;
                // aux va a ser igual al hijo derecho de aux
                aux = aux->right;
            }
        }
    }
    // No lo encontramos
    return false;
} 


template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    // Validamos si el arbol esta vacío
    if (isEmpty()) {
        // El árbol está vacío
        // root va a ser igual a un nuevo nodo con el valor de data
        root = new TNode<T>(data);
    } else {
        // El arbol no está vacío
        // Creamos un apuntador auxiliar apuntado a roor
        TNode<T>* aux = root;
        // Iteramos el árbol hasta poder insertar el valor nuevo (aux != nullptr)
        while (aux != nullptr) {
            // Comparamos si data es menor a aux->data
            if (data < aux->data) {
                // si es menor
                // Validamos si el apuntador del lado izquierdo de aux es nulo
                if (aux->left == nullptr) {
                    // si es nulo
                    // aux->left va a ser igual a nuevo nodo con el valor de data
                    aux->left = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // no es nulo
                    // Recorremos aux hacia aux->left
                    aux = aux->left;
                }
            } else {
                // es mayor o igual
                // Validamos si el apuntador del lado derecho de aux es nulo
                if (aux->right == nullptr) {
                    // si es nulo
                    // aux->right va a ser igual a nuevo nodo con el valor de data
                    aux->right = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // no es nulo
                    // Recorremos aux hacia aux->right
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::find(T data){
    // Creamos un apuntador auxiliar a root
    TNode<T>* aux = root;
    // Recorremos el arbol para buscar data
    while (aux != nullptr){
        // Validamos si data igual a aux->data
        if (aux->data == data){
            return true;
        } else {
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    // No lo encontramos
    return false;
}

template <class T>
void BST<T>::height(){
    // Validamos si el arbol esta vacio
    if (isEmpty()){
        // El arbol esta vacio
        cout << "El arbol esta vacio" << endl;
    } else {
        // El arbol no esta vacio, creamos un apuntador auxiliar a root
        TNode<T>* aux = root;
        // Creamos una variable para la altura
        int height = 0;
        // Recorremos el arbol para buscar la altura
        while (aux != nullptr){
            // Validamos si aux->left es nulo
            if (aux->left == nullptr){
                // Si es nulo, validamos si aux->right es nulo
                if (aux->right == nullptr){
                    // Si es nulo, regresamos la altura
                    cout << "La altura del arbol es: " << height << endl;
                    return;
                } else {
                    // No es nulo, recorremos aux hacia aux->right
                    aux = aux->right;
                    // Aumentamos la altura
                    height++;
                }
            } else {
                // No es nulo, recorremos aux hacia aux->left
                aux = aux->left;
                // Aumentamos la altura
                height++;

            }
        }
    }
}

// Visit
template <class T>
void BST<T>::visit(int order) {
    switch (order) {
        case 1: // Preorder
            preorder(root);
            break;
        case 2: // Inorder
            inorder(root);
            break;
        case 3: // Postorder
            postorder(root);
            break;
        case 4: // Level by level
            levelByLevel();
            break;
        default:
            std::cout << "Invalid order" << std::endl;
    }
}

// Preorder
template <class T>
void BST<T>::preorder(TNode<T>* node) {
    // Comprobamos que el nodo no sea nulo
    if (node != nullptr) {
        // Desplegamos el dato del nodo
        cout << node->data << " ";
        // Recorremos el lado izquierdo del nodo
        preorder(node->left);
        // Recorremos el lado derecho del nodo
        preorder(node->right);
    }
}

// Inorder
template <class T>
void BST<T>::inorder(TNode<T>* node) {
    // Comprobamos que el nodo no sea nulo
    if (node != nullptr) {
        // Recorremos el lado izquierdo del nodo
        inorder(node->left);
        // Desplegamos el dato del nodo
        cout << node->data << " ";
        // Recorremos el lado derecho del nodo
        inorder(node->right);
    }
}

// Postorder
template <class T>
void BST<T>::postorder(TNode<T>* node) {
    // Comprobamos que el nodo no sea nulo
    if (node != nullptr) {
        // Recorremos el lado izquierdo del nodo
        postorder(node->left);
        // Recorremos el lado derecho del nodo
        postorder(node->right);
        // Desplegamos el dato del nodo
        cout << node->data << " ";
    }
}

// Level by level
template <class T>
void BST<T>::levelByLevel() {
    // Comprobamos que el arbol no sea nulo
    if (root == nullptr)
        // El arbol esta vacio
        return;
    // Creamos una cola
    queue<TNode<T>*> lvlq;
    // Insertamos la raiz usando push
    lvlq.push(root);
    // Iteramos mientras la cola no este vacia
    while (!lvlq.empty()) {
        // Creamos un apuntador aux y lo igualamos al frente de la cola
        TNode<T>* aux = lvlq.front();
        // Desplegamos el dato del nodo
        lvlq.pop();
        cout << aux->data << " ";
        // Insertamos el hijo izquierdo de aux
        if (aux->left != nullptr){
            lvlq.push(aux->left);
        }
        // Insertamos el hijo derecho de aux  
        if (aux->right != nullptr){
            lvlq.push(aux->right);
        }
    }
}

// Ancestors de un nodo
template <class T>
bool BST<T>::findAncestors(TNode<T>* node, T data) {
    // Validamos si el nodo es nulo
    if (node == nullptr)
        return false;
    // Validamos si el dato es igual al dato del nodo
    if (node->data == data)
        return true;
    // Validamos si el dato es igual al dato del hijo izquierdo o derecho del nodo
    if (findAncestors(node->left, data) || findAncestors(node->right, data)) {
        cout << node->data << " ";
        return true;
    }
    return false;
}

// Ancestors
template <class T>
void BST<T>::ancestors(T data) {
    // Validamos si el arbol esta vacio
    if (!isEmpty()) {
        // Desplegamos los ancestros
        cout << "Ancestros de " << data << ": ";
        // Validamos si el dato se encuentra en el arbol
        if (!findAncestors(root, data))
            cout << "Dato no encontrado";
        cout << endl;
    } else {
        cout << "El arbol esta vacio" << endl;
    }
}

// Nivel de un nodo
template <class T>
int BST<T>::findLevel(TNode<T>* node, T data, int level) {
    // Validamos si el nodo es nulo
    if (node == nullptr)
        return -1;
    // Validamos si el dato es igual al dato del nodo
    if (node->data == data)
        return level;

    // Validamos si el dato es igual al dato del hijo izquierdo o derecho del nodo
    int leftLvl = findLevel(node->left, data, level + 1);
    // Validamos si el dato es igual al dato del hijo izquierdo o derecho del nodo
    if (leftLvl != -1)
        return leftLvl;
    // Regresamos el nivel del nodo
    return findLevel(node->right, data, level + 1);
}

// Nivel
template <class T>
int BST<T>::whatLevelAmI(T data) {
    // Validamos si el arbol esta vacio
    if (!isEmpty()) {
        // Creamos una variable para el nivel
        int lvl = 0;
        // Usams la funcion findLevel para encontrar el nivel del nodo
        int result = findLevel(root, data, lvl);
        // Validamos si el resultado es diferente de -1
        return result != -1 ? result : -1;
    } else {
        return -1;
    }
}

#endif /* BST_h */