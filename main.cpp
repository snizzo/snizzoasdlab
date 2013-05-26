#include <iostream>
using namespace std;

#include "stack.hpp"
#include "queue.hpp"
#include "set.hpp"
#include "vector.hpp"
#include "btree.hpp"
#include "heap.hpp"

int main()
{
	Heap h;
	
	h.add(80);
	h.add(40);
	h.add(30);
	h.add(60);
	h.add(81);
	h.add(90);
	h.add(100);
	h.add(10);
	
	
	h.build_heap();
	
	return 0;
}
