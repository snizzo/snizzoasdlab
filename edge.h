#ifndef EDGE_H
#define EDGE_H

#include <cstdlib>
#include <cstring>
#include "graph.h"
#include "vertex.h"

using namespace std;

class Edge {
    private:
        Vertex * m_from;
        Vertex * m_to;
    
    public:
        Edge();
        Edge(Vertex * from, Vertex * to);
        
        void setFrom(Vertex * from);
        Vertex * getFrom();
        void setTo(Vertex * to);
        Vertex * getTo();
        
        string toString();
};

#endif
