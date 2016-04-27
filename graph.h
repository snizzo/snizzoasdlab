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
		//constructor/destructor
		~Graph();
		//internal structure modifiers 
        bool addVertex(std::string name);
        void addEdge(std::string from, std::string to);
        void addEdge(int from, int to);
        
        //setters getters
        std::string getName();
        void setName(std::string name);
        int getSizeNodes();
        
        //debugging
        void printGraph();
        
        //static methods
        static Graph * generateRandomGraph(int nodes);
};

#endif
