
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

/*
 * Perform a linear search over all the vector.
 * Note that this will happen in worst: linear time O(n)
 */
bool Vector::find(int n)
{
	for(int i=0;i<this->size;i++)
	{
		if (this->data[i]==n){
			return true;
		} else {
			return false;
		}
	}
}

/*
 * Return the element contained at that position of the array.
 * Note that vector.at(3) will return this->data[3], the 4th element of the array.
 */
int Vector::at(int pos)
{
	if (pos <= this->size){
		return this->data[pos];
	} else {
		std::cout << "Impossible to access not set value at position " << pos << "in vector structure \n";
		return -1;
	}
}

void Vector::print_data()
{
	
	std::cout << "data: ";
	
	for(int i=0;i<this->size;i++)
	{
		std::cout << "[" << this->data[i] << "]" << " ";
	}
	
	std::cout << std::endl;
}

