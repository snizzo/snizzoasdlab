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
        
        bool operator> (Vertex &y);
        bool operator< (Vertex &y);
        bool operator== (Vertex &y);
        bool operator<= (Vertex &y);
};

#endif
