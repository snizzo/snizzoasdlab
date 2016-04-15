#include <iostream>
using namespace std;

//template based class
#include "vector.h"
#include "orderedvector.h"

//normal headers
#include "graph.h"
#include "vertex.h"
#include "edge.h"

int main(int argc, char* argv[])
{
    Vertex * a = new Vertex("A");
    Vertex * b = new Vertex("B");
    Vertex * c = new Vertex("C");
    Vertex * d = new Vertex("D");
    Vertex * e = new Vertex("E");
    Vertex * f = new Vertex("F");
    Vertex * g = new Vertex("G");
    Vertex * h = new Vertex("H");
    Vertex * i = new Vertex("I");
    Vertex * l = new Vertex("L");
    Vertex * m = new Vertex("M");
    Vertex * o = new Vertex("O");
    Vertex * p = new Vertex("P");
    Vertex * q = new Vertex("Q");
    Vertex * r = new Vertex("R");
    Vertex * s = new Vertex("S");
    Vertex * t = new Vertex("T");
    Vertex * u = new Vertex("U");
    Vertex * v = new Vertex("V");
    Vertex * z = new Vertex("Z");
    
    OrderedVector<Vertex> ve;
    ve.add(*a);
    ve.add(*b);
    ve.add(*c);
    ve.add(*d);
    ve.add(*e);
    ve.add(*f);
    ve.add(*g);
    ve.add(*h);
    ve.add(*i);
    ve.add(*l);
    ve.add(*m);
    ve.add(*o);
    ve.add(*p);
    ve.add(*q);
    ve.add(*r);
    ve.add(*s);
    ve.add(*t);
    ve.add(*u);
    ve.add(*v);
    ve.add(*z);
    
    cout << ve.find(Vertex("N")) << endl;
    
    ve.print_data();
	return 0;
}
