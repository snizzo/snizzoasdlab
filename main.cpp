#include <iostream>
using namespace std;

#include "stack.hpp"
#include "queue.hpp"
#include "set.hpp"
#include "vector.hpp"

int main()
{
	Vector v;
	
	v.add(1);
	v.add(2);
	v.add(3);
	v.add(4);
	v.add(5);
	v.add(6);
	
	v.print_data();
	
	return 0;
}
