#ifndef STACK_HPP
#define STACK_HPP

class Stack {
	private:
		int size;
		int * data;
		
	public:
		Stack();
		int getSize();
		bool push(int n);
		int pop();
};

#endif
