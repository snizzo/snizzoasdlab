#include "graph.hpp"

void Graph::setData()
{
	this->connections[0][0] = 0;
	this->connections[0][1] = 1;
	this->connections[0][2] = 0;
	this->connections[0][3] = 0;
	this->connections[1][1] = 1;
	this->connections[1][2] = 1;
	this->connections[1][3] = 1;
	this->connections[2][2] = 0;
	this->connections[2][3] = 1;
	this->connections[3][3] = 0;
}

int * Graph::adj(int n)
{
	
}

void Graph::bfs(int n)
{
	for(int i=0; i<4; i++){
		if (i != n){
			color[i] = 'w';
			d[i] = 4;
		}
	}
	
	color[n] = 'g';
	d[n] = 0;
	pi[n] = n;
	this->q->enqueue(n);
	
	while(!q->empty()){
		int u = this->q->at(0);
	}
	
}
