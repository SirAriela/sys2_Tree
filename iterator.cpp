//arielag1998@gmail.com
//206862666



#include "iterator.hpp"

template <typename T>
iterator<T> &iterator<T>::operator++()
{
    if (!m_stack.empty())
    {
        Node<T> *current = m_stack.top();
        m_stack.pop();

        for (int i = current->children.size() - 1; i >= 0; i--)
        {
            m_stack.push(current->children[i]);
        }

        m_pointer = current;
    }
    else
    {
        m_pointer = nullptr;
    }

    return *this;
}

template <typename T>
iterator<T> &iterator<T>::operator++(int)
{
    iterator<T> temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
iterator<T> &iterator<T>::inorder_next()
{
    if (!m_stack.empty())
    {
        Node<T> *current = m_stack.top();
        m_stack.pop();

        for (int i = current->children.size() - 1; i >= 0; i--)
        {
            m_stack.push(current->children[i]);
        }

        m_pointer = current;
    }
    else
    {
        m_pointer = nullptr;
    }

    return *this;
}

template <typename T>
iterator<T> &iterator<T>::bfs_next()
{
    if (!m_queue.empty())
    {
        Node<T> *current = m_queue.front();
        m_queue.pop();

        for (int i = 0; i < current->children.size(); i++)
        {
            m_queue.push(current->children[i]);
        }

        m_pointer = current;
    }
    else
    {
        m_pointer = nullptr;
    }

    return *this;
}

template <typename T>
iterator<T> &iterator<T>::dfs_next()
{
    if (!m_stack.empty())
    {
        Node<T> *current = m_stack.top();
        m_stack.pop();

        for (int i = current->children.size() - 1; i >= 0; i--)
        {
            m_stack.push(current->children[i]);
        }

        m_pointer = current;
    }
    else
    {
        m_pointer = nullptr;
    }

    return *this;
}
