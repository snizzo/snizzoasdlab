#include <iostream>
using namespace std;

#include "vector.h"
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
    
    Vector<int> v;
    v.add(1);v.add(3);v.add(4);v.add(7);v.add(8);v.remove(3);
    v.print_data();
    
	return 0;
}
