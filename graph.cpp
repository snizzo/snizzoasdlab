#include "graph.h"
#include "utils.h"
#include "queue.h"
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

OrderedVector<Vertex *> * Graph::getNodes()
{
	return &this->data;
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
		//incrementing edges count
		this->original_edges += 1;
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

Vertex * Graph::getRoot()
{
	return this->root;
}

void Graph::setRoot(Vertex * v)
{
	this->root = v;
}

void Graph::setRootLabel()
{	
	std::ostringstream s;
	s << (total_edges - original_edges);
	const std::string difference(s.str());
	
	if(this->root!=NULL){
		this->root->setLabel("root = "+root->getName()+" ; |E'|-|E| = "+difference);
	}
}

void Graph::printGraph()
{
	//setting fixed label to root node 
	this->setRootLabel();
	
	std::cout << "digraph " << this->getName() << " {" << endl;
	if(data.get_size()>0){
		for(int i=0;i<data.get_size();i++){
			std::cout << "    " << (*data.at(i)).getName();
			if((*data.at(i)).getLabel().length()>0){
				std::cout << " [label=\"" << (*data.at(i)).getLabel() << "\"]";
			} else {
				std::cout << " [label=\"d(" << this->getRoot()->getName() << "," << (*data.at(i)).getName() << ")=" << (*data.at(i)).getDistance() << "\"]";
			}
			std::cout << /* " " << (*data.at(i)).getColor() << */";" << endl; //remove comment to print vertex color for dfs
			for(int j=0;j<(*data.at(i)).getOutgoing().get_size();j++){
				
				Edge * current = (*data.at(i)).getOutgoing().at(j);
				
				std::cout << "    " << (*data.at(i)).getName() << " -> " << current->getTo()->getName();
				
				if(current->getStyle()==Edge::Style::dashed && current->getColor()!=Edge::Color::red){
					std::cout << " [style=dashed]";
				}
				
				if(current->getStyle()==Edge::Style::dashed && current->getColor()==Edge::Color::red){
					std::cout << " [style=dashed,color=red]";
				}
				
				if(current->getStyle()==Edge::Style::solid && current->getColor()==Edge::Color::red){
					std::cout << " [color=red]";
				}
				std::cout << ";" << endl;
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

Vertex * Graph::getFirstWhite()
{
	for(int i=0;i<this->data.get_size();i++){
		Vertex * current = this->data.at(i);
		if(current->getColor()==Vertex::Color::white){
			return current;
		}
	}
	
	return NULL;
}

/**
 * When found, the orange node becomes gray
 * @return Vertex * if found, else NULL
 */
Vertex * Graph::getFirstOrangeAndRecolor()
{
	for(int i=0;i<this->data.get_size();i++){
		Vertex * current = this->data.at(i);
		if(current->getColor()==Vertex::Color::orange){
			current->setColor(Vertex::Color::gray);
			return current;
		}
	}
	
	return NULL;
}

void Graph::setAllColorsTo(Vertex::Color c)
{
	for(int i=0;i<this->data.get_size();i++){
		Vertex * current = this->data.at(i);
		current->setColor(Vertex::Color::white);
	}
}

void Graph::generateShortestPathTree(Graph * g)
{
	if(g->getSizeNodes()<1){
		return;
	}
	
	g->setAllColorsTo(Vertex::Color::white);
	Queue<Vertex *> * q = new Queue<Vertex *>();
	
	while(true){
		Vertex * start = g->getRoot();
		
		//checks
		if(start==NULL){ break; }
		
		start->setDistance(0);
		q->enqueue(start);
		
		while(!q->empty()){
			Vertex * t = q->dequeue();
			OrderedVector<Edge *> out = t->getOutgoing();
			for(int i=0;i<out.get_size();i++){
				Vertex * current_node = out.at(i)->getTo();
				if(current_node->getColor() == Vertex::Color::white){
					current_node->setDistance(t->getDistance() + 1);
					current_node->setParent(t);
					out.at(i)->setStyle(Edge::Style::dashed);
					current_node->setColor(Vertex::Color::gray);
					q->enqueue(current_node);
				} else {
					if(current_node != start){
						current_node->setColor(Vertex::Color::gray);
					}
				}
			}
		}
		break;
	}
}

/**
 * Static method for finding minimum number of edges
 * to be added needed to have a root node in the graph. 
 */
int Graph::minimumEdgesNeededToRoot(Graph * g)
{
	int edges = 0;
	//graph is empty
	if(g->getSizeNodes()<1){
		return 0;
	}
	
	Queue<Vertex *> * q = new Queue<Vertex *>();
	
	while(true){
		Vertex * start = g->getFirstWhite();
		
		//checks
		if(start==NULL){ break; }
		
		start->setColor(Vertex::Color::orange);
		
		q->enqueue(start);
		
		while(!q->empty()){
			Vertex * t = q->dequeue();
			OrderedVector<Edge *> out = t->getOutgoing();
			for(int i=0;i<out.get_size();i++){
				Vertex * current_node = out.at(i)->getTo();
				if(current_node->getColor() == Vertex::Color::white){
					current_node->setColor(Vertex::Color::gray);
					q->enqueue(current_node);
				} else {
					if(current_node != start){
						current_node->setColor(Vertex::Color::gray);
					}
				}
			}
		}
	}
	
	Vertex * root = g->getFirstOrangeAndRecolor();
	g->setRoot(root);
	
	//no more oranges on the graph
	if(root==NULL){
		return edges;
	}
	
	g->total_edges = g->original_edges;
	
	while(true){
		Vertex * found = g->getFirstOrangeAndRecolor();
		
		if(found==NULL){
			return edges;
		}
		edges += 1;
		root->addOutgoing(found, Edge::Color::red, Edge::Style::dashed);
		g->total_edges += 1;
	}
}
