#include <iostream>
using namespace std;

//template based class
#include "vector.h"
#include "orderedvector.h"

//normal headers
#include "graph.h"

int main(int argc, char* argv[])
{
	Graph g;
	g.addVertex("A");
	g.addVertex("E");
	g.addVertex("C");
	g.addVertex("G");
	g.addVertex("B");
	g.addVertex("F");
	g.addVertex("D");
	g.addEdge("A", "D");
	
	g.printGraph();
	
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
    */
    
	return 0;
}
