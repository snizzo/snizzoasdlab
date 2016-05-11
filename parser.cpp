
#include "parser.h"

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>

/**
 * Not yet implemented
 */
Graph * Parser::buildGraphFromFile(std::string filepath)
{
    return NULL;
}

/**
 * Return correctly parsed graph. Input text is scanned from stdin.
 * 
 * Use ./executable < inputfile.dot with this function
 */
Graph * Parser::buildGraphFromStdin()
{
	//generate tokens from .dot graphviz file
	this->tokenize();
	
	//initializing status
	this->parse_status = 1;
	
	Graph * result = new Graph();
	
	for(int i=0;i<this->tokens.get_size();i++){
		Token * current = this->tokens.at(i);
		if(this->parse_status==1){
			if(current->getContent()=="digraph"){
				Token * name = this->tokens.at(i+1);
				//check for emptiness first, then set name and open declaration section
				if(name!=NULL){
					result->setName(name->getContent());
					Token * opengraph = this->tokens.at(i+2);
					if(opengraph!=NULL && opengraph->getContent()=="{"){
						//change parser status to declarations
						this->parse_status = 2;
						//additions will be computed at the end just to avoid mess
						i += 2;
					}
				} else {
					std::cout << "ERROR: Invalid graph name. No name found after 'digraph'. Expecting graph name in string format!\n";
				}
			}
		}
		
		if(this->parse_status==2){
			if(current->getContent()==";"){
				Token * divider = this->tokens.at(i-2);
				//check for emptiness first, then set name and open declaration section
				if((divider!=NULL) && (divider->getContent()=="->")){
					//edge vertex-vertex connection
					Token * from = this->tokens.at(i-3);
					Token * to = this->tokens.at(i-1);
					result->addVertex(from->getContent());
					result->addVertex(to->getContent());
					result->addEdge(from->getContent(),to->getContent());
				} else if ((divider!=NULL) && (divider->getContent()==";")){
					Token * vertex = this->tokens.at(i-1);
					result->addVertex(vertex->getContent());
				}
			}
		}
	}
	
	this->release_memory();
	
    return result;
}

void Parser::release_memory()
{
	for(int i=0;i<this->tokens.get_size();i++){
		delete this->tokens.at(i);
	}
	this->tokens.release_memory();
}

/**
 * Generate tokens internally from stdin input
 */
void Parser::tokenize()
{
	std::string buffer;
	
	//receiving input
	for (std::string line; std::getline(std::cin, line);) {
		for(char& c : line) {
			if(c == ' ' or c == '>' or c == '\t'){
				if(!buffer.empty()){
					Token * t = new Token(buffer);
					this->tokens.add(t);
					buffer.erase();
				}
			} else
			if(c == '{'){
				if(!buffer.empty()){
					Token * t = new Token(buffer);
					this->tokens.add(t);
					buffer.erase();
				}
				Token * t2 = new Token("{");
				this->tokens.add(t2);
			} else
			if(c == ';'){
				if(!buffer.empty()){
					Token * t = new Token(buffer);
					this->tokens.add(t);
					buffer.erase();
				}
				Token * t2 = new Token(";");
				this->tokens.add(t2);
			} else
			if(c == '}'){
				if(!buffer.empty()){
					Token * t = new Token(buffer);
					this->tokens.add(t);
					buffer.erase();
				}
				Token * t2 = new Token("}");
				this->tokens.add(t2);
			} else
			if(c == '-'){
				if(!buffer.empty()){
					Token * t = new Token(buffer);
					this->tokens.add(t);
					buffer.erase();
				}
				Token * t2 = new Token("->");
				this->tokens.add(t2);
			} else {
				buffer += c;
			}
		}
		
    }
}
