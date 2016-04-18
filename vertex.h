#ifndef VERTEX_H
#define VERTEX_H

#include <cstdlib>
#include <cstring>
#include "graph.h"
#include "orderedvector.h"

using namespace std;

class Vertex {
    private:
        std::string m_name;
        OrderedVector<Vertex *> outgoing_edges;
        OrderedVector<Vertex *> ingoing_edges;
    
    public:
        Vertex();
        Vertex(string name);
        
        std::string getName() const;
        void setName(string name);
        
        //define an order relation between vertex objects
        bool operator> (Vertex &y);
        bool operator< (Vertex &y);
        bool operator== (Vertex &y);
        bool operator<= (Vertex &y);
        bool operator>= (Vertex &y);
        bool operator!= (Vertex &y);
        friend std::ostream& operator<< (std::ostream &os, Vertex const &m);
};

#endif
