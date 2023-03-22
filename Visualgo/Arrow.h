#pragma once
#include <SFML/Graphics.hpp>

struct Arrow {
    sf::RectangleShape body;
    sf::ConvexShape head;

    Arrow(float x, float y, float length, float thickness, sf::Color color);
    void draw(sf::RenderTarget& window);
};

