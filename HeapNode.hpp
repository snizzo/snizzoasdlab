#ifndef HEAPNODE_HPP
#define HEAPNODE_HPP

class HeapNode
{
	private:
		int data;
		HeapNode * right;
		HeapNode * left;
		HeapNode * parent;
	public:
		HeapNode();
		void set_data(int n);
		int get_data();
		HeapNode * get_left();
		HeapNode * get_right();
		void set_left(HeapNode * n);
		void set_right(HeapNode * n);
};

#endif
