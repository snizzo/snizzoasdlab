#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph{
	private:
		int connections [4][4];
		int d [4];
		int pi [4];
		Queue q [4];
		char color [4];
		int * adj(int n)
	
	public:
		void setData();
		void bfs(int n); //this one prints shit
};

#endif
