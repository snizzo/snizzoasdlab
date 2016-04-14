#ifndef VERTEX_H
#define VERTEX_H

#include <cstdlib>
#include <cstring>
#include "graph.h"

using namespace std;

class Vertex {
    private:
        std::string m_name;
    
    public:
        Vertex();
        Vertex(string name);
        
        std::string getName();
        void setName(string name);
        
        //define an order relation between vertex objects
        bool operator> (Vertex &y);
        bool operator< (Vertex &y);
        bool operator== (Vertex &y);
        bool operator<= (Vertex &y);
        bool operator>= (Vertex &y);
        bool operator!= (Vertex &y);
};

#endif
