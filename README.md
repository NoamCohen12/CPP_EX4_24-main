# CPP_EX3_24 - STL, Templates, and Iterators


## Author
- [Noam Cohen]
- Email: Noam12345002@gmail.com

## Overview
This project implements a generic tree data structure in C++ using SFML for visualization
with Iterators and Templates.


# Main Classes

- `tree` -  represents a k-ary tree data structure for organizing data hierarchically.

- `Iterators` - Provides a mechanism to traverse through the elements of a container (like tree) without exposing its 

internal structure.

- `Node` - Represents the individual elements within the tree, containing data and possibly links to other nodes.

- `Complex` - Manages complex numbers, supporting operations like addition, subtraction, and multiplication of complex 

values.


# Iterators
There are six tyoys of Iterators:
1.Preorder Iterator - The iterator scans the tree in the following way: current node -> left subtree -> right subtree (this iterator works this way for binary tree only! For general tree return a normal DFS scan starting from the root of the tree).


2.Post-Order Iterator - An iterator scans the tree in the following way: left subtree -> right subtree -> current node (this iterator works this way for binary tree only! For general tree return a normal DFS scan starting from the root of the tree).


3.In-order iterator - an iterator scans the tree in the following way: left subtree -> current node -> right subtree (this iterator works this way for a binary tree only! For a general tree return a normal DFS scan starting from the root of the tree).


4.BFS iterator - scanning the tree laterally (from left to right) (works on a general tree).


5.DFS iterator - scanning the tree using the DFS algorithm (works on a general tree).


6.Heap iterator - transforming a binary tree into a minimum heap


in all Iterators there are `operator++` , `operator==` ,`operator!=` , `operator->`.

in addition in tree there are two function for iterators:

<type_of_iterator> begin_<type_of_iterator>_order() { return <type_of_iterator>>(root);}

<type_of_iterator> end_<type_of_iterator>_order() { return <type_of_iterator>(nullptr); }

# Special properties of iterators

(1) Preorder , Post-Order , In-order , Heap iterators working good just on binary tree.

(2) DFS and BFS iterators working good on any tree

If we call to (1) on K>2 tree behind the scenes we call to DFS iterator.


# compiltion
for compiltion should write the command `make tree` 
and for compiltion of test `make test`


# GUI 

Type: SFML(Simple and Fast Multimedia Library).

The command for install On Ubuntu: - "sudo apt-get install libsfml-dev".

The GUI shows the tree structure in a simple way on the screen.


# Integrity checks

for testing I am check input on Double and Complex there is `Test.cpp` file


