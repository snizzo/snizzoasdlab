#include <iostream>
using namespace std;

#include "vector.h"
#include "graph.h"
#include "vertex.h"
#include "edge.h"
#include "orderedvector.h"

int main(int argc, char* argv[])
{
    Graph g;
    
    Vertex * x = new Vertex("B");
    Vertex * y = new Vertex("A");
    Vertex * z = new Vertex("A");
    
    Vector<Vertex> v;
    v.add(*x);v.add(*y);v.add(*y);v.add(*y);v.add(*y);v.add(*y);v.add(*y);v.add(*y);v.add(*y);
    v.remove(0);v.remove(0);v.remove(0);v.remove(0);v.remove(0);v.remove(0);v.remove(0);v.remove(0);v.remove(0);v.remove(0);v.remove(0);
    v.add(*x);v.add(*y);v.add(*y);v.add(*y);v.add(*y);v.add(*y);v.add(*y);v.add(*y);v.add(*y);
	return 0;
}
