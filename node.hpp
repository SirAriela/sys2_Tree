// arielag1998@gmail.com
// 206862666

// node.hpp
#ifndef NODE_HPP
#define NODE_HPP

#include "complex.hpp"
#include <vector>

template <typename T>
class Node
{
public:
    Node(const T &data) : data(data)
    {
        children = std::vector<Node<T> *>();
    }

    T get_data() const { 
        return data;
    }
    std::vector<Node<T> *> get_children() const { return children; }

    T data;
    std::vector<Node<T> *> children;
};

#endif
