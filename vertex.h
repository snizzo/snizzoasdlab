#ifndef VERTEX_H
#define VERTEX_H

#include <cstdlib>
#include <cstring>
#include "orderedvector.h"

class Vertex {
    private:
        std::string m_name;
        OrderedVector<Vertex *> outgoing_edges;
        OrderedVector<Vertex *> ingoing_edges;
    
    public:
        Vertex();
        Vertex(string name);
        
        void addIngoing(Vertex * v);
        void addOutgoing(Vertex * v);
        OrderedVector<Vertex *> getOutgoing();
        OrderedVector<Vertex *> getIngoing();
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
