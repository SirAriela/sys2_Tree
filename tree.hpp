// arielag1998@gmail.com
// 206862666

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <queue>
#include "node.hpp"
#include "iterator.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>

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

    // Begin and end functions for iterators
    iterator_pre_Order<T> begin_pre_order()
    {
        return iterator_pre_Order<T>(root);
    }

    iterator_pre_Order<T> end_pre_order()
    {
        return iterator_pre_Order<T>(nullptr);
    }

    iterator_post_Order<T> begin_post_order()
    {
        return iterator_post_Order<T>(root);
    }

    iterator_post_Order<T> end_post_order()
    {
        return iterator_post_Order<T>(nullptr);
    }
    iterator_in_Order<T> begin_in_order()
    {
        return iterator_in_Order<T>(root);
    }

    iterator_in_Order<T> end_in_order()
    {
        return iterator_in_Order<T>(nullptr);
    }

    iterator_bfs_scan<T> begin_bfs_scan()
    {
        return iterator_bfs_scan<T>(root);
    }

    iterator_bfs_scan<T> end_bfs_scan()
    {
        return iterator_bfs_scan<T>(nullptr);
    }

    friend std::ostream &operator<<(std::ostream &os, const Tree<T, k> &tree)
    {
        os << tree->toString(tree.root, "", true);
        tree.visualizeTree(); // קריאה לפונקציה שמציגה את העץ באמצעות SFML
        return os;
    }
};

#endif // TREE_HPP
