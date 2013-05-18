
#include "stack.hpp"

#include <cstdio>
#include <cstdlib>

Stack::Stack()
{
	this->size = 0;
	this->data = NULL;
}

int Stack::getSize()
{
	return this->size;
}

bool Stack::push(int n)
{
	this->size += 1;
	this->data = (int *) realloc(this->data, this->size*sizeof(int));
	this->data[this->size-1] = n;
	return true;
}

int Stack::pop()
{
	if (this->data==NULL) {
		return 0;
	} else {
		this->size -= 1;
		
		//allocating because we need to return it later
		int r = this->data[this->size];
		
		this->data = (int *) realloc(this->data, this->size*sizeof(int));
		
		return r;
	}
}
