#ifndef Graph_h
#define Graph_h

#include "Edge.h"
#include <queue>
#include <stack>
#include <climits> // INT_MAX
#include <vector>


template <class T>
class Graph {
private:
    vector<T> vertices;
    vector< vector< Edge<T> > > adjacencyList;
    int findVertex(T vertex);
    void dfsr(T vertex, vector<bool> &status);
    int findShortest(vector<bool> &status, vector<int> &cost);
public:
    Graph();
    Graph(vector<T> vertices, vector< Edge<T> > edges);
    void addEdge(Edge<T> edge);
    void addVertex(T vertex);
    void removeEdge(Edge<T> edge);
    void removeVertex(T Vertex);
    void bfs(T vertex);
    void dfs(T vertex);
    void dijkstra(T vertex);
    void print();
};

template <class T>
Graph<T>::Graph() {

}

template <class T>
int Graph<T>::findVertex(T vertex) {

    typename vector<T>::iterator it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }

}


template <class T>
Graph<T>::Graph(vector<T> vertices, vector< Edge<T> > edges) {
    // Actualizar la lista de vertices
    this->vertices = vertices;
    // Inicializamos la lista de adyacencias
    vector< Edge<T> > defaultEdges;
    adjacencyList.assign(vertices.size(), defaultEdges);
    
    // Recorremos la lista de adyacencias
    for (auto edge : edges) {
        // Buscamos el índice del vertice origen
        int sourceIndex = findVertex(edge.source);
        // Validamos si el vértice origen existe en la lista de vértices
        if (sourceIndex != -1) {
            // Agreamos el edge en la posición del vértice origen de nuestra lista de adyacencias
            adjacencyList[sourceIndex].push_back(edge);
        }
    }
}

template <class T>
void Graph<T>::addEdge(Edge<T> edge) {
    // Buscar el índice del vértice origen
    int sourceIndex = findVertex(edge.source);
    // Buscar el índice del vértice destino
    int targetIndex = findVertex(edge.target);
    // Validar que los dos vértices existan
    if (sourceIndex != -1 && targetIndex != -1) {
        // Buscar si ya existe el edgen en la lista de adyacencias 
        for (int i=0; i<adjacencyList[sourceIndex].size(); i++) {
            // Validamos si ya existe el target
            if (adjacencyList[sourceIndex][i].target == edge.target) {
                // Nos salimos de la función
                throw invalid_argument("El arco ya existe");
            }
        }
        // Si no existe agregarlo
        adjacencyList[sourceIndex].push_back(edge);
    } else {
        throw invalid_argument("Alguno de los vértices no existe");
    }
}

template <class T>
void Graph<T>::addVertex(T vertex) {    
    // Buscar si existe el vértice a agregar
    int vertexIndex = findVertex(vertex);
    // Agregarlos si no existe
    if (vertexIndex == -1) {
        // Agregamos el vértice en la lista de vértices
        vertices.push_back(vertex);
        // Agregamos una elemento en la lista de adyacencias vacío
        vector < Edge<T> > adyacencies;
        adjacencyList.push_back(adyacencies);
    } else {
        throw invalid_argument("El vértice ya existe");
    }
}

