#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <list>
using namespace std;

template <class T>
class Queue {
	private:
		list <T> queue_data;
		
	public:
		bool enqueue(T data);
		T dequeue();
};

#endif
