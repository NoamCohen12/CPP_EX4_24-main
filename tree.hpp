
#ifndef TREE_HPP
#define TREE_HPP
#include <vector>  // Include this at the top of your file
using namespace std;
#include "iterators.hpp"
template <typename T, int N = 2>  // Make Tree a template class
class Tree {
   private:
    Node<T>* root;  // Assuming Node is a template class that accepts a type T

   public:
    // Constructor
    Tree() : root(nullptr) {}

    // Destructor
    ~Tree() {
    }

    // Add root to the tree
    void add_root(Node<T>* root) {
        if (root == nullptr) {
            throw invalid_argument("Root cannot be null");
        }

        this->root = root;
    }

    // Add a sub-node to a parent node
    void add_sub_node(Node<T>* parent, Node<T>* chield) {
        if (root == nullptr) {
            throw invalid_argument("Root cannot be null");
        }

        if (parent == nullptr) {
            throw invalid_argument("Parent cannot be null");
        }

        parent->children.push_back(chield);
    }

    // Pre-Order traversal iterators
    PreOrderIterator<T> begin_pre_order() {
        return PreOrderIterator<T>(root);
    }
    PreOrderIterator<T> end_pre_order() {
        return PreOrderIterator<T>(nullptr);
    }

    // Post-Order traversal iterators
    PostOrderIterator<T> begin_post_order() {
        return PostOrderIterator<T>(root);
    }
    PostOrderIterator<T> end_post_order() {
        return PostOrderIterator<T>(nullptr);
    }

    // In-Order traversal iterators
    InOrderIterator<T> begin_in_order() {
        return InOrderIterator<T>(root);
    }
    InOrderIterator<T> end_in_order() {
        return InOrderIterator<T>(nullptr);
    }

    // BFS traversal iterators
    BfsIterator<T> begin_bfs_scan() {
        return BfsIterator<T>(root);
    }

    BfsIterator<T> end_bfs_scan() {
        return BfsIterator<T>(nullptr);
    }

    // DFS traversal iterators
    DFSIterator<T> begin_dfs_scan() {
        return DFSIterator<T>(root);
    }
    DFSIterator<T> end_dfs_scan() {
        return DFSIterator<T>(nullptr);
    }

    HeapIterator<T> begin_heap_scan() {
        return HeapIterator<T>(root);
    }
    HeapIterator<T> end_heap_scan() {
        return HeapIterator<T>(nullptr);
    }
};

#endif