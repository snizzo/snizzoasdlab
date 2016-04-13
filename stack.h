#ifndef STACK_H
#define STACK_H

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
