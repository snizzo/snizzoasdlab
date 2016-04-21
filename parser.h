#ifndef PARSER_H
#define PARSER_H

#include <cstdlib>
#include <string>
#include "graph.h"
#include "token.h"

using namespace std;

/**
 * Class parser is currently a one-timer. You have to create a new
 * Parser object for every graph you want to be parsed.
 */
class Parser {
	private:
		Vector<Token *> tokens;
		/*
		 * 0 = unknown
		 * 1 = outside graph definition
		 * 2 = declarations
		 */
		int parse_status = 0;
    public:
		void tokenize();
        Graph * buildGraphFromFile(string filepath);
        Graph * buildGraphFromStdin();
};

#endif
