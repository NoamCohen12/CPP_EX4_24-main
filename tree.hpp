#ifndef TREE_HPP
#define TREE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>  // for std::cerr
#include <sstream>   // Include this at the top of your file
#include <stdexcept>
#include <vector>

#include "Complex.hpp"
#include "Iterators.hpp"
#include "Node.hpp"

template <typename T, int N = 2>//default value of N is >= 2
class Tree {
   private:
    Node<T>* root;
    sf::Font font;

    void drawNode(sf::RenderWindow& window, Node<T>* node, sf::Vector2f position, float xOffset, float yOffset, int depth = 0) {
        if (node == nullptr) return;

        // Dynamic circle size based on xOffset, ensuring it's visually proportional
        float circleRadius = std::max(30.0f, xOffset / 5);
        sf::CircleShape circle(circleRadius);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(position - sf::Vector2f(circleRadius, circleRadius));  // Center the circle on the position
        window.draw(circle);

        // Adjust text size based on circle size
        sf::Text text;
        text.setFont(font);
        std::ostringstream oss;
        oss << node->get_value();  // This works for any type that supports the << operator
        text.setString(oss.str());
        text.setCharacterSize(15);  // Scale text size with circle size
        text.setFillColor(sf::Color::Blue);

        // Center text within the circle
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(position);
        window.draw(text);

        // Dynamically adjust child node positioning and line drawing based on depth
        float childXOffset = std::max(static_cast<float>(xOffset / std::pow(2, depth)), 50.0f);  // Ensure minimum spacing

        float childYOffset = yOffset + depth * 20;  // Increase yOffset with depth to spread nodes vertically

        for (size_t i = 0; i < node->children.size(); ++i) {
            sf::Vector2f childPosition(position.x + (i - (node->children.size() - 1) / 2.0f) * childXOffset, position.y + childYOffset);

            // Draw lines with increased thickness
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(position.x, position.y), sf::Color::White),
                sf::Vertex(sf::Vector2f(childPosition.x, childPosition.y), sf::Color::White)};
            line[0].color = sf::Color::Red;
            line[1].color = sf::Color::Red;
            window.draw(line, 2, sf::Lines);

            drawNode(window, node->children[i], childPosition, childXOffset * 0.8, childYOffset, depth + 1);  // Pass depth to recursively adjust spacing
        }
    }

   public:
    Tree() : root(nullptr) {
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSerif.ttf")) {
            std::cerr << "Error loading font 'arial.ttf'\n";
        }
    }
    ~Tree() {
     
           BfsIterator<T> it = begin();
        BfsIterator<T> prev = it;
        BfsIterator<T> end = end_bfs_scan();
        while (it != end) {
            prev = it;
            ++it;
            prev->remove_children();
        }
        root = nullptr;
    }
    
    

     BfsIterator<T> begin() {  // Default iterator
        return begin_bfs_scan();
    }

    BfsIterator<T> end() {  // Default iterator
        return end_bfs_scan();
    }
   

    void add_root(Node<T>* root) {
        if (root == nullptr) {
            throw std::invalid_argument("Root cannot be null");
        }
        this->root = root;
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (root == nullptr) {
            throw std::invalid_argument("Root cannot be null");
        }
        if (parent == nullptr) {
            throw std::invalid_argument("Parent cannot be null");
        }
        parent->children.push_back(child);
    }

Node<double>* get_root() {
    return root;
}
    void draw() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            drawNode(window, root, sf::Vector2f(400, 50), 200, 100);
            window.display();
        }
    }

    // Pre-Order traversal iterators
    DFSIterator<T> begin_pre_order() { return DFSIterator<T>(root); }
    DFSIterator<T> end_pre_order() { return DFSIterator<T>(nullptr); }

    // Post-Order traversal iterators
    DFSIterator<T> begin_post_order() { return DFSIterator<T>(root); }
    DFSIterator<T> end_post_order() { return DFSIterator<T>(nullptr); }

    // In-Order traversal iterators
    DFSIterator<T> begin_in_order() { return DFSIterator<T>(root); }
    DFSIterator<T> end_in_order() { return DFSIterator<T>(nullptr); }

    // BFS traversal iterators
    BfsIterator<T> begin_bfs_scan() { return BfsIterator<T>(root); }
    BfsIterator<T> end_bfs_scan() { return BfsIterator<T>(nullptr); }

    // DFS traversal iterators
    DFSIterator<T> begin_dfs_scan() { return DFSIterator<T>(root); }
    DFSIterator<T> end_dfs_scan() { return DFSIterator<T>(nullptr); }

    // // Heap traversal iterators
    // HeapIterator<T> begin_heap_scan() { return HeapIterator<T>(root); }
    // HeapIterator<T> end_heap_scan() { return HeapIterator<T>(nullptr); }
};

