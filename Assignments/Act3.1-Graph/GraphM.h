#ifndef GraphM_h
#define GraphM_h

#include "Edge.h"

template <class T>
class GraphM {
private:
    vector<T> vertices;
    vector< vector<int> > matrix;
    int findVertex(T vertex);
public:
    GraphM();
    GraphM(vector<T> vertices, vector< Edge<T> > edges);
    void addVertex(T vertex);
    void addEdge(Edge<T> edge);
    void removeVertex(T vertex);
    void removeEdge(Edge<T> edge);
    void print();
};

template <class T>
GraphM<T>::GraphM() {

}

template <class T>
int GraphM<T>::findVertex(T vertex) {

    typename vector<T>::iterator it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }

}

template <class T>
GraphM<T>::GraphM(vector<T> vertices, vector< Edge<T> > edges) {
    // Actualizamos el atributo vértices en base a los vertices que recibimos de parametro
    this->vertices = vertices;
    // Inicializamos la matriz con valores en falso y de tamaño vertices.size x vertices.size 
    vector<int> row(vertices.size(),0);
    matrix.assign(vertices.size(),row);
    // Actualizamos los valores de la matriz en base a la lista de edges
    for (auto edge : edges) {
        // Buscamos la posición del origen
        int sourceIndex = findVertex(edge.source);
        // Buscamos la posición del destino
        int targetIndex = findVertex(edge.target);
        // Actualizamos la matriz
        if (sourceIndex != -1 && targetIndex != -1) {
            matrix[sourceIndex][targetIndex] = edge.weight;
        }
    }
}

template <class T>
void GraphM<T>::print() {
    cout << "   ";
    for (auto vertex : vertices) {
        cout << " " << vertex;
    }
    cout << endl;
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (int j=0; j<vertices.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <class T>
void GraphM<T>::addVertex(T vertex) {
    // Checamos si el vertices a agregar ya existe
    if (findVertex(vertex) == -1) {
        // Agregamos el vertice al vector de vertices
        vertices.push_back(vertex);
        // Agregamos una nueva columna a la matriz
        for (int i=0; i<matrix.size(); i++) {
            matrix[i].push_back(0);
        }
        // Agregamos una nueva fila a la matriz
        vector<int> row(vertices.size(),0);
        matrix.push_back(row);
    }
}

template <class T>
void GraphM<T>::addEdge(Edge<T> edge) {
    // Buscamos la posición del origen
    int sourceIndex = findVertex(edge.source);
    // Buscamos la posición del destino
    int targetIndex = findVertex(edge.target);
    // Validamos que los vertices existan
    if (sourceIndex != -1 && targetIndex != -1) {
        // Validamos que no exista ya una conexión entre los vertices
        if (matrix[sourceIndex][targetIndex] == 0) {
            // Actualizamos la matriz
            matrix[sourceIndex][targetIndex] = edge.weight;
        }
    }
}

template <class T>
void GraphM<T>::removeVertex(T vertex){
    // Buscamos la posición del vertice
    int vertexIndex = findVertex(vertex);
    // Validamos que el vertice exista
    if (vertexIndex != -1) {
        // Eliminamos el vertice del vector de vertices
        vertices.erase(vertices.begin() + vertexIndex);
        // Eliminamos la columna de la matriz
        for (int i=0; i<matrix.size(); i++) {
            matrix[i].erase(matrix[i].begin() + vertexIndex);
        }
        // Eliminamos la fila de la matriz
        matrix.erase(matrix.begin() + vertexIndex);
    }
}

template <class T>
void GraphM<T>::removeEdge(Edge<T> edge){
    // Buscamos la posición del origen
    int sourceIndex = findVertex(edge.source);
    // Buscamos la posición del destino
    int targetIndex = findVertex(edge.target);
    // Validamos que los vertices existan
    if (sourceIndex != -1 && targetIndex != -1) {
        // Validamos que exista una conexión entre los vertices
        if (matrix[sourceIndex][targetIndex] != 0) {
            // Actualizamos la matriz
            matrix[sourceIndex][targetIndex] = 0;
        }
    }
}

#endif /* GraphM_h */