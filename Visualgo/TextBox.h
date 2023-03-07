#include <SFML/Graphics.hpp>

#include <SFML/Graphics.hpp>

struct TextBox {
    sf::RectangleShape shape;
    sf::Text text;
    bool isSelected = false;

    TextBox(sf::Font& font, float x, float y, float width, float height, sf::Color fillColor, sf::Color outlineColor, float outlineThickness);

    void draw(sf::RenderWindow& window);

    void handleEvent(sf::Event event);
};