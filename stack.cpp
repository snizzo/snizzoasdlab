
#include "stack.hpp"

template<class T> bool Stack<T>::push(T data){
	this->stack_data->push_back(data);
	
	return true;
}

template<class T> T Stack<T>::pop(){
	return this->stack_data->pop_back();
}
