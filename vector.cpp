
#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

/*
 * Setting default starting value.
 */
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

/*
 * Overloaded function that add an element in desired position at pos
 * 
 */
void Vector::add(int n, int pos)
{
	int segment = this->size-pos;
	//incrementing internal pointer
	this->size += 1;
	//reallocating in order to fit
	this->data = (int *) realloc(this->data, this->size*sizeof(int));
	//moving everything to make the new space fit
	memmove(&this->data[pos+1], &this->data[pos], segment*sizeof(int));
	//inserting new element into array
	this->data[pos] = n;
}

/*
 * This function removes the specified element in position pos
 */
void Vector::remove(int pos)
{
	int segment = this->size-pos;
	
	memmove(&this->data[pos], &this->data[pos+1], segment*sizeof(int));	
	
	this->size -= 1;
	
	this->data = (int *) realloc(this->data, this->size*sizeof(int));
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
	
	return false;
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

/*
 * Return total size of vector
 */
int Vector::get_size()
{
	return this->size-1;
}

/*
 * Swap 2 elements from given indexes
 */
void Vector::swap(int i1, int i2)
{
	int temp = this->data[i1];
	this->data[i1] = this->data[i2];
	this->data[i2] = temp;
}

/*
 * Utility function that prints all elements of vector in order.
 */
void Vector::print_data()
{
	
	std::cout << "data: ";
	
	for(int i=0;i<this->size;i++)
	{
		std::cout << "[" << this->data[i] << "]" << " ";
	}
	
	std::cout << std::endl;
}

