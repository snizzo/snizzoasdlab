#ifndef SET_HPP
#define SET_HPP

class Set{
	private:
		int * data;
		int cardinality;
		
	public:
		Set(int n); //MAKE
		Set(Set s1, Set s2); //UNION
		bool isHere(int n);
};

#endif
