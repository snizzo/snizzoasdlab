#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
using namespace std;

template <class T>
class Stack {
	private:
		vector <T> stack_data;
		
	public:
		bool push(T data);
		T pop();
};

#endif
