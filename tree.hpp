// arielag1998@gmail.com
// 206862666

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <queue>
#include "node.hpp"


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

   
};

#endif // TREE_HPP
