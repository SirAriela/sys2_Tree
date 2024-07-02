//arielag1998@gmail.com
//206862666


#include <stack>
#include <queue>
#include "node.hpp"


template <typename T>
class iterator_pre_Order
{
private:
    Node<T> *m_pointer;
    std::queue<Node<T> *> m_queue;

public:
    iterator_pre_Order(Node<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            m_queue.push(ptr);
        }
    }

    bool operator!=(const iterator_pre_Order &other) const { return !m_queue.empty(); }
    T &operator*() const { return m_queue.front()->data; }

    // Preorder ++
    iterator_pre_Order &operator++(){
        Node<T> *current = m_queue.front();
        m_queue.pop();
        for (auto child : current->children)
        {
            m_queue.push(child);
        }
        return *this;
    }

    
};

template <typename T>
class iterator_post_Order
{
private:
    Node<T>* m_pointer;
    std::stack<Node<T>*> m_stack;
    Node<T>* m_last_visited;

public:
    iterator_post_Order(Node<T>* ptr = nullptr) : m_pointer(ptr), m_last_visited(nullptr) {
        if (ptr) {
            m_stack.push(ptr);
            advance();
        }
    }

    bool operator!=(const iterator_post_Order& other) const {
        return m_pointer != other.m_pointer;
    }

    T& operator*() const {
        return m_pointer->data;
    }

    iterator_post_Order& operator++() {
        advance();
        return *this;
    }

private:
    void advance() {
        while (!m_stack.empty()) {
            Node<T>* current = m_stack.top();
            if (!current->children.empty() && m_last_visited != current->children.back()) {
                for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
                    m_stack.push(*it);
                }
            } else {
                m_stack.pop();
                m_last_visited = current;
                m_pointer = current;
                return;
            }
        }
        m_pointer = nullptr;
    }

};