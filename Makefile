CC=clang++
CFLAGS=-Wall -pedantic -std=c++11

main:
	$(CC) -g -o main main.cpp parser.cpp graph.cpp vertex.cpp edge.cpp token.cpp utils.cpp $(CFLAGS)

test:
	$(CC) -g -o test test.cpp parser.cpp graph.cpp vertex.cpp edge.cpp token.cpp utils.cpp $(CFLAGS)

clean:
	rm -f main
	rm -f test
