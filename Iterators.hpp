#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <unordered_set>
#include <vector>

#include "Node.hpp"
using namespace std;

template <typename T>  // Make Tree a template class
class PreOrderIterator {
   private:
    Node<T>* current;
    std::stack<Node<T>*> stack;

   public:
    PreOrderIterator(Node<T>* root) {
        stack.push(nullptr);
        if (root != nullptr) {
            stack.push(root);
        }
    }

    Node<T>* operator*() {
        return current;
    }
    Node<T>* operator->() {
        return stack.top();
    }

    PreOrderIterator& operator++() {
        if (stack.empty()) {
            current = nullptr;
            return *this;
        }
        current = stack.top();
        stack.pop();
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it != nullptr) {
                stack.push(*it);
            }
        }
        return *this;
    }
    bool operator!=(const PreOrderIterator& other) {
        return !(stack.top() == other.stack.top());
    }
    bool operator==(const PreOrderIterator& other) {
        return stack.top() == other.stack.top();
    }
    Node<T>* operator[](int n) {
        PreOrderIterator temp(*this);  // Make a copy to not alter the original iterator
        while (n > 0 && !temp.stack.empty()) {
            --n;
            ++temp;  // Use the already defined prefix increment to advance
        }
        if (temp.current != nullptr) {
            return temp.current;
        } else {
            throw std::out_of_range("Index out of range for pre-order traversal");
        }
    }
};
template <typename T>
class PostOrderIterator {
   public:
    PostOrderIterator(Node<T>* root) : current(nullptr) {
        if (root != nullptr) {
            stack.push(root);
            advance();  // Initialize current with the first node to process
        }
    }
    

    Node<T>* operator*() const {
        return current;
    }

    PostOrderIterator& operator++() {
        advance();
        return *this;
    }

    bool operator!=(const PostOrderIterator& other) const {
        return !(current == other.current);
    }
    bool operator==(const PostOrderIterator& other) const {
        return current == other.current;
    }

    Node<T>* operator->() const {
        return current;
    }

   private:
    std::stack<Node<T>*> stack;
    std::unordered_set<Node<T>*> visited;
    Node<T>* current;

    void advance() {
        while (!stack.empty()) {
            Node<T>* node = stack.top();
            // If the node has children that have not been visited, push them onto the stack
            bool has_unvisited_children = false;
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                if (*it != nullptr && visited.find(*it) == visited.end()) {
                    stack.push(*it);
                    has_unvisited_children = true;
                }
            }
            // If all children have been visited, visit this node
            if (!has_unvisited_children) {
                current = node;
                stack.pop();
                visited.insert(current);
                return;
            }
        }
        // If the stack is empty, we are done
        current = nullptr;
    }
};

template <typename T>
class InOrderIterator {
   private:
    Node<T>* current;
    std::stack<Node<T>*> stack;
    void push_left(Node<T>* node) {
        while (node != nullptr) {
            stack.push(node);
            if (node->children.size() > 0)
                node = node->children[0];
            else
                node = nullptr;
        }
    }

   public:
    InOrderIterator(Node<T>* root) : current(nullptr) {
        push_left(root);
        ++(*this);  // Initialize the iterator to the first element
    }

    Node<T>* operator*() {
        return current;
    }

    InOrderIterator& operator++() {
        if (stack.empty()) {
            current = nullptr;
            return *this;
        }
        current = stack.top();
        stack.pop();
        if (current->children.size() > 1) {
            push_left(current->children[1]);
        }
        return *this;
    }

    bool operator!=(const InOrderIterator& other) const {
        return !(current == other.current);
    }
    bool operator==(const InOrderIterator& other) const {
        return current == other.current;
    }

    Node<T>* operator[](int n) {
        InOrderIterator temp(*this);  // Make a copy to not alter the original iterator
        while (n > 0 && !temp.stack.empty()) {
            --n;
            ++temp;  // Use the already defined prefix increment to advance
        }
        if (temp.current != nullptr) {
            return temp.current;
        } else {
            throw std::out_of_range("Index out of range for in-order traversal");
        }
    }

    Node<T>* operator->() const {
        return current;
    }
};

template <typename T>
class BfsIterator {
   private:
    Node<T>* current;
    std::queue<Node<T>*> queue;

   public:
    BfsIterator(Node<T>* root) : current(nullptr) {
        if (root != nullptr) {
            queue.push(root);
            ++(*this);  // Initialize the iterator to the first element
        }
    }

    BfsIterator& operator++() {
        if (queue.empty()) {
            current = nullptr;
            return *this;
        }
        current = queue.front();
        queue.pop();
        for (auto child : current->children) {
            if (child != nullptr) {
                queue.push(child);
            }
        }
        return *this;
    }
    Node<T>* operator*() {
        return current;
    }
    Node<T>* operator->() {
        return current;
    }
    bool operator!=(const BfsIterator& other) {
        return !(current == other.current);
    }
    bool operator==(const BfsIterator& other) {
        return current == other.current;
    }
};

template <typename T>
class DFSIterator {
   private:
    Node<T>* current;
    std::stack<Node<T>*> stack;

   public:
    DFSIterator(Node<T>* root) : current(nullptr) {
         
        if (root != nullptr) {
            stack.push(root);
            ++(*this);  // Initialize the iterator to the first element
        }
    }

    DFSIterator& operator++() {
        if (stack.empty()) {
            current = nullptr;
            return *this;
        }
        current = stack.top();
        stack.pop();
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it != nullptr) {
                stack.push(*it);
            }
        }
        return *this;
    }

    Node<T>* operator*() {
        return current;
    }

    Node<T>* operator->() {
        return current;
    }

    bool operator==(const DFSIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const DFSIterator& other) const {
        return !(*this == other);
    }
};

template <typename T>
class HeapIterator {
   private:
    Node<T>* current;
    std::vector<Node<T>*> heap;
    void fill_heap(Node<T>* root) {
        if (root == nullptr) {
            return;
        }
        heap.push_back(root);
        for (auto child : root->children) {
            fill_heap(child);
        }
    }

   public:
    HeapIterator(Node<T>* root) : current(nullptr) {
        if (root == nullptr) {
            return;
        }
        fill_heap(root);
        std::make_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { return a->get_value() > b->get_value(); });
        if (!heap.empty()) {
            current = heap.front();
        }
    }

    HeapIterator& operator++() {
        if (!heap.empty()) {
            std::pop_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { return a->get_value() > b->get_value(); });
            heap.pop_back();
            if (!heap.empty()) {
                current = heap.front();
            } else {
                current = nullptr;
            }
        } else {
            current = nullptr;
        }
        return *this;
    }

    Node<T>* operator->() {
        return current;
    }
    bool operator!=(const HeapIterator& other) {
        return !(current == other.current);
    }
    bool operator==(const HeapIterator& other) {
        return current == other.current;
    }
};

#endif  // ITERATORS_HPP
