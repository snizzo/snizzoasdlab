#ifndef VECTOR_H
#define VECTOR_H

#include <cstring>

template <class T> class Vector{
	private:
		int * data;
		int size;
		
	public:
        /*
         * Setting default starting value.
         */
		Vector()
        {
            this->data = NULL;
            this->size = 0;
        }

        /*
         * By default, elements will be added at the end of the array.
         */
		void add(T n)
        {
            //adding 1 to size as 1 element has been added
            this->size += 1;
            
            //reallocation of Ternal data array
            this->data = (T *) realloc(this->data, sizeof(T)*this->size);
            
            //setting last element to new element
            this->data[this->size-1] = n;
        }

        /*
         * Overloaded function that add an element in desired position at pos
         * 
         */
		void add(T n, T pos)
        {
            T segment = this->size-pos;
            //incrementing Ternal poTer
            this->size += 1;
            //reallocating in order to fit
            this->data = (T *) realloc(this->data, this->size*sizeof(T));
            //moving everything to make the new space fit
            memmove(&this->data[pos+1], &this->data[pos], segment*sizeof(T));
            //inserting new element To array
            this->data[pos] = n;
        }

        /*
         * This function removes the specified element in position pos
         */
		void remove(T pos)
        {
            T segment = this->size-pos;
            
            memmove(&this->data[pos], &this->data[pos+1], segment*sizeof(T));	
            
            this->size -= 1;
            
            this->data = (T *) realloc(this->data, this->size*sizeof(T));
        }

        /*
         * Perform a linear search over all the vector.
         * Note that this will happen in worst: linear time O(n)
         */
		bool find(T n)
        {
            for(int i=0;i<this->size;i++)
            {
                if (this->data[i]==n){
                    return true;
                } else {
                    return false;
                }
            }
            
            return false;
        }

        /*
         * Return the element contained at that position of the array.
         * Note that vector.at(3) will return this->data[3], the 4th element of the array.
         */
		T at(T pos)
        {
            if (pos <= this->size){
                return this->data[pos];
            } else {
                std::cout << "Impossible to access not set value at position " << pos << "in vector structure \n";
                return -1;
            }
        }

        /*
         * Return total size of vector
         */
		T get_size()
        {
            return this->size-1;
        }

        /*
         * Swap 2 elements from given indexes
         */
		void swap(T i1, T i2)
        {
            T temp = this->data[i1];
            this->data[i1] = this->data[i2];
            this->data[i2] = temp;
        }
		
		/*
         * Utility function that prints all elements of vector in order.
         */
		void print_data()
        {
            
            std::cout << "data: ";
            
            for(int i=0;i<this->size;i++)
            {
                std::cout << "[" << this->data[i] << "]" << " ";
            }
            
            std::cout << std::endl;
        }
};

#endif
