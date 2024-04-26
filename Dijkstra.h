#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"

struct Node {
    int distance;
    struct Node * previous;
};

class Dijkstra {
    private:
        Node* nodes;
        Node * considered;
        Node * not_considered;
    public: 
        Dijkstra();
  
};


#endif