#ifndef HEAP_HPP
#define HEAP_HPP

#include "HeapNode.hpp"

/*
 * This is written to be a max-heap and not a generally a heap.
 */
class Heap
{
	private:
		HeapNode * root;
		int size;
	public:
		Heap();
		void add(int * numbers);
		void add(int n);
		void heapify(HeapNode * node);
		void swap(HeapNode * n1, HeapNode * n2);
		
};

#endif
