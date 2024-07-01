// node.hpp
#ifndef NODE_HPP
#define NODE_HPP

#pragma once

#include <vector>

template <typename T>
class Node
{
public:
    Node(const T &data) : data(data) {}
    ~Node() = default;

    T get_data() const{ return data;}
    std::vector<Node<T>*> get_children() const { return children; }

    T data;
    std::vector<Node<T>*> children;
};

#endif 
