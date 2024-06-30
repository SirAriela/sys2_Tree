//arielag1998@gmail.com
//206862666

#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include <iostream>

class MainWindow {
public:
    MainWindow(Tree<int>& tree) : tree(tree) {}

    void run() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            drawTree(window, tree.getRoot(), 400, 50, 200);
            window.display();
        }
    }

private:
    Tree<int>& tree;

    void drawTree(sf::RenderWindow& window, Node<int>* node, float x, float y, float offset) {
        if (!node) return;

        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(x - circle.getRadius(), y - circle.getRadius());
        window.draw(circle);

        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Error loading font\n";
            return;
        }
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(node->get_data()));
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x - 10, y - 15);
        window.draw(text);

        float childX = x - offset;
        float childY = y + 100;

        for (auto child : node->children) {
            if (child) {
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x, y)),
                    sf::Vertex(sf::Vector2f(childX, childY))
                };
                window.draw(line, 2, sf::Lines);
                drawTree(window, child, childX, childY, offset / 2);
                childX += offset;
            }
        }
    }
};

int main() {
    Tree<int> tree;
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);

    tree.add_root(root);
    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(child1, child3);

    MainWindow mainWindow(tree);
    mainWindow.run();

    return 0;
}
