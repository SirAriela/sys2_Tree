#include "node.hpp"

template <typename T>
Node<T>::Node(const T &data) : data(data) {
    this->children = {};
}

template <typename T>
T Node<T>::get_data() const
{
    return data;
}
