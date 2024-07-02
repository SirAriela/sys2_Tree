// arielag1998@gmail.com
// 206862666

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <queue>
#include "node.hpp"
#include "iterator.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>

template <typename T, int k = 2>
class Tree
{
private:
    Node<T> *root;
    std::vector<T> heap;

    // HEAP FUNCTIONS ------------------------------------------------------------------------
    void inorder_traversal(Node<T> *node, std::vector<T> &nodes)
    {
        if (node == nullptr)
            return;
        // Traverse left
        if (node->children.size() > 0 && node->children[0] != nullptr)
            inorder_traversal(node->children[0], nodes);
        // Visit node
        nodes.push_back(node->data);
        // Traverse right
        if (node->children.size() > 1 && node->children[1] != nullptr)
            inorder_traversal(node->children[1], nodes);
    }

    void heapify()
    {
        std::make_heap(heap.begin(), heap.end(), std::greater<T>());
    }

public:
    // TREE FUNCTIONS ------------------------------------------------------------------------
    Tree() : root(nullptr) {}

    void add_root(Node<T> *node)
    {
        root = node;
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

    Node<T> *getRoot() const
    {
        if (root == nullptr)
            throw std::invalid_argument("Tree is empty");
        return root;
    }

    void delete_tree(Node<T> *node)
    {
        if (node)
        {
            if (!node->children.empty())
            {
                delete node;
                node = nullptr;
                return;
            }

            for (auto child : node->get_children())
            {
                delete_tree(child);
            }

            node->children.clear();

            delete node;
            node = nullptr;
        }
    }

    // Iterator functions -----------------------------------------------------------------------------------------

    // Begin and end functions for iterators
    iterator_pre_Order<T> begin_pre_order()
    {
        return iterator_pre_Order<T>(root);
    }

    iterator_pre_Order<T> end_pre_order()
    {
        return iterator_pre_Order<T>(nullptr);
    }

    iterator_post_Order<T> begin_post_order()
    {
        return iterator_post_Order<T>(root);
    }

    iterator_post_Order<T> end_post_order()
    {
        return iterator_post_Order<T>(nullptr);
    }
    iterator_in_Order<T> begin_in_order()
    {
        return iterator_in_Order<T>(root);
    }

    iterator_in_Order<T> end_in_order()
    {
        return iterator_in_Order<T>(nullptr);
    }

    iterator_bfs_scan<T> begin_bfs_scan()
    {
        return iterator_bfs_scan<T>(root);
    }

    iterator_bfs_scan<T> end_bfs_scan()
    {
        return iterator_bfs_scan<T>(nullptr);
    }

    iterator_dfs_scan<T> begin_dfs_scan()
    {
        return iterator_dfs_scan<T>(root);
    }

    iterator_dfs_scan<T> end_dfs_scan()
    {
        return iterator_dfs_scan<T>(nullptr);
    }

    // Heap iterator functions
    iterator_heap<T> begin_heap()
    {
        if (k == 2)
        {
            if (heap.empty())
            {
                myHeap();
            }
            return iterator_heap<T>(heap.begin());
        }
        else
        {
            throw "cant use heap iterator on non binary tree";
        }
    }

    iterator_heap<T> end_heap()
    {
        if (k == 2)
        {
            if (heap.empty())
            {
                myHeap();
            }
            return iterator_heap<T>(heap.end());
        }
        else
        {
            throw "cant use heap iterator on non binary tree";
        }
    }

    // Convert tree to min-heap
    void myHeap()
    {
        heap.clear();
        if (root)
        {
            inorder_traversal(root, heap);
        }
        heapify();
    }

    void run()
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            window.clear(sf::Color::White);
            drawTree(window, getRoot(), 400, 50, 200);
            window.display();
        }
    }

    void drawTree(sf::RenderWindow &window, Node<T> *node, float x, float y, float offsetX)
    {
        if (!node)
            return;

        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(x - circle.getRadius(), y - circle.getRadius());
        window.draw(circle);

        sf::Font font;
        std::string fontPath = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";

        if (!font.loadFromFile(fontPath))
        {
            std::cerr << "Error loading font from: " << fontPath << std::endl;
            return;
        }

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(node->get_data()));
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x - 10, y - 15);
        window.draw(text);

        float startY = y + 40;

        // Calculate child positions
        float startX = x - (k - 1) * offsetX / 2;
        for (size_t i = 0; i < node->children.size(); ++i)
        {
            float childX = startX + i * offsetX;
            float childY = startY + 100;

            // Draw line to child
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y)),
                sf::Vertex(sf::Vector2f(childX, childY), sf::Color::Black)};

            window.draw(line, 2, sf::Lines);

            // Draw child recursively
            drawTree(window, node->children[i], childX, childY, offsetX / 2);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, Tree<T, k> &tree)
    {
        tree.run();
        return os;
    }
};

#endif // TREE_HPP
