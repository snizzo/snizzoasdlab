
#include "heap.hpp"
#include <iostream>

//constructor, void for now
Heap::Heap()
{
	this->size = 0;
}

void Heap::add(int input)
{
	this->data.add(input);
}

int Heap::left(int n)
{
	return n*2;
}

int Heap::right(int n)
{
	return n*2;
}

bool Heap::exists_left(int n)
{
	if ((n*2) > this->size-1){
		return false;
	} else {
		return true;
	}
}

bool Heap::exists_right(int n)
{
	if ((n*2+1) > this->size-1){
		return false;
	} else {
		return true;
	}
}

void Heap::heapify(int i)
{
	int largest = i;
	int l = this->left(i);
	int r = this->right(i);
	
	if (this->exists_left(l) && this->data.at(l) > this->data.at(i)){
		largest = l;
	} else {
		largest = i;
	}
	
	if (this->exists_right(r) && this->data.at(r) > this->data.at(largest)){
		largest = r;
	}
	
	if (largest != i){
		this->data.swap(largest,i);
		this->heapify(largest);
	}
}

void Heap::build_heap()
{
	for(int i=this->size/2; i>0; i--){
		this->heapify(i);
	}
}

void Heap::sort()
{
	this->build_heap();
	
	for(int i = this->size-1;i>0;i--){
		this->data.swap(0,i);
		this->heapify(0);
	}
}
