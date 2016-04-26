#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T> class Vector{
	protected:
        //internal parameters
		T * data;
		int size;
        int memsize;
        
        //class options
        bool allow_automatic_realloc;
        
	public:
        /*
         * Setting default starting value.
         */
		explicit Vector()
        {
            this->data = NULL;
            this->size = 0;
            this->memsize = 0;
            this->allow_automatic_realloc = true;
            this->data = (T *) realloc(this->data, sizeof(T)*this->memsize);
        }
        
        ~Vector()
        {
			free(this->data);
		}
        
        /**
         * Can enable or disable automatic memory realloc.
         * USE THIS WITH CAUTION, CAN LEAD TO SEGFAULT!!!
         * 
         * @param value true or false
         */
        void set_automatic_realloc(bool value)
        {
            this->allow_automatic_realloc = value;
        }
        
        /**
         * Performance fristd::endly vector resize.
         * This assures constant time when adding (memory part)
         * instead of linear.
         * 
         * Can be useful when input size is already known.
         * 
         * @param int amount of items of type T to be contained in Vector
         */
        void force_realloc(int amount)
        {
            if(amount < this->size){
                std::cout << "WARNING: can't resize Vector's memory less then its items required memory!";
                return;
            }
            
            //reallocation of internal data array
            this->data = (T *) realloc(this->data, sizeof(T)*amount);
            this->memsize = amount;
        }
        
        /**
         * This will assure there's always enough space for incoming objects.
         * When memory is almost filled, this will double the amount, making
         * it scale in power of 2 and allowing for faster insertion.
         */
        void automatic_realloc()
        {
            if(!this->allow_automatic_realloc){
                return;
            }
            
            if((this->memsize-this->size)<2){
                if(this->memsize==0){
                    this->memsize += 1;
                }
                this->force_realloc(this->memsize*2);
            }
            
            if (this->size < (this->memsize/2)-3){
                this->force_realloc(this->memsize/2);
            }
        }
        
        /**
         * By default, elements will be added at the end of the array.
         * 
         * @param n the element to be added.
         */
		void add(T n)
        {
            //adding 1 to size as 1 element has been added
            this->size += 1;
            
            this->automatic_realloc();
            
            //setting last element to new element
            this->data[this->size-1] = n;
        }

        /*
         * Overloaded function that add an element in desired position at pos
         * 
         */
		void add(T n, int pos)
        {
            int segment = this->size-pos;
            //incrementing internal pointer
            this->size += 1;
            this->automatic_realloc();
            //moving everything to make the new space fit
            memmove(&this->data[pos+1], &this->data[pos], segment*sizeof(T));
            //inserting new element into array
            this->data[pos] = n;
        }

        /*
         * This function removes the specified element in position pos
         */
		void remove(int pos)
        {
            if(this->size==0){
                std::cout << "Vector::remove("<<pos<<"): can't delete: vector is already empty" << std::endl;
                return;
            }
            
            int segment = this->size-pos;
            
            memmove(&this->data[pos], &this->data[pos+1], segment*sizeof(T));	
            
            this->size -= 1;
            
            this->automatic_realloc();
        }

        /**
         * Perform a linear search over all the vector.
         * Note that this will happen in worst: linear time O(n)
         * 
         * @return bool true if n is found; else false
         */
		bool has(T n)
        {
            for(int i=0;i<this->size;i++)
            {
                if (*this->data[i]==*n){
                    return true;
                }
            }
            
            return false;
        }

        /**
         * Perform a linear search over all the vector.
         * Note that this will happen in worst: linear time O(n)
         * 
         * @param T n object to look for
         * 
         * @return int i >= 0 if n has been found. i contains the position of n.
         */
		int find(T n)
        {
            for(int i=0;i<this->size;i++)
            {
                if (*this->data[i]==*n){
                    return i;
                }
            }
            
            return -1;
        }

        /*
         * Return the element contained at that position of the array.
         * Note that vector.at(3) will return this->data[3], the 4th element of the array.
         */
		T at(int pos)
        {
            if (pos <= this->size){
                return this->data[pos];
            } else {
                std::cout << "Impossible to access not set value at position " << pos << "in vector structure \n";
                return NULL;
            }
        }

        /**
         * Return total size of vector
         */
		int get_size()
        {
            return this->size;
        }

        /**
         * Swap 2 elements from given indexes
         */
		void swap(T i1, T i2)
        {
            T temp = this->data[i1];
            this->data[i1] = this->data[i2];
            this->data[i2] = temp;
        }
		
		/**
         * Utility function that prints all elements of vector in order.
         * 
         * WARNING: DO NOT USE WITH CUSTOM OBJECTS
         *          USE ONLY WITH BASIC TYPES (int, double, etc...)
         */
		void print_data()
        {
            
            std::cout << "data: ";
            
            for(int i=0;i<this->size;i++)
            {
                std::cout << "[";
                std::cout << *this->data[i];
                std::cout << "]";
                std::cout << " ";
            }
            
            std::cout << std::endl;
        }
};

#endif
