#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "GraphM.h"
#include "Graph.h"


// Declaramos las funciones
template <class T>
void createData();

template <class T>
void menu(Graph<T> graph, GraphM<T> graphM);

int main() {
    // Inicio de la Act 3.1, 3.2 y 3.3
    // Tipo de dato a utilizar
    int dataType;
    cout << "Que tipo de dato desea utilizar?" << endl;
    cout << "1. Int" << endl;
    cout << "2. String" << endl;
    cout << "3. Float" << endl << endl;
    cin >> dataType;
    // cout << endl;

    if (dataType == 1){
        createData<int>();
    } else if (dataType == 2){
        createData<string>();
    } else if (dataType == 3){
        createData<float>();
    } else {
        throw out_of_range("Opcion invalida");
    }

    return 0;
}

template <class T>
void createData() {
    // Inicializamos edges y vertices
    vector<T> vertices;
    vector< Edge<T> > edges;
    // Pedimos al usuario la cantidad de vertices y edges(arcos)
    int numVertex = 0;
    int numEdges = 0;
    cout << "Ingresa la cantidad de vértices: ";
    cin >> numVertex;
    //cout << endl;
    cout << "Ingresa la cantidad de arcos: ";
    cin >> numEdges;
    //cout << endl;

    // Inicializamos las variables
    T vertex;
    T vertexSource;
    T vertexTarget;
    // Pedimos al usuario los vertices y edges(arcos)
    for(int i = 0; i < numVertex; i++) {
        cout << "Ingresa el vértice " << i + 1 << ": ";
        cin >> vertex;
        vertices.push_back(vertex);
    }
    for(int j = 0; j < numEdges; j++) {
        cout << "Ingresa el vértice Source: ";
        cin >> vertexSource;
        //cout << endl;
        cout << "Ingresa el vértice Target: ";
        cin >> vertexTarget;
        //cout << endl;
        edges.emplace_back(vertexSource, vertexTarget);
    }
    // Inicializamos los grafos.
    Graph<T> graph(vertices, edges);
    GraphM<T> graphM(vertices, edges);

    menu(graph, graphM);
}

template <class T>
void menu(Graph<T> graph, GraphM<T> graphM){
    // Iniciamos el index en 0 para luego hacer el while
    int index = -7;
    cout << "Ingresa la opcion a realizar: " << endl;
    cout << "1. Agregar vértice " << endl;
    cout << "2. Agregar arco " << endl;
    cout << "3. Eliminar vértice " << endl;
    cout << "4. Eliminar arco " << endl;
    cout << "5. Imprimir " << endl;
    cout << "6. BFS " << endl;
    cout << "7. DFS " << endl;
    cout << "8. Dijkstra " << endl;
    cout << "9. Salir " << endl;
    while (index != 0){
        cout << "Ingresa la opcion a realizar: " << endl;
        cin >> index;
        if (index == 1) {
            // Agregar vértice
            T vertex;
            cout << "Ingrese el vértice a añadir: ";
            cin >> vertex;
            graph.addVertex(vertex); // Agregamos el vértice al grafo representado por lista
            graphM.addVertex(vertex); // Agregamos el vértice al grafo representado por matriz
        } else if (index == 2) {
            // Agregar arco
            T vertexSource;
            T vertexTarget;
            cout << "Ingrese el vértice Source: ";
            cin >> vertexSource;
            cout << "Ingrese el vértice Target: ";
            cin >> vertexTarget;
            graph.addEdge(Edge<T>(vertexSource, vertexTarget)); // Agregamos el arco al grafo representado por lista
            graphM.addEdge(Edge<T>(vertexSource, vertexTarget)); // Agregamos el arco al grafo representado por matriz
        } else if (index == 3) {
            // Eliminar vertice
            T vertex;
            cout << "Ingresa el vértice a eliminar: ";
            cin >> vertex;
            graph.removeVertex(vertex);
            graphM.removeVertex(vertex);
        } else if (index == 4) {
            // Eliminar arco
            T vertexSource;
            T vertexTarget;
            cout << "Ingrese el vértice Source: ";
            cin >> vertexSource;
            cout << "Ingrese el vértice Target: ";
            cin >> vertexTarget;
            graph.removeEdge(Edge<T>(vertexSource, vertexTarget));
            graphM.removeEdge(Edge<T>(vertexSource, vertexTarget));
        } else if (index == 5) { 
            // Imprimir los grafos
            cout << "Lista de adyacencias:\n";
            graph.print();
            cout << "\nMatriz de adyacencias:\n";
            graphM.print();
        } else if (index == 6) {
            // BFS
            T vertex;
            cout << "Ingresa el vértice inicial: ";
            cin >> vertex;
            graph.bfs(vertex);
        } else if (index == 7) {
            // DFS
            T vertex;
            cout << "Ingresa el vértice inicial: ";
            cin >> vertex;
            graph.dfs(vertex);
            cout << endl;
        } else if (index == 8) {
            // Dijkstra
            T vertex;
            cout << "Ingresa el vértice inicial: ";
            cin >> vertex;
            graph.dijkstra(vertex);
        } else if (index == 9) {
            // Salir
            cout << "Adios!" << endl;
            index = 0;
        } else if (index < 1 || index > 9) {
            // Opcion invalida
            cout << "No existe esta opcion" << endl;
        }
    }
}
