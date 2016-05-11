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
	
	/*
	Graph g;
	g.addEdge("C","E");
    g.addEdge("A","E");
    g.addEdge("A","F");
    g.addEdge("F","B");
    g.addVertex("G");
	
	g.printGraph();
	*/
	
	/*
    Vertex * a = new Vertex("A");
    Vertex * b = new Vertex("B");
    Vertex * c = new Vertex("C");
    Vertex * d = new Vertex("D");
    Vertex * e = new Vertex("E");
    Vertex * f = new Vertex("F");
    Vertex * h = new Vertex("H");
    Vertex * g = new Vertex("G");
    Vertex * i = new Vertex("I");
    Vertex * l = new Vertex("L");
    Vertex * m = new Vertex("M");
    
    OrderedVector<Vertex *> ve;
    ve.add(a);
    ve.add(b);
    ve.add(d);
    ve.add(e);
    ve.add(f);
    ve.add(h);
    ve.add(g);
    ve.add(i);
    ve.add(l);
    ve.add(m);
    ve.add(c);
    
    //ve.print_data();
    cout << ve.find(new Vertex("A")) << endl;
    cout << ve.find(new Vertex("B")) << endl;
    cout << ve.find(new Vertex("C")) << endl;
    cout << ve.find(new Vertex("D")) << endl;
    cout << ve.find(new Vertex("E")) << endl;
    cout << ve.find(new Vertex("F")) << endl;
    cout << ve.find(new Vertex("G")) << endl;
    cout << ve.find(new Vertex("H")) << endl;
    cout << ve.find(new Vertex("M")) << endl;
    cout << ve.find(new Vertex("Z")) << endl;
    */
    
	return 0;
}
