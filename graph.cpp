#include "graph.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void Graph::addVertex(std::string name)
{
	Vertex * v = new Vertex(name);
	this->data.add(v);
}

void Graph::addEdge(std::string from, std::string to)
{
	Vertex * vfrom = data.at(data.find(new Vertex(from)));
	Vertex * vto = data.at(data.find(new Vertex(to)));
	
	if(vfrom!=NULL && vto!=NULL){
		vfrom->addOutgoing(vto);
		vto->addIngoing(vfrom);
	} else {
		std::cout << "WARNING: can't find node" << endl;
	}
}

void Graph::printGraph()
{
	cout << *(*data.at(0)).getOutgoing().at(0) << endl;
	
	for(int i=0;i<data.get_size();i++){
		std::cout << "Node: " << *data.at(i) << endl;
		for(int j=0;j<(*data.at(i)).getOutgoing().get_size();j++){
			std::cout << "      " << " -> " << *(*data.at(i)).getOutgoing().at(j) << endl;
		}
		for(int j=0;j<(*data.at(i)).getIngoing().get_size();j++){
			std::cout << "      " << " <- " << *(*data.at(i)).getIngoing().at(j) << endl;
		}
	}
}
