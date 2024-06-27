#include <iostream>

#include "Node.hpp"
#include "iterators.hpp"
#include "tree.hpp"
using namespace std;
int main() {
    
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;  // Binary tree that contains doubles.
    tree.add_root(&root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    cout << "Pre order scan:\n";
    //   auto node = tree.begin_pre_order() ;
    //    cout << node->get_value() << endl;
    //    ++node;
    //    cout << node->get_value() << endl;
    //     ++node;
    //     cout << node->get_value() << endl;
    //     ++node;
    //     cout << node->get_value() << endl;
    //     ++node;
    //     cout << node->get_value() << endl;
    //     ++node;
    //     cout << node->get_value() << endl;
    // auto node1 = tree.begin_pre_order();
    // auto node2 = tree.end_pre_order();
    // out << node1->get_value() << endl;
    // cout << node2->get_value() << endl;

    /// node1 != tree.end_pre_order();

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "Post order scan:\n";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "In order scan:\n";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << "BFS scan:\n";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << "DFS scan:\n";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6 
cout << "heap scan:\n";
    for (auto node = tree.begin_heap_scan(); node != tree.end_heap_scan(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
     auto node = tree.begin_pre_order();
     auto node1 = tree.end_pre_order();
    //cout << node->get_value() << endl;
    //cout << node1->get_value() << endl;

    return 0;
}