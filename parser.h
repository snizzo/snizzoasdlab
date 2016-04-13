#ifndef PARSER_H
#define PARSER_H

#include <cstdlib>
#include <string>
#include "graph.h"

using namespace std;

class Parser {
    
    public:
        Graph * buildGraphFromFile(string filepath);
};

#endif
