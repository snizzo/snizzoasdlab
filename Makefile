all:
	clang++ -g -o main main.cpp parser.cpp graph.cpp vertex.cpp edge.cpp token.cpp utils.cpp -Wall -pedantic -std=c++11

test:
	clang++ -g -o test test.cpp parser.cpp graph.cpp vertex.cpp edge.cpp token.cpp utils.cpp -Wall -pedantic -std=c++11
