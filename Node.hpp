
#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
using namespace std;
template<typename T> 
class Node {  // Assuming Node definition is part of Tree for demonstration
   public:
    T value;                     // Use the template parameter T for the value
    vector<Node*> children;      // Assuming a generic tree structure
    Node(T val) : value(val) {}  // Constructor
    T get_value() { return value; }
  
    
};
#endif