#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template<typename T> 
class Node {  
public:
    T value;                     
    std::vector<Node*> children; 
    float x, y;  // Position for visualization

    Node(T val) : value(val) {}

    T get_value() const { return value; }

     void remove_children() {
        children.clear();
    }

 bool operator==(const Node& other) const {
    return value == other.value;
}

    
};

#endif
