#include <iostream>
#include <cstdio>
#include "edge.h"

using namespace std;

/*
 * Constructor for oriented edge
 */
Edge::Edge(Vertex * to)
{
    setTo(to);
    this->m_style = Edge::Style::solid;
	this->m_color = Edge::Color::black;
}

Edge::Edge(Vertex * to, Edge::Style s, Edge::Color c)
{
    setTo(to);
    this->m_style = s;
	this->m_color = c;
}

/*
 * Dummy constructor (do not use)
 */
Edge::Edge()
{
	this->m_style = Edge::Style::solid;
	this->m_color = Edge::Color::black;
}

/*
 * Getters / setters
 */
void Edge::setTo(Vertex * to)
{
    m_to = to;
}

Vertex * Edge::getTo()
{
    return m_to;
}

void Edge::setColor(Edge::Color c)
{
	m_color = c;
}

Edge::Color Edge::getColor()
{
	return m_color;
}

void Edge::setStyle(Edge::Style s)
{
	m_style = s;
}

Edge::Style Edge::getStyle()
{
	return m_style;
}

/**
 * order relation
 */
bool Edge::operator> (Edge &y)
{
    if(m_to->getName().compare(y.getTo()->getName())>0){
        return true;
    } else {
        return false;
    }
}

/**
 * order relation
 */
bool Edge::operator< (Edge &y)
{
    if(m_to->getName().compare(y.getTo()->getName())<0){
        return true;
    } else {
        return false;
    }
}

/**
 * order relation
 */
bool Edge::operator== (Edge &y)
{
    if(m_to->getName().compare(y.getTo()->getName())==0){
        return true;
    } else {
        return false;
    }
}

/**
 * order relation
 */
bool Edge::operator<= (Edge &y)
{
    return !operator>(y);
}

/**
 * order relation
 */
bool Edge::operator>= (Edge &y)
{
    return !operator<(y);
}

/**
 * order relation
 */
bool Edge::operator!= (Edge &y)
{
    return !operator==(y);
}

std::ostream& operator<< (std::ostream &os, Edge const &m)
{
    return os << "(-> :"<< m.m_to->getName() << ")";
}