template <class T>
void Graph<T>::removeVertex(T vertex) {
    // Buscar si existe el vértice a borrar
    int vertexIndex = findVertex(vertex);
    // Eliminar el vértice de la lista de adyacencias tanto como origen y/o destino
    if (vertexIndex != -1) {
        // Eliminar el vértice de la lista de adyacencias
        adjacencyList.erase(adjacencyList.begin() + vertexIndex);
        // Eliminar el vértice de la lista de vértices
        vertices.erase(vertices.begin() + vertexIndex);
        // Eliminar el vértice de la lista de adyacencias de los demás vértices
        for (int i=0; i<adjacencyList.size(); i++) {
            // Recorremos la lista de adyacencias de cada vértice
            for (int j=0; j<adjacencyList[i].size(); j++) {
                // Validamos si el target es igual al vértice a borrar
                if (adjacencyList[i][j].target == vertex) {
                    // Borramos el edge
                    adjacencyList[i].erase(adjacencyList[i].begin() + j);
                }
            }
        }
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

template <class T>
void Graph<T>::removeEdge(Edge<T> edge) {
    // Buscar el índice del vértice origen
    int sourceIndex = findVertex(edge.source);
    // Buscar el índice del vértice destino
    int targetIndex = findVertex(edge.target);
    // Validar que los dos vértices existan
    if (sourceIndex != -1 && targetIndex != -1) {
        // Buscar si ya existe el edgen en la lista de adyacencias 
        for (int i=0; i<adjacencyList[sourceIndex].size(); i++) {
            // Validamos si ya existe el target
            if (adjacencyList[sourceIndex][i].target == edge.target) {
                // Eliminamos el edge
                adjacencyList[sourceIndex].erase(adjacencyList[sourceIndex].begin() + i);
            }
        }
    } else {
        throw invalid_argument("Alguno de los vértices no existe");
    }
}

template <class T>
void Graph<T>::bfs(T vertex) {
    // Verificamos si existe el vértice
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Si existe
        // Creamos un vector de tipo bool del tamaño de la cantidad de vértices inicializado en false (status)
        vector<bool> status(vertices.size(), false);
        // Creamos una file de tipo int (Vamos a almacenar el índice del vértice)
        queue<int> bfsQueue;
        // Agreamos el vértice que recibimos de parámetro a la fila
        bfsQueue.push(vertexIndex);
        // Cambiamos su estado a verdadero en la lista de estados
        status[vertexIndex] = true;
        // Hacemos un ciclo mientras la fila no este vacía
        while (!bfsQueue.empty()) {
            // Leemos el primer elemento de la fila
            int neighborIndex = bfsQueue.front();
            // Recorremos sus vecinos en la lista de adyacencias
            for (auto edge : adjacencyList[neighborIndex]) {
                // Buscamos el indice de vecino
                int targetIndex = findVertex(edge.target);
                // Validamos su estatus en el vector de estado
                if (!status[targetIndex]) {
                    // Si es falso agregamos el índice a la fila
                    bfsQueue.push(targetIndex);
                    // Actualizamos su estado
                    status[targetIndex]= true;
                }
            }
            // Imprimimos el elemento 
            cout << bfsQueue.front() << " ";
            // Sacamos el elemento de la fila
            bfsQueue.pop();
        }
        cout << endl;
    } else {
        throw invalid_argument("Vértice inválido");
    }
}

template <class T>
void Graph<T>::dfsr(T  vertex, vector<bool> &status) {
    // Visitamos al vértice
    cout << vertex << " ";
    // Búscamos el índice del vértice
    int vertexIndex = findVertex(vertex);
    // Cambiamos su estado a verdadero
    status[vertexIndex] = true;
    // Recorremos todos sus vecinos
    for (auto neighbor : adjacencyList[vertexIndex]) {
        // Buscamos el índice del vecino
        int neighborIndex = findVertex(neighbor.target);
        // Validamos si el estado esta en falso
        if (!status[neighborIndex]) {
            // Llamamos a la función de recursividad
            dfsr(neighbor.target, status);
        }
    }
}

template <class T>
void Graph<T>::dfs(T vertex) {
    // Validamos si el vértice éxiste
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos un vector de booleanos del tamaño de la cantidad de vértices
        vector<bool> status(vertices.size(), false);
        // Llamamos a la función de recursividad
        dfsr(vertex, status);
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

template <class T>
int Graph<T>::findShortest(vector<bool> &status, vector<int> &cost) {
    // inicializamos el valor del índice del valor más pequeño en -1
    int shortestIndex = -1;
    // Inicializamos una variable con el costo más grande
    int shortestCost = INT_MAX;
    // Iteramos todos los vértices
    for (int i=0; i<vertices.size(); i++) {
        // Validamos si su estado no es falso
        if (!status[i]) {
            // Validamos si es menor al valor más pequeño
            if (cost[i] < shortestCost) {
                // Actualizamos shortCost
                shortestCost = cost[i];
                // Actualizamos el índice del más pequeño
                shortestIndex = i;
            }
        }
    }
    // regresamos el índice más pequeño
    return shortestIndex;
}

template <class T>
void Graph<T>::dijkstra(T vertex) {
    // Revisamos si exoste el vértice
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos la lista de estado
        vector<bool> status(vertices.size(), false);
        // Creamos la lista de pesos
        vector<int> cost(vertices.size(), INT_MAX);
        // Creamos la lista de paths
        vector<int> path(vertices.size(), -1);
        // Actualizamos en 0 el costo del índice del vértice inicial
        cost[vertexIndex] = 0;
        int shortestIndex = vertexIndex;
        // Iteramos mientras el estado de alguno de los vértices sea falso
        while (shortestIndex != -1) {
            // Actualizamos su estado
            status[shortestIndex] = true;
            // Iteramos en todos los vecinos
            for (auto neighbor : adjacencyList[shortestIndex]) {
                // Buscamos el índice del vecino
                int neighborIndex = findVertex(neighbor.target);
                // Validamos que su estado no sea verdadero
                if (!status[neighborIndex]) {
                    // Comparamos si el costo del vecino es mayor al costo de shortestVertex + el peso del vecino
                    if (cost[neighborIndex] > cost[shortestIndex] + neighbor.weight) {
                        // Actualizamos el costo
                        cost[neighborIndex] = cost[shortestIndex] + neighbor.weight;
                        // Actualizamos el path
                        path[neighborIndex] = shortestIndex;
                    }
                }
            }
            // Encontramos el nuevo shortestIndex
            shortestIndex = findShortest(status, cost);
        }
        // Iniciamos la segunda parte del algoritmo
        // Creamos una lista de pilas vacías
        vector< stack<int> > shortestPaths(vertices.size());
        // Iteramos todos los vértices
        for (int i=0; i<vertices.size(); i++) {
            // Agregamos el índice del vértice a la pila
            shortestPaths[i].push(i);
            // le asignamos el valor del path del vértice actual a una variable
            int pathIndex = path[i];
            // Iteramos mientras el pathIndex sea diferente de -1
            while (pathIndex != -1) {
                // Agregamos el valor del pathIndex a la pila del vértice actual
                shortestPaths[i].push(pathIndex);
                // Actualizamos el pathIndex
                pathIndex = path[pathIndex];
            }
        }
        // Imprimos el resultado
        for (int i=0; i<vertices.size(); i++) {
            cout << vertices[i] << " - ";
            // Validamos que el costo no sea infinito
            if (cost[i] != INT_MAX) {
                // Iteramos mientras la pila no este vacía
                while (!shortestPaths[i].empty()) {
                    // Imprimimos el vértice de arriba de la pila
                    cout << vertices[shortestPaths[i].top()] << " ";
                    // Sacamos un elemento de la pila
                    shortestPaths[i].pop();
                }
                // Imprimimos el costo
                cout << "- " << cost[i];
            } else {
                // Imprimimos infinito
                cout << "no hay camino";
            }
            cout << endl;
        }
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

template <class T>
void Graph<T>::print() {
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (auto edge : adjacencyList[i]) {
            cout << edge.target << " " << edge.weight << " - ";
        }
        cout << endl;
    }
}




#endif /* Graph_h */