#ifndef EDGE_H
#define EDGE_H

#include <cstdlib>
#include <cstring>

class Vertex;

class Edge {
	public:
		enum Style { solid, dashed };
		enum Color { black, red };
		
    private:
        Vertex * m_to;
        Style m_style;
        Color m_color;
    
    public:
        Edge();
        Edge(Vertex * to);
        Edge(Vertex * to, Edge::Style s, Edge::Color c);
        void setTo(Vertex * to);
        Vertex * getTo();
        
        //setter-getter
        void setColor(Color c);
        void setStyle(Style s);
        Color getColor();
        Style getStyle();
        
		//define an order relation between Edge objects
        bool operator> (Edge &y);
        bool operator< (Edge &y);
        bool operator== (Edge &y);
        bool operator<= (Edge &y);
        bool operator>= (Edge &y);
        bool operator!= (Edge &y);
        friend std::ostream& operator<< (std::ostream &os, Edge const &m);
};

#include "vertex.h"

#endif
