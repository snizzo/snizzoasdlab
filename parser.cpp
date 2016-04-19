
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
		
		cout << line << endl;
    }
    
    return NULL;
}
