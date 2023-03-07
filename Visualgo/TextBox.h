#include <SFML/Graphics.hpp>

#include "DoublyLinkedList.h"

struct TextBox {
    sf::RectangleShape shape;
    sf::Text text;
    doublyLinkedList List;

    bool isSelected = false;

    TextBox(sf::Font& font, float x, float y, float width, float height, sf::Color fillColor, sf::Color outlineColor, float outlineThickness);

    void update();
    void draw(sf::RenderWindow& window);

    void handleEvent(sf::Event event);
};