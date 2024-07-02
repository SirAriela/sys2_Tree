// arielag1998@gmail.com
// 206862666

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
    iterator_pre_Order &operator++()
    {
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
    Node<T> *m_pointer;
    std::stack<Node<T> *> m_stack;
    Node<T> *m_last_visited;

public:
    iterator_post_Order(Node<T> *ptr = nullptr) : m_pointer(ptr), m_last_visited(nullptr)
    {
        if (ptr)
        {
            m_stack.push(ptr);
            advance();
        }
    }

    bool operator!=(const iterator_post_Order &other) const
    {
        return m_pointer != other.m_pointer;
    }

    T &operator*() const
    {
        return m_pointer->data;
    }

    iterator_post_Order &operator++()
    {
        advance();
        return *this;
    }

private:
    void advance()
    {
        while (!m_stack.empty())
        {
            Node<T> *current = m_stack.top();
            if (!current->children.empty() && m_last_visited != current->children.back())
            {
                for (auto it = current->children.rbegin(); it != current->children.rend(); ++it)
                {
                    m_stack.push(*it);
                }
            }
            else
            {
                m_stack.pop();
                m_last_visited = current;
                m_pointer = current;
                return;
            }
        }
        m_pointer = nullptr;
    }
};

template <typename T>
class iterator_in_Order
{
private:
    Node<T> *m_pointer;
    std::stack<Node<T> *> m_stack;

public:
    void push_leftmost(Node<T> *node)
    {
        while (node)
        {
            m_stack.push(node);
            if (!node->children.empty())
            {
                node = node->children[0];
            }
            else
            {
                node = nullptr;
            }
        }
    }

public:
    iterator_in_Order(Node<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            push_leftmost(ptr);
            m_pointer = m_stack.empty() ? nullptr : m_stack.top();
        }
    }

    bool operator!=(const iterator_in_Order &other) const
    {
        return m_pointer != other.m_pointer;
    }

    T &operator*() const
    {
        return m_stack.top()->data;
    }

    iterator_in_Order &operator++()
    {
        if (!m_stack.empty())
        {
            Node<T> *node = m_stack.top();
            m_stack.pop();
            if (node->children.size() > 1)
            {
                push_leftmost(node->children[1]);
            }
            m_pointer = m_stack.empty() ? nullptr : m_stack.top();
        }
        return *this;
    }
};

template <typename T>
class iterator_bfs_scan
{
private:
    Node<T> *m_pointer;
    std::queue<Node<T> *> m_queue;

public:
    iterator_bfs_scan(Node<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            m_queue.push(ptr);
        }
    }

    bool operator!=(const iterator_bfs_scan &other) const { return !m_queue.empty(); }
    T &operator*() const { return m_queue.front()->data; }

    iterator_bfs_scan &operator++()
    {
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
class iterator_dfs_scan
{
private:
    Node<T> *m_pointer;
    std::stack<Node<T> *> m_stack;

public:
    iterator_dfs_scan(Node<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            m_stack.push(ptr);
        }
    }

    bool operator!=(const iterator_dfs_scan &other) const
    {
        // Properly compare against another iterator
        if (other.m_stack.empty() && m_stack.empty())
        {
            return false;
        }
        if (!m_stack.empty() && other.m_stack.empty())
        {
            return true;
        }
        return m_stack.top() != other.m_stack.top();
    }

    T &operator*() const
    {
        if (!m_stack.empty())
        {
            return m_stack.top()->data;
        }
        throw std::out_of_range("Iterator out of range");
    }

    iterator_dfs_scan &operator++()
    {
        if (!m_stack.empty())
        {
            Node<T> *current = m_stack.top();
            m_stack.pop();
            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it)
            {
                m_stack.push(*it);
            }
        }
        return *this;
    }

    bool operator==(const iterator_dfs_scan &other) const
    {
        return !(*this != other);
    }
};


template <typename T>
class iterator_heap {
private:
    typename std::vector<T>::iterator m_iterator;

public:
    iterator_heap(typename std::vector<T>::iterator it) : m_iterator(it) {}

    bool operator!=(const iterator_heap &other) const { return m_iterator != other.m_iterator; }
    T &operator*() const { return *m_iterator; }
    iterator_heap &operator++() {
        ++m_iterator;
        return *this;
    }
};

