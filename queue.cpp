
#include "stack.hpp"

template<class T> bool Stack<T>::enqueue(T data){
	
	this->queue_data->push_back(data);
	
	return true;
}

template<class T> T Stack<T>::dequeue(){
	return this->stack_data->pop_back();
}
