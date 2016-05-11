#ifndef VERTEX_H
#define VERTEX_H

#include <cstdlib>
#include <cstring>
#include "orderedvector.h"
#include "edge.h"

class Edge;

class Vertex {
	public:
		enum Color { white, orange, gray };
	
    private:
        std::string m_name;
        std::string label;
        OrderedVector<Edge *> outgoing_edges;
        OrderedVector<Edge *> ingoing_edges;
        Color m_color = white;
        int distance = -1;
        Vertex * parent = NULL;
    
    public:
        Vertex();
        Vertex(string name);
        ~Vertex();
        
        void addIngoing(Vertex * v);
        void addOutgoing(Vertex * v);
        void addOutgoing(Vertex * v, Edge::Color c, Edge::Style s);
        OrderedVector<Edge *> getOutgoing();
        OrderedVector<Edge *> getIngoing();
        std::string getName() const;
        void setName(string name);
        void setColor(Color color);
		Color getColor() const;
		void setLabel(std::string s);
		std::string getLabel();
		void setDistance(int d);
		int getDistance();
		void setParent(Vertex * p);
		Vertex * getParent();
        
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
