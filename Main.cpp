#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"
#include <iostream>

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return NULL;
    }

    Graph* g = new Graph(numOfVertices, numOfEdges);
    
    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        std::cin >> startVertice;
        std::cin >> endVertice;
        Edge* newEdge = new Edge(startVertice, endVertice);
        // Here is where you load up the Graph object
        
        if (g->hasEdge(numOfEdges)) break;

        g->addEdge(newEdge);

        Vertex* v1 = new Vertex();
        v1->setIndex(startVertice);
        
        if (!g->hasVertex(v1)) {
            v1->setDegree(1);
            g->addVertex(v1);
        } else {
            // std::cout << "has vertex is working!" << std::endl;
            g->getVertex(v1)->setDegree(g->getVertex(v1)->getDegree() + 1);
        }

        Vertex * v2 = new Vertex();
        v2->setIndex(endVertice);

        if (!g->hasVertex(v2)) {
            v2->setDegree(1);
            g->addVertex(v2);
        } else {
            g->getVertex(v2)->setDegree(g->getVertex(v2)->getDegree() + 1);
        }

        g->addAdjacentVertexes(v1, v2);

        delete v1;
        delete v2;
    }

    // And here is where you start working on the three tasks
    std::cout << "The adjacency matrix of G:" << std::endl;
    g->printAdjacencyList();

    std::cout << std::endl;

    std::cout << "The odd degree vertices in G:" << std::endl;
    g->printOddDegreeVertices();

    std::cout << std::endl;
    
    Vertex * vertices = g->getAllVertices();

    for (int i = 0; i < numOfVertices; i++) {
        if ((vertices[i].getDegree() % 2) != 0) {
            std::cout << "Single source shortest path lengths from node " << i + 1 << std::endl;
            g->calculateDijkstras(&vertices[i], &vertices[i]);
            std::cout << "ran" << std::endl;
            g->printDijkstras();
        }
    }

    return 0;
}