#ifndef ORDEREDVECTOR_H
#define ORDEREDVECTOR_H

#include <cstdlib>
#include <cstring>
#include "vector.h"

template <class T> class OrderedVector : public Vector<T>{
	public:
        /*
         * Inheriting parent constructor
         */
		using Vector<T>::Vector;

        /*
         * Overridden method.
         * This adds element to the Vector assuring a greater order.
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

        /**
         * Perform a logarithmic search over all the vector.
         * Note that this will happen in worst: linear time O(log n)
         * 
         * @param T n object to look for
         * 
         * @return int i >= 0 if n has been found. i contains the position of n.
         */
		int find(T n)
        {
            int low = 0;
            int high = this->size-1; //array pos is size-1
            int mid = 0; //to be set immediately
            
            if(n<this->data[low] or n>this->data[high])
            {
                return -1;
            }
            
            int old = -1; //previous result
            
            while(true){
                mid = low+((high-low)/2);
                
                //prevents from infinite loop
                if(old==mid){
                    return -1;
                }
                
                if( this->data[mid] == n){
                    return mid;
                }
                if( this->data[mid] < n ){
                    low = mid;
                }
                if( this->data[mid] > n ){
                    high = mid;
                }
                old = mid;
            }
            
            return -1;
        }
};

#endif