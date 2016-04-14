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

/*
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

/*
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

/*
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

/*
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

/*
 * order relation
 */
bool Vertex::operator<= (Vertex &y)
{
    return !operator>(y);
}

/*
 * order relation
 */
bool Vertex::operator>= (Vertex &y)
{
    return !operator<(y);
}

/*
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

