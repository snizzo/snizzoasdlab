
#include "heap.hpp"
#include <iostream>

//constructor, void for now
Heap::Heap()
{
	this->root = NULL;
	this->size = 0;
}

void Heap::add(int * numbers)
{
	//
}

void Heap::add(int n)
{
	//
}

void Heap::heapify(HeapNode * node)
{
	HeapNode * largest = NULL;
	
	HeapNode * left = node->get_left();
	HeapNode * right = node->get_right();
	
	if ((left==NULL) && (right==NULL)){
		return; //it's a leaf
	}
	
	if ((left != NULL) && (left->data > node->data)){
		largest = left;
	} else {
		largest = node;
	}
	
	if ((right != NULL) && (right->data > largest->data)){
		largest = right;
	}
	
	if (largest != node){
		this->swap(largest, node);
		this->heapify(largest);
	}
}

void Heap::swap(HeapNode * n1, HeapNode * n2)
{
	int swap = n1->data;
	n1->data = n2->data;
	n2->data = swap;
}

void Heap::buildHeap()
{
	int n = this->size-1;
	
	for(int i=n/2;i>0;i--){
		//this->heapify(i
	} 
}

/*
def BuildHeap( A ): 
    n = HeapLength( A )
    for i in range( n/2 ,0 ,-1 ):
        Heapify( A, i, n )
 */
