#include <iostream>
using namespace std;

#include "stack.hpp"
#include "queue.hpp"
#include "set.hpp"
#include "vector.hpp"

int main()
{
	Vector v;
	
	v.add(43);
	v.add(53);
	v.add(12);
	v.add(34);
	v.add(94);
	v.add(16);
	
	v.print_data();
	
	v.add(12, 0);
	
	v.print_data();
	
	return 0;
}
