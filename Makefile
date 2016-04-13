all:
	clang++ -g -o main main.cpp stack.cpp queue.cpp set.cpp vector.cpp heap.cpp btree.cpp parser.cpp graph.cpp vertex.cpp edge.cpp -Wall -pedantic -std=c++11
