#include <iostream>
#include <cstdio>
#include "vertex.h"

using namespace std;

/*
 * Empty constructor
 */
Vertex::Vertex()
{
}

/**
 * Vertex connection representation
 */
void Vertex::addIngoing(Vertex * v)
{
	this->ingoing_edges.add(v);
}

void Vertex::addOutgoing(Vertex * v)
{
	this->outgoing_edges.add(v);
}

OrderedVector<Vertex *> Vertex::getOutgoing()
{
	return outgoing_edges;
}

OrderedVector<Vertex *> Vertex::getIngoing()
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
 * Other setter/getter
 */
void Vertex::setColor(Color color)
{
	m_color = color;
}

Vertex::Color Vertex::getColor()
{
	return m_color;
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
    return os << "(Vertex:"<<m.getName()<<")";
}

