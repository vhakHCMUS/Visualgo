#include "Circle.h"

Circle::Circle(float x, float y, float radius, std::string text_str, sf::Font& font, 
            sf::Color fill_color, sf::Color text_color, sf::Color outline_color) {
    shape.setPosition(x, y);
    shape.setRadius(radius);
    shape.setFillColor(fill_color);
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(outline_color);

    text.setFont(font);
    text.setString(text_str);
    text.setCharacterSize(20);
    text.setFillColor(text_color);

    // Center text in the circle
    sf::FloatRect text_bounds = text.getLocalBounds();
    text.setOrigin(text_bounds.left + text_bounds.width / 2.0f, text_bounds.top + text_bounds.height / 2.0f);
    text.setPosition(x + radius, y + radius);
}

void Circle::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}


