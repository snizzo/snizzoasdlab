#include <iostream>
#include <string>

//template based class
#include "vector.h"
#include "orderedvector.h"

//normal headers
#include "graph.h"
#include "parser.h"

int main(int argc, char* argv[])
{
	Parser p;
	Graph * g = p.buildGraphFromStdin();
	
	//also add red dashed edges for nodes added to make graph
	//have a root node
	Graph::minimumEdgesNeededToRoot(g);
	Graph::generateShortestPathTree(g);
	
	g->printGraph();
	
	delete g;
    
	return 0;
}
