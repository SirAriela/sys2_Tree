

#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include <iostream>
#include <filesystem>

template <typename T, int k>
class MainWindow
{
public:
    MainWindow(Tree<T, k> &tree) : tree(tree) {}

    void run()
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            drawTree(window, tree.getRoot(), 400, 50, 200);
            window.display();
        }
    }

private:
    Tree<T, k> &tree;

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
                sf::Vertex(sf::Vector2f(childX, childY), sf::Color::Black)
            };
            
            window.draw(line, 2, sf::Lines);

            // Draw child recursively
            drawTree(window, node->children[i], childX, childY, offsetX / 2);
        }
    }
};
int main()
{
    Node<double> root_node1(1.1);
    Tree<double, 3> three_ary_tree; // 3-ary tree.

    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    three_ary_tree.add_root(&root_node1);
    three_ary_tree.add_sub_node(root_node1, n1);
    three_ary_tree.add_sub_node(root_node1, n2);
    three_ary_tree.add_sub_node(root_node1, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    MainWindow<double, 3> mainWindow(three_ary_tree);
    mainWindow.run();

    return 0;
}
