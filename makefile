.PHONY: all clean

CC = g++ -g -Wall
all: tree

tree:tree.hpp iterators.hpp Node.hpp main.cpp
	$(CC) main.cpp -o tree



clean:
	rm -f tree tree.o iterators.o node.o