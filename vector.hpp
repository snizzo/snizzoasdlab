#ifndef VECTOR_HPP
#define VECTOR_HPP

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
		
		//utility
		void print_data();
		
};

#endif
