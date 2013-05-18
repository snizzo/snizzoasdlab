
#include "vector.hpp"
#include <iostream>
#include <cstdlib>

Vector::Vector()
{
	this->data = NULL;
	this->size = 0;
}

/*
 * By default, elements will be added at the end of the array.
 */
void Vector::add(int n)
{
	//adding 1 to size as 1 element has been added
	this->size += 1;
	
	//reallocation of internal data array
	this->data = (int *) realloc(this->data, sizeof(int)*this->size);
	
	//setting last element to new element
	this->data[this->size-1] = n;
}

void Vector::add(int n, int pos)
{
	//
}

void Vector::remove(int pos)
{
	//
}
bool Vector::find(int n)
{
	//
}

int Vector::at(int pos)
{
	//
}

void Vector::print_data()
{
	
	std::cout << "data: ";
	
	for (int &i: this->data)
	{
		std::cout << "[" << i << "]" << " ";
	}
	
	std::cout << std::endl;
}

