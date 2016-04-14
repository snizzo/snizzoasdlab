#ifndef QUEUE_H
#define QUEUE_H


class Queue {
	private:
		int size;
		int * data;
		
	public:
		Queue();
		int at(int pos);
		bool empty();
		int getSize();
		bool enqueue(int n);
		int dequeue();
};

#endif