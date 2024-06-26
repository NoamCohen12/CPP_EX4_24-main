#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "iterators.hpp"
#include "Node.hpp"

using namespace std;


TEST_CASE("preorder") {
    Node<double> root_node = Node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
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

    PreOrderIterator<double> it = tree.begin_pre_order();
    CHECK(it != tree.end_pre_order());
    CHECK((*it)->get_value() == 1.1);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((*it)->get_value() == 1.2);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((*it)->get_value() == 1.4);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((*it)->get_value() == 1.5);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((*it)->get_value() == 1.3);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((*it)->get_value() == 1.6);
    ++it;
    CHECK(it == tree.end_pre_order());


}
