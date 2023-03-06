#pragma once
#include <SFML/Graphics.hpp>

struct Circle {
    sf::CircleShape shape;
    sf::Text text;

    Circle(float x, float y, float radius, std::string text_str, sf::Font& font,
        sf::Color fill_color, sf::Color text_color, sf::Color outline_color);

    void draw(sf::RenderWindow& window);
};

