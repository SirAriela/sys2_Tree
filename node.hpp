#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template <typename T>
class Node
{
public:

    Node(const T &data);
    ~Node(){}

    T get_data() const;

    T data;
    std::vector<Node<T> *> children;

};
#endif // NODE_HPP
