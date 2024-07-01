//arielag1998@gmail.com
//206862666


#include <stack>
#include <queue>
#include "node.hpp"


template <typename T>
class iterator
{
private:
    Node<T> *m_pointer;
    std::queue<Node<T> *> m_queue;

public:
    iterator(Node<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            m_queue.push(ptr);
        }
    }

    bool operator!=(const iterator &other) const { return m_pointer != other.m_pointer; }
    T &operator*() const { return m_pointer->data; }

    // Preorder ++
    iterator &operator++(){
        Node<T> *current = m_queue.front();
        m_queue.pop();
        for (auto child : current->children)
        {
            m_queue.push(child);
        }
        return *this;
    }

    // Begin and end functions for iterators
    iterator begin() {
        return iterator(root);
    }

    iterator end() {
        return iterator(nullptr);
    }
};