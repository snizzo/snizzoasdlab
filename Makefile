all:
	clang++ -g -o main main.cpp parser.cpp graph.cpp vertex.cpp edge.cpp token.cpp -Wall -pedantic -std=c++11
