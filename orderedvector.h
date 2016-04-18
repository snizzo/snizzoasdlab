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
            std::cout << std::endl << "adding..." << *n << std::endl;
            int spot = find_closest(n);
            Vector<T>::add(n, spot);
            Vector<T>::print_data();
            
        }

        /**
         * Perform a logarithmic search over all the vector
         * looking for the closest spot. Used by add method,
         * or for fine-grained manual insertions.
         * 
         * @param T n object to look for
         * 
         * @return int i >= 0 if n has been found; else -1. i contains the position of n.
         */
		int find_closest(T n)
        {
            int low = 0;
            int high = this->size-1; //array pos is size-1
            int mid = 0; //to be set immediately
            
            if(high<0){
                return 0;
            }
            
            if(*n<*this->data[low])
            {
                return 0;
            }
            
            if(*n>*this->data[high])
            {
                return high+1;
            }
            
            int old = -1; //previous result
            
            while(true){
                mid = low+((high-low)/2);
                
                //prevents from infinite loop
                if(old==mid){
                    return mid+1;
                }
                
                if( *this->data[mid] == *n){
                    return mid;
                }
                if( *this->data[mid] < *n ){
                    low = mid;
                }
                if( *this->data[mid] > *n ){
                    high = mid;
                }
                old = mid;
            }
            
            return -1;
        }
        
        /**
         * Perform a logarithmic search over all the vector.
         * Note that this will happen in worst: linear time O(log n)
         * 
         * @param T n object to look for
         * 
         * @return int i >= 0 if n has been found; else -1. i contains the position of n.
         */
		int find(T n)
        {
            int low = 0;
            int high = this->size-1; //array pos is size-1
            int mid = 0; //to be set immediately
            
            if(*n<*this->data[low] or *n>*this->data[high])
            {
                return -1;
            }
            
            int old = -1; //previous result
            
            while(true){
                mid = low+((high-low)/2);
                
                //prevents from infinite loop
                if(old==mid){
                    if(*this->data[mid+1] == *n){
                        return mid+1;
                    }
                    return -1;
                }
                
                if( *this->data[mid] == *n){
                    return mid;
                }
                if( *this->data[mid] < *n ){
                    low = mid;
                }
                if( *this->data[mid] > *n ){
                    high = mid;
                }
                old = mid;
            }
            
            return -1;
        }
};

#endif
