#ifndef GRAPH_H
#define GRAPH_H

#include <cstring>

#include "queue.h"
#include "orderedvector.h"
#include "vertex.h"
#include "edge.h"

using namespace std;

class Graph{
	private:
		Vertex * root = NULL;
		OrderedVector<Vertex *> data;
		std::string m_name;
    public:
		int original_edges = 0;
		int total_edges = 0;
		//constructor/destructor
		~Graph();
		//internal structure modifiers 
        bool addVertex(std::string name);
        void addEdge(std::string from, std::string to);
        void addEdge(int from, int to);
        Vertex * getRoot();
		void setRoot(Vertex * v);
		void setRootLabel();
        
        //setters getters
        std::string getName();
        void setName(std::string name);
        int getSizeNodes();
        OrderedVector<Vertex *> * getNodes();
        Vertex * getFirstWhite();
        Vertex * getFirstOrangeAndRecolor();
        void setAllColorsTo(Vertex::Color c);
        
        //debugging
        void printGraph();
        
        //static methods
        static Graph * generateRandomGraph(int nodes);
        static int minimumEdgesNeededToRoot(Graph * g);
        static void generateShortestPathTree(Graph * g);
};

#endif
