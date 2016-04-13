#include <iostream>
using namespace std;

#include "stack.h"
#include "queue.h"
#include "set.h"
#include "vector.h"
#include "btree.h"
#include "heap.h"
#include "graph.h"
#include "vertex.h"
#include "edge.h"

int main(int argc, char* argv[])
{
    Graph g;
    
    Vertex * x = new Vertex("B");
    Vertex * y = new Vertex("A");
    
    Edge e(x, y);
    
    if(*x<=*y){
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    
    
    
	return 0;
}
