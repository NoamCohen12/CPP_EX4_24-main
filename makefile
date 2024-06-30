.PHONY: all clean

# Compilation and linking flags
CC = g++ -g -Wall
SFML_INCLUDE = -I/path/to/sfml/include
SFML_LIBDIR = -L/path/to/sfml/lib
SFML_LIBS = $(SFML_LIBDIR) -lsfml-graphics -lsfml-window -lsfml-system

# Build targets
all: tree test

# Valgrind target
valgrind: tree
	valgrind ./tree --tool=memcheck -v --leak-check=full --show-leak-kinds=all --suppressions=qt.supp --error-exitcode=99

# Main executable
tree: tree.hpp Iterators.hpp Node.hpp main.cpp Complex.cpp Complex.hpp
	$(CC) $(SFML_INCLUDE) main.cpp Complex.cpp -o tree $(SFML_LIBS)

# Test executable
test: tree.hpp Iterators.hpp Node.hpp Test.cpp Complex.cpp Complex.hpp
	$(CC) $(SFML_INCLUDE) Test.cpp Complex.cpp -o test $(SFML_LIBS)

# Demo 
demo: tree.hpp Iterators.hpp Node.hpp Demo.cpp Complex.cpp Complex.hpp
	$(CC) $(SFML_INCLUDE) Demo.cpp Complex.cpp -o demo $(SFML_LIBS)

# Clean target
clean:
	rm -f tree test demo *.o
