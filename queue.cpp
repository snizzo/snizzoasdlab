
#include "queue.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

Queue::Queue()
{
	this->size = 0;
	this->data = NULL;
}

int Queue::at(int pos)
{
	return this->data[pos];
}

bool Queue::empty()
{
	if (this->getSize() < 1){
		return true;
	} else { 
		return false;
	}
}

int Queue::getSize()
{
	return this->size;
}

bool Queue::enqueue(int n)
{
	this->size += 1;
	this->data = (int *) realloc(this->data, this->size*sizeof(int));
	this->data[this->size-1] = n;
	return true;
}

int Queue::dequeue()
{
	if (this->data==NULL) {
		return 0;
	} else {
		this->size -= 1;
		
		//allocating because we need to return it later
		int r = this->data[0];
		
		//reallocation in order to make all the queue shift
		memmove(&this->data[0], &this->data[1], this->size*sizeof(int));
		
		this->data = (int *) realloc(this->data, this->size*sizeof(int));
		
		return r;
	}
}
