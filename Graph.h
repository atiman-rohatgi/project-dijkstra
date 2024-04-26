#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"
#include "iostream"


struct Node {
    int distance;
    struct Node * previous;
};

class Graph {
    private:
        Edge * edges;
        Vertex * vertexes;
        int edge_counter;
        int NUM_NODES;
        int ** adjacencyMatrix;
        int ** adjacencyList;
        int * dijkstraPaths;
        int * consideredNodes;

    public:
        Graph();
        Graph(int numV, int numE);
        void addVertex(Vertex *v);
        void addEdge(Edge *e);
        bool hasVertex(Vertex *v);
        bool hasEdge(int numOfEdges);
        Vertex* getVertex(Vertex *v);
        Vertex * getVertexByIndex(int index);
        Vertex* getAllVertices();
        void printAdjacencyMatrix();
        void addAdjacentVertexes(Vertex *v1, Vertex* v2);
        void printOddDegreeVertices();
        void printAdjacencyList();
        void calculateDijkstras(Vertex *v, Vertex* startingVertex);
        void printDijkstras();

};

#endif
