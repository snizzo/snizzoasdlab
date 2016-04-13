#ifndef VECTOR_H
#define VECTOR_H

class Vector{
	private:
		int * data;
		int size;
		
	public:
		Vector();
		void add(int n);
		void add(int n, int pos);
		void remove(int pos);
		bool find(int n);
		int at(int pos);
		int get_size();
		void swap(int i1, int i2);
		
		//utility
		void print_data();
		
};

#endif
