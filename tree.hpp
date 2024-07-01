// arielag1998@gmail.com
// 206862666

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <queue>
#include "node.hpp"
#include "iterator.hpp"

template <typename T, int k = 2>
class Tree
{
private:
    Node<T> *root;

public:
    Tree() : root(nullptr) {}
    ~Tree() = default;

    void add_root(Node<T> *node)
    {
        this->root = node;
    }

    void add_sub_node(Node<T> &parent, Node<T> &child)
    {
        if (parent.children.size() < k)
        {
            parent.children.push_back(&child);
        }
        else
        {
            throw "cant add more childrens";
        }
    }

    Node<T> *getRoot() const { return root; }

    // preorder
    iterator begin_pre_order();
    iterator end_pre_order();

    // Post-Order
    iterator begin_post_order();
    iterator end_post_order();

    // In-Order
    iterator begin_in_order();
    iterator end_in_order();

    // BFS
    iterator begin_bfs_scan();
    iterator end_bfs_scan();

    // DFS
    iterator begin_dfs_scan();
    iterator end_dfs_scan();

    iterator heap;

    void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const Tree &tree)
    {
        // tree.print(os);
        // return os;
    }
};

#endif // TREE_HPP
