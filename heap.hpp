#ifndef HEAP_HPP
#define HEAP_HPP

#include "vector.hpp"

/*
 * This is written to be a max-heap and not a generally a heap.
 */
class Heap
{
	private:
		Vector data;
		int size;
	public:
		Heap();
		void add(int input);
		int left(int n);
		int right(int n);
		bool exists_left(int n);
		bool exists_right(int n);
		void heapify(int i, int n);
		void build_heap();
		void sort();
		
		//debug
		void print_data();
};

#endif
