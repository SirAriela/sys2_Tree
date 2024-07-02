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

    // Begin and end functions for iterators
    iterator_pre_Order<T> begin_pre_order() {
        return iterator_pre_Order<T>(root);
    }

    iterator_pre_Order<T> end_pre_order() {
        return iterator_pre_Order<T>(nullptr);
    }
   
    iterator_post_Order<T> begin_post_order() {
        return iterator_post_Order<T>(root);
    }

    iterator_post_Order<T> end_post_order() {
        return iterator_post_Order<T>(nullptr);
    }
};

#endif // TREE_HPP
