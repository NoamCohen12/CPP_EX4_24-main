#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Node.hpp"
#include "doctest.h"
#include "iterators.hpp"
#include "tree.hpp"

using namespace std;

TEST_CASE("preorder") {
    Node<double> root_node = Node(1.1);
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

    PreOrderIterator<double> it = tree.begin_pre_order();
    CHECK(it != tree.end_pre_order());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK(it != tree.end_pre_order());
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK(it == tree.end_pre_order());
};
TEST_CASE("postorder") {
    Node<double> root_node = Node(1.1);
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
    PostOrderIterator<double> it = tree.begin_post_order();
    CHECK(it != tree.end_post_order());
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it != tree.end_post_order());
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK(it != tree.end_post_order());
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK(it != tree.end_post_order());
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK(it != tree.end_post_order());
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK(it != tree.end_post_order());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK(it == tree.end_post_order());
};
TEST_CASE("inOrder") {
    Node<double> root_node = Node(1.1);
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
    InOrderIterator<double> it = tree.begin_in_order();
    CHECK(it != tree.end_in_order());
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it != tree.end_in_order());
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK(it != tree.end_in_order());
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK(it != tree.end_in_order());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK(it != tree.end_in_order());
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK(it != tree.end_in_order());
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK(it == tree.end_in_order());
};
TEST_CASE("BFS") {
    Node<double> root_node = Node(1.1);
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
    BfsIterator<double> it = tree.begin_bfs_scan();
    CHECK(it != tree.end_bfs_scan());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK(it != tree.end_bfs_scan());
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK(it != tree.end_bfs_scan());
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK(it != tree.end_bfs_scan());
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it != tree.end_bfs_scan());
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK(it != tree.end_bfs_scan());
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK(it == tree.end_bfs_scan());
};
TEST_CASE("DFS") {
    Node<double> root_node = Node(1.1);
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
    DFSIterator<double> it = tree.begin_dfs_scan();
    CHECK(it != tree.end_dfs_scan());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK(it != tree.end_dfs_scan());
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK(it != tree.end_dfs_scan());
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it != tree.end_dfs_scan());
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK(it != tree.end_dfs_scan());
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK(it != tree.end_dfs_scan());
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK(it == tree.end_dfs_scan());
};
TEST_CASE("heap") {
    Node<double> root_node = Node(1.1);
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
    HeapIterator<double> it = tree.begin_heap_scan();
    CHECK(it != tree.end_heap_scan());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK(it != tree.end_heap_scan());
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK(it != tree.end_heap_scan());
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK(it != tree.end_heap_scan());
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it != tree.end_heap_scan());
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK(it != tree.end_heap_scan());
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK(it == tree.end_heap_scan());
};

TEST_CASE("in order with tree k>2") {//use DFS iterator
    Node<double> root_node = Node(1.1);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);
    Tree<double, 3> three_ary_tree;  // 3-ary tree.
    three_ary_tree.add_root(&root_node);
    three_ary_tree.add_sub_node(&root_node, &n1);
    three_ary_tree.add_sub_node(&root_node, &n2);
    three_ary_tree.add_sub_node(&root_node, &n3);
    three_ary_tree.add_sub_node(&n1, &n4);
    three_ary_tree.add_sub_node(&n2, &n5);
    auto it = three_ary_tree.begin_in_order();
   CHECK(it != three_ary_tree.end_in_order());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it == three_ary_tree.end_in_order());
};
    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

TEST_CASE("pre order with tree k>2") {
  Node<double> root_node = Node(1.1);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);
    Tree<double, 3> three_ary_tree;  // 3-ary tree.
    three_ary_tree.add_root(&root_node);
    three_ary_tree.add_sub_node(&root_node, &n1);
    three_ary_tree.add_sub_node(&root_node, &n2);
    three_ary_tree.add_sub_node(&root_node, &n3);
    three_ary_tree.add_sub_node(&n1, &n4);
    three_ary_tree.add_sub_node(&n2, &n5);    auto it = three_ary_tree.begin_pre_order();
    CHECK(it != three_ary_tree.end_pre_order());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it == three_ary_tree.end_pre_order());
};

TEST_CASE("post order with tree k>2") {
  Node<double> root_node = Node(1.1);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);
    Tree<double, 3> three_ary_tree;  // 3-ary tree.
    three_ary_tree.add_root(&root_node);
    three_ary_tree.add_sub_node(&root_node, &n1);
    three_ary_tree.add_sub_node(&root_node, &n2);
    three_ary_tree.add_sub_node(&root_node, &n3);
    three_ary_tree.add_sub_node(&n1, &n4);
    three_ary_tree.add_sub_node(&n2, &n5);    auto it = three_ary_tree.begin_post_order();
    CHECK(it != three_ary_tree.end_post_order());
    CHECK((it)->get_value() == 1.1);
    ++it;
    CHECK((it)->get_value() == 1.2);
    ++it;
    CHECK((it)->get_value() == 1.5);
    ++it;
    CHECK((it)->get_value() == 1.3);
    ++it;
    CHECK((it)->get_value() == 1.6);
    ++it;
    CHECK((it)->get_value() == 1.4);
    ++it;
    CHECK(it == three_ary_tree.end_post_order());

};
