#include "Graph.h"

Graph::Graph() {
    this->vertexes = nullptr;
    this->edges = nullptr;
    this->edge_counter = 0;
    this->adjacencyMatrix = nullptr;
    this->NUM_NODES = 0;

}

Graph::Graph(int numV, int numE) {
    this->vertexes = new Vertex[numV];
    this->edges = new Edge[numE];
    this->edge_counter = 0;
    this->NUM_NODES = numV;


    this->adjacencyMatrix = new int * [numV];
    this->adjacencyList = new int * [numV];    
    this->dijkstraPaths = new int [numV];
    this->consideredNodes = new int [numV];
    
    for (int i = 0; i < numV; i++) {

        this->adjacencyMatrix[i] = new int [numV];
        this->adjacencyList[i] = new int [numV];
        this->dijkstraPaths[i] = 1000;
    
        for (int j = 0; j < NUM_NODES; j++) {
            this->adjacencyMatrix[i][j] = 0;
        }

        for (int j = 0; j < NUM_NODES - 1; j++) {
            this->adjacencyList[i][j] = 0;
        }
    }


}

void Graph::addVertex (Vertex *v) {
    this->vertexes[v->getIndex() - 1] = *v;
}

void Graph::addEdge(Edge* i) {
    this->edge_counter = this->edge_counter + 1;
    this->edges[edge_counter - 1] = *i;
}

bool Graph::hasVertex(Vertex * v) {
    // return (this->vertexes[v->getIndex()].getIndex() == v->getIndex());
    if (this->vertexes[v->getIndex() - 1].getIndex() == v->getIndex()) {
        return true;
    } else {
        return false;
    }
}

bool Graph::hasEdge(int numOfEdges) {
    return this->edge_counter == numOfEdges;
}

Vertex* Graph::getVertex(Vertex * v) {
    // if (this->vertexes[v->getindex] != ) {

    // }
    return &this->vertexes[v->getIndex() - 1];
}

Vertex* Graph::getVertexByIndex(int index) {
    return &this->vertexes[index - 1];
}

Vertex* Graph::getAllVertices() {
    return this->vertexes;
}

void Graph::addAdjacentVertexes(Vertex *v1, Vertex * v2) {
    int v1Index = v1->getIndex() - 1;
    int v2Index = v2->getIndex() - 1;
    
    // add adjacent vertexes v1, v2 to their respective place in the adjacency matrix
    this->adjacencyMatrix[v1Index][v2Index] = 1;
    this->adjacencyMatrix[v2Index][v1Index] = 1;

    // add v2 as one of v1's adjacent nodes
    int i = 0;
    while (this->adjacencyList[v1Index][i] > 0) {
        i++;
    }
    this->adjacencyList[v1Index][i] = v2Index + 1;
    
    // add v1 as one of v2's adjacent nodes
    i = 0;
    while (adjacencyList[v2Index][i] > 0) {
        i++;
    }
    this->adjacencyList[v2Index][i] = v1Index + 1;
}

void Graph::printAdjacencyMatrix() {
    for (int i = 0; i < this->NUM_NODES; i++) {
        for (int j = 0; j < this->NUM_NODES; j++) {
            std::cout << this->adjacencyMatrix[i][j] << " ";

        }
        std::cout << std::endl;
    }
}

void Graph::printAdjacencyList() {
    for (int i = 0; i < this->NUM_NODES; i++) {
            std::cout << "\n" << i + 1 << ": "; 
        int j = 0;
        while (this->adjacencyList[i][j] > 0) {
            std::cout << this->adjacencyList[i][j] << " ";
            j++;
        }
    }
}

void Graph::printOddDegreeVertices() {
    std::cout << "O = {";

    for (int i = 0; i < this->NUM_NODES; i++) {
        if ((this->vertexes[i].getDegree() % 2) != 0) {
            std::cout << " " << this->vertexes[i].getIndex();

        }
    }

    std::cout << " }" << std::endl;
}

void Graph::calculateDijkstras(Vertex *v, Vertex* startingVertex) {
    int index = v->getIndex() - 1;

        dijkstraPaths[v->getIndex() - 1] = 0;
    // if (v->getIndex() == startingVertex->getIndex()) {
    //     consideredNodes[index] = v->getIndex();
    // } 
    
    int j = 0;
    while (j < NUM_NODES - 1) {
        if (this->adjacencyList[index][j] > 0) {
            dijkstraPaths[this->adjacencyList[index][j]] = dijkstraPaths[index] + 1;
            // calculateDijkstras(this->getVertexByIndex(this->adjacencyList[index][j]), startingVertex);
        }
        j++;
    }

    // for (int i = 0; i < NUM_NODES - 1; i++) {
    //     if (this->adjacencyList[index][j] > 0) {
    //     }
    // }




    // }
    


        // if (this->adjacencyList[index][i] == 0) break;
        // if (this->adjacencyList[index][i] == startingVertex->getIndex() - 1) break;
        // if (this->adjacencyList[index][i] > 0) {
        //     this->dijkstraPaths[this->adjacencyList[index][i]] += 1;
        //     std::cout << "This runs" << std::endl;
        //     calculateDijkstras(this->getVertexByIndex(this->adjacencyList[index][i]), startingVertex);
        // }       
}

void Graph::printDijkstras() {
    for (int i = 0; i < NUM_NODES; i++) {
        std::cout << i + 1 << ": " << dijkstraPaths[i] << std::endl;
    }
}