// Specialization for binary tree (N = 2)
template <typename T>
class Tree<T, 2> {
   private:
    Node<T>* root;
    sf::Font font;

    void drawNode(sf::RenderWindow& window, Node<T>* node, sf::Vector2f position, float xOffset, float yOffset) {
        if (node == nullptr) return;
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(position);
        window.draw(circle);

        sf::Text text;
        text.setFont(font);
        std::ostringstream oss;
        oss << node->get_value();  // This works for any type that supports the << operator
        text.setString(oss.str());
        // text.setString(std::to_string(node->get_value()));
        text.setCharacterSize(15);  // the point on y
        text.setFillColor(sf::Color::White);
        text.setPosition(position.x + 20, position.y + 5);  // the point on X
        window.draw(text);

        float childXOffset = xOffset / 2.0f;
        float childYOffset = yOffset;

        for (size_t i = 0; i < node->children.size(); ++i) {
            sf::Vector2f childPosition(position.x + (i == 0 ? -childXOffset : childXOffset), position.y + childYOffset);

            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(position.x + 20, position.y + 20)),
                sf::Vertex(sf::Vector2f(childPosition.x + 20, childPosition.y + 20))};
            window.draw(line, 2, sf::Lines);

            drawNode(window, node->children[i], childPosition, childXOffset, childYOffset);
        }
    }

   public:
    Tree() : root(nullptr) {
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSerif.ttf")) {
            std::cerr << "Error loading font 'arial.ttf'\n";
        }
    }
    ~Tree() {}
        BfsIterator<T> begin() {  // Default iterator
        return begin_bfs_scan();
    }

    BfsIterator<T> end() {  // Default iterator
        return end_bfs_scan();
    }

    void add_root(Node<T>* root) {
        if (root == nullptr) {
            throw std::invalid_argument("Root cannot be null");
        }
        this->root = root;
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (root == nullptr) {
            throw std::invalid_argument("Root cannot be null");
        }
        if (parent == nullptr) {
            throw std::invalid_argument("Parent cannot be null");
        }
        if (parent->children.size() >= 2) {
            throw std::invalid_argument("Binary tree node cannot have more than two children");
        }
        parent->children.push_back(child);
    }
Node<double>* get_root() {
    return root;
}
    void draw() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Binary Tree Visualization");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            drawNode(window, root, sf::Vector2f(400, 100), 200, 100);  // location of nodes
            window.display();
        }
    }

    // Pre-Order traversal iterators
    PreOrderIterator<T> begin_pre_order() { return PreOrderIterator<T>(root); }
    PreOrderIterator<T> end_pre_order() { return PreOrderIterator<T>(nullptr); }

    // Post-Order traversal iterators
    PostOrderIterator<T> begin_post_order() { return PostOrderIterator<T>(root); }
    PostOrderIterator<T> end_post_order() { return PostOrderIterator<T>(nullptr); }

    // In-Order traversal iterators
    InOrderIterator<T> begin_in_order() { return InOrderIterator<T>(root); }
    InOrderIterator<T> end_in_order() { return InOrderIterator<T>(nullptr); }

    // BFS traversal iterators
    BfsIterator<T> begin_bfs_scan() { return BfsIterator<T>(root); }
    BfsIterator<T> end_bfs_scan() { return BfsIterator<T>(nullptr); }

    // DFS traversal iterators
    DFSIterator<T> begin_dfs_scan() { return DFSIterator<T>(root); }
    DFSIterator<T> end_dfs_scan() { return DFSIterator<T>(nullptr); }

    // Heap traversal iterators
    HeapIterator<T> begin_heap_scan() { return HeapIterator<T>(root); }
    HeapIterator<T> end_heap_scan() { return HeapIterator<T>(nullptr); }
};

#endif
