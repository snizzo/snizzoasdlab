
#include "heap.hpp"
#include <iostream>

//constructor, void for now
Heap::Heap()
{
	this->size = 0;
}

void Heap::add(int input)
{
	//incrementing size of heap
	this->size +=1;
	
	this->data.add(input);
}

int Heap::left(int n)
{
	return n*2;
}

int Heap::right(int n)
{
	return n*2+1;
}

bool Heap::exists_left(int n)
{
	if ((n*2) > this->size-1){
		std::cout << "left child not found, n="<<n<<", size="<<this->size-1<<"\n";
		return false;
	} else {
		return true;
	}
}

bool Heap::exists_right(int n)
{
	if ((n*2+1) > this->size-1){
		std::cout << "right child not found, n="<<n<<", size="<<this->size-1<<"\n";
		return false;
	} else {
		return true;
	}
}

void Heap::heapify(int i)
{
	int smallest = i;
	int l = this->left(i);
	int r = this->right(i);
	
	if (this->exists_left(i) && this->data.at(l) < this->data.at(i)){
		smallest = l;
	} else {
		smallest = i;
	}
	
	if (this->exists_right(i) && this->data.at(r) < this->data.at(smallest)){
		smallest = r;
	}
	
	if (smallest != i){
		this->data.swap(smallest,i);
		this->heapify(smallest);
	}
	this->print_data();
}

void Heap::build_heap()
{
	int to = this->size/2;
	for(int i=to; i>=0; i--){
		this->heapify(i);
	}
}

void Heap::sort()
{
	this->build_heap();
	
	for(int i = this->size-1;i>0;i--){
		this->data.swap(0,i);
		this->heapify(i);
	}
}

void Heap::print_data()
{
	this->data.print_data();
}
