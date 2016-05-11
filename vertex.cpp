#include <iostream>
#include <cstdio>
#include "vertex.h"

using namespace std;

/*
 * Empty constructor
 */
Vertex::Vertex(): outgoing_edges()
, ingoing_edges()
{
}

Vertex::~Vertex()
{
	this->outgoing_edges.release_memory();
	this->ingoing_edges.release_memory();
}

/**
 * Vertex connection representation
 */
void Vertex::addIngoing(Vertex * v)
{
	this->ingoing_edges.add(new Edge(v));
}

void Vertex::addOutgoing(Vertex * v)
{
	this->outgoing_edges.add(new Edge(v));
}

void Vertex::addOutgoing(Vertex * v, Edge::Color c, Edge::Style s)
{
	this->outgoing_edges.add(new Edge(v,s,c));
}

OrderedVector<Edge *> Vertex::getOutgoing()
{
	return outgoing_edges;
}

OrderedVector<Edge *> Vertex::getIngoing()
{
	return ingoing_edges;
}

/**
 * Constructor that sets name
 */
Vertex::Vertex(string name)
{
    setName(name);
}

string Vertex::getName() const
{
    return m_name;
}

void Vertex::setName(string name)
{
    m_name = name;
}

/**
 * For the purpose of this program, label can be assigned only once
 * to prevent root to be assigned
 */
void Vertex::setLabel(std::string s)
{
	if(this->label.length()==0){
		this->label = s;
	}
}

std::string Vertex::getLabel()
{
	return this->label;
}

/**
 * Other setter/getter
 */
void Vertex::setColor(Color color)
{
	m_color = color;
}

Vertex::Color Vertex::getColor() const
{
	return m_color;
}

void Vertex::setDistance(int d)
{
	this->distance = d;
}

int Vertex::getDistance()
{
	return this->distance;
}

void Vertex::setParent(Vertex * p)
{
	this->parent = p;
}

Vertex * Vertex::getParent()
{
	return this->parent;
}

/**
 * order relation
 */
bool Vertex::operator> (Vertex &y)
{
    if(m_name.compare(y.getName())>0){
        return true;
    } else {
        return false;
    }
}

/**
 * order relation
 */
bool Vertex::operator< (Vertex &y)
{
    if(m_name.compare(y.getName())<0){
        return true;
    } else {
        return false;
    }
}

/**
 * order relation
 */
bool Vertex::operator== (Vertex &y)
{
    if(m_name.compare(y.getName())==0){
        return true;
    } else {
        return false;
    }
}

/**
 * order relation
 */
bool Vertex::operator<= (Vertex &y)
{
    return !operator>(y);
}

/**
 * order relation
 */
bool Vertex::operator>= (Vertex &y)
{
    return !operator<(y);
}

/**
 * order relation
 */
bool Vertex::operator!= (Vertex &y)
{
    return !operator==(y);
}

std::ostream& operator<< (std::ostream &os, Vertex const &m)
{
    return os << "(Vertex:"<<m.getName()<< " " << m.getColor() <<")";
}

