#ifndef GRAPH_H
#define GRAPH_H

#include <cstring>

#include "queue.h"
#include "orderedvector.h"
#include "vertex.h"

using namespace std;

class Graph{
	private:
		OrderedVector<Vertex *> data;
		std::string m_name;
    public:
		//internal structure modifiers 
        void addVertex(std::string name);
        void addEdge(std::string from, std::string to);
        
        //setters getters
        std::string getName();
        void setName(std::string name);
        
        //debugging
        void printGraph();
};

#endif
