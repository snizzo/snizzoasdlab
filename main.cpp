#include <iostream>
using namespace std;

#include "stack.hpp"

int main()
{
	
	Stack <int> s;
	
	s.push(6);
	s.push(5);
	s.push(11);
	s.push(18);
	
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	
	
	
	return 0;
}
