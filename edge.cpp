#include <iostream>
#include <cstdio>
#include "edge.h"

using namespace std;

/*
 * Constructor for oriented edge
 */
Edge::Edge(Vertex * from, Vertex * to)
{
    setFrom(from);
    setTo(to);
}

/*
 * Dummy constructor (do not use)
 */
Edge::Edge()
{
}

/*
 * Getters / setters
 */
void Edge::setFrom(Vertex * from)
{
    m_from = from;
}

Vertex * Edge::getFrom()
{
    return m_from;
}

void Edge::setTo(Vertex * to)
{
    m_to = to;
}

Vertex * Edge::getTo()
{
    return m_to;
}

string Edge::toString()
{
    string out("");
    out += m_from->getName();
    out += " -> ";
    out += m_to->getName();
    out += "\n";
    return out;
}
