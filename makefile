.PHONY: all clean

# Compilation and linking flags
CC = g++ -g -Wall
SFML_INCLUDE = -I/path/to/sfml/include
SFML_LIBDIR = -L/path/to/sfml/lib
SFML_LIBS = $(SFML_LIBDIR) -lsfml-graphics -lsfml-window -lsfml-system

# Valgrind flags
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# Build targets
all: tree test

# Valgrind target
valgrind: tree
	valgrind --tool=memcheck $(VALGRIND_FLAGS) tree 2>&1 | { egrep "lost| at " || true; }

# Main executable
tree: tree.hpp iterators.hpp Node.hpp main.cpp Complex.cpp Complex.hpp
	$(CC) $(SFML_INCLUDE) main.cpp -o tree $(SFML_LIBS)

# Test executable
test: tree.hpp iterators.hpp Node.hpp Test.cpp Complex.cpp Complex.hpp
	$(CC) $(SFML_INCLUDE) Test.cpp -o test $(SFML_LIBS)

# Clean target
clean:
	rm -f tree test *.o
