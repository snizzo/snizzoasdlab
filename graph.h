#ifndef GRAPH_H
#define GRAPH_H

#include "queue.h"
#include "orderedvector.h"
#include "vertex.h"

using namespace std;

class Graph{
	private:
		OrderedVector<Vertex *> data;
    public:
        void addVertex(std::string name);
        void addEdge(std::string from, std::string to);
        
        void printGraph();
};

#endif
