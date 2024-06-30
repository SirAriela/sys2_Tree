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
    std::stack<Node<T> *> m_stack;
    std::queue<Node<T> *> m_queue;

public:
    iterator(Node<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            m_stack.push(ptr);
            m_queue.push(ptr);
        }
    }

    bool operator!=(const iterator &other) const { return m_pointer != other.m_pointer; }
    T &operator*() { return m_pointer->data; }

    // Preorder ++
    iterator &operator++();

    // Postorder ++
    iterator &operator++(int);

    // Inorder iterator
    iterator &inorder_next();

    // BFS
    iterator &bfs_next();

    // DFS
    iterator &dfs_next();
};