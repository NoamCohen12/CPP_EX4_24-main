#include <iostream>
#include <string>

#include "Complex.hpp"
#include "Iterators.hpp"
#include "Node.hpp"
#include "tree.hpp"
using namespace std;
int main() {
    Node<double> root_nodee = Node(1.1);
    Node<double> n11 = Node(1.2);
    Node<double> n22 = Node(1.3);
    Node<double> n33 = Node(1.4);
    Node<double> n44 = Node(1.5);
    Node<double> n55 = Node(1.6);
    Tree<double> tree1;  // Binary tree that contains doubles.
    tree1.add_root(&root_nodee);
    tree1.add_sub_node(&root_nodee, &n11);
    tree1.add_sub_node(&root_nodee, &n22);
    tree1.add_sub_node(&n11, &n33);
    tree1.add_sub_node(&n11, &n44);
    tree1.add_sub_node(&n22, &n55);

    cout << "Pre order scan:\n";
    for (auto node = tree1.begin_pre_order(); node != tree1.end_pre_order(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "Post order scan:\n";
    for (auto node = tree1.begin_post_order(); node != tree1.end_post_order(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "In order scan:\n";
    for (auto node = tree1.begin_in_order(); node != tree1.end_in_order(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << "BFS scan:\n";
    for (auto node = tree1.begin_bfs_scan(); node != tree1.end_bfs_scan(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

cout<<"BFS same:\n";//like demo
for (auto node : tree1)
    {
        cout << node->get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6


    cout << "DFS scan:\n";
    for (auto node = tree1.begin_dfs_scan(); node != tree1.end_dfs_scan(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << "heap scan:\n";
    for (auto node = tree1.begin_heap_scan(); node != tree1.end_heap_scan(); ++node) {
        cout << node->get_value() << ", " << endl;
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    Complex c1 = Complex(1.1, 2.2);
    Complex c2 = Complex(1.2, 2.3);
    Complex c3 = Complex(1.3, 2.4);
    Complex c4 = Complex(1.4, 2.5);
    Complex c5 = Complex(1.5, 2.6);
    Complex c6 = Complex(1.6, 2.7);

    Node<Complex> root_node = Node(c1);
    Node<Complex> n1 = Node(c2);
    Node<Complex> n2 = Node(c3);
    Node<Complex> n3 = Node(c4);
    Node<Complex> n4 = Node(c5);
    Node<Complex> n5 = Node(c6);

    Tree<Complex> tree;  // 3-ary tree.
    tree.add_root(&root_node);
    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);
     tree.draw();
//drawTreeGUI(tree);
    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    Node<double> root_nodeee = Node(1.1);
    Node<double> n111 = Node(1.2);
    Node<double> n222 = Node(1.3);
    Node<double> n333 = Node(1.4);
    Node<double> n444 = Node(1.5);
    Node<double> n555 = Node(1.6);
    Node<double> n666 = Node(1.7);
    Node<double> n777 = Node(1.8);
    Node<double> n888 = Node(1.9);
    Node<double> n999 = Node(2.0);


    Tree<double, 3> tree111;  // Binary tree that contains doubles.
    tree111.add_root(&root_nodeee);
    tree111.add_sub_node(&root_nodeee, &n111);
    tree111.add_sub_node(&root_nodeee, &n222);
    tree111.add_sub_node(&root_nodeee, &n666);
    tree111.add_sub_node(&n111, &n333);
    tree111.add_sub_node(&n111, &n444);
    tree111.add_sub_node(&n222, &n555);
    tree111.add_sub_node(&n222, &n777);
    tree111.add_sub_node(&n222, &n888);
    tree111.draw();
   // The tree structure should represent the following hierarchy:

//                      1.1
//              /        |       /
//            1.2      1.3      1.7
//           /  \      /|  /
//         1.4 1.5  1.6 1.8 1.9

 




    return 0;
}