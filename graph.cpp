#include "graph.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void Graph::addVertex(std::string name)
{
	//avoid duplicates
	if(data.find(new Vertex(name))==-1){
		Vertex * v = new Vertex(name);
		this->data.add(v);
	}
}

void Graph::addEdge(std::string from, std::string to)
{
	Vertex * vfrom = NULL;
	Vertex * vto = NULL;
	
	int at_from = data.find(new Vertex(from));
	int at_to = data.find(new Vertex(to));
	
	if(at_from >= 0){
		vfrom = data.at(at_from);
	} else {
		vfrom = new Vertex(from);
		data.add(vfrom);
	}
	
	if(at_to >= 0){
		vto = data.at(at_to);
	} else {
		vto = new Vertex(to);
		data.add(vto);
	}
	
	vfrom = data.at(data.find(new Vertex(from)));
	vto = data.at(data.find(new Vertex(to)));
	
	
	if(vfrom!=NULL && vto!=NULL){
		vfrom->addOutgoing(vto);
		vto->addIngoing(vfrom);
	} else {
		std::cout << "WARNING: can't find node" << endl;
	}
}

std::string Graph::getName()
{
	return m_name;
}

void Graph::setName(std::string name)
{
	m_name = name;
}

void Graph::printGraph()
{
	std::cout << "Graph name: " << this->getName() << endl;
	if(data.get_size()>0){
		for(int i=0;i<data.get_size();i++){
			std::cout << "Node: " << *data.at(i) << endl;
			for(int j=0;j<(*data.at(i)).getOutgoing().get_size();j++){
				std::cout << "      " << " -> " << *(*data.at(i)).getOutgoing().at(j) << endl;
			}
			for(int j=0;j<(*data.at(i)).getIngoing().get_size();j++){
				std::cout << "      " << " <- " << *(*data.at(i)).getIngoing().at(j) << endl;
			}
		}
	} else {
		cout << "No nodes." << endl;
	}
}
