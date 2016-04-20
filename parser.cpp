
#include "parser.h"

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>

Graph * Parser::buildGraphFromFile(std::string filepath)
{
    return NULL;
}

Graph * Parser::buildGraphFromStdin()
{
	Graph * result = new Graph();
	
	//receiving input
	for (std::string line; std::getline(std::cin, line);) {
		line.erase (std::remove (line.begin(), line.end(), ' '), line.end());
		line.erase (std::remove (line.begin(), line.end(), ';'), line.end());
		
		std::size_t pos = line.find("->");
		
		if(pos!=std::string::npos){
			std::string n1 = line.substr(0,pos);
			std::string n2 = line.substr(pos+2);
			
			result->addVertex(n1);
			result->addVertex(n2);
			result->addEdge(n1,n2);
		} else {
			if(line.find("{")==std::string::npos && line.find("}")==std::string::npos){
				result->addVertex(line);
			}
		}
    }
    
    return result;
}
