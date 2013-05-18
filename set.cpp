
#include "set.hpp"
#include <cstdlib>

Set::Set(int n) //MAKE
{
	this->data = (int *) malloc(sizeof(int));
	this->data[0] = n;
}

Set::Set(Set s1, Set s2) //UNION
{
	//
}

bool Set::isHere(int n) //part of FIND
{
	//
}

