#ifndef QUEUE_H
#define QUEUE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T> class Queue {
	private:
		int size;
		T * data;
		
	public:
		Queue()
		{
			this->size = 0;
			this->data = NULL;
		}

		/**
         * Manully releases memory. Call before destruction
         * instead of normal destructor. Apparently destructor
         * is called during output print for no reason.
         */
        void release_memory()
        {
			free(this->data);
		}

		T at(int pos)
		{
			return this->data[pos];
		}
		
		bool empty()
		{
			if (this->getSize() < 1){
				return true;
			} else { 
				return false;
			}
		}

		int getSize()
		{
			return this->size;
		}

		bool enqueue(T n)
		{
			this->size += 1;
			this->data = (T *) realloc(this->data, this->size*sizeof(T));
			this->data[this->size-1] = n;
			return true;
		}

		T dequeue()
		{
			if (this->data==NULL) {
				return 0;
			} else {
				this->size -= 1;
				
				//allocating because we need to return it later
				T r = this->data[0];
				
				//reallocation in order to make all the queue shift
				memmove(&this->data[0], &this->data[1], this->size*sizeof(T));
				
				this->data = (T *) realloc(this->data, this->size*sizeof(T));
				
				return r;
			}
		}
	
};

#endif
