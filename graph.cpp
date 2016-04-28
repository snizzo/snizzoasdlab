#include "graph.h"
#include "utils.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

Graph::~Graph()
{
	for(int i=0;i<this->data.get_size();i++){
		delete this->data.at(i);
	}
	this->data.release_memory();
}

int Graph::getSizeNodes()
{
	return data.get_size();
}

bool Graph::addVertex(std::string name)
{
	Vertex search(name);
	//avoid duplicates
	if(data.find(&search)==-1){
		Vertex * v = new Vertex(name);
		this->data.add(v);
		return true;
	} else {
		return false;
	}
}

void Graph::addEdge(std::string from, std::string to)
{
	Vertex search_from(from);
	Vertex search_to(to);
	
	Vertex * vfrom = NULL;
	Vertex * vto = NULL;
	
	int at_from = data.find(&search_from);
	int at_to = data.find(&search_to);
	
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
	
	vfrom = data.at(data.find(&search_from));
	vto = data.at(data.find(&search_to));
	
	
	if(vfrom!=NULL && vto!=NULL){
		vfrom->addOutgoing(vto);
		vto->addIngoing(vfrom);
	} else {
		std::cout << "WARNING: can't find node" << endl;
	}
}

void Graph::addEdge(int from, int to)
{
	Vertex * vfrom = NULL;
	Vertex * vto = NULL;
	
	if(from >= 0){
		vfrom = data.at(from);
	}
	
	if(to >= 0){
		vto = data.at(to);
	}
	
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
	std::cout << "digraph " << this->getName() << " {" << endl;
	if(data.get_size()>0){
		for(int i=0;i<data.get_size();i++){
			std::cout << "    " << (*data.at(i)).getName() << ";" << endl;
			for(int j=0;j<(*data.at(i)).getOutgoing().get_size();j++){
				std::cout << "    " << (*data.at(i)).getName() << " -> " << (*(*data.at(i)).getOutgoing().at(j)).getName() << ";" << endl;
			}
			// uncomment for bidirectional print
			/*
			for(int j=0;j<(*data.at(i)).getIngoing().get_size();j++){
				std::cout << "    " << (*(*data.at(i)).getIngoing().at(j)).getName() << " -> " << (*data.at(i)).getName() << ";" << endl;
			}
			*/
		}
	}
	std::cout << "}" << endl;
}

/**
 * Generates a random graph with number of nodes = nodes
 * @param n number of nodes
 * @return random graph
 */
Graph * Graph::generateRandomGraph(int nodes)
{
	//new graph
	Graph * test = new Graph();
	//setting initial seed
	Utils::setSeed();
	
	//generating random nodes
	for (int i=0; i<nodes; i++) {
		double rand = Utils::random();
		std::ostringstream strs; strs << rand; std::string name = strs.str();
		if(!test->addVertex(name)){
			i--;
		}
	}
	
	//generating random edges
	for (int i=0; i < (pow(nodes, 2))/5; i++) {
		int n1 = (floor(Utils::random() * (nodes-1) + 0.5));
		int n2 = (floor(Utils::random() * (nodes-1) + 0.5));
		
		if (n1!=n2) {
			test->addEdge(n1,n2);
		} else {
			i-=1;
		}
	}
	
	return test;
}
